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
echo "========================================"
echo " Building lexer"
make lexer
echo "========================================"
echo " Building parser"
make parser
echo "========================================"
echo " Force building bin/compiler (all lexer, parser..)"
make bin/compiler
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
fi
echo ""
echo "========================================"
echo "Compiling to MIPS..."
echo $2 | ./bin/compiler 
# cat $2 | ./bin/compiler 2> /dev/null 1> $4

# -------------------------
# PASSED=0
# CHECKED=0

# if [[ -f test/valid_expressions.got.txt ]]; then
#     rm test/valid_expressions.got.txt
# fi
# while IFS=, read -r INPUT_LINE REF_LINE BINDINGS REF_VALUE; do
#     echo "==========================="
#     echo ""
#     echo "Input : ${INPUT_LINE}"
#     GOT_LINE=$( echo -n "${INPUT_LINE}" | bin/compiler )
#     echo "Output : ${GOT_LINE}"
#     if [[ "${GOT_LINE}" != "${REF_LINE}" ]]; then
#         echo ""
#         echo "ERROR"
#     else
#         PASSED=$(( ${PASSED}+1 ));
#     fi
#     CHECKED=$(( ${CHECKED}+1 ));

#     echo "${INPUT_LINE},${GOT_LINE}" >> test/valid_expressions.got.txt

# done < <( cat test/valid_expressions.input.txt | ${DOS2UNIX})

# echo "########################################"
# echo "Passed ${PASSED} out of ${CHECKED} checks".
# echo ""
# -------------------------


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
