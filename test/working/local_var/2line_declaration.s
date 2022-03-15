.global f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move $fp,$sp
addiu $sp,$sp,-4 
#AddOperator generateMIPS Called
#Calling left 
li $2,12345
move $10,$2
#MulOperator generateMIPS Called
#Calling left 
li $2,5
move $8,$2
li $2,6
move $9,$2
mult $8,$9
mflo $2
mfhi $3
move $11,$2
add $2,$10,$11
#DEBUG : IN INITDECLARATOR 
sw $2,0($fp)
sw $fp,4($sp)
move $fp,$sp
addiu $sp,$sp,-4 
li $2,4
#DEBUG : IN INITDECLARATOR 
sw $2,0($fp)
sw $fp,4($sp)
move $fp,$sp
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop
