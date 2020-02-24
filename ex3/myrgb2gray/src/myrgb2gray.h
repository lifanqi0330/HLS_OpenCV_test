#ifndef _MYRGB2GRAY_H_   //ifndef  不是ifdef...
#define _MYRGB2GRAY_H_
#include "hls_video.h"

#define INPUT_IMAGE "IN_IMG.bmp"
#define OUTPUT_IMAGE "OUT_IMG.bmp"
#define GOLD_IMAGE "GOLD_IMG.bmp"

typedef  hls::stream<ap_axiu<32,1,1,1> > 	AXI_STREAM; //opencvAXI数据类型
typedef  hls::Mat<1080,1920,HLS_8UC3> 	 RGB_IMAGE; //hls_8uc3  8为8bit，3为3通道
typedef  hls::Mat<1080,1920,HLS_8UC1>  	GRAY_IMAGE; //灰度图像  1通道

void myrgb2gray(AXI_STREAM &src,AXI_STREAM &dst,int rows,int cols);

#endif
