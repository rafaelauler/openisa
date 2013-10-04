	.file	"calc.bc"
	.section	__TEXT,__const
	.align	8
.LCPI0_0:
	.word	1081529344              ! double 3.652500e+02
                                        !  (0x4076d40000000000)
	.word	0
	.section	__TEXT,__text,regular,pure_instructions
	.globl	data_para_dias
	.align	4
	.type	data_para_dias,@function
data_para_dias:                         ! @data_para_dias
! BB#0:                                 ! %entry
	save %sp, -144, %sp
	add %fp, -32, %l0
	or %l0, 4, %l1
	st %i1, [%l1]
	st %i0, [%fp+-32]
	st %i2, [%fp+-24]
	add %fp, -16, %l0
	or %l0, 4, %l0
	ld [%l1], %l1
	st %l1, [%l0]
	st %i2, [%fp+-8]
	ld [%fp+-32], %l1
	st %l1, [%fp+-16]
	sethi 0, %l1
	st %l1, [%fp+-36]
	ld [%fp+-8], %l1
	add %l1, -1, %l1
	st %l1, [%fp+-40]
	sethi %hi(.LCPI0_0), %l1
	ldd [%l1+%lo(.LCPI0_0)], %f0
	ld [%fp+-40], %f2
	fitod %f2, %f2
	fmuld %f2, %f0, %f0
	fdtoi %f0, %f0
	st %f0, [%fp+-44]
	ld [%fp+-44], %l1
	st %l1, [%fp+-36]
	ld [%l0], %l1
	subcc %l1, 6, %l2
	bgu .LBB0_7
	nop
! BB#1:                                 ! %entry
	subcc %l1, 3, %l2
	bgu .LBB0_4
	nop
! BB#2:                                 ! %entry
	subcc %l1, 2, %l2
	be .LBB0_24
	nop
! BB#3:                                 ! %entry
	subcc %l1, 3, %l1
	be .LBB0_23
	nop
	ba .LBB0_25
	nop
.LBB0_7:                                ! %entry
	subcc %l1, 9, %l2
	bgu .LBB0_11
	nop
! BB#8:                                 ! %entry
	subcc %l1, 7, %l2
	be .LBB0_19
	nop
! BB#9:                                 ! %entry
	subcc %l1, 8, %l2
	be .LBB0_18
	nop
! BB#10:                                ! %entry
	subcc %l1, 9, %l1
	be .LBB0_17
	nop
	ba .LBB0_25
	nop
.LBB0_4:                                ! %entry
	subcc %l1, 4, %l2
	be .LBB0_22
	nop
! BB#5:                                 ! %entry
	subcc %l1, 5, %l2
	be .LBB0_21
	nop
! BB#6:                                 ! %entry
	subcc %l1, 6, %l1
	be .LBB0_20
	nop
	ba .LBB0_25
	nop
.LBB0_11:                               ! %entry
	subcc %l1, 10, %l2
	be .LBB0_16
	nop
! BB#12:                                ! %entry
	subcc %l1, 11, %l2
	be .LBB0_15
	nop
! BB#13:                                ! %entry
	subcc %l1, 12, %l1
	bne .LBB0_25
	nop
! BB#14:                                ! %sw.bb
	ld [%fp+-36], %l1
	add %l1, 30, %l1
	st %l1, [%fp+-36]
.LBB0_15:                               ! %sw.bb2
	ld [%fp+-36], %l1
	add %l1, 31, %l1
	st %l1, [%fp+-36]
.LBB0_16:                               ! %sw.bb4
	ld [%fp+-36], %l1
	add %l1, 30, %l1
	st %l1, [%fp+-36]
.LBB0_17:                               ! %sw.bb6
	ld [%fp+-36], %l1
	add %l1, 31, %l1
	st %l1, [%fp+-36]
.LBB0_18:                               ! %sw.bb8
	ld [%fp+-36], %l1
	add %l1, 31, %l1
	st %l1, [%fp+-36]
.LBB0_19:                               ! %sw.bb10
	ld [%fp+-36], %l1
	add %l1, 30, %l1
	st %l1, [%fp+-36]
.LBB0_20:                               ! %sw.bb12
	ld [%fp+-36], %l1
	add %l1, 31, %l1
	st %l1, [%fp+-36]
.LBB0_21:                               ! %sw.bb14
	ld [%fp+-36], %l1
	add %l1, 30, %l1
	st %l1, [%fp+-36]
.LBB0_22:                               ! %sw.bb16
	ld [%fp+-36], %l1
	add %l1, 31, %l1
	st %l1, [%fp+-36]
.LBB0_23:                               ! %sw.bb18
	ld [%fp+-36], %l1
	add %l1, 28, %l1
	st %l1, [%fp+-36]
.LBB0_24:                               ! %sw.bb20
	ld [%fp+-36], %l1
	add %l1, 31, %l1
	st %l1, [%fp+-36]
.LBB0_25:                               ! %sw.epilog
	ld [%fp+-8], %l1
	sra %l1, 31, %l2
	srl %l2, 30, %l2
	oiadd %l1, %l2, %l2
	and %l2, -4, %l2
	oisub %l1, %l2, %l1
	subcc %l1, 0, %l1
	bne .LBB0_28
	nop
! BB#26:                                ! %land.lhs.true
	ld [%l0], %l0
	subcc %l0, 3, %l0
	bl .LBB0_28
	nop
