.data
	NotNat: .asciiz "Entrada invalida."
	Prime: .asciiz "sim"
	NotPrime: .asciiz "nao"
	n: .asciiz "\n"

.text
main:
	li $v0, 5 
	syscall
	
	move $t0, $v0      
	addi $t1, $zero, 1 
	addi $t2, $zero, 2 
	addi $t3, $zero, 3 
	
		
	beq $t0, $t1, EntriNotPrime		
	ble $t0, $zero, InvEntri		
	beq $t0, $t2, PrimeEntri		
	rem $s1, $t0, $t2
	beq $s1, $zero EntriNotPrime
	
	while:
		mul $t4, $t3, $t3  		
		bgt $t4, $t0, PrimeEntri   	
		rem $s0, $t0, $t3		
		beq $s0, $zero, EntriNotPrime 
		addi $t3, $t3, 2			
		j while
	
	EntriNotPrime: 
		li $v0, 4
		la $a0, NotPrime
		syscall
		
		li $v0, 4
		la $a0, n
		syscall
		
		li $v0, 10
		syscall
		
	InvEntri:
		li $v0, 4
		la $a0, NotNat
		syscall
		
		li $v0, 4
		la $a0, n
		syscall
		
		li $v0, 10
		syscall
		
	PrimeEntri:
		li $v0, 4
		la $a0, Prime
		syscall
		
		li $v0, 4
		la $a0, n
		syscall
		
		li $v0, 10
		syscall