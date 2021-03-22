/*
 *
 *
 *
 *
 */

#include "../source/ircam04.h"

using namespace std;

//---------------------------------------------------------
//
//---------------------------------------------------------

int 
main(int argc, char** argv) 
{ 
    IMG_AXIS    SRC_IMG_I;
    IMG_AXIS    DST_IMG_O;

    ircam04(SRC_IMG_I, DST_IMG_O);

    return 0;
}
