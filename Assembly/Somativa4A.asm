	.data
inv:	.asciiz "Entrada invalida."
n:	.asciiz  "\n"
	
	.text 

main:		
	li $v0,5
	syscall
	move $t0, $v0
	
	li $t4, 32767
	bgt $t0, $t4, inver
		
	li $t5, 2
	blt $t0, $t5, inver
	

		
	li $t1,2
	
while: bge $t1, $t0, endwhile

	div $t0,$t1
	mfhi $t2
	bnez $t2, else
	
	li $v0,1
	move $a0,$t1
	syscall
	
	li $v0, 4
	la $a0, n
	syscall
	
	mflo $t0
	
	j while

else: 
	addi $t1,$t1,1
	j while
	
inver:
	li $v0, 4
	la $a0, inv
	syscall
	
	j end

endwhile:
	li $v0, 1
	move $a0, $t0
	syscall
end:
	
	li $v0, 10
	syscall
	
	
	
	