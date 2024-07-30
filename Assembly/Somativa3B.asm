.data
	Impar: .asciiz "THUMS THUMS THUMS\n"
	Par: .asciiz "THUMS THUMS THUMS THUMS THUMS THUMS\n"
	Pula: .asciiz "\n"
	.text
main:	
	li $v0,5		#Lê o primeiro inteiro
	syscall			#chamada do sistema
	move $t1, $v0
	
	li $t0,1			
    	

loop:
    bgt $t0, $t1, exit        # se $t0 > t1, interrompa laço
    
    move $t3,$t0
    li $t2,2
    
    div $t3,$t2
    
    mfhi $t2
	
    beq $t2,0,even
      
     odd:
     li $v0, 4		
	la $a0, Impar		
	syscall	   
    
    addiu $t0, $t0, 1       # incrementa índice
    j loop 

 even:
     li $v0, 4		
	la $a0, Par		
	syscall	
 addiu $t0, $t0, 1       # incrementa índice
    j loop 

exit: