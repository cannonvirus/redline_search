#include <opencv2/opencv.hpp>
#include <iostream>
#include "redline_search.h"

using namespace std;

int main()
{
    Findred cls_redsearch;
    // Read the image file
    cv::Mat image = cv::imread("/works/cpp_histo/output_F.jpg");
    cv::Mat gary_img(image.rows, image.cols, CV_8UC1);

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // wait for any key press
        return -1;
    }

    cls_redsearch.Search_Red_Point(image);
    cls_redsearch.Pull_Param();
    // cv::imwrite("mask.jpg", gary_img);

    // cv::Mat img_edge;
    // cv::Canny(gary_img, img_edge, 200, 220);
    // cv::imwrite("edge.jpg", img_edge);

    return 0;
}