	.file	"22.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.globl	main
	.type	main, @function
main:
.LFB1518:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	call	getchar@PLT
	movl	%eax, -20(%rbp)
.L3:
	cmpl	$-1, -20(%rbp)
	je	.L23
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	isspace@PLT
	testl	%eax, %eax
	je	.L23
	call	getchar@PLT
	movl	%eax, -20(%rbp)
	jmp	.L3
.L23:
	cmpl	$-1, -20(%rbp)
	je	.L4
	movb	$1, -21(%rbp)
	movl	$0, -16(%rbp)
.L6:
	cmpl	$-1, -20(%rbp)
	je	.L5
	cmpl	$48, -20(%rbp)
	jne	.L5
	addl	$1, -16(%rbp)
	call	getchar@PLT
	movl	%eax, -20(%rbp)
	jmp	.L6
.L5:
	movl	$0, -12(%rbp)
.L8:
	cmpl	$-1, -20(%rbp)
	je	.L7
	cmpl	$49, -20(%rbp)
	jne	.L7
	addl	$1, -12(%rbp)
	call	getchar@PLT
	movl	%eax, -20(%rbp)
	jmp	.L8
.L7:
	cmpl	$0, -16(%rbp)
	je	.L9
	cmpl	$0, -12(%rbp)
	jne	.L18
.L9:
	movb	$0, -21(%rbp)
.L18:
	cmpl	$-1, -20(%rbp)
	je	.L11
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	isspace@PLT
	testl	%eax, %eax
	jne	.L11
	movzbl	-21(%rbp), %eax
	xorl	$1, %eax
	testb	%al, %al
	jne	.L11
	movl	$0, -8(%rbp)
.L13:
	cmpl	$-1, -20(%rbp)
	je	.L12
	cmpl	$48, -20(%rbp)
	jne	.L12
	addl	$1, -8(%rbp)
	call	getchar@PLT
	movl	%eax, -20(%rbp)
	jmp	.L13
.L12:
	movl	$0, -4(%rbp)
.L15:
	cmpl	$-1, -20(%rbp)
	je	.L14
	cmpl	$49, -20(%rbp)
	jne	.L14
	addl	$1, -4(%rbp)
	call	getchar@PLT
	movl	%eax, -20(%rbp)
	jmp	.L15
.L14:
	movl	-16(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jne	.L16
	movl	-12(%rbp), %eax
	cmpl	-4(%rbp), %eax
	je	.L18
.L16:
	movb	$0, -21(%rbp)
	jmp	.L18
.L11:
	movzbl	-21(%rbp), %eax
	movl	%eax, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEb@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.L20:
	cmpl	$-1, -20(%rbp)
	je	.L22
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	isspace@PLT
	testl	%eax, %eax
	jne	.L22
	call	getchar@PLT
	movl	%eax, -20(%rbp)
	jmp	.L20
.L22:
	cmpl	$-1, -20(%rbp)
	je	.L23
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	isspace@PLT
	testl	%eax, %eax
	je	.L23
	call	getchar@PLT
	movl	%eax, -20(%rbp)
	jmp	.L22
.L4:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1518:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2005:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L27
	cmpl	$65535, -8(%rbp)
	jne	.L27
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L27:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2005:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2006:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2006:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 8.2.1 20181127"
	.section	.note.GNU-stack,"",@progbits