! BB#27:                                ! %if.then
	ld [%fp+-36], %l0
	add %l0, 1, %l0
	st %l0, [%fp+-36]
.LBB0_28:                               ! %if.end
	ld [%fp+-16], %l0
	ld [%fp+-36], %l1
	oiadd %l1, %l0, %i0
	st %i0, [%fp+-36]
	jmp %i7+8
	restore %g0, %g0, %g0
.Ltmp0:
	.size	data_para_dias, .Ltmp0-data_para_dias

	.globl	main
	.align	4
	.type	main,@function
main:                                   ! @main
! BB#0:                                 ! %entry
	save %sp, -160, %sp
	sethi 0, %l0
	st %l0, [%fp+-4]
	add %fp, -16, %l3
	or %l3, 4, %l0
	sethi %hi(.Lmain.inicio), %l1
	add %l1, %lo(.Lmain.inicio), %l2
	ld [%l2+4], %l4
	st %l4, [%l0]
	ld [%l2+8], %l2
	st %l2, [%fp+-8]
	ld [%l1+%lo(.Lmain.inicio)], %l1
	st %l1, [%fp+-16]
	add %fp, -32, %l2
	or %l2, 4, %l1
	sethi %hi(.Lmain.fim), %l4
	add %l4, %lo(.Lmain.fim), %l5
	ld [%l5+4], %l6
	st %l6, [%l1]
	ld [%l5+8], %l5
	st %l5, [%fp+-24]
	ld [%l4+%lo(.Lmain.fim)], %l4
	st %l4, [%fp+-32]
	sethi %hi(.L.str), %l4
	call printf
	add %l4, %lo(.L.str), %o0
	sethi %hi(.L.str1), %l4
	call printf
	add %l4, %lo(.L.str1), %o0
	sethi %hi(.L.str2), %l4
	add %l4, %lo(.L.str2), %l4
	add %l3, 8, %o3
	or %g0, %l4, %o0
	or %g0, %l3, %o1
	call scanf
	or %g0, %l0, %o2
	subcc %o0, 3, %l3
	be .LBB1_2
	nop
	ba .LBB1_1
	nop
.LBB1_2:                                ! %if.end
	sethi %hi(.L.str4), %l3
	call printf
	add %l3, %lo(.L.str4), %o0
	add %l2, 8, %o3
	or %g0, %l4, %o0
	or %g0, %l2, %o1
	call scanf
	or %g0, %l1, %o2
	subcc %o0, 3, %l2
	bne .LBB1_1
	nop
	ba .LBB1_3
	nop
.LBB1_1:                                ! %if.then
	sethi %hi(.L.str3), %l0
	call printf
	add %l0, %lo(.L.str3), %o0
	call exit
	or %g0, 1, %o0
.LBB1_3:                                ! %if.end12
	add %fp, -48, %l2
	or %l2, 4, %l2
	ld [%l1], %l1
	st %l1, [%l2]
	ld [%fp+-24], %l1
	st %l1, [%fp+-40]
	ld [%fp+-32], %l1
	st %l1, [%fp+-48]
	ld [%l2], %o1
	ld [%fp+-48], %o0
	call data_para_dias
	ld [%fp+-40], %o2
	or %g0, %o0, %l1
	add %fp, -64, %l2
	or %l2, 4, %l2
	ld [%l0], %l0
	st %l0, [%l2]
	ld [%fp+-8], %l0
	st %l0, [%fp+-56]
	ld [%fp+-16], %l0
	st %l0, [%fp+-64]
	ld [%l2], %o1
	ld [%fp+-64], %o0
	call data_para_dias
	ld [%fp+-56], %o2
	oisub %l1, %o0, %o1
	sethi %hi(.L.str5), %l0
	call printf
	add %l0, %lo(.L.str5), %o0
	call exit
	sethi 0, %o0
.Ltmp1:
	.size	main, .Ltmp1-main

	.type	.Lmain.inicio,@object   ! @main.inicio
	.section	__TEXT,__const
	.align	4
.Lmain.inicio:
	.word	1                       ! 0x1
	.word	1                       ! 0x1
	.word	1                       ! 0x1
	.size	.Lmain.inicio, 12

	.type	.Lmain.fim,@object      ! @main.fim
	.align	4
.Lmain.fim:
	.word	1                       ! 0x1
	.word	1                       ! 0x1
	.word	1                       ! 0x1
	.size	.Lmain.fim, 12

	.type	.L.str,@object          ! @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Calculadora de datas.\n"
	.size	.L.str, 23

	.type	.L.str1,@object         ! @.str1
.L.str1:
	.asciz	 "Digite a data de in\303\255cio (DD/MM/AAAA): "
	.size	.L.str1, 40

	.type	.L.str2,@object         ! @.str2
.L.str2:
	.asciz	 "%d/%d/%d"
	.size	.L.str2, 9

	.type	.L.str3,@object         ! @.str3
.L.str3:
	.asciz	 "\nEntrada incorreta.\n"
	.size	.L.str3, 21

	.type	.L.str4,@object         ! @.str4
.L.str4:
	.asciz	 "Digite a data final (DD/MM/AAAA): "
	.size	.L.str4, 35

	.type	.L.str5,@object         ! @.str5
.L.str5:
	.asciz	 "A diferen\303\247a \303\251 de %d dias.\n"
	.size	.L.str5, 29


