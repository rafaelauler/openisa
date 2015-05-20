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

  # Test lui with immediates
	lui	$5, 15                  # F
	ori	$5, $5, 16960           # 4240  -- > F4240 hex = 1.000.000 dec
  move  $17, $5
  # Print output
  lui	$4, %hi($.str2)
	addiu	$4, $4, %lo($.str2)
	jal	printf

  # Test lui with relocations
  lui $5, %hi(my_symbol)
  addiu $5, %lo(my_symbol)
  # Print output
  lui	$4, %hi($.str3)
	addiu	$4, $4, %lo($.str3)
	jal	printf

  # Test access for loading far-away addresses
 	lui	$18, %hi(my_symbol)
	sw	$17, %lo(my_symbol)($18)
  lw $5, %lo(my_symbol)($18)
  # Print output
  lui	$4, %hi($.str4)
	addiu	$4, $4, %lo($.str4)
	jal	printf

  # Testing loading far-away floats
  lui $1, %hi(my_float)
  lwc1  $f2, %lo(my_float)($1)
  cvt.d.s  $f2, $f2
  move  $5, $0
  mfc1  $6, $f2
  mfc1  $7, $f3
  # Print output
  lui	$4, %hi($.str5)
	addiu	$4, $4, %lo($.str5)
	jal	printf

  # Testing loading far-away doubles
  lui $1, %hi(my_double)
  ldc1  $f2, %lo(my_double)($1)
  move  $5, $0
  mfc1  $6, $f2
  mfc1  $7, $f3
  # Print output
  lui	$4, %hi($.str6)
	addiu	$4, $4, %lo($.str6)
	jal	printf

  # Testing storing far-away doubles
  lui $1, %hi(my_float)
  lwc1  $f2, %lo(my_float)($1)
  cvt.d.s  $f2, $f2
  lui $1, %hi(my_double)
  ldc1  $f0, %lo(my_double)($1)
  mul.d $f0, $f0, $f2
  lui $1, %hi(my_double_result)
  sdc1 $f0, %lo(my_double_result)($1)
  ldc1 $f6, %lo(my_double_result)($1)
  move $5, $0
  mfc1 $6, $f6
  mfc1 $7, $f7
  # Print output
  lui	$4, %hi($.str7)
	addiu	$4, $4, %lo($.str7)
	jal	printf

  # Printing 10 * my_double as int
  addiu $1, $0, 10
  mtc1  $1, $f2
  cvt.d.w  $f2, $f2
  lui $1, %hi(my_double)
  ldc1  $f0, %lo(my_double)($1)
  mul.d $f0, $f0, $f2
  trunc.w.d $f5, $f0
  mfc1 $5, $f5
  mfc1 $6, $f0
  mfc1 $7, $f1
  # Print output
  lui	$4, %hi($.str8)
	addiu	$4, $4, %lo($.str8)
	jal	printf

  # Epilogue
	lw	$ra, 36($sp)            # 4-byte Folded Reload
	addiu	$2, $zero, 0
	addiu	$sp, $sp, 40
	jr	$ra

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

