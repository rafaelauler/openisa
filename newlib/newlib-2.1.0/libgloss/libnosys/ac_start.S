	.file	1 "start.c"
	.text
	.align	2
	.globl	_start
	.ent	_start
_start:
	ldi	$gp,%lo(_gp)
  ldihi %hi(_gp)
  ldw      $4, 0($sp)
  addi     $5, $sp, 4
  addi $sp, $sp, -32
  addi $6, $zero, -8
  and $sp ,$sp, $6
	call	main, 2
	call	_exit, 1
	.end	_start
