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
#DEBUG: adding to map at address <NULL> making map size = 2
sw $2,8($fp)
#DEBUG: reg of argument=2 <NULL>
#DEBUG : IN INITDECLARATOR 
#DEBUG: adding to map at address <NULL> making map size = 3
li $2,10
#DEBUG : in variables_map for y -8 -8
sw $2,8($fp)
#DEBUG: DECLARATOR adding to map at addressy making map size = 3
lw $8,-8($fp)
addiu $sp,$sp,-4 
sw $25,0($fp) 
move $fp,$sp
#DEBUG: adding to map at address <NULL> making map size = 3
sw $2,8($fp)
#DEBUG: reg of argument=2 <NULL>
#DEBUG : IN INITDECLARATOR 
#DEBUG: adding to map at address <NULL> making map size = 4
#AddOperator generateMIPS Called
li $10,20
lw $11,-8($fp)
add $2,$10,$11
#DEBUG : in variables_map for x -12 -12
sw $2,8($fp)
#DEBUG: DECLARATOR adding to map at addressx making map size = 4
lw $9,-12($fp)
lw $2,-12($fp)
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop
