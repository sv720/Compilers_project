.global f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move $fp,$sp
addiu $sp,$sp,-4 
li $2,10
#DEBUG : IN INITDECLARATOR 
sw $2,0($fp)
sw $fp,4($sp)
move $fp,$sp
addiu $sp,$sp,-4 
#AddOperator generateMIPS Called
#Calling left 
li $2,20
move $10,$2
lw $2,8($fp)
move $11,$2
add $2,$10,$11
#DEBUG : IN INITDECLARATOR 
sw $2,0($fp)
sw $fp,4($sp)
move $fp,$sp
lw $2,8($fp)
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop
