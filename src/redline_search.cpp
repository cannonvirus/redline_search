#include "redline_search.h"

using namespace std;

Findred::Findred()
{
    red_cnt = 0;
    red_threshold = 100;
    best_redIntensity = 0.0;
    best_b = 0.0;
    best_g = 0.0;
    best_r = 0.0;
    cout << "FIND RED START" << endl;
}

void Findred::Find_Red_Intensity(cv::Mat &img)
{
    for (int row = 0; row < img.rows; row++)
    {
        uchar *pointer_row = img.ptr<uchar>(row);
        for (int col = 0; col < img.cols; col++)
        {
            double b = static_cast<double>(pointer_row[col * 3 + 0]);
            double g = static_cast<double>(pointer_row[col * 3 + 1]);
            double r = static_cast<double>(pointer_row[col * 3 + 2]);

            double redIntensity = r / ((g + b + 1) / 2);
            // cout << "RED : " << redIntensity << endl;
            if (redIntensity > best_redIntensity && r > red_threshold)
            {
                best_redIntensity = redIntensity;
                best_b = b;
                best_g = g;
                best_r = r;
            }
        }
    }
}

void Findred::Search_Red_Point(cv::Mat &img)
{
    if (best_redIntensity == 0.0)
    {
        Findred::Find_Red_Intensity(img);
    }
    for (int row = 0; row < img.rows; row++)
    {
        uchar *pointer_row = img.ptr<uchar>(row);
        for (int col = 0; col < img.cols; col++)
        {
            double b = static_cast<double>(pointer_row[col * 3 + 0]);
            double g = static_cast<double>(pointer_row[col * 3 + 1]);
            double r = static_cast<double>(pointer_row[col * 3 + 2]);

            double redIntensity = r / ((g + b + 1) / 2);

            if (redIntensity > best_redIntensity * 0.4 && r > best_r * 0.8)
            {
                // line_point.push_back(cv::Point2f(col, row));
                // y_line_point.push_back(row);
                // x_line_point.push_back(col);
                // gary_img.at<uchar>(row, col) = 255;
                red_cnt++;
            }
            else
            {
                // gary_img.at<uchar>(row, col) = 0;
            }
        }
    }
}

void Findred::Pull_Param()
{
    cout << "-----------------------------------------------------" << endl;
    cout << "red_cnt : " << red_cnt << endl;
    cout << "best_redIntensity : " << best_redIntensity << endl;
    cout << "best_b : " << best_b << endl;
    cout << "best_g : " << best_g << endl;
    cout << "best_r : " << best_r << endl;
    cout << "-----------------------------------------------------" << endl;
}
