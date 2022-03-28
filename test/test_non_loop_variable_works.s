f:
addiu $sp,$sp,-12
sw $fp,4($sp)
sw $31,8($sp)
move $25,$fp
move $fp,$sp
addiu $sp,$sp,-4
sw $25,0($fp)
sw $31,4($fp)
move $fp,$sp
#DEBUG InitDeclarator: adding to map at address i making map size = 1
li $2,2
sw $2,12($fp)
addiu $sp,$sp,-4
sw $25,0($fp)
sw $31,4($fp)
move $fp,$sp
#DEBUG: ARRAYDECLARATOR
#DEBUG: adding array to stack
addiu $sp,$sp,-28
move $fp,$sp
sw $25,4($fp)
sw $31,8($fp)
#DEBUG ARRAYDeclarator: adding to map at address of ARRAY x making map size = 9
#DEBUG : left->getNature = ArrayCall
#DEBUG Declarator: FOUND_VAR, adding to map at addressi making map size = 9
lw $2,44($fp)
#DEBUG Declarator: FOUND_VAR, adding to map at addressi making map size = 9
lw $8,44($fp)
li $9,4
mult $8,$9
mflo $8
#DEBUG : curr_map_size = 9#DEBUG : old_map_size =2
addi $9,$8,-40
sub $9,$0,$9
add $10,$9,$fp
sw $2,0($10)
#DEBUG: calling generateMIPS on arg is return
#DEBUG: ARRAYCALL
lw $2,32($fp)
j end_f
nop
end_f:
move $sp,$fp
lw $fp,4($sp)
move $sp,$25
jr $31
nop
.global f
0