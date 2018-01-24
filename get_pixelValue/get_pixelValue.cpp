#include "cv.h"
#include "highgui.h"
#include<opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
void on_mouse(int envent, int x,int y, int flags, void* userdata);
void main()
{
	namedWindow("input_image");
	Mat src, hsv;
	src = imread("RGB.bmp");

	setMouseCallback("input_image",on_mouse,&src);
	printf("the range of B G R are 0 - 255\n");
	printf("the range of H is 0-180, S is 0-255, V is 0-255\n");
	while(1)
	{
		imshow("input_image", src);
		waitKey(40);
	}
}

void on_mouse(int event, int x,int y, int flags, void* userdata)
{
	Mat rgb, hsv;
	rgb = *(Mat*)userdata;
	Mat temp;
	
	cvtColor(rgb, hsv, CV_BGR2HSV);
	Point p(x, y);
	switch(event)
	{
		case EVENT_LBUTTONDOWN:
		{
			printf("B=%d\t", rgb.at<Vec3b>(p)[0]);
			printf("G=%d\t", rgb.at<Vec3b>(p)[1]);
			printf("R=%d\t", rgb.at<Vec3b>(p)[2]);
			
			printf("H=%d\t", hsv.at<Vec3b>(p)[0]);
			printf("S=%d\t", hsv.at<Vec3b>(p)[1]);
			printf("V=%d\t", hsv.at<Vec3b>(p)[2]);
			printf("\n");
			circle(rgb, p, 2, Scalar(255),3);
		}
		break;
	}
}