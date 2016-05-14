//  .set my_symbol, 1000000
//  .weak my_symbol
	.text
	.globl	main
	.align	2
  .set noat
main:                                   # @main
  # Prologue
	addi	$sp, $sp, -40         # Allocate a stack frame with 10 positions
	stw	$ra, 36($sp)            # 4-byte Folded Spill

  addi $5, $0, 1515
  addi $6, $0, 4040
  # Print output
  ldi	  $4, %lo($.str)
  ldihi	%hi($.str)
	call	printf, 3


  # Epilogue
	ldw	$ra, 36($sp)            # 4-byte Folded Reload
	addi	$2, $zero, 0
	addi	$sp, $sp, 40
	jumpr	$ra

.data
$.str:
	.asciz	"number 1: %d ...number 2: %d...\n"



