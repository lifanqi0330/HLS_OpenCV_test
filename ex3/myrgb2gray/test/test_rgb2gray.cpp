#include "./../src/myrgb2gray.h"
#include "hls_opencv.h"

int main(int argc ,int ** argv){

	//使用软件OPENCV将图像读入：
	IplImage *src =cvLoadImage(INPUT_IMAGE);
	IplImage *dst =cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
	//转化成AXI
	AXI_STREAM axi_src,axi_dst;
	IplImage2AXIvideo(src,axi_src);
	//运行函数
	myrgb2gray(axi_src,axi_dst,src->height,src->width);
	//转化为IPl
	AXIvideo2IplImage(axi_dst,dst);
	//用软件OPENCV读出
	cvSaveImage(OUTPUT_IMAGE,dst);

	//生成opencv处理图像
	IplImage *tmp_g =cvCreateImage(cvGetSize(src),src->depth,1);
	IplImage *tmp =cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
	cvCvtColor(src,tmp_g,CV_RGB2GRAY);
	cvCvtColor(tmp_g,tmp,CV_GRAY2RGB);
	cvSaveImage(GOLD_IMAGE,tmp);
	//释放空间
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvReleaseImage(&tmp_g);
	cvReleaseImage(&tmp);
	//对比测试
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
