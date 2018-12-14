#############################
#       PROJETO DE OAC 2    #
#############################

#############################

#############################

#############################

#############################
#############################
#############################

#############################





main:

addi $24, $zero, 2 #arg0=2
addi $a1, $zero, 3 #arg1=3
addi $a2, $zero, 5 #arg2=5
addi $a3, $zero, 6 #arg3=6
jal media
add $s0, $v0, $zero
j exit
addi $24, $zero, 2 #arg0=2
addi $a1, $zero, 3 #arg1=3
addi $a2, $zero, 5 #arg2=5
addi $a3, $zero, 6 #arg3=6
jal media
add $s0, $v0, $zero
j exit
media:
addi $sp, $sp, 12
sw $t1, 8($sp) #salva $t1
sw $t0, 4($sp) #salva $t0
sw $s0, 0($sp) #salva $s0
addi $sp, $sp, 12
sw $t1, 8($sp) #salva $t1
sw $t0, 4($sp) #salva $t0
sw $s0, 0($sp) #salva $s0
jr $4
exit: