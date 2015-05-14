	.text
	.abicalls
	.option	pic0
	.section	.mdebug.abi32,"",@progbits
	.nan	legacy
	.file	"simple.bc"
	.text
	.globl	main
	.align	2
	.type	main,@function
	.set	nomicromips
	.set	nomips16
	.ent	main
main:                                   # @main
	.frame	$sp,32,$ra
	.mask 	0x80030000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.set	noat
	addiu	$sp, $sp, -40         # Allocate a stack frame with 10 positions
	sw	$ra, 36($sp)            # 4-byte Folded Spill  
  jal aux
	lw	$ra, 36($sp)            # 4-byte Folded Reload
	addiu	$2, $zero, 0
	addiu	$sp, $sp, 40
	jr	$ra
	.set	at
	.set	macro
	.set	reorder
	.end	main
$tmp0:
	.size	main, ($tmp0)-main
  
aux:  
# BB#0:                                 # %entry
$BB0_1:                                 # %while.body
  # =>This Inner Loop Header: Depth=1
	lw	$5, %lo(i)($16)
	addiu	$17, $zero, 4
	addiu	$1, $5, 1
	addiu	$4, $16, %lo($.str)
	sw	$1, %lo(i)($16)
	jal	printf
	lw	$5, %lo(i)($16)
	bne	$5, $17, $BB0_1
# BB#2:                                 # %while.end
	addiu	$2, $zero, 0
	jr	$ra

	.type	i,@object               # @i
	.bss
	.globl	i
	.align	2
i:
	.4byte	0                       # 0x0
	.size	i, 4

	.type	$.str,@object           # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
$.str:
	.asciz	"iteration %d\n"
	.size	$.str, 14


	.ident	"clang version 3.7.0 (http://llvm.org/git/clang.git 25b834d9ed41ba3eed4afe43997a293e21ccff68) (git@git-marvin:llvm-openisa dd2cf22a7afb948ba576d337bebfba25bfdae1c0)"
	.section	".note.GNU-stack","",@progbits
	.text
