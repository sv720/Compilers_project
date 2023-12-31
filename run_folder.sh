#!/bin/bash

# Try to find a portable way of getting rid of
# any stray carriage returns
if which dos2unix ; then
    DOS2UNIX="dos2unix"
elif which fromdos ; then
    DOS2UNIX="fromdos"
else
    >&2 echo "warning: dos2unix is not installed."
    # This should work on Linux and MacOS, it matches all the carriage returns with sed and removes
    # them.  `tr` is used instead of `sed` because some versions of `sed` don't recognize the
    # carriage return symbol.  Something similar could be implemented with `sed` if necessary or
    # worst case it could be disabled by substituting it with `cat`.  One other thing to note is
    # that there are no quotes around the \r, which is so that it gets converted by bash.
    DOS2UNIX="tr -d \r"
    # DOS2UNIX="sed -e s/\r//g"
    # DOS2UNIX="cat"
fi

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
# echo "========================================"
# echo " Building lexer"
# make lexer
# echo "========================================"
# echo " Building parser"
# make parser
echo "========================================"
echo " Force building bin/compiler (all lexer, parser..)"
make -B bin/c_compiler # 2> /dev/null
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
fi
echo ""
echo "========================================"
echo "Compiling OUTPUTS..."
# echo $2 | bin/compiler 
# cat $2 | ./bin/compiler 2> /dev/null 1> $4


basefolder=$(basename $1)
mkdir -p test/working/${basefolder}/
mkdir -p test/err/${basefolder}/
mkdir -p test/objects/${basefolder}/

# -------------------------
index=1
CHECKED=0

for testcase in compiler_tests/${basefolder}/*_driver.c; do
    base=$(basename ${testcase});
    name=${base%_driver.c}
    file=${testcase%_driver.c}.c
    
    
    echo "=============TESTCASE ${index}=============="
    echo ""
    echo "Input file : ${file}"
    echo "Testing ${name}:"
    cat ${file}
    echo " "
    echo " ------------"
    echo "OUTPUT PRINT: "
    bin/c_compiler -S ${file} -o test/working/${basefolder}/${name}.s 2> test/err/${basefolder}/${name}.err
    cat test/working/${basefolder}/${name}.s
    # cat ${file} | bin/c_compiler 2> test/err/${basefolder}/${name}.err
    errMsg=$?
    echo $errMsg    
    if [[ $errMsg -eq "139" ]]; then
    	echo " ERROR - seg fault"
    else
    	if (cmp -s test/err/${basefolder}/${name}.err test/ErrorMSG.txt); then # 0 when equal
		CHECKED=$(( ${CHECKED}+1 )); 
    	else
        	echo -n " ERROR - parsing syntax"
    	fi
    fi
    index=$((${index}+1));
    # cat ${file} | bin/c_compiler 2> test/err/local_var/$name.err 1> test/working/local_var/$name.o
    # cat ${file} | bin/c_compiler 1> test/working/local_var/$name.o

    # AIM:
    # cat $2 | ./bin/compiler 2> /dev/null 1> $4
    # bin/c_compiler -S ${file} -o test/working/local_var/${name}.s
                        # $2          $4

    echo " "
done

echo "########################################"
echo " Nb of files PARSING succesfully: ${CHECKED} out of $((${index}-1))"
echo " "


index=1
PASSED=0
for testcase in test/working/${basefolder}/*; do
    base=$(basename ${testcase});
    name=${base%.s}    
    
    echo "=============MIPS-LINUX-GNU-GCC on ${name} (${index})=============="
    # MIPS conversion 
    mips-linux-gnu-gcc -g -mfp32 -o test/objects/${basefolder}/${name}.o -c test/working/${basefolder}/${name}.s

    mips-linux-gnu-gcc -g -mfp32 -static -o test/objects/${basefolder}/${name} test/objects/${basefolder}/${name}.o compiler_tests/${basefolder}/${name}_driver.c
    qemu-mips test/objects/${basefolder}/${name}

    errMsg=$?
    echo "QEMU-MIPS: " $errMsg    
    if [[ $errMsg -eq "0" ]]; then
    	echo " QEMU-MIPS: TESTCASE + driver compiler succesfully"
        PASSED=$(( ${PASSED}+1 )); 
    else
        echo " QEMU-MIPS: ERROR"
    fi
    echo " "
    index=$((${index}+1));
done

echo "########################################"
echo " Nb of files COMPILED succesfully: ${PASSED} out of $((${index}-1))"
echo ""


RELEASE=$(lsb_release -d)
if [[ $? -ne 0 ]]; then
    echo ""
    echo "Warning: This appears not to be a Linux environment"
    echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
else
    grep -q "Ubuntu 20.04" <(echo $RELEASE)
    FOUND=$?

    if [[ $FOUND -ne 0 ]]; then
        echo ""
        echo "Warning: This appears not to be the target environment"
        echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
    fi
fi
