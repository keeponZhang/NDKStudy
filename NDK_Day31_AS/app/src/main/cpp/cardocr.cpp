//
// Created by hcDarren on 2018/7/28.
//

#include "cardocr.h"
#include <vector>
#include <android/log.h>

using namespace std;

int co1::find_card_area(const Mat &mat, Rect &area) {

    // 首先降噪
    Mat blur;
    GaussianBlur(mat, blur, Size(5, 5), BORDER_DEFAULT, BORDER_DEFAULT);

    // 边缘梯度增强（保存图片）x,y 增强
    Mat gard_x, gard_y;
    Scharr(blur, gard_x, CV_32F, 1, 0);
    Scharr(blur, gard_y, CV_32F, 0, 1);
    Mat abs_gard_x, abs_gard_y;
    convertScaleAbs(gard_x, abs_gard_x);
    convertScaleAbs(gard_y, abs_gard_y);
    Mat gard;
    addWeighted(abs_gard_x, 0.5, abs_gard_y, 0.5, 0, gard);

    // 二值化，筛选轮廓
    Mat gray;
    cvtColor(gard, gray, COLOR_BGRA2GRAY);
//    imwrite("/storage/emulated/0/card_n.jpg",gray);

    Mat binary;
    threshold(gray, binary, 40, 255, THRESH_BINARY);

    // 稍微知道这么个概念，card.io  很多图像过滤
    vector<vector<Point> > contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    for (int i = 0; i < contours.size(); i++) {
        Rect rect = boundingRect(contours[i]);
        // 过滤轮廓
        if (rect.width > mat.cols / 2 && rect.width != mat.cols && rect.height > mat.rows / 2) {
            // 银行卡区域的宽高必须大于图片的一半
            area = rect;
            break;
        }
    }

    return 0;
}