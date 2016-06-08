	.text
	.globl	main
	.align	2
  .set noat
main:                                   # @main
  # Prologue
	addi	$sp, $sp, -40         # Allocate a stack frame with 10 positions
	stw	$ra, 36($sp)            # 4-byte Folded Spill

  # Read input to fill contents of register $21
  ldi   $5, %lo(num)
  ldihi %hi(num)
  ldi   $4, %lo($.str3)
  ldihi %hi($.str3)
  call __isoc99_scanf, 2
  ldi   $5, %lo(num)
  ldihi %hi(num)
  ldw $21, ($5)

  # Code excerpt from 445.gobmk which will loop up from 0 to 3 or from 0 to
  # $21, whichever is smaller
  negu $1, $21
  sltiu $1, $1, -3
  addi $3, $21, -1
  addi $23, $zero, 3
  addi $2, $zero, 0
  movz $23, $3, $1
$LBB1:
  add  $17, $zero, $2
  # Print output
	ldi 	$4, %lo($.str2)
  ldihi	%hi($.str2)
	call	printf, 1

#head:
  addi $2, $17, 1
  jne $17, $23, $LBB1

  # Epilogue
	ldw	$ra, 36($sp)            # 4-byte Folded Reload
	addi	$2, $zero, 0
	addi	$sp, $sp, 40
	jumpr	$ra

$tmp0:

.data
$.str2:
	.asciz	"hi\n"
$.str3:
  .asciz  "%d"

num:
  .int 0
