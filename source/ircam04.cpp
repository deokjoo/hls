/******************************************************************
 *
 *
 *
 *
 *******************************************************************/
#include "ircam04.h"

//-------------------------------------------------------------------
// isp filter for pipe01
//  TODO: move below code to package header file
//
//-------------------------------------------------------------------
namespace pipe01
{
    #include "ahe.h"
}

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
using namespace pipe01;
using namespace xf::cv;

//-------------------------------------------------------------------
// main isp pipeline
//-------------------------------------------------------------------
void
ircam04
(
    IMG_AXIS    &SRC_IMG_I,
    IMG_AXIS    &DST_IMG_O,
    HIS_AXIM    *SRC_HIS_I,
    HIS_AXIM    *DST_HIS_O
)
{
	Mat<XF_16UC1, PIC_ROW, PIC_COL, XF_NPPC1> src_img_i;
	Mat<XF_16UC1, PIC_ROW, PIC_COL, XF_NPPC1> dst_img_o;

	AXIvideo2xfMat(SRC_IMG_I, src_img_i);
	ahe_filter<PIC_ROW, PIC_COL,16,16>(src_img_i, dst_img_o, SRC_HIS_I, DST_HIS_O);
	xfMat2AXIvideo(dst_img_o, DST_IMG_O);

    return;
}

