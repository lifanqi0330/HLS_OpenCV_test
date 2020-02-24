#ifndef _MYRGB2GRAY_H_   //ifndef  ����ifdef...
#define _MYRGB2GRAY_H_
#include "hls_video.h"

#define INPUT_IMAGE "IN_IMG.bmp"
#define OUTPUT_IMAGE "OUT_IMG.bmp"
#define GOLD_IMAGE "GOLD_IMG.bmp"

typedef  hls::stream<ap_axiu<32,1,1,1> > 	AXI_STREAM; //opencvAXI��������
typedef  hls::Mat<1080,1920,HLS_8UC3> 	 RGB_IMAGE; //hls_8uc3  8Ϊ8bit��3Ϊ3ͨ��
typedef  hls::Mat<1080,1920,HLS_8UC1>  	GRAY_IMAGE; //�Ҷ�ͼ��  1ͨ��

void myrgb2gray(AXI_STREAM &src,AXI_STREAM &dst,int rows,int cols);

#endif
