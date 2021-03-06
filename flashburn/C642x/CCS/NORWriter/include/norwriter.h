
/**************************************************************************
*                                                                         *
*   (C) Copyright 2008                                                    *
*   Texas Instruments, Inc.  <www.ti.com>                                 * 
*                                                                         *
*   See file CREDITS for list of people who contributed to this project.  *
*                                                                         *
**************************************************************************/


/**************************************************************************
*                                                                         *
*   This file is part of the DaVinci Flash and Boot Utilities.            *
*                                                                         *
*   This program is free software: you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation, either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful, but   *
*   WITHOUT ANY WARRANTY; without even the implied warranty of            *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
*   General Public License for more details.                              *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program.  if not, write to the Free Software          *
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307   *
*   USA                                                                   *
*                                                                         *
**************************************************************************/

/* --------------------------------------------------------------------------
  FILE        : norwriter.c 				                             	 	        
  PROJECT     : TI Booting and Flashing Utilities
  AUTHOR      : Daniel Allred
  DESC        : CCS NOR Flashing Utility  
 ----------------------------------------------------------------------------- */

#ifndef _NORWRITER_H_
#define _NORWRITER_H_

#include "tistdtypes.h"

// Prevent C++ name mangling
#ifdef __cplusplus
extern far "c" {
#endif

/**************************************************
* Global Macro Declarations                       *
**************************************************/

//UBL version number
#define UBL_VERSION_STRING "1.00"
#ifdef UBL_NAND
#define UBL_FLASH_TYPE "NAND"
#else
#define UBL_FLASH_TYPE "NOR"
#endif

// Define MagicNumber constants
#define MAGIC_NUMBER_VALID	(0xA1ACED00)
#define AIS_MAGIC_NUMBER	(0x41504954)

// Used by UBL when doing UART boot
#define UBL_UART_BOOT		(0xA1ACED00)		/* Safe boot mode */
#define UBL_NOR_BURN		(0xA1ACED11)		/* Download via UART & Burn NOR with UBL readable header and BIN data*/
#define UBL_NOR_ERASE		(0xA1ACED22)		/* Download via UART & Global erase the NOR Flash*/
#define UBL_NAND_BURN		(0xA1ACED33)		/* Download via UART & Burn NAND - Image is binary */
#define UBL_NAND_ERASE		(0xA1ACED44)		/* Download via UART & Global erase the NAND Flash*/

// Used by RBL when doing NAND boot
#define UBL_MAGIC_DMA				(0xA1ACED11)		/* DMA boot mode */
#define UBL_MAGIC_IC				(0xA1ACED22)		/* I Cache boot mode */
#define UBL_MAGIC_FAST				(0xA1ACED33)		/* Fast EMIF boot mode */
#define UBL_MAGIC_DMA_IC			(0xA1ACED44)		/* DMA + ICache boot mode */
#define UBL_MAGIC_DMA_IC_FAST		(0xA1ACED55)		/* DMA + ICache + Fast EMIF boot mode */

// Used by UBL when doing UART boot, UBL Nor Boot, or NAND boot
#define UBL_MAGIC_BIN_IMG			(0xA1ACED66)		/* Execute in place supported*/

// Used by UBL when doing UART boot
#define UBL_MAGIC_NOR_RESTORE		(0xA1ACED77)		/* Download via UART & Restore NOR with binary data */
#define UBL_MAGIC_NOR_SREC_BURN		(0xA1ACED88)		/* Download via UART & Burn NOR with UBL readable header and SREC data*/
#define UBL_MAGIC_NOR_BIN_BURN      (0xA1ACED99)		/* Download via UART & Burn NOR with UBL readable header and BIN data*/
#define UBL_MAGIC_NOR_GLOBAL_ERASE	(0xA1ACEDAA)		/* Download via UART & Global erase the NOR Flash*/
#define UBL_MAGIC_NAND_SREC_BURN	(0xA1ACEDBB)		/* Download via UART & Burn NAND - Image is S-record*/
#define UBL_MAGIC_NAND_BIN_BURN		(0xA1ACEDCC)		/* Download via UART & Burn NAND - Image is binary */
#define UBL_MAGIC_NAND_GLOBAL_ERASE	(0xA1ACEDDD)		/* Download via UART & Global erase the NAND Flash*/

// Define UBL image size
#define UBL_IMAGE_SIZE      (0x00003800)

// Define maximum downloadable image size
#define MAX_IMAGE_SIZE 		(0x02000000u)
#define RAM_START_ADDR 		(0x80000000u)
#define RAM_END_ADDR 		((RAM_START_ADDR + DDR_RAM_SIZE))


/************************************************
* Global Typedef declarations                   *
************************************************/

typedef struct {
	Uint32		magicNum;
	Uint32		entryPoint;	
	Uint32		appSize;
	Uint32		ldAddress;	/* Starting RAM address where image is to copied - XIP Mode */
} NOR_BOOT;


/******************************************************
* Global Function Declarations                        *
******************************************************/

void main(void);


/***********************************************************
* End file                                                 *
***********************************************************/

#ifdef __cplusplus
}
#endif

#endif //_NORWRITER_H_


/* -------------------------------------------------------------------------- 
    HISTORY
 		v1.00  -  DJA  -  20-Feb-2008
			Initial Release 	   
----------------------------------------------------------------------------- */
