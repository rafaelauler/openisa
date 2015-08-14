//  .set my_symbol, 1000000
//  .weak my_symbol
	.text
	.globl	main
	.align	2
  .set noat
main:                                   # @main
  # Prologue
	addiu	$sp, $sp, -40         # Allocate a stack frame with 10 positions
	sw	$ra, 36($sp)            # 4-byte Folded Spill

  ori $10, 1515
  ori $11, 4040
  mtlo $10
  mthi $11
  mflo $5
  mfhi $6
  # Print output
  lui	$4, %hi($.str)
	addiu	$4, $4, %lo($.str)
	jal	printf


  # Epilogue
	lw	$ra, 36($sp)            # 4-byte Folded Reload
	addiu	$2, $zero, 0
	addiu	$sp, $sp, 40
	jr	$ra

.data
$.str:
	.asciz	"number 1: %d ...number 2: %d...\n"



