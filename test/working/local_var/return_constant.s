.global f
#DEBUG: DECLARATOR adding to map at addressf making map size = 1
lw $2,0($fp)
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move $25,$fp
move $fp,$sp
li $2,5678
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop
