#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int getMaxPixelValue(const cv::Mat& img) {
	double minVal, maxVal;
	cv::minMaxLoc(img, &minVal, &maxVal);
	return static_cast<int>(maxVal);
}

int main() {
	cv::Mat img = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);

	int maxPixel = getMaxPixelValue(img);
	std::cout << "최대 화소 밝기: " << maxPixel << std::endl;
}