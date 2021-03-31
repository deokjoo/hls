/*
 * Copyright 2020
 *
 *
 *
 */

#ifndef _AHE_H_
#define _AHE_H_ 

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
template <int ROWS, int COLS, int B_ROWS, int B_COLS>
void
ahe_proc00
(
	Mat<XF_16UC1, ROWS, COLS, XF_NPPC1> &src_img_i,
	Mat<XF_16UC1, ROWS, COLS, XF_NPPC1> &dst_img_o,
	HIS_AXIM 							hist_line[(COLS/B_COLS)][4096],
	
	int 								base_index
)
{
	int i;
	int j;
	int pix_idx = base_index;
	
	XF_TNAME(XF_16UC1, XF_NPPC1) pixel_i;
	
	//
	r_loop:for(i=0; i<B_ROWS; i++)
	{
		c_loop:for(j=0; j<COLS; j++)
		{
			int blk_idx = j >> (6); 				// TODO: use log2 for automation (log2<B_COLS>::cvalue);
			//
			pixel_i = src_img_i.read(pix_idx)  ;
			hist_line[blk_idx][j] =           j;
			dst_img_o.write(pix_idx, pixel_i)  ;
			//
			pix_idx++;
		}
	}

	return;
}


//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
template <int ROWS, int COLS, int B_ROWS, int B_COLS>
void
ahe_filter
(
   Mat<XF_16UC1, ROWS, COLS, XF_NPPC1> &src_img_i,
   Mat<XF_16UC1, ROWS, COLS, XF_NPPC1> &dst_img_o,
   HIS_AXIM                            *SRC_HIS_I,
   HIS_AXIM                            *DST_HIS_O
)
{
#ifndef __SYNTHESIS__
	assert((ROWS % B_ROWS == 0) && (COLS % B_COLS == 0));
#endif

	//
	int 		i       ;
	int 		base_idx;
	ap_uint<1>  pr      ;
	ap_uint<1>  wr      ;

	HIS_AXIM   *base_adr;
	HIS_AXIM 	hist_line[2][(COLS/B_COLS)][4096] ;

	const int   mem_len = sizeof(hist_line)/2;
	const int   blk_row = ROWS / B_ROWS      ;

	//
	base_idx = 0        ;
	base_adr = DST_HIS_O;
	//
	l0_loop:for(i=0; i<blk_row; i++)
	{
		pr = (i & 0x1);
		wr = (~pr    );

		if(i != 0)
		{
			printf("memcpy %02d %08x(%d, %d)\r\n", i, base_adr, mem_len, wr.to_uint());
			memcpy(base_adr, hist_line[wr], mem_len);
		}
		ahe_proc00<ROWS, COLS, B_ROWS, B_COLS>(src_img_i, dst_img_o, hist_line[pr], base_idx);

		base_idx += (COLS * blk_row);
		base_adr += mem_len       ;
	}
	l1_loop:
	{
		printf("memcpy %02d %08x(%d, %d)\r\n", i, base_adr, mem_len, wr.to_uint());
		memcpy(base_adr, hist_line[pr], mem_len);
	}

	//


    return;
}


#endif
