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
	addi	$sp, $sp, -40         # Allocate a stack frame with 10 positions
	stw	$ra, 36($sp)            # 4-byte Folded Spill  
  call aux, 0
	ldw	$ra, 36($sp)            # 4-byte Folded Reload
	addi	$2, $zero, 0
	addi	$sp, $sp, 40
	jumpr	$ra
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
	ldw	$5, %lo(i)($16)
	addi	$17, $zero, 4
	addi	$1, $5, 1
	addi	$4, $16, %lo($.str)
	stw	$1, %lo(i)($16)
	call	printf, 0
	ldw	$5, %lo(i)($16)
	jne	$5, $17, $BB0_1
# BB#2:                                 # %while.end
	addi	$2, $zero, 0
	jumpr	$ra

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
