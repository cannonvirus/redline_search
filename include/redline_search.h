#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

class Findred
{
public:
    Findred();
    void Find_Red_Intensity(cv::Mat &img);
    void Search_Red_Point(cv::Mat &img);

    void Pull_Param();

private:
    int red_cnt;
    int red_threshold;
    double best_redIntensity;
    double best_b;
    double best_g;
    double best_r;
};