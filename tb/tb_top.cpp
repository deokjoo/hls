/***********************************************************
 *
 *
 *
 *
 ***********************************************************/

#include "../source/ircam04.h"


using namespace std;

//---------------------------------------------------------
//
//---------------------------------------------------------
int
load_stream(IMG_AXIS &stream)
{
    int i;
    int j;
    ap_axiu<16,1,1,1> pixel;         // TODO : get type from IMG_AXIS

    pixel.data = 0;
    pixel.keep = 1;
    pixel.strb = 1;
    pixel.user = 0;
    pixel.last = 0;
    pixel.id   = 0;
    pixel.dest = 1;

    for(i=0; i<PIC_ROW; i++)
    {
        for(j=0; j<PIC_COL; j++)
        {
            pixel.user = 0;
            pixel.last = 0;
            pixel.data = j;

            if( (i==0) & (j==0))
                pixel.user = 1;
            if( j == (PIC_COL-1))
                pixel.last = 1;

            stream.write(pixel);
        }
    }

	return 0;
}

//---------------------------------------------------------
//
//---------------------------------------------------------
int
store_stream(IMG_AXIS &stream)
{
    int i;
    int j;
    ap_axiu<16,1,1,1> pixel;         // TODO : get type from IMG_AXIS

    for(i=0; i<PIC_ROW; i++)
    {
        for(j=0; j<PIC_COL; j++)
        {
            stream.read(pixel);
        }
    }

	return 0;
}


//---------------------------------------------------------
//
//---------------------------------------------------------
int
main(int argc, char** argv)
{
    IMG_AXIS    SRC_IMG_I;
    IMG_AXIS    DST_IMG_O;
    HIS_AXIM   *SRC_HIS_I;
    HIS_AXIM   *DST_HIS_O;

    DST_HIS_O = new HIS_AXIM[PIC_ROW*PIC_COL*4096/256];
    SRC_HIS_I = new HIS_AXIM[PIC_ROW*PIC_COL*4096/256];
    
    // prepare input stream
    load_stream (SRC_IMG_I);
    ircam04(SRC_IMG_I, DST_IMG_O,SRC_HIS_I, DST_HIS_O);
    store_stream(DST_IMG_O);

    return 0;
}










