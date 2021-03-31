/***********************************************************
 *
 *
 *
 *
 ***********************************************************/

#ifndef _IRCAM04_H_
#define _IRCAM04_H_

#include <ap_int.h>
#include "hls_stream.h"
#include "common/xf_common.hpp"
#include "common/xf_utility.hpp"
#include "common/xf_infra.hpp"

//---------------------------------------------------------
//
//---------------------------------------------------------
#define IMG_AXIS hls::stream<ap_axiu<16,1,1,1>>
#define HIS_AXIM unsigned short

//---------------------------------------------------------
//
//---------------------------------------------------------
void ircam04
(
	IMG_AXIS    &SRC_IMG_I,
	IMG_AXIS    &DST_IMG_O,
	HIS_AXIM    *SRC_HIS_I,
	HIS_AXIM    *SRC_HIS_O
);

//---------------------------------------------------------
//
//---------------------------------------------------------
#define 	PIC_COL	640
#define		PIC_ROW	16


#endif
