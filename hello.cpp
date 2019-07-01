#include <opencv2/opencv.hpp>
#include <iostream>

void help(char** argv ) {
    std::cout << "\n"
    << "\nxample 2-10. The same object can load videos from a camera or a file"
    << "\nCall:\n"  
    << argv[0] <<" [path/image]\n"
    << "\nor, read from camera:\n"
    << argv[0]
    << "\nFor example:\n"
    << argv[0] << " ../tree.avi\n"
    << std::endl;
}
    

int main() {

    cv::Mat image(cv::Size(256,256), CV_8UC3);

    for (int x = 0; x < image.size().width; ++x) {
	for (int y = 0; y <image.size().height; ++y) {
	    image.at < cv::Vec3b > (y,x)[0] = x;
	    image.at < cv::Vec3b > (y,x)[1] = y;
	    image.at < cv::Vec3b > (y,x)[2] = (x+y)/2;
	}
    }

    cv::namedWindow( "Example", cv::WINDOW_AUTOSIZE );

  for(;;) {
    if( image.empty() ) break; // Ran out of film
    cv::imshow( "Example", image );
    if( (char) cv::waitKey(33) >= 0 ) break;
    }

    return 0;
}