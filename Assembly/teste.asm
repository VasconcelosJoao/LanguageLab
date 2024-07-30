.data
	n: .asciiz "\n"
	string1: .space 100
	string2: .space 100
.text
.globl main

main:
  	li $v0, 5		#Lê o inteiro da quantidade de letras
  	syscall			
  	move $t0, $v0		#Guarda o inteiro no registrador t0

 	li $v0, 8		#Lê a primeira String
    	la $a0, string1		#Guarda a String
    	li $a1, 99		#Tamanho da String
    	syscall

    	li $v0, 8		#Lê a segunda String
    	la $a0, string2		#Guarda a String
    	li $a1, 99		#Tamanho da String
    	syscall

   	 la $t1, string1	#Carrega a primeira String no Registrador
   	 la $t2, string2	#Carrega a segunda String no Registrador
   	 
   	 add $t7, $zero, $zero	#Auxiliar do iterador
   	 add $a0, $zero, $zero	#inicia o resultado em 0

    loop:
    	addi $t7, $t7, 1	#iteração
 	
        lb $t3, 0($t1)		#Carrega o caracter da String
        lb $t4, 0($t2)		#Carrega o caracter da Strin
   
        sub $t6, $t3, $t4	#Verifica se os caracter são iguais

	addi $t1, $t1, 1	#Adiciona 1 para ajudar a carregar o próximo caracter no inicio do loop
        addi $t2, $t2, 1	#Adiciona 1 para ajudar a carregar o próximo caracter no inicio do loop

        beq $t6, $zero, equal	#Se for igual chama o procedimento equal
   	beq $t7, $t0, exit	#Se os regisgradores foram iguais é porque chegou ao fim do loop
   	j loop			#Volta ao loop
        
    equal:
     	addi $a0, $a0, 1	#acrescenta 1 no resultado
     	beq $t7, $t0, exit	#Se os regisgradores foram iguais é porque chegou ao fim do loop
   	j loop			#volta ao loop

exit:
	li $v0,1		#Imprime o resultado
	syscall
	
	li $v0,4		#imprime um String
	la $a0, n		#pula a linha
	syscall
	
    	li $v0, 10		#fim da execução
    	syscall
    	
    	jr $ra			#return 0