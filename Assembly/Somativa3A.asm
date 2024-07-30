.data
	string1: .space 16
	n: .asciiz "\n"
	zero: .asciiz "0"
	um: .asciiz "1"
	dois: .asciiz "2"
	tres: .asciiz "3"
	quatro: .asciiz "4"
	cinco: .asciiz "5"
	seis: .asciiz "6"
	sete: .asciiz "7"
	oito: .asciiz "8"
	nove: .asciiz "9"
	hifen: .asciiz "-"
	A: .asciiz "A"

.text
.globl main

main:

 	li $v0, 8		#Lê a primeira String
    	la $a0, string1		#Guarda a String
    	li $a1, 16		#Tamanho da String
    	add	$s0, $a0, $zero	
    	syscall
    	
    	la $t1, string1	#Carrega a primeira String no Registrador
	j loop
	
loop:
	lb $t3, 0($t1)		#Carrega o caracter da String
	
	beq $t3,'-' , Hifen
	beq $t3,'0' , Zero
	beq $t3,'1' , one
	
	
	beq $t3,'A' , two
	beq $t3,'a' , two
	beq $t3,'B' , two
	beq $t3,'b' , two
	beq $t3,'C' , two
	beq $t3,'c' , two
	beq $t3,'2' , two
	
	beq $t3,'D' , three
	beq $t3,'d' , three
	beq $t3,'E' , three
	beq $t3,'e' , three
	beq $t3,'F' , three
	beq $t3,'f' , three
	beq $t3,'3' , three

    	beq $t3,'G' , four
	beq $t3,'g' , four
	beq $t3,'H' , four
	beq $t3,'h' , four
	beq $t3,'I' , four
	beq $t3,'i' , four
	beq $t3,'4' , four
	
	beq $t3,'J' , five
	beq $t3,'j' , five
	beq $t3,'K' , five
	beq $t3,'k' , five
	beq $t3,'L' , five
	beq $t3,'l' , five
	beq $t3,'5' , five
	
   	beq $t3,'M' , six
	beq $t3,'m' , six
	beq $t3,'N' , six
	beq $t3,'n' , six
	beq $t3,'O' , six
	beq $t3,'o' , six
	beq $t3,'6' , six
	
	beq $t3,'P' , seven
	beq $t3,'p' , seven
	beq $t3,'Q' , seven
	beq $t3,'q' , seven
	beq $t3,'R' , seven
	beq $t3,'r' , seven
    	beq $t3,'S' , seven
	beq $t3,'s' , seven
	beq $t3,'7' , seven
	
	beq $t3,'T' , eight
	beq $t3,'t' , eight
	beq $t3,'U' , eight
	beq $t3,'u' , eight
	beq $t3,'V' , eight
	beq $t3,'v' , eight
	beq $t3,'8' , eight
	
	beq $t3,'W' , nine
	beq $t3,'w' , nine
	beq $t3,'X' , nine
	beq $t3,'x' , nine
	beq $t3,'Y' , nine
	beq $t3,'y' , nine
   	beq $t3,'Z' , nine
	beq $t3,'z' , nine
	beq $t3,'9' , nine
	
	j exit

Zero:
	 li $v0, 4
   	 la $a0, zero
   	 syscall

addi $t1, $t1, 1

j loop  
      	 
one:
	 li $v0, 4
   	 la $a0, um
   	 syscall

addi $t1, $t1, 1

j loop 
         	 
two:
	 li $v0, 4
   	 la $a0, dois
   	 syscall

addi $t1, $t1, 1

j loop  
         	 
three:
	 li $v0, 4
   	 la $a0, tres
   	 syscall

addi $t1, $t1, 1

j loop   
      	 
four:
	 li $v0, 4
   	 la $a0, quatro
   	 syscall

addi $t1, $t1, 1

j loop 
       
five:
	 li $v0, 4
   	 la $a0, cinco
   	 syscall

addi $t1, $t1, 1

j loop   
     
six:
	 li $v0, 4
   	 la $a0, seis
   	 syscall

addi $t1, $t1, 1

j loop   
     
seven:
	 li $v0, 4
   	 la $a0, sete
   	 syscall

addi $t1, $t1, 1

j loop  
      
eight:
	 li $v0, 4
   	 la $a0, oito
   	 syscall

addi $t1, $t1, 1

j loop   
     
nine:
	 li $v0, 4
   	 la $a0, nove
   	 syscall

addi $t1, $t1, 1

j loop     
   
Hifen:
	 li $v0, 4
   	 la $a0, hifen
   	 syscall

addi $t1, $t1, 1

j loop
    
exit:
	li $v0, 4
   	 la $a0, n
   	 syscall

	li $v0, 10
	syscall
	
