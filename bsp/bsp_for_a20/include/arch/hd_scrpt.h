/*
* (C) Copyright 2007-2013
* Allwinner Technology Co., Ltd. <www.allwinnertech.com>
* Martin zheng <zhengjiewen@allwinnertech.com>
*
* See file CREDITS for list of people who contributed to this
* project.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston,
* MA 02111-1307 USA
*/
/*
************************************************************************************************************************
*                                                     suni define
*                            suni CPU hardware registers, memory, interrupts, ... define
*
*                             Copyright(C), 2009-2010, uLive Microelectronic Co., Ltd.
*											       All Rights Reserved
*
* File Name : sunii.h
*
* Author : kevin.z
*
* Version : 1.1.0
*
* Date : 2009-9-7 10:53
*
* Description : This file provides some defination of suni's hardware registers, memory, interrupt
*             and so on. This file is very similar to file "sunii.inc"; the two files should be
*             modified at the same time to keep coherence of information.
*
* Others : None at present.
*
*
* History :
*
*  <Author>        <time>       <version>      <description>
*
* kevin.z      2009-9-7 10:53    1.0.0        build the file
*
************************************************************************************************************************
*/

#ifndef  __SUNII_H_
#define  __SUNII_H_

#define A20_EVB_PLATFORM

#define __REG(x)    (*(volatile unsigned int   *)(x))
#define __REGw(x)   (*(volatile unsigned int   *)(x))
#define __REGhw(x)  (*(volatile unsigned short *)(x))
#define __REGb(x)   (*(volatile unsigned char  *)(x))

#define readl(addr)    				( *((volatile unsigned int *)(addr)))
#define writel(value, addr)			((*((volatile unsigned int *)(addr))) = (value))
/*
*********************************************************************************************************
*   hardware registers base define
*********************************************************************************************************
*/
#define REGS_BASE	   0x01C00000		//??????????????
#define REGS_SIZE      0x00300000      //??????????????????
#define DRAM_BASE      0x80000000
#define SRAM_BASE      0x00000000
#define SRAM_SIZE      (32 * 1024)

// ????????
#define SRAM_REGS_BASE         ( REGS_BASE + 0x00000 )    //SRAM controller
#define DRAM_REGS_BASE         ( REGS_BASE + 0x01000 )    //SDRAM/DDR controller
#define DMAC_REGS_BASE         ( REGS_BASE + 0x02000 )    //DMA controller
//#define NAFC_REGS_BASE         ( REGS_BASE + 0x03000 )    //nand flash controller
#define TSC_REGS_BASE          ( REGS_BASE + 0x04000 )    //transport stream interface
#define SPIC0_REGS_BASE        ( REGS_BASE + 0x05000 )    //spi0
#define SPIC1_REGS_BASE        ( REGS_BASE + 0x06000 )    //spi1
#define MSHC_REGS_BASE         ( REGS_BASE + 0x07000 )    //ms
#define TVD_REGS_BASE          ( REGS_BASE + 0x08000 )    //ms
#define CSIC_REGS_BASE         ( REGS_BASE + 0x09000 )    //csi controller
#define TVEC_REGS_BASE         ( REGS_BASE + 0x0a000 )    //tv
#define EMAC_REGS_BASE         ( REGS_BASE + 0x0b000 )    //emac
#define LCD0_REGS_BASE         ( REGS_BASE + 0x0c000 )    //lcd0
#define LCD1_REGS_BASE         ( REGS_BASE + 0x0d000 )    //lcd1
#define VE_REGS_BASE           ( REGS_BASE + 0x0e000 )    //video engine
#define SDMC0_REGS_BASE        ( REGS_BASE + 0x0f000 )    //sdmmc0 controller
#define SDMC1_REGS_BASE        ( REGS_BASE + 0x10000 )    //sdmmc1 controller
#define SDMC2_REGS_BASE        ( REGS_BASE + 0x11000 )    //sdmmc2 controller
#define SDMC3_REGS_BASE        ( REGS_BASE + 0x12000 )    //sdmmc3 controller

