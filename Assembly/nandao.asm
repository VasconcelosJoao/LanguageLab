.data
buffer: .space 33
equals: .asciiz "="
newLine: .asciiz "\n"
ASC: .byte    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'

##############
.text

main:
    	la $s3, ASC			#Carrega o vetor em S3
    
    
    	li $v0, 8    	   		# Ler string
    	la $a0, buffer			# Carregar espaco da string
    	li $a1, 33      		#Tamano máximo da String
    	move $t0, $a0  
    	syscall
    
    	add $t5, $zero, -1			#t5 = -1
    
loopCount: 				#contar numero de letras
      	lb   $a0,0($t0)			#t0 = String; a0 = byte
      	beqz $a0, exitCount		#Se a0 = 0 a String acabou
      	add $t0,$t0,1			#add +1 a t0
      	add $t5,$t5,1			#add +1 a t5
    	j loopCount
    
exitCount:
	la $s2, buffer			#carrega a String em s2
    	add $t6, $zero, $zero		#t6 = 0
    	j loopString 			#pula para o Loop
   

soma:
	lb $a0, ($s2)			#primeiro caracter da String

	add $s1, $a0, $zero		#Adicionar o valor da caracter em s1
	sll $s1, $s1, 8			#Descolamento para a esquerda 8bits

	lb $a0, 1($s2)			#Segundo caracter da String
	add $t8, $a0, $zero
	
	add $s1, $a0, $s1		#adiciona o valor nos 8 bits significativos de s1, (vazios)
	sll $s1, $s1, 8			#Descolamento para a esquerda 8bits

	lb $a0, 2($s2)			#Terceiro caracter da String
	add $t9, $a0, $zero

	add $s1, $a0, $s1		#Adiciona nos 8 bits menos significativos
	
	j pegaOsBits

pegaOsBits:			
	and $a0, $s1, 63		#and para extrair apenas os 6 últimos bits
	add $t0, $zero, $a0		#add o resultado em t0 que vai ser o último bit do resultado

	srl $s1, $s1, 6			#deslocamentos de 6 bits para a direita
	and $a0, $s1, 63		#and para extrair apenas os 6 últimos bits
	add $t1, $zero, $a0		#add o resultado em t1 que vai ser o terceiro bit do resultado

	srl $s1, $s1, 6			#deslocamentos de 6 bits para a direita
	and $a0, $s1, 63		#and para extrair apenas os 6 últimos bits
	add $t2, $zero, $a0		#add o resultado em t2 que vai ser o segundo bit do resultado
	
	srl $s1, $s1, 6			#deslocamentos de 6 bits para a direita
	and $a0, $s1, 63		#and para extrair apenas os 6 últimos bits
	add $t3, $zero, $a0		#add o resultado em t2 que vai ser o primeiro bit do resultado
	
	j imprime
	
imprime:
	#sub $t7, $t6, $t5	
		
	lb $a0, ASC($t3)		#t3 = posição do vetor de ASC que vai ser armazenado em a0
	
	li $v0, 11      		#printa o resultado
	syscall
	

	lb $a0, ASC($t2)		#t2 = posição do vetor de ASC que vai ser armazenado em a0
	
	li $v0, 11      		#printa o resultado
	syscall

	beq $t8, 10, printIgualDois	#printa 2 iguais	
	
	lb $a0, ASC($t1)		#t1 = posição do vetor de ASC que vai ser armazenado em a0
	
	li $v0, 11      		#printa o resultado
	syscall
		
	beq $t9, 10, printIgualUm	#printa 1 igual

	lb $a0, ASC($t0)		#t0 = posição do vetor de ASC que vai ser armazenado em a0
	
	li $v0, 11      		#printa o resultado
	syscall
	
	sai:
	j exitBits
	
printIgualUm:				#printa o primeiro =
	la $a0, equals
	li $v0, 4
	syscall
	j sai

printIgualDois:				#printa o segundo =
	la $a0, equals
	li $v0, 4
	syscall
	la $a0, equals
	li $v0, 4
	syscall
	j sai
    
loopString:
	j soma			#pula p soma
	
exitBits:
	addi $t6, $t6, 3
	addi $s2, $s2, 3
	bge $t6, $t5, saida
	j loopString
	
saida:
	
    	la $a0, newLine
    	li $v0, 4
    	syscall
	
    	li $v0, 10    		#Saida do programa
    	syscall
    	
    	jr $ra			#return 0