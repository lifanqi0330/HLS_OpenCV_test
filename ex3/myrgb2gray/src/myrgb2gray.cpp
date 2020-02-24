#include "myrgb2gray.h"

void myrgb2gray(AXI_STREAM &src,AXI_STREAM &dst,int rows,int cols){
	RGB_IMAGE img_0(rows,cols);
	GRAY_IMAGE img_1(rows,cols);
	RGB_IMAGE img_2(rows,cols);
	hls::AXIvideo2Mat(src,img_0);
	hls::CvtColor<HLS_RGB2GRAY>(img_0,img_1);//��RGBת��Ϊ�Ҷ�ͼ��
	hls::CvtColor<HLS_GRAY2RGB>(img_1,img_2);//��ͨ����Ҫ��ض�ͨ��
	hls::Mat2AXIvideo(img_2,dst);  //ת����ȥ,�ǻҶ�ͼ�� �ܹ�ʹ�����OPENCV����

}
