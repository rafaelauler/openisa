	.text
	.globl	main
	.align	2
  .set noat
main:                                   # @main
  # Prologue
	addiu	$sp, $sp, -40         # Allocate a stack frame with 10 positions
	sw	$ra, 36($sp)            # 4-byte Folded Spill

  # Test input reading
	lui	$1, 15                  # F
	ori	$1, $1, 16960           # 4240  -- > F4240 hex = 1.000.000 dec
	sw	$1, 24($sp)             # Stack(24) <= 1.000.000
	addiu	$1, $zero, 3
	sw	$1, 16($sp)             # Stack(16) <= 3
	lui	$1, %hi($str)
	addiu	$4, $1, %lo($str)     # $4 <=  $str
	sw	$zero, 28($sp)          # Stack(28) <= 0
	sw	$zero, 20($sp)          # Stack(20) <= 0
	jal	puts                    # puts($str)
	lui	$1, %hi($.str1)
	addiu	$4, $1, %lo($.str1)
	addiu	$5, $sp, 24
	addiu	$6, $sp, 16
	jal	__isoc99_scanf          # scanf($.str1, &Stack(24), &Stack(16))

  # Load operands
	lw	$1, 24($sp)
	lw	$2, 16($sp)
	lw	$5, 20($sp)

  # Test program
	multu	$2, $1
	lui	$4, %hi($.str2)
	addiu	$4, $4, %lo($.str2)
	mflo	$6
	mfhi	$3
	mul	$1, $5, $1
	lw	$5, 28($sp)
	mul	$2, $2, $5

  # Print output
	addiu	$5, $zero, 0
	addu	$2, $3, $2
	addu	$7, $2, $1
	jal	printf

  # Epilogue
	lw	$ra, 36($sp)            # 4-byte Folded Reload
	addiu	$2, $zero, 0
	addiu	$sp, $sp, 40
	jr	$ra

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

