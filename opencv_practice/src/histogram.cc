#include "common.hpp"
using namespace cv;
int main(int argc, char** argv) {
	string pics;
  if (argc==1) {
    pics = std::getenv("HOME") + string("/maps/sz_314/sz_314.pgm");
  } else {
    for (char* p = argv[1];*p!='\0';p++) {
      pics.push_back(*p);
    }
  }
  cout << "argc: " << argc << endl;
  cout << "path: " << pics << endl;
  int histSize[1];
  float hranges[2];
  const float* ranges[1];
  int channels[1];
  histSize[0] = 256;
  hranges[0] = 0.0;
  hranges[1] = 256.0;
  ranges[0] = hranges;
  channels[0] = 0;
  Mat image = imread(pics, cv::IMREAD_GRAYSCALE);
  Mat hist;
  cv::calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);
  double maxVal = 0;
  double minVal = 0;
  minMaxLoc(hist, &minVal, &maxVal, 0, 0);
  int hist_size = hist.rows;
  Mat histImg(hist_size*1, hist_size*1, CV_8U, Scalar(255));
  int hpt = static_cast<int>(0.9*hist_size);
  for (int h = 0; h<hist_size; h++) {
  	float binVal = hist.at<float>(h);
  	if (binVal>0) {
  		int intensity = static_cast<int>(binVal*hpt/maxVal);
  		cv::line(histImg, Point(h*1, hist_size*1),
  			Point(h*1, hist_size-intensity), Scalar(0),
  		  1);
  	}
  }
  for (int i=0; i<hist.rows; i++) {
  	cout << "Value " << i << " = " 
  	    << hist.at<float>(i) << "\n";
  }
  namedWindow("histogram");
  imshow("histogram", histImg);
  cv::waitKey(0);
	return 0;
}