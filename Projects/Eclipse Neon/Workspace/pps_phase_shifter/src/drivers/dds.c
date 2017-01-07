/*
 * dds.c
 *
 *  Created on: 07.01.2017
 *      Author: mlokc
 */

#include "drivers/dds.h"

/** AS9956 registers */

#define CFR1                0x00 /** Control Function Register 1 */
#define CFR2                0x01 /** Control Function Register 2 */
#define RDFTW               0x02 /** Rising Delta Frequency Tunning Word */
#define FDFTW               0x03 /** Falling Delta Frequency Tunning Word */
#define RSRR                0x04 /** Rising Sweep Ramp Rate */
#define FSRR                0x05 /** Falling Sweep Ramp Rate */
#define PCR0                0x06 /** Profile Control Register No. 0*/
#define PCR1                0x07 /** Profile Control Register No. 1*/
#define PCR2                0x08 /** Profile Control Register No. 2*/
#define PCR3                0x09 /** Profile Control Register No. 3*/
#define PCR4                0x0A /** Profile Control Register No. 4*/
#define PCR5                0x0B /** Profile Control Register No. 5*/
#define PCR6                0x0C /** Profile Control Register No. 6*/
#define PCR7                0x0D /** Profile Control Register No. 7*/
