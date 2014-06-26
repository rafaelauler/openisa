	.file	1 "start.c"
	.text
	.align	2
	.globl	_start
	.ent	_start
_start:
	ori	$gp,$0,%lo(_gp)
        lw      $4, 0($sp)
        lw      $5, 4($sp)
	jal	main
	nop
	jal	_exit
	nop
	.end	_start
