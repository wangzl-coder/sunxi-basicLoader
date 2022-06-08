/*
************************************************************************************************************************
*                                                         eGON
*                                         the Embedded GO-ON Bootloader System
*
*                             Copyright(C), 2006-2008, SoftWinners Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name : Boot0_head.c
*
* Author : Gary.Wang
*
* Version : 1.1.0
*
* Date : 2007.11.06
*
* Description : This file defines the file head part of Boot0, which contains some important
*             infomations such as magic, platform infomation and so on, and MUST be allocted in the
*             head of Boot0.
*
* Others : None at present.
*
*
* History :
*
*  <Author>        <time>       <version>      <description>
*
* Gary.Wang       2007.11.06      1.1.0        build the file
*
************************************************************************************************************************
*/
#include "boot0_i.h"

#define   DDR3_USED

const boot0_file_head_t  BT0_head __attribute__((__section__(".bt0_head")))= {
									{
	  /* jump_instruction */      		( 0xEA000000 | ( ( ( sizeof( boot0_file_head_t ) + sizeof( int ) - 1 ) / sizeof( int ) - 2 ) & 0x00FFFFFF ) ),	// one intruction jumping to real code
										BOOT0_MAGIC,		// ="eGON.BT0" or "eGON.BT1",  not C-style string.
										STAMP_VALUE,		// generated by PC
		#ifdef ALIGN_SIZE_8K
										0x2000,
		#else
										0x8000,			// generated by PC
		#endif
										sizeof( boot_file_head_t ),	// the size of boot_file_head_t
										BOOT_PUB_HEAD_VERSION,		// the version of boot_file_head_t
										0,							 // the return value
										0,							// run addr
										EGON_VERSION,					// eGON version
										{
											0, 0, '3','.','1','.','0',0	// platform information
										},
									},
#ifdef  DDR3_USED
									{
										sizeof( boot0_private_head_t ),	// the size of prvt_head
										BOOT0_PRVT_HEAD_VERSION,			// the version of boot0_private_head_t
										/******DRAM patameters for initialising dram. Original values is arbitrary******/
										{ 	
											/***normal configuration******/
											552, 				//dram_clk
											3, 				//dram_type
											0x3bbb,				//dram_zq
											1,				//dram_odt_en
											0x10F20200,				//dram_para1
											0x00,				//dram_para2

											/****timing configuration*****/
											0x1840,				//dram_mr0
											0x40,				//dram_mr1
											0x8,			//dram_mr2
											0,			//dram_mr3
											0x0048A192,				//dram_tpr0
											0x01B1B18d,				//dram_tpr1
											0x00076052,				//dram_tpr2
											0x0,				//dram_tpr3
											0x0,				//dram_tpr4
											0x0,				//dram_tpr5
											0x0,				//dram_tpr6
											0x0,				//dram_tpr7
											0x0,				//dram_tpr8
											0x0,				//dram_tpr9
											0x0,				//dram_tpr10
											0x0,				//dram_tpr11
											168,				//dram_tpr12
											0x10900,				//dram_tpr13
										},							
										3,								// UART控制器编号
										{
											{ 8, 6, 3, 1, 0xff, 0xff, {0, 0} },	// UART控制器(调试打印口)数据信息 tx
											{ 8, 7, 3, 1, 0xff, 0xff, {0, 0} }		// UART控制器(调试打印口)数据信息 rx
										},
										0,									// jtag 1 : enable,  0 : disable
										{
											{ 0, 0, 0, 0, 0, 0, {0, 0} },
											{ 0, 0, 0, 0, 0, 0, {0, 0} },
											{ 0, 0, 0, 0, 0, 0, {0, 0} },
											{ 0, 0, 0, 0, 0, 0, {0, 0} },
											{ 0, 0, 0, 0, 0, 0, {0, 0} },
										},							// 保存JTAG的全部GPIO信息
										{
											{ 6, 0, 2, 1, 2, 0, {0, 0} },	
											{ 6, 1, 2, 1, 2, 0, {0, 0} },
											{ 6, 2, 2, 1, 2, 0, {0, 0} },
											{ 6, 3, 2, 1, 2, 0, {0, 0} },
											{ 6, 4, 2, 1, 2, 0, {0, 0} },
											{ 6, 5, 2, 1, 2, 0, {0, 0} },			// 存储设备 GPIO信息
										},

										/****用户保留数据信息****/
										{ 
											0,
										}					
									}
#else
									{
										sizeof( boot0_private_head_t ),
										BOOT0_PRVT_HEAD_VERSION,
										{ 0x40000000,
											1024,
											180,
											1,
											1,
											0,
											(__dram_type_e)1,
											16,
											10,
											14,
											4,
											3,
											0,
											16,
											1024
										},
										0,
										{
											{ 2, 22, 4, 1, 1, 0, 0, 0},
											{ 2, 23, 4, 1, 1, 0, 0, 0}
										},
										0,
										{ 0 },
										{ 0 },
										{ 0 }
									}
#endif
								};



/*******************************************************************************
*
*                  关于Boot_file_head中的jump_instruction字段
*
*  jump_instruction字段存放的是一条跳转指令：( B  BACK_OF_Boot_file_head )，此跳
*转指令被执行后，程序将跳转到Boot_file_head后面第一条指令。
*
*  ARM指令中的B指令编码如下：
*          +--------+---------+------------------------------+
*          | 31--28 | 27--24  |            23--0             |
*          +--------+---------+------------------------------+
*          |  cond  | 1 0 1 0 |        signed_immed_24       |
*          +--------+---------+------------------------------+
*  《ARM Architecture Reference Manual》对于此指令有如下解释：
*  Syntax :
*  B{<cond>}  <target_address>
*    <cond>    Is the condition under which the instruction is executed. If the
*              <cond> is ommitted, the AL(always,its code is 0b1110 )is used.
*    <target_address>
*              Specified the address to branch to. The branch target address is
*              calculated by:
*              1.  Sign-extending the 24-bit signed(wro's complement)immediate
*                  to 32 bits.
*              2.  Shifting the result left two bits.
*              3.  Adding to the contents of the PC, which contains the address
*                  of the branch instruction plus 8.
*
*  由此可知，此指令编码的最高8位为：0b11101010，低24位根据Boot_file_head的大小动
*态生成，所以指令的组装过程如下：
*  ( sizeof( boot_file_head_t ) + sizeof( int ) - 1 ) / sizeof( int )
*                                              求出文件头占用的“字”的个数
*  - 2                                         减去PC预取的指令条数
*  & 0x00FFFFFF                                求出signed-immed-24
*  | 0xEA000000                                组装成B指令
*
*******************************************************************************/

