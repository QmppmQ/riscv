	.file	"test_point.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	li	a5,10
	sw	a5,-32(s0)
	li	a5,2130706432
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	li	a4,1234
	sw	a4,0(a5)
	addi	a5,s0,-32
	sw	a5,-24(s0)
	lw	a5,-24(s0)
 #APP
# 18 "test_point.c" 1
	mv a5,a5
# 0 "" 2
 #NO_APP
	sw	a5,-28(s0)
	li	a5,0
	mv	a0,a5
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (GNU) 9.2.0"
