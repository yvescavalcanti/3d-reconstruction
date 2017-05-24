#include <iostream>
#include <string>
#include <vector>
#include "opencv/cv.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"


using namespace std;
using namespace cv;

#define WINDOW_ONE "img1"
#define WINDOW_TWO "img2"
#define FAST_THRESHOLD 50

void joinImages(const Mat& img1, const Mat& img2, Mat& destiny)
{
	destiny = Mat::zeros(img1.rows, (img1.cols*2)+10, img1.type());
	cout<<destiny.size()<<endl;
	img1.copyTo(destiny(Range::all(), Range(0,img1.cols)));
	img2.copyTo(destiny(Range::all(), Range(img2.cols+10,img2.cols*2+10)));

	//destiny = destiny.adjustROI(120,120,120,120);
//	destiny = x;
}

int main(int argc, char* argv[])
{
// read images

	Mat img1 = imread(argv[1]);

	if (!img1.data)
	{
		cerr<<argv[1]<<": problema ao ler"<<endl;
	}
	Mat img2 = imread(argv[2]);
	if(!img2.data)
	{
		cerr<<argv[2]<<": problema ao ler"<<endl;
	}

	// setup windows for result
	namedWindow(WINDOW_ONE, CV_WINDOW_AUTOSIZE);
	namedWindow(WINDOW_TWO, CV_WINDOW_AUTOSIZE);


	// detection of keypoints
	//FastFeatureDetector detec();
	vector<KeyPoint> keypoints1,keypoints2;

	//detec.detect(img1, keypoints1);
	//detec.detect(img2, keypoints2);
	FAST(img1,keypoints1,FAST_THRESHOLD);
	FAST(img2,keypoints2,FAST_THRESHOLD);

	Mat img1key, img2key;

	drawKeypoints(img1,keypoints1, img1key, Scalar::all(-1),DrawMatchesFlags::DEFAULT);
	drawKeypoints(img2,keypoints2, img2key, Scalar::all(-1),DrawMatchesFlags::DEFAULT);
	imshow(WINDOW_ONE, img1key);
	imshow(WINDOW_TWO, img2key);
	Mat joined;
	joinImages(img1key, img2key, joined);
	cout<<"key one:"<<keypoints1.size()<<endl;
	cout<<"key two:"<<keypoints2.size()<<endl;
	ORB orb();
	//Mat fMat=findFundamentalMat(img1key,img2key);

	imshow("joined", joined);

	waitKey(0);

}
