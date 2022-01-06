#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
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

    double best_redIntensity = 0;
    double best_b;
    double best_g;
    double best_r;
    for (int row = 0; row < image.rows; row++)
    {
        uchar *pointer_row = image.ptr<uchar>(row);
        for (int col = 0; col < image.cols; col++)
        {
            double b = static_cast<double>(pointer_row[col * 3 + 0]);
            double g = static_cast<double>(pointer_row[col * 3 + 1]);
            double r = static_cast<double>(pointer_row[col * 3 + 2]);

            double redIntensity = r / ((g + b + 1) / 2);
            // cout << "RED : " << redIntensity << endl;
            if (redIntensity > best_redIntensity && r > 100)
            {
                best_redIntensity = redIntensity;
                best_b = b;
                best_g = g;
                best_r = r;
            }
        }
    }

    cout << "best : " << best_redIntensity << endl;
    cout << "best b : " << best_b << endl;
    cout << "best g : " << best_g << endl;
    cout << "best r : " << best_r << endl;

    int point_red = 0;
    for (int row = 0; row < image.rows; row++)
    {
        uchar *pointer_row = image.ptr<uchar>(row);
        for (int col = 0; col < image.cols; col++)
        {
            double b = static_cast<double>(pointer_row[col * 3 + 0]);
            double g = static_cast<double>(pointer_row[col * 3 + 1]);
            double r = static_cast<double>(pointer_row[col * 3 + 2]);

            double redIntensity = r / ((g + b + 1) / 2);

            if (redIntensity > best_redIntensity * 0.4 && r > 130)
            {
                // line_point.push_back(cv::Point2f(col, row));
                // y_line_point.push_back(row);
                // x_line_point.push_back(col);
                gary_img.at<uchar>(row, col) = 255;
                point_red++;
            }
            else
            {
                gary_img.at<uchar>(row, col) = 0;
            }
        }
    }
    cout << "point : " << point_red << endl;
    cv::imwrite("mask.jpg", gary_img);

    cv::Mat img_edge;
    cv::Canny(gary_img, img_edge, 200, 220);
    cv::imwrite("edge.jpg", img_edge);

    return 0;
}