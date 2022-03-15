.global f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move $fp,$sp
addiu $sp,$sp,-4 
sw $fp,4($sp)
move $fp,$sp
li $2,5678
sw $0,4($fp)
lw $2,8($fp)
addiu $sp,$sp,-4 
sw $fp,4($sp)
move $fp,$sp
li $2,1234
sw $0,8($fp)
lw $2,8($fp)
lw $2,8($fp)
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop
