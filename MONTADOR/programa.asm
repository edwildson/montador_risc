#7.5.	Faça um programa em linguagem de montagem MIPS que receba como entrada dois números, 
#	n e s, e que tenha como saída o resultado da combinação de n tomados s a s. 
#	Os números n e s devem ser carregados da memória e o resultado da combinação 
#	 deve ser colocado na mesma em uma variável COMB. 
#		Caso s seja maior que n, deve ser armazenado o valor 1 no registrador v1. 
#		Caso n e/ou s seja menor que zero, o valor 2 deve ser armazenado no registrador v1. 
#		Quando n for igual a s o valor 3 deve ser armazenado no registrador V1. 
#		Quando n e/ou s for igual a zero o valor 4 deve ser armazenado no registrador v1. 
#	Segue abaixo a fórmula da combinação.    

#Comb = n!/(s! * (n-s)!)


main:
	addi $a0,$zero, 10
	addi $a1,$zero, 3
	jal comb
	j exit
	
	
#functions
#int fatorial(int x=$a0){
fato:	addi $sp,$sp,-8
	sw $t0,4($sp)
	sw $a0,($sp)
#inicializando função, garantindo preservação de contexto

	bne $a0,$zero,recur
	addi $v0,$zero,1
	j fimFato
recur:	add $t0,$a0,$zero
	
#chamada de função dentro de função
	addi $a0,$a0,-1
	addi $sp, $sp, -4
	sw $ra,0($sp)
	jal fato
	lw $ra,0($sp)
	addi $sp, $sp, 4
#chamada de função dentro de função

	mul $v0,$t0,$v0

fimFato:lw $a0,0($sp)
	lw $t0,4($sp)
	addi $sp, $sp, 8
	jr $ra
#finalizando função, Retomando contexto anterior	
#}

#int comb(int n=$a0, int s=$a1){
comb:	addi $sp, $sp, -28
	sw $a0,0($sp)
	sw $a1,4($sp)
	sw $t0,8($sp)
	sw $t1,12($sp)
	sw $t2,16($sp)
	sw $t3,20($sp)
	sw $t4,24($sp)
	
if1:	slt $t0,$a0,$a1
	beq $t0,$zero,if2
	beq $a0,$a1,if2
	addi $v1,$zero,1
	j fimComb
if2:	slt $t0,$a0,$zero
	beq $t0,$zero,if21
	addi $v1,$zero,2
	j fimComb
if21:	slt $t0,$a1,$zero
	beq $t0,$zero,if3
	addi $v1,$zero,2
	j fimComb
if3:	bne $a0,$a1,if4
	addi $v1,$zero,3
	j fimComb
if4:	beq $a0,$zero, then
	bne $a1,$zero, else
then:	addi $v1,$zero,4
	j fimComb
else:	add $t0,$zero,$a0
	add $t1,$zero,$a1
	
	addi $sp, $sp, -4
	sw $ra,0($sp)
	jal fato
	lw $ra,0($sp)
	addi $sp, $sp, 4
	
	add $t2,$zero, $v0
	add $a0,$zero,$t1
	
	addi $sp, $sp, -4
	sw $ra,0($sp)
	jal fato
	lw $ra,0($sp)
	addi $sp, $sp, 4
	
	add $t3,$zero,$v0
	sub $a0,$t0,$t1
	
	addi $sp, $sp, -4
	sw $ra,0($sp)
	jal fato
	lw $ra,0($sp)
	addi $sp, $sp, 4
	
	mul $t4,$t3,$v0
	addi $t2,$t2,1
	div $v0,$t2,$t4

fimComb:lw $a0,0($sp)
	lw $a1,4($sp)
	lw $t0,8($sp)
	lw $t1,12($sp)
	lw $t2,16($sp)
	lw $t3,20($sp)
	lw $t4,24($sp)
	addi $sp, $sp, 28
	jr $ra
#}
exit: