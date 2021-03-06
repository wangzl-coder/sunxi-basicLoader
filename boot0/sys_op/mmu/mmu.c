/*
************************************************************************************************************************
*                                                         eGON
*                                         the Embedded GO-ON Bootloader System
*
*                             Copyright(C), 2006-2008, SoftWinners Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name   : mmu.c
*
* Author      : Gary.Wang
*
* Version     : 1.1.0
*
* Date        : 2009.03.20
*
* Description :
*
* Others      : None at present.
*
*
* History     :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang      2009.03.20       1.1.0        build the file
*
************************************************************************************************************************
*/
#ifndef  __mmu_c
#define  __mmu_c

#include "../sys_op_i.h"

extern void    mmu_set_smp( void);
extern void    mmu_flush_TLB( void);
extern void    flush_icache( void );
extern void    flush_dcache( void );
extern void    mmu_set_domain_access( void );


void mmu_system_init(__u32 dram_base, __u32 dram_size, __u32 mmu_base)
{
	__s32   *mmu_tlb_address = (__s32 *)mmu_base;
	__u32    i;

	//建立16k的段表，表项大小为1M
	for(i = 0; i < 4 * 1024; i++)
	{
		mmu_tlb_address[i] =  (i << 20)    |
							  (0 << 19)    |
							  (0 << 18)    |
							  (0 << 17)    |
							  (0 << 16)    |
							  (0 << 15)    |
							  (0 << 12)    |
							  (3 << 10)    |
							  (0 <<  9)    |
							  (15 << 5)    |
							  (0  << 4)    |
							  (0  << 3)    |
							  (0  << 2)    |
							  (2  << 0);
	}
	//cache sram
	mmu_tlb_address[0] = (0 << 20)    |         //地址
						 (0 << 19)    |         //安全区域
						 (0 << 18)    |         //1M段表
						 (0 << 17)    |         //not global
						 (0 << 16)    |         //not shared
						 (0 << 15)    |         //
						 (0 << 12)    |         //
						 (3 << 10)    |         //访问权限 特权
						 (0 <<  9)    |         //
						 (15 << 5)    |         //域控制
						 (0  << 4)    |         //
						 (1  << 3)    |         //有cache
						 (0  << 2)    |         //无buffer
						 (2  << 0);             //段表
	//cache dram
	for(i = 0; i < dram_size; i++)
	{
		mmu_tlb_address[i + (dram_base>>20)] = (dram_base + (i << 20))  |
									     (0 << 19)    |
										 (0 << 18)    |
										 (0 << 17)    |
										 (0 << 16)    |
										 (0 << 15)    |
										 (0 << 12)    |
										 (3 << 10)    |
									     (0 <<  9)    |
										 (15 << 5)    |
										 (0  << 4)    |
										 (1  << 3)    |
										 (0  << 2)    |
										 (2  << 0);
	}
	mmu_flush_TLB();
	//set ttb
	__asm__ __volatile__(
	"mcr p15, 0, %0, c2, c0, 0"
	:
	:"r"(mmu_base)
	:"memory"
	);
	__asm__ __volatile__(
	"mcr p15, 0, %0, c2, c0, 1"
	:
	:"r"(mmu_base)
	:"memory"
	);
	//clean i/d cache
	flush_icache();
	//flush_dcache();
	//set domain controller
	mmu_set_domain_access();
	//
	//mmu_set_smp();

	return ;
}

void   mmu_enable( void )
{
	__u32 c1format = 0;

	__asm__ __volatile__(
	"mrc p15,0,%0,c1,c0,0"
	:"=r"(c1format)
	:
	:"memory"
	);
	c1format &= ~ 0x1007;
	c1format |= 0x1001;				//打开ICACHE，MMU，DISABLE ALIGIN CHECK
	__asm__ __volatile__(
	"mcr p15,0,%0,c1,c0,0"
	:
	:"r"(c1format)
	:"memory"
	);
}



void   mmu_disable( void )
{
	__u32 c1format = 0;

	__asm__ __volatile__(
	"mrc p15,0,%0,c1,c0,0"
	:"=r"(c1format)
	:
	:"memory"
	);
	c1format &= ~ 0x1007;
	c1format |= 0;
	__asm__ __volatile__(
	"mcr p15,0,%0,c1,c0,0"
	:
	:"r"(c1format)
	:"memory"
	);
}





#endif     //  ifndef __mmu_c

/* end of mmu.c */
