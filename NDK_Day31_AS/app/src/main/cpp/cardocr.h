//
// Created by hcDarren on 2018/7/28.
//

#ifndef NDK_DAY31_AS_CARDOCR_H
#define NDK_DAY31_AS_CARDOCR_H

#include "opencv2/opencv.hpp"

using namespace cv;

// 会针对不同的场景，做不同的事情
namespace co1 {
    /**
     * 找到银行卡区域
     * @param mat 图片的 mat
     * @param area 卡号区域
     * @return 是否成功 0 成功，其他失败
     */
    int find_card_area(const Mat &mat, Rect &area);
}

/**
 * 备选方案
 */
namespace co2 {

}


#endif //NDK_DAY31_AS_CARDOCR_H
