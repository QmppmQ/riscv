	.file	"test.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-128
	sw	ra,124(sp)
	sw	s0,120(sp)
	addi	s0,sp,128
	li	a5,16
	sw	a5,-32(s0)
	sw	zero,-20(s0)
	j	.L2
.L5:
	sw	zero,-24(s0)
	j	.L3
.L4:
	lw	a5,-20(s0)
	slli	a4,a5,2
	lw	a5,-24(s0)
	add	a5,a4,a5
	addi	a4,a5,1
	lw	a5,-20(s0)
	slli	a3,a5,2
	lw	a5,-24(s0)
	add	a5,a3,a5
	slli	a5,a5,2
	addi	a3,s0,-16
	add	a5,a3,a5
	sw	a4,-96(a5)
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
.L3:
	lw	a4,-24(s0)
	li	a5,3
	ble	a4,a5,.L4
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L2:
	lw	a4,-20(s0)
	li	a5,3
	ble	a4,a5,.L5
	addi	a5,s0,-112
	sw	a5,-36(s0)
	lw	a5,-36(s0)
	lw	a4,-32(s0)
 #APP
# 19 "test.c" 1
	addi zero,zero,0
.insn r 0x2b, 2, 0, a5, a5, a4
# 0 "" 2
 #NO_APP
	sw	a5,-40(s0)
	sw	zero,-28(s0)
	j	.L6
.L7:
	lw	a5,-28(s0)
	addi	a4,a5,1
	lw	a5,-28(s0)
	slli	a5,a5,2
	addi	a3,s0,-16
	add	a5,a3,a5
	sw	a4,-112(a5)
	lw	a5,-28(s0)
	addi	a5,a5,1
	sw	a5,-28(s0)
.L6:
	lw	a4,-28(s0)
	li	a5,3
	ble	a4,a5,.L7
	call	max_pool
	call	relu
	addi	a5,s0,-128
	mv	a0,a5
	call	wb23
	li	a5,1
	sw	a5,-44(s0)
	li	a5,4
	sw	a5,-48(s0)
	lw	a1,-48(s0)
	lw	a0,-44(s0)
	call	w_wb
	li	a5,0
	mv	a0,a5
	lw	ra,124(sp)
	lw	s0,120(sp)
	addi	sp,sp,128
	jr	ra
	.size	main, .-main
	.align	1
	.globl	wb23
	.type	wb23, @function
wb23:
	addi	sp,sp,-48
	sw	s0,44(sp)
	addi	s0,sp,48
	sw	a0,-36(s0)
	addi	a5,s0,-36
	sw	a5,-20(s0)
	lw	a5,-20(s0)
	lw	a4,-24(s0)
 #APP
# 39 "test.c" 1
	addi zero,zero,0
.insn r 0x2b, 3, 0, a5, a5, a4
# 0 "" 2
 #NO_APP
	sw	a5,-28(s0)
	nop
	lw	s0,44(sp)
	addi	sp,sp,48
	jr	ra
	.size	wb23, .-wb23
	.align	1
	.globl	max_pool
	.type	max_pool, @function
max_pool:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	lw	a5,-20(s0)
	lw	a4,-20(s0)
 #APP
# 48 "test.c" 1
	.insn r 0x2b, 4, 0, a5, a5, a4
# 0 "" 2
 #NO_APP
	sw	a5,-20(s0)
	nop
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra
	.size	max_pool, .-max_pool
	.align	1
	.globl	relu
	.type	relu, @function
relu:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	lw	a5,-20(s0)
	lw	a4,-20(s0)
 #APP
# 56 "test.c" 1
	.insn r 0x2b, 5, 0, a5, a5, a4
# 0 "" 2
 #NO_APP
	sw	a5,-20(s0)
	nop
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra
	.size	relu, .-relu
	.align	1
	.globl	w_wb
	.type	w_wb, @function
w_wb:
	addi	sp,sp,-48
	sw	s0,44(sp)
	addi	s0,sp,48
	sw	a0,-36(s0)
	sw	a1,-40(s0)
	lw	a5,-36(s0)
	lw	a4,-40(s0)
 #APP
# 65 "test.c" 1
	addi zero,zero,0
addi zero,zero,0
.insn r 0x2b, 6, 0, a5, a5, a4
# 0 "" 2
 #NO_APP
	sw	a5,-20(s0)
	nop
	lw	s0,44(sp)
	addi	sp,sp,48
	jr	ra
	.size	w_wb, .-w_wb
	.ident	"GCC: (GNU) 9.2.0"
