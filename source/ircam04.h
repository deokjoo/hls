/*
 *
 *
 *
 *
 */
#ifndef _IRCAM04_H_
#define _IRCAM04_H_

#include "hls_stream.h"
#include <ap_int.h>
//#include "xf_config_params.h"
#include "common/xf_common.hpp"
#include "common/xf_utility.hpp"


//---------------------------------------------------------
//
//---------------------------------------------------------
#define IMG_AXIS hls::stream<ap_axis<16,1,1,1>>

//---------------------------------------------------------
//
//---------------------------------------------------------
void ircam04
(
    IMG_AXIS    &SRC_IMG_I,
    IMG_AXIS    &DST_IMG_O
);


#endif
