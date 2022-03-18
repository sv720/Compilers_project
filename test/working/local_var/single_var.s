.global f
#DEBUG: DECLARATOR adding to map at addressf making map size = 1
lw $2,0($fp)
f:
addiu $sp,$sp,-8
sw $fp,4($sp)
move $25,$fp
move $fp,$sp
addiu $sp,$sp,-4 
sw $25,0($fp) 
move $fp,$sp
#DEBUG: adding to map at address x making map size = 2
sw $2,8($fp)
#DEBUG: reg of argument=2 x
#DEBUG: DECLARATOR adding to map at addressx making map size = 2
lw $2,-8($fp)
#DEBUG: adding to map at address <NULL> making map size = 2
li $2,1234
#DEBUG : in variables_map for x -8 -8
sw $2,-8($fp)
lw $2,-8($fp)
lw $2,-8($fp)
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop
