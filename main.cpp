#include "opencv2/opencv.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>

#include <iostream>
using namespace std;
using namespace cv;


int main()
{
    
    VideoCapture cap(0);



    Mat a;

    while (true) {
        cap.read(a);

        Mat b, temp, gray;

        resize(a, b, Size(), 0.5, 0.2); // Resize to width=50% and height=50%

        string intensity = " ..,:;=!*#$@";



        /* while (true) {
             cap.read(temp);

             resize(temp, b, Size(),0.5,0.5);
             imshow("vid", b);
             waitKey(5);

         }*/

        cvtColor(b, gray, COLOR_BGR2GRAY);

        //putText(gray, "hi cnc", Point(50, 50), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 0));

        /*cout << gray << endl;*/



        imshow("gr", gray);


        resize(gray, temp, Size(), 1, 1);

        imshow("t", temp);


        uchar* p = temp.data;
        int ncol = temp.cols;
        int nrow = temp.rows;
        vector<string> out;

        Mat new_image = Mat::zeros(Size(600, 600), temp.type());



        for (unsigned int i = 0; i < nrow; ++i) {

            string s = "";

            for (int j = 0;j < ncol;j++) {

                s += intensity[(((*p) * intensity.length()) / 256)];
                p++;

            }

            out.push_back(s);


        }

        /*cout << temp << endl;
        cout << gray.size;
        cout << "ts" << temp.size << endl;*/

        int y = 0;
        ofstream my_file("example.txt", ios::out);

        
        for (auto x : out) {

            my_file << x << endl;

        }
        cout << "hi" << endl;

        //imshow("w", new_image);



        waitKey(200);
        
        //system("cls");

    }
    return 0;
}