#define USBC0_REGS_BASE        ( REGS_BASE + 0x13000 )    //usb/otg 0 controller
#define USBC1_REGS_BASE        ( REGS_BASE + 0x14000 )    //usb/otg 1 controller
#define SS_REGS_BASE           ( REGS_BASE + 0x15000 )    //ss engine
#define HDMI_REGS_BASE         ( REGS_BASE + 0x16000 )    //hdmi controller
#define SPI2_REGS_BASE         ( REGS_BASE + 0x17000 )    //spi2
#define SATA_REGS_BASE         ( REGS_BASE + 0x18000 )    //sata
#define PATA_REGS_BASE         ( REGS_BASE + 0x19000 )    //pata
#define ACEC_REGS_BASE         ( REGS_BASE + 0x1A000 )    //audio/compress engine
#define TVE1_REGS_BASE         ( REGS_BASE + 0x1B000 )    //tve1
#define USBC2_REGS_BASE        ( REGS_BASE + 0x1C000 )    //usb/otg 2 controller
#define CSIC1_REGS_BASE        ( REGS_BASE + 0x1D000 )    //csi controller1
#define TZASC_REGS_BASE        ( REGS_BASE + 0x1E000 )    //??


#define CCMU_REGS_BASE         ( REGS_BASE + 0x20000 )    //clock manager unit
#define INTC_REGS_BASE         ( REGS_BASE + 0x20400 )    //arm interrupt controller
#define PIOC_REGS_BASE         ( REGS_BASE + 0x20800 )    //general perpose I/O
#define TMRC_REGS_BASE         ( REGS_BASE + 0x20c00 )    //timer

#define SPDIF_REGS_BASE        ( REGS_BASE + 0x21000 )    //spdif
#define AC97_REGS_BASE         ( REGS_BASE + 0x21400 )    //AC97 interface
#define IRC0_REGS_BASE         ( REGS_BASE + 0x21800 )    //ir0
#define IRC1_REGS_BASE         ( REGS_BASE + 0x21C00 )    //ir1
#define I2SC_REGS_BASE         ( REGS_BASE + 0x22000 )    //i2s
#define LRAC_REGS_BASE         ( REGS_BASE + 0x22800 )    //lradc
#define ADDA_REGS_BASE         ( REGS_BASE + 0x22c00 )    //AD/DA
#define KAPD_REGS_BASE         ( REGS_BASE + 0x23000 )    //keypad
#define TZPC_REGS_BASE         ( REGS_BASE + 0x23400 )    //tzpc


#define UART0_REGS_BASE        ( REGS_BASE + 0x28000 )    //uart0 base
#define UART1_REGS_BASE        ( REGS_BASE + 0x28400 )    //uart1 base
#define UART2_REGS_BASE        ( REGS_BASE + 0x28800 )    //uart2 base
#define UART3_REGS_BASE        ( REGS_BASE + 0x28C00 )    //uart3 base
#define UART4_REGS_BASE        ( REGS_BASE + 0x29000 )    //uart4 base
#define UART5_REGS_BASE        ( REGS_BASE + 0x29400 )    //uart5 base
#define UART6_REGS_BASE        ( REGS_BASE + 0x29800 )    //uart6 base
#define UART7_REGS_BASE        ( REGS_BASE + 0x29C00 )    //uart7 base


#define TWIC0_REGS_BASE        ( REGS_BASE + 0x2AC00 )    //twi0
#define TWIC1_REGS_BASE        ( REGS_BASE + 0x2B000 )    //twi1
#define TWIC2_REGS_BASE        ( REGS_BASE + 0x2B400 )    //twi2

#define ARMV7_SCU_BASE		(0x01c80000)
#define ARMV7_GIC_BASE		(0x01c81000)
#define ARMV7_CPUIF_BASE	(0x01c82000)
#define ARMV7_CPUBIST_BASE	(0x01c88000)


#endif // end of #ifndef __SUNII_H_
