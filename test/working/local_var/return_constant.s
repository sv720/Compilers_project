.global f
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move $fp,$sp
li $2,5678
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop
