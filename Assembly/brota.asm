	.data

float: .float 0.0
simbolo: .asciiz "0x"
quebraDeLinha: .asciiz "\n"
positivo: .asciiz "+\n"
negativo: .asciiz "-\n"
resultadoHex:  .space  8
	
	.text
main:
    li $v0, 6				#leitura de um float
    syscall
   
    mfc1 $t8, $f0 			#move o valor do f0 para t0
  
    li $v0, 2				#imprime o float
    mov.s $f12, $f0			#com dupla precisao
    syscall
  
    li $v0, 4 
    la $a0, quebraDeLinha
    syscall
     
    #bit de sinal
    ori  $t0, $zero, 0x1		#OR com um imediato
    sll  $t0, $t0, 31 			#deslocamento de 31 bits
    and  $a0, $t0, $t8			#and com t8 para conseguir o bit de sinal		
    srl  $a0, $a0, 31			#deslocamento para para armazenar o bit de sinal
    add  $t1, $zero, $a0		#guarda o valor de a0 em t1
    beq  $a0, 0, Positivo		#a0 é positivo?
    bne  $a0, 0, Negativo		#a0 é negativo?

inicio: 
    #extrair bits 23-30
    ori  $t0, $zero, 0xFF		#or com imediaro
    sll  $t0, $t0, 23			#deslocamento de 23bits para a esquerda
    and  $a0, $t0, $t8			#and para armazenar o valor dos bits
    srl  $a0, $a0, 23			#desloca os 23 bits para a direita
    addi  $t3, $zero, 127		#valor de 127
    sub $a0, $a0, $t3			#a0 - 127 = valor do expoente
    
    #print do expoente
    addi $v0, $zero, 1
    syscall

    li $v0, 4 
    la $a0, quebraDeLinha
    syscall

   	
    li $v0, 4
    la $a0, simbolo
    syscall

   
    #extrair bits 0-22
    
    ori  $t0, $zero, 0xFFFF		#or com um imediato
    sll  $t0, $t0, 7			#deslocamento de 7bits para a esquerda		
    ori  $t0, $t0, 0x7F			#or com um imediaro
    and  $a0, $t0, $t8			#armazena o valor do float em bit com a operação and		
    j hexadecimal			#transforma o valor em hexadecimal
   	
Positivo:
    add $t4, $zero, $a0
    li $v0, 4 
    la $a0, positivo
    syscall
   j inicio
   
Negativo:
    add $t4, $zero, $a0
    li $v0, 4 
    la $a0, negativo
    syscall
    j inicio
    
hexadecimal:    
    move $s2, $a0               	# guarda o valor de a0 em s2
    li $s0, 8                   	# 8 digitos para a palavra em hedacimal (32/4)
    la $s3, resultadoHex        	# configuracao da String para o resultado em hexadecimal

loop:
    rol $s2, $s2, 4             	# rotação começando com o ultimo bit
    and $s1, $s2, 0xf           	# Mascara de 15 digitos em s2 e o resultado em s1
    ble $s1, 9, print           	# s1 <= 9?
    add $s1, $s1, 7             	# Não? s1 = s1 + 7 (colocar A-F)

print:
    add $s1, $s1, 48            	# Adidciona 48 (30 hex) para pegar o codigo ascii
    sb $s1,($s3)                	# Armazena o byte no resultado
    add $s3, $s3, 1             	# s3 = s3 + 1
    add $s0, $s0, -1            	# s0 = s0 - 1
    bnez $s0, loop              	# If s0 != 0? Volta para o Loop
    
    la $a0, resultadoHex        	# printa o resultado
    li $v0, 4
    syscall
    
fim:
    li $v0, 4 				
    la $a0, quebraDeLinha		#quebra de linha
    syscall
 
    li $v0, 10				#fim da execução
    syscall
    
    jr $ra				#return	
 
