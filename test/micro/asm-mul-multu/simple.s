	.text
	.globl	main
	.align	2
  .set noat
main:                                   # @main
  # Prologue
	addi	$sp, $sp, -40         # Allocate a stack frame with 10 positions
	stw	$ra, 36($sp)            # 4-byte Folded Spill

  # Test input reading
	ldi  	$1, 576             # 240  -- > F4240 hex = 1.000.000 dec
	ldihi	61                  # 3D
	stw	  $1, 24($sp)         # Stack(24) <= 1.000.000
	addi	$1, $zero, 3
	stw	$1, 16($sp)             # Stack(16) <= 3
	ldi 	$4, %lo($str)
  ldihi	%hi($str)            # $4 <=  $str
	stw	$zero, 28($sp)          # Stack(28) <= 0
	stw	$zero, 20($sp)          # Stack(20) <= 0
	call	puts, 1               # puts($str)
	ldi 	$4, %lo($.str1)
  ldihi	%hi($.str1)
	addi	$5, $sp, 24
	addi	$6, $sp, 16
	call	__isoc99_scanf, 3     # scanf($.str1, &Stack(24), &Stack(16))

  # Load operands
	ldw	$1, 24($sp)
	ldw	$2, 16($sp)
	ldw	$5, 20($sp)

  # Test program
	mulu	$3, $6, $2, $1
	ldi 	$4, %lo($.str2)
  ldihi	%hi($.str2)
	mul	$0, $1, $5, $1
	ldw	$5, 28($sp)
	mul	$0, $2, $2, $5

  # Print output
	addi	$5, $zero, 0
	add  	$2, $3, $2
	add	  $7, $2, $1
	call	printf, 4

  # Epilogue
	ldw	 $ra, 36($sp)            # 4-byte Folded Reload
	addi	$2, $zero, 0
	addi	$sp, $sp, 40
	jumpr	$ra

$tmp0:

	.section	.rodata.str1.1,"aMS",@progbits,1
$.str1:
	.asciz	"%lld %lld"

$.str2:
	.asciz	"signed: %d %lld\n"

	.section	.rodata.str1.16,"aMS",@progbits,1
	.align	4
$str:
	.asciz	"Type 2123456789 and 3:"

