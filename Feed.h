#pragma once
#ifndef MY_FEED
#define MY_FEED
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<conio.h>  
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include<conio.h>           // it may be necessary to change or remove this line if not using Windows

#include "Blob.h"
class Feed {

public:
	

	// global variables ///////////////////////////////////////////////////////////////////////////////
	 const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
	 const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
	 const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
	 const cv::Scalar SCALAR_GREEN = cv::Scalar(0.0, 200.0, 0.0);
	 const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);
	 cv::String cam_name;
	 int carCount = 0;
	 int carCount1 = 0;
	 cv::Mat imgFrame1;
	 cv::Mat imgFrame2;
	 std::vector<Blob> blobs;
	 cv::Point crossingLine[2];
	 cv::Point crossingLine1[2];
	 cv::VideoCapture capVideo;
	 int intHorizontalLinePosition = imgFrame1.cols / 4;
	 //int intHorizontalLinePosition = (int)std::round((double)imgFrame1.rows * 0.35); //@CW - position of the line cars going left to right need to hit to increment carCount. It says horizonrl position, but it isn't, I just didn't feel like changing the name everywhere
	 //int intVerticalLinePosition = (int)std::round((double)imgFrame1.rows * 0.35);
	 int intVerticalLinePosition = imgFrame1.cols - (imgFrame1.cols / 4); //@CW - position of the line cars going right to left need to hit to increment carCount1. 
	 char chCheckForEscKey = 0;
	

	 

	 

	 bool blnFirstFrame = true;

	 int frameCount = 2;
	 //@CW These are just the positions for the visual lines on the screen. crossingLine was originally a horizontal line, so I just switched the x and y values. imgFrame1.cols and imageFrame.rows can be used to change the 


	// function prototypes ////////////////////////////////////////////////////////////////////////////
	 Feed();
	 //void createFeed(cv::String video, cv::String name);
	 void matchCurrentFrameBlobsToExistingBlobs(std::vector<Blob> &existingBlobs, std::vector<Blob> &currentFrameBlobs);
	 void addBlobToExistingBlobs(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs, int &intIndex);
	 void addNewBlob(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs);
	 double distanceBetweenPoints(cv::Point point1, cv::Point point2);
	 void drawAndShowContours(cv::Size imageSize, std::vector<std::vector<cv::Point> > contours, std::string strImageName);
	 void drawAndShowContours(cv::Size imageSize, std::vector<Blob> blobs, std::string strImageName);
	 bool checkIfBlobsCrossedTheLine(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &carCount);
	 bool checkIfBlobsCrossedTheLineFromLeft(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &carCount);
	 void drawBlobInfoOnImage(std::vector<Blob> &blobs, cv::Mat &imgFrame2Copy);
	 void drawCarCountOnImage(int &carCount, cv::Mat &imgFrame2Copy);
	 void drawCarCountOnImage1(int &carCount, cv::Mat &imgFrame2Copy);
	 Feed(cv::String video, cv::String name);
	 void doStuff();
};

#endif