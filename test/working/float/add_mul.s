#DEBUG Function Declarator: label f_0 f_0
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
#DEBUG Declarator: adding to map f_0 at address: x making map size = 1
sw $4,12($fp)
#DEBUG: reg of argument=4 x
addiu $sp,$sp,-4 
sw $25,0($fp) 
sw $31,4($fp) 
move $fp,$sp
#DEBUG Declarator: adding to map f_0 at address: y making map size = 2
sw $5,12($fp)
#DEBUG: reg of argument=5 y
addiu $sp,$sp,-4 
sw $25,0($fp) 
sw $31,4($fp) 
move $fp,$sp
#DEBUG Declarator: adding to map f_0 at address: z making map size = 3
sw $6,12($fp)
#DEBUG: reg of argument=6 z
#DEBUG: calling generateMIPS on arg is return 
#AddOperator generateMIPS Called
#DEBUG Declarator: NOT_FOUND_VAR, but found, x from function f_0
#DEBUG : maps_offsets: 0 ; context.functions[f].variables_map.size(): 3 ; context.functions[f].variables_map[id].old_map_size: 1
lw $8,20($fp)
#MulOperator generateMIPS Called
#DEBUG Declarator: NOT_FOUND_VAR, but found, y from function f_0
#DEBUG : maps_offsets: 0 ; context.functions[f].variables_map.size(): 3 ; context.functions[f].variables_map[id].old_map_size: 2
lw $10,16($fp)
#DEBUG Declarator: NOT_FOUND_VAR, but found, z from function f_0
#DEBUG : maps_offsets: 0 ; context.functions[f].variables_map.size(): 3 ; context.functions[f].variables_map[id].old_map_size: 3
lw $11,12($fp)
mult $10,$11
mflo $9
mfhi $10
add $2,$8,$9
j end_f
nop
end_f:
move $sp,$fp
lw $fp,4($sp)
move $sp,$25
jr $31
nop
.global f
