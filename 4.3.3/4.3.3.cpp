// 4.3.3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv.hpp>
#include<iostream>

using namespace cv;


int main()
{
	cv::Mat out; 
    cv:Mat src = imread("D:\\lena.jpg", 0);
	if (src.empty()) return -1;
	const cv::Point2f src_pt[] = { cv::Point2f(200,200),cv::Point2f(250,200),cv::Point2f(200,100) };
	const cv::Point2f dst_pt[] = { cv::Point2f(300,100),cv::Point2f(300,50),cv::Point2f(200,100) };
	const cv::Mat aff = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(src, out, aff, src.size());
	imshow("src", src);
	imshow("out", out);
	waitKey(0);
}

