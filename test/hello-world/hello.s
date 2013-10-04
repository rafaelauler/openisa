	.section .mdebug.abi32
	.previous
	.file	"hello.bc"
	.section	__TEXT,__text,regular,pure_instructions
	.globl	main
	.align	2
	.type	main,@function
	.set	nooi16                  # @main
	.ent	main
main:
	.cfi_startproc
	.frame	$sp,32,$ra
	.mask 	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
# BB#0:                                 # %entry
	lui	$2, %hi(_gp_disp)
	addiu	$2, $2, %lo(_gp_disp)
	addiu	$sp, $sp, -32
$tmp2:
	.cfi_def_cfa_offset 32
	sw	$ra, 28($sp)            # 4-byte Folded Spill
$tmp3:
	.cfi_offset 31, -4
	addu	$gp, $2, $25
	sw	$zero, 24($sp)
	addiu	$1, $zero, 350
	sw	$1, 20($sp)
	addiu	$1, $zero, 150
	sw	$1, 16($sp)
	lw	$1, 20($sp)
	lw	$2, %got($.str)($gp)
	addiu	$4, $2, %lo($.str)
	lw	$25, %call16(printf)($gp)
	jalr	$25
	addiu	$5, $1, 150
	addiu	$2, $zero, 0
	lw	$ra, 28($sp)            # 4-byte Folded Reload
	jr	$ra
	addiu	$sp, $sp, 32
	.set	at
	.set	macro
	.set	reorder
	.end	main
$tmp4:
	.size	main, ($tmp4)-main
	.cfi_endproc

	.type	$.str,@object           # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
$.str:
	.asciz	 "%d\n"
	.size	$.str, 4


