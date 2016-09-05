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

  # Test lui with immediates
	ldi  	$5, 576             # 240  -- > F4240 hex = 1.000.000 dec
	ldihi	61                  # 3D
  add   $17, $0, $5
  # Print output
	ldi 	$4, %lo($.str2)
  ldihi	%hi($.str2)
	call	printf, 2

  # Test lui with relocations
  ldi $5, %lo(my_symbol)
  ldihi %hi(my_symbol)
  # Print output
	ldi 	$4, %lo($.str3)
  ldihi	%hi($.str3)
	call	printf, 2

  # Test access for loading far-away addresses
  ldi $18, %lo(my_symbol)
  ldihi %hi(my_symbol)
	stw	$17, ($18)
  ldw $5,  ($18)
  # Print output
	ldi 	$4, %lo($.str4)
  ldihi	%hi($.str4)
	call	printf, 2

  # Testing loading far-away floats
  ldi $1, %lo(my_float)
  ldihi %hi(my_float)
  lwc1  $f2, ($1)
  cvt.d.s  $f2, $f2
  add   $5, $0, $0
  mflc1  $6, $d2
  mfhc1  $7, $d2
  # Print output
	ldi 	$4, %lo($.str5)
  ldihi	%hi($.str5)
	call	printf, 5

  # Testing loading far-away doubles
  ldi $1, %lo(my_double)
  ldihi %hi(my_double)
  ldc1  $f2, ($1)
  add   $5, $0, $0
  mflc1  $6, $d2
  mfhc1  $7, $d2
  # Print output
	ldi 	$4, %lo($.str6)
  ldihi	%hi($.str6)
	call	printf, 5

  # Testing storing far-away doubles
  ldi $1, %lo(my_float)
  ldihi %hi(my_float)
  lwc1  $f2, ($1)
  cvt.d.s  $d1, $f2
  ldi $1, %lo(my_double)
  ldihi %hi(my_double)
  ldc1  $d0, ($1)
  mul.d $d0, $d0, $d1
  ldi $1, %lo(my_double_result)
  ldihi %hi(my_double_result)
  sdc1 $d0, ($1)
  ldc1 $d3, ($1)
  add  $5, $0, $0
  mflc1 $6, $d3
  mfhc1 $7, $d3
  # Print output
	ldi 	$4, %lo($.str7)
  ldihi	%hi($.str7)
	call	printf, 5

  # Printing 10 * my_double as int
  addi  $1, $0, 10
  mtc1  $1, $f2
  cvt.d.w  $d1, $f2
	ldi 	$1, %lo(my_double)
  ldihi	%hi(my_double)
  ldc1  $d0, ($1)
  mul.d $d0, $d0, $d1
  trunc.w.d $f5, $d0
  mfc1 $5, $f5
  mflc1 $6, $d0
  mfhc1 $7, $d0
  # Print output
	ldi 	$4, %lo($.str8)
  ldihi	%hi($.str8)
	call	printf, 5

  # Epilogue
	ldw	$ra, 36($sp)            # 4-byte Folded Reload
	addi	$2, $zero, 0
	addi	$sp, $sp, 40
	jumpr	$ra

$tmp0:

.data
$.str2:
	.asciz	"lui with immediates: %d\n"
$.str3:
	.asciz	"lui with relocation: %d\n"
$.str4:
	.asciz	"loading far-away addresses: %d\n"
$.str5:
	.asciz	"loading far-away float: %d %lf\n"
$.str6:
	.asciz	"loading far-away double: %d %lf\n"
$.str7:
	.asciz	"multiplying the two previous numbers: %d %lf\n"
$.str8:
	.asciz	"10* double = int: %d double: %lf\n"


  .org 1000000, 0
my_symbol:
  .int 1234567
my_float:
	.4byte	1060439283              # float 0.707106769
my_double:
	.8byte	4599976659396224614     # double 0.34999999999999998
my_double_result:
  .8byte 0

