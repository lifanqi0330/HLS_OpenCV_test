#include "./../src/myrgb2gray.h"
#include "hls_opencv.h"

int main(int argc ,int ** argv){

	//ʹ�����OPENCV��ͼ����룺
	IplImage *src =cvLoadImage(INPUT_IMAGE);
	IplImage *dst =cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
	//ת����AXI
	AXI_STREAM axi_src,axi_dst;
	IplImage2AXIvideo(src,axi_src);
	//���к���
	myrgb2gray(axi_src,axi_dst,src->height,src->width);
	//ת��ΪIPl
	AXIvideo2IplImage(axi_dst,dst);
	//�����OPENCV����
	cvSaveImage(OUTPUT_IMAGE,dst);

	//����opencv����ͼ��
	IplImage *tmp_g =cvCreateImage(cvGetSize(src),src->depth,1);
	IplImage *tmp =cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
	cvCvtColor(src,tmp_g,CV_RGB2GRAY);
	cvCvtColor(tmp_g,tmp,CV_GRAY2RGB);
	cvSaveImage(GOLD_IMAGE,tmp);
	//�ͷſռ�
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvReleaseImage(&tmp_g);
	cvReleaseImage(&tmp);
	//�ԱȲ���
	char tmp_buf[2000];
	sprintf(tmp_buf,"diff -w %s %s",OUTPUT_IMAGE,GOLD_IMAGE);
	int rslt=system(tmp_buf);
	if(rslt==0)
	{
		printf("OK \n");
		return rslt;
	}else{
		printf("no \n");
		return 0;
	}


}
