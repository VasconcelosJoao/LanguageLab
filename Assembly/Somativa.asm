.data
	Soma: .asciiz "ADD: "
	Sub: .asciiz "\nSUB: "
	AND: .asciiz "\nAND: "
	OR: .asciiz  "\nOR: "
	XOR: .asciiz "\nXOR: "
	MASK: .asciiz "\nMASK: "
	SLL: .asciiz "\nSLL("
	SRL: .asciiz "\nSRL("
	FEC: .asciiz "): "
	Pula: .asciiz "\n"
	.text
main:
	li $v0,5		#Lê o primeiro inteiro
	syscall			#chamada do sistema
	
	move $t0, $v0		#move o valor do primeiro inteiro para um reg temporário
	
	li $v0,5		#Lê o segundo inteiro
	syscall			#chamada do sistema
	
	move $t1, $v0		#move o valor do segundo inteiro para um reg temporário
	
	li $v0,5		#Lê o primeiro inteiro
	syscall			#chamada do sistema
	
	move $t3, $v0		#move o valor do primeiro inteiro para um reg temporário
	
	
	
	#ADD			
	add $t2,$t1,$t0		#soma e armazena os dois inteiros
	
	li $v0, 4		#printa uma String
	la $a0, Soma		#armazena a String Soma em a0
	syscall			#chamada do sistema
	
	
	li $v0, 1		#printa um inteiro
	move $a0, $t2		#move t2 para a0 para ser printado
	syscall			#chamada do sistema
	
	#SUB
	sub $t2,$t0,$t1		#subtrai e armazena os dois inteiros
	
	li $v0, 4		#printa uma String
	la $a0, Sub		#armazena a String Sub em a0
	syscall			#chamada do sistema
	
	li $v0, 1		#printa um inteiro
	move $a0, $t2		#move t2 para a0 para ser printado
	syscall			#chamada do sistema
	
	#AND			
	and $t2,$t1,$t0		#AND e armazena os dois inteiros
	
	li $v0, 4		#printa uma String
	la $a0, AND		#armazena a String AND em a0
	syscall			#chamada do sistema
	
	
	li $v0, 1		#printa um inteiro
	move $a0, $t2		#move t2 para a0 para ser printado
	syscall			#chamada do sistema
	
	#OR			
	or $t2,$t1,$t0		#OR e armazena os dois inteiros
	
	li $v0, 4		#printa uma String
	la $a0, OR		#armazena a String OR em a0
	syscall			#chamada do sistema
	
	
	li $v0, 1		#printa um inteiro
	move $a0, $t2		#move t2 para a0 para ser printado
	syscall			#chamada do sistema
	
	#XOR			
	xor $t2,$t1,$t0		#XOR e armazena os dois inteiros
	
	li $v0, 4		#printa uma String
	la $a0, XOR		#armazena a String OR em a0
	syscall			#chamada do sistema
	
	
	li $v0, 1		#printa um inteiro
	move $a0, $t2		#move t2 para a0 para ser printado
	syscall			#chamada do sistema
	
	#MASK
	
	and $t4,$t3,31		#AND 
	
	li $v0, 4		#printa uma String
	la $a0, MASK		#armazena a String AND em a0
	syscall			#chamada do sistema
	
	
	li $v0, 1		#printa um inteiro
	move $a0, $t4		#move t2 para a0 para ser printado
	syscall			#chamada do 
	
	
	
	
	#SLL			
	sllv   $t2, $t0, $t4	# move T4 bits para esquerda
	 
	li $v0, 4		#printa uma String
	la $a0, SLL		#armazena a String SLL em a0
	syscall			#chamada do sistema
	
	li $v0, 1		#printa um inteiro
	move $a0, $t4		#move t2 para a0 para ser printado
	syscall			#chamada do 
	
	li $v0, 4		#printa uma String
	la $a0, FEC		#armazena a String SLL em a0
	syscall			#chamada do sistema
	
	
	li $v0, 1		#printa um inteiro
	move $a0, $t2		#move t2 para a0 para ser printado
	syscall			#chamada do sistema
	
	#SRL			
	srlv $t2, $t1, $t4	# move T4 bitS para direita
	 
	li $v0, 4		#printa uma String
	la $a0, SRL		#armazena a String SRL1 em a0
	syscall			#chamada do sistema
	
	li $v0, 1		#printa um inteiro
	move $a0, $t4		#move t2 para a0 para ser printado
	syscall			#chamada do 
	
	li $v0, 4		#printa uma String
	la $a0, FEC		#armazena a String SLL em a0
	syscall			#chamada do sistema
	
	li $v0, 1		#printa um inteiro
	move $a0, $t2		#move t2 para a0 para ser printado
	syscall			#chamada do sistema
	
	#Salta uma linha no fim do código
	
	li $v0, 4		#printa uma String
	la $a0, Pula		#armazena a String em a0
	syscall			#chamada do sistema
	
	jr $ra