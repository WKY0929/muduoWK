
1pthread:     file format elf64-x86-64


Disassembly of section .init:

00000000004005e0 <_init>:
_init():
  4005e0:	48 83 ec 08          	sub    $0x8,%rsp
  4005e4:	48 8b 05 0d 0a 20 00 	mov    0x200a0d(%rip),%rax        # 600ff8 <_DYNAMIC+0x1e0>
  4005eb:	48 85 c0             	test   %rax,%rax
  4005ee:	74 05                	je     4005f5 <_init+0x15>
  4005f0:	e8 8b 00 00 00       	callq  400680 <sleep@plt+0x10>
  4005f5:	48 83 c4 08          	add    $0x8,%rsp
  4005f9:	c3                   	retq   

Disassembly of section .plt:

0000000000400600 <pthread_create@plt-0x10>:
  400600:	ff 35 02 0a 20 00    	pushq  0x200a02(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400606:	ff 25 04 0a 20 00    	jmpq   *0x200a04(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40060c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400610 <pthread_create@plt>:
  400610:	ff 25 02 0a 20 00    	jmpq   *0x200a02(%rip)        # 601018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400616:	68 00 00 00 00       	pushq  $0x0
  40061b:	e9 e0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400620 <__stack_chk_fail@plt>:
  400620:	ff 25 fa 09 20 00    	jmpq   *0x2009fa(%rip)        # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400626:	68 01 00 00 00       	pushq  $0x1
  40062b:	e9 d0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400630 <getuid@plt>:
  400630:	ff 25 f2 09 20 00    	jmpq   *0x2009f2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400636:	68 02 00 00 00       	pushq  $0x2
  40063b:	e9 c0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400640 <printf@plt>:
  400640:	ff 25 ea 09 20 00    	jmpq   *0x2009ea(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400646:	68 03 00 00 00       	pushq  $0x3
  40064b:	e9 b0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400650 <__libc_start_main@plt>:
  400650:	ff 25 e2 09 20 00    	jmpq   *0x2009e2(%rip)        # 601038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400656:	68 04 00 00 00       	pushq  $0x4
  40065b:	e9 a0 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400660 <pthread_join@plt>:
  400660:	ff 25 da 09 20 00    	jmpq   *0x2009da(%rip)        # 601040 <_GLOBAL_OFFSET_TABLE_+0x40>
  400666:	68 05 00 00 00       	pushq  $0x5
  40066b:	e9 90 ff ff ff       	jmpq   400600 <_init+0x20>

0000000000400670 <sleep@plt>:
  400670:	ff 25 d2 09 20 00    	jmpq   *0x2009d2(%rip)        # 601048 <_GLOBAL_OFFSET_TABLE_+0x48>
  400676:	68 06 00 00 00       	pushq  $0x6
  40067b:	e9 80 ff ff ff       	jmpq   400600 <_init+0x20>

Disassembly of section .plt.got:

0000000000400680 <.plt.got>:
  400680:	ff 25 72 09 20 00    	jmpq   *0x200972(%rip)        # 600ff8 <_DYNAMIC+0x1e0>
  400686:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000400690 <_start>:
_start():
  400690:	31 ed                	xor    %ebp,%ebp
  400692:	49 89 d1             	mov    %rdx,%r9
  400695:	5e                   	pop    %rsi
  400696:	48 89 e2             	mov    %rsp,%rdx
  400699:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40069d:	50                   	push   %rax
  40069e:	54                   	push   %rsp
  40069f:	49 c7 c0 c0 08 40 00 	mov    $0x4008c0,%r8
  4006a6:	48 c7 c1 50 08 40 00 	mov    $0x400850,%rcx
  4006ad:	48 c7 c7 b9 07 40 00 	mov    $0x4007b9,%rdi
  4006b4:	e8 97 ff ff ff       	callq  400650 <__libc_start_main@plt>
  4006b9:	f4                   	hlt    
  4006ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004006c0 <deregister_tm_clones>:
deregister_tm_clones():
  4006c0:	b8 67 10 60 00       	mov    $0x601067,%eax
  4006c5:	55                   	push   %rbp
  4006c6:	48 2d 60 10 60 00    	sub    $0x601060,%rax
  4006cc:	48 83 f8 0e          	cmp    $0xe,%rax
  4006d0:	48 89 e5             	mov    %rsp,%rbp
  4006d3:	76 1b                	jbe    4006f0 <deregister_tm_clones+0x30>
  4006d5:	b8 00 00 00 00       	mov    $0x0,%eax
  4006da:	48 85 c0             	test   %rax,%rax
  4006dd:	74 11                	je     4006f0 <deregister_tm_clones+0x30>
  4006df:	5d                   	pop    %rbp
  4006e0:	bf 60 10 60 00       	mov    $0x601060,%edi
  4006e5:	ff e0                	jmpq   *%rax
  4006e7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4006ee:	00 00 
  4006f0:	5d                   	pop    %rbp
  4006f1:	c3                   	retq   
  4006f2:	0f 1f 40 00          	nopl   0x0(%rax)
  4006f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4006fd:	00 00 00 

0000000000400700 <register_tm_clones>:
register_tm_clones():
  400700:	be 60 10 60 00       	mov    $0x601060,%esi
  400705:	55                   	push   %rbp
  400706:	48 81 ee 60 10 60 00 	sub    $0x601060,%rsi
  40070d:	48 c1 fe 03          	sar    $0x3,%rsi
  400711:	48 89 e5             	mov    %rsp,%rbp
  400714:	48 89 f0             	mov    %rsi,%rax
  400717:	48 c1 e8 3f          	shr    $0x3f,%rax
  40071b:	48 01 c6             	add    %rax,%rsi
  40071e:	48 d1 fe             	sar    %rsi
  400721:	74 15                	je     400738 <register_tm_clones+0x38>
  400723:	b8 00 00 00 00       	mov    $0x0,%eax
  400728:	48 85 c0             	test   %rax,%rax
  40072b:	74 0b                	je     400738 <register_tm_clones+0x38>
  40072d:	5d                   	pop    %rbp
  40072e:	bf 60 10 60 00       	mov    $0x601060,%edi
  400733:	ff e0                	jmpq   *%rax
  400735:	0f 1f 00             	nopl   (%rax)
  400738:	5d                   	pop    %rbp
  400739:	c3                   	retq   
  40073a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400740 <__do_global_dtors_aux>:
__do_global_dtors_aux():
  400740:	80 3d 19 09 20 00 00 	cmpb   $0x0,0x200919(%rip)        # 601060 <__TMC_END__>
  400747:	75 11                	jne    40075a <__do_global_dtors_aux+0x1a>
  400749:	55                   	push   %rbp
  40074a:	48 89 e5             	mov    %rsp,%rbp
  40074d:	e8 6e ff ff ff       	callq  4006c0 <deregister_tm_clones>
  400752:	5d                   	pop    %rbp
  400753:	c6 05 06 09 20 00 01 	movb   $0x1,0x200906(%rip)        # 601060 <__TMC_END__>
  40075a:	f3 c3                	repz retq 
  40075c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400760 <frame_dummy>:
frame_dummy():
  400760:	bf 10 0e 60 00       	mov    $0x600e10,%edi
  400765:	48 83 3f 00          	cmpq   $0x0,(%rdi)
  400769:	75 05                	jne    400770 <frame_dummy+0x10>
  40076b:	eb 93                	jmp    400700 <register_tm_clones>
  40076d:	0f 1f 00             	nopl   (%rax)
  400770:	b8 00 00 00 00       	mov    $0x0,%eax
  400775:	48 85 c0             	test   %rax,%rax
  400778:	74 f1                	je     40076b <frame_dummy+0xb>
  40077a:	55                   	push   %rbp
  40077b:	48 89 e5             	mov    %rsp,%rbp
  40077e:	ff d0                	callq  *%rax
  400780:	5d                   	pop    %rbp
  400781:	e9 7a ff ff ff       	jmpq   400700 <register_tm_clones>

0000000000400786 <fun(void*)>:
_Z3funPv():
  400786:	55                   	push   %rbp
  400787:	48 89 e5             	mov    %rsp,%rbp
  40078a:	48 83 ec 10          	sub    $0x10,%rsp
  40078e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  400792:	e8 99 fe ff ff       	callq  400630 <getuid@plt>
  400797:	89 c6                	mov    %eax,%esi
  400799:	bf d4 08 40 00       	mov    $0x4008d4,%edi
  40079e:	b8 00 00 00 00       	mov    $0x0,%eax
  4007a3:	e8 98 fe ff ff       	callq  400640 <printf@plt>
  4007a8:	bf 01 00 00 00       	mov    $0x1,%edi
  4007ad:	e8 be fe ff ff       	callq  400670 <sleep@plt>
  4007b2:	b8 00 00 00 00       	mov    $0x0,%eax
  4007b7:	c9                   	leaveq 
  4007b8:	c3                   	retq   

00000000004007b9 <main>:
main():
  4007b9:	55                   	push   %rbp
  4007ba:	48 89 e5             	mov    %rsp,%rbp
  4007bd:	48 83 ec 40          	sub    $0x40,%rsp
  4007c1:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
  4007c8:	00 00 
  4007ca:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
  4007ce:	31 c0                	xor    %eax,%eax
  4007d0:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%rbp)
  4007d7:	83 7d cc 04          	cmpl   $0x4,-0x34(%rbp)
  4007db:	7f 2e                	jg     40080b <main+0x52>
  4007dd:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
  4007e1:	8b 55 cc             	mov    -0x34(%rbp),%edx
  4007e4:	48 63 d2             	movslq %edx,%rdx
  4007e7:	48 c1 e2 03          	shl    $0x3,%rdx
  4007eb:	48 01 d0             	add    %rdx,%rax
  4007ee:	b9 00 00 00 00       	mov    $0x0,%ecx
  4007f3:	ba 86 07 40 00       	mov    $0x400786,%edx
  4007f8:	be 00 00 00 00       	mov    $0x0,%esi
  4007fd:	48 89 c7             	mov    %rax,%rdi
  400800:	e8 0b fe ff ff       	callq  400610 <pthread_create@plt>
  400805:	83 45 cc 01          	addl   $0x1,-0x34(%rbp)
  400809:	eb cc                	jmp    4007d7 <main+0x1e>
  40080b:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%rbp)
  400812:	83 7d cc 04          	cmpl   $0x4,-0x34(%rbp)
  400816:	7f 1d                	jg     400835 <main+0x7c>
  400818:	8b 45 cc             	mov    -0x34(%rbp),%eax
  40081b:	48 98                	cltq   
  40081d:	48 8b 44 c5 d0       	mov    -0x30(%rbp,%rax,8),%rax
  400822:	be 00 00 00 00       	mov    $0x0,%esi
  400827:	48 89 c7             	mov    %rax,%rdi
  40082a:	e8 31 fe ff ff       	callq  400660 <pthread_join@plt>
  40082f:	83 45 cc 01          	addl   $0x1,-0x34(%rbp)
  400833:	eb dd                	jmp    400812 <main+0x59>
  400835:	b8 00 00 00 00       	mov    $0x0,%eax
  40083a:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  40083e:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
  400845:	00 00 
  400847:	74 05                	je     40084e <main+0x95>
  400849:	e8 d2 fd ff ff       	callq  400620 <__stack_chk_fail@plt>
  40084e:	c9                   	leaveq 
  40084f:	c3                   	retq   

0000000000400850 <__libc_csu_init>:
__libc_csu_init():
  400850:	41 57                	push   %r15
  400852:	41 56                	push   %r14
  400854:	41 89 ff             	mov    %edi,%r15d
  400857:	41 55                	push   %r13
  400859:	41 54                	push   %r12
  40085b:	4c 8d 25 9e 05 20 00 	lea    0x20059e(%rip),%r12        # 600e00 <__frame_dummy_init_array_entry>
  400862:	55                   	push   %rbp
  400863:	48 8d 2d 9e 05 20 00 	lea    0x20059e(%rip),%rbp        # 600e08 <__init_array_end>
  40086a:	53                   	push   %rbx
  40086b:	49 89 f6             	mov    %rsi,%r14
  40086e:	49 89 d5             	mov    %rdx,%r13
  400871:	4c 29 e5             	sub    %r12,%rbp
  400874:	48 83 ec 08          	sub    $0x8,%rsp
  400878:	48 c1 fd 03          	sar    $0x3,%rbp
  40087c:	e8 5f fd ff ff       	callq  4005e0 <_init>
  400881:	48 85 ed             	test   %rbp,%rbp
  400884:	74 20                	je     4008a6 <__libc_csu_init+0x56>
  400886:	31 db                	xor    %ebx,%ebx
  400888:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  40088f:	00 
  400890:	4c 89 ea             	mov    %r13,%rdx
  400893:	4c 89 f6             	mov    %r14,%rsi
  400896:	44 89 ff             	mov    %r15d,%edi
  400899:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  40089d:	48 83 c3 01          	add    $0x1,%rbx
  4008a1:	48 39 eb             	cmp    %rbp,%rbx
  4008a4:	75 ea                	jne    400890 <__libc_csu_init+0x40>
  4008a6:	48 83 c4 08          	add    $0x8,%rsp
  4008aa:	5b                   	pop    %rbx
  4008ab:	5d                   	pop    %rbp
  4008ac:	41 5c                	pop    %r12
  4008ae:	41 5d                	pop    %r13
  4008b0:	41 5e                	pop    %r14
  4008b2:	41 5f                	pop    %r15
  4008b4:	c3                   	retq   
  4008b5:	90                   	nop
  4008b6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4008bd:	00 00 00 

00000000004008c0 <__libc_csu_fini>:
__libc_csu_fini():
  4008c0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000004008c4 <_fini>:
_fini():
  4008c4:	48 83 ec 08          	sub    $0x8,%rsp
  4008c8:	48 83 c4 08          	add    $0x8,%rsp
  4008cc:	c3                   	retq   
