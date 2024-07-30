.data
	naoNatural: .asciiz "Entrada invalida.\n"
	ehPrimo: .asciiz "sim\n"
	naoPrimo: .asciiz "nao\n"

.text
main:
	#ler o inteiro
	li $v0, 5 
	syscall
	
	move $t0, $v0      # mover o numero lido para $t0
	addi $t1, $zero, 1 # $t1 cont�m o valor 1  (constante 1)
	addi $t2, $zero, 2 # $t2 cont�m o valor 2  (constante 2)
	addi $t3, $zero, 3 # $t3 cont�m o valor 3  (i = 3) {contador}
	
	
	
	beq $t0, $t1, entradaNaoPrimo		# se a entrada for 1 dir� que n�o eh primo
	ble $t0, $zero, entradaInvalida		# se a entrada for <= 0 dir� entrada inv�lida
	beq $t0, $t2, entradaPrimo		# se a entrada for 2 dir� que � primo
	rem $s1, $t0, $t2
	beq $s1, $zero entradaNaoPrimo
	
	while:
		mul $t4, $t3, $t3  		# $t4 cont�m o valor de i*i 
		bgt $t4, $t0, entradaPrimo   	# se i * i >  num , printa numero primo
		rem $s0, $t0, $t3		# guarda num % i
		beq $s0, $zero, entradaNaoPrimo  # if (num % i == 0) printa numero n�o primo
		addi $t3, $t3, 2			# i += 2
		j while
	
	entradaNaoPrimo: 
		li $v0, 4
		la $a0, naoPrimo
		syscall
		li $v0, 10
		syscall
		
	entradaInvalida:
		li $v0, 4
		la $a0, naoNatural
		syscall
		li $v0, 10
		syscall
		
	entradaPrimo:
		li $v0, 4
		la $a0, ehPrimo
		syscall
		li $v0, 10
		syscall
		
		
		
		
	
	
