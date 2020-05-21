#include <jni.h>
#include <string>
#include <android/log.h>
#include "ArrayUtil.cpp"
// 补讲一个知识点
// 结构体区别名
#define TAG "TAG"
// 方法进行 define   LOGE(...参数)  -> __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
// 重要一个点
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
// 其他方法的定义 __android_log_print 取了一个别名 （参数固定，可变）
using namespace std;


void print_array(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        // 这个方法比较复杂
        LOGE("%d", arr[i]);
    }
}

// 冒泡排序：思想：相邻两个数进行比较，如果前面的比后面的大，就进行交换，否则不需要交换
// 能写  ， 时间复杂度，空间复杂度   O（n的平方）
// 能优化  下周  ，网上有两种优化方法 作业 （鸡尾酒排序，标志位）
// 第三种思路：遍历的过程中可以记录一下位置  思想了解
void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) { //  n-1 步
        // j < len - i - 1
        for (int j = 0; j < len - i - 1; ++j) { // n-1, n-2 ,n - 3, 1
            if (arr[j] > arr[j + 1]) {
                // 交换 一次交换是三次赋值
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void optimizeBubbleSort(int arr[], int len) {
    // 记录上一次的最后遍历的位置
    int n = len;
    int newn = 0;// 控制位置
    do {
        newn = 0;
        for (int i = 1; i < n; ++i) {// 遍历最后的位置
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                // 记录最后徐一次交换的位置
                newn = i;
            }
        }
        n = newn;
    } while (n > 0);
}
void insertSort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0  ; --j) {
            if(arr[j] < arr[j - 1]){
                swap(arr[j], arr[j - 1]);
            }else{
                break;
            }

        }
    }
}
// 插入排序 - 前身
/*
void insertSort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}
*/

void insertSort(int arr[], int len) {
    int j, i;
    for (i = 1; i < len; ++i) {// O(n)
        // 当前的位置
        int tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; --j) {
            arr[j] = arr[j - 1];
        }
        // 插入合适的位置
        arr[j] = tmp;
    }
}

// 希尔排序思想：对插入排序分组 过一下
void shellInsertSort(int arr[], int len) {// 8
    // 思考？  作业，求算法复杂度，
    int increment = len / 2; // 4 组
    int i, j, k;
    while (increment >= 1) {
        // 希尔排序
        for (i = 0; i < increment; ++i) { // i = 0, increment = 2
            for (j = i + increment; j < len; j += increment) {
                int tmp = arr[j];// 5
                // k = j = 6
                for (k = j; k > 0 && arr[k - increment] > tmp; k -= increment) {
                    // 往后逻动
                    arr[k] = arr[k - increment];
                }
                // k是有问题的
                LOGE("temp = %d,%d,%d,%d", tmp, k, j, increment);
                arr[k] = tmp;
                // k = 5
                // print_array(arr, len);
                // LOGE("------------------");
            }
        }
        increment /= 2;
    }
}

// 选择：思想 遍历找出最小的位置，最后与第一个位置进行交换 O(1)
void selectSort(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}


extern "C"
JNIEXPORT jstring

JNICALL
Java_com_darren_ndk_day35_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    // 测试, 取时间 ， 两个算法
    int len = 10;
    // 创建的时接近排好序的数据
    int *arr = ArrayUtil::create_nearly_ordered_array(len, 2);
    print_array(arr, len);
    LOGE("------------------1");
    int *arr1 = ArrayUtil::copy_random_array(arr, len);
    int *arr2 = ArrayUtil::copy_random_array(arr, len);
    int *arr3 = ArrayUtil::copy_random_array(arr, len);
    // optimizeBubbleSort 提取终止循环 ，选择好一点？
    //ArrayUtil::sort_array("optimizeBubbleSort", optimizeBubbleSort, arr2, len);
    //ArrayUtil::sort_array("bubbleSort", bubbleSort, arr, len);// 5
    ArrayUtil::sort_array("selectSort", selectSort, arr1, len);// 2 O(n2)
    ArrayUtil::sort_array("insertSort", insertSort, arr3, len);// 3 提前终止循环
    ArrayUtil::sort_array("shellInsertSort", shellInsertSort, arr, len);
    // 如果对于接近拍好序的数据，时间复杂度最优 O(n)，考虑最坏的情况 O(n2)
    print_array(arr, len);
    // ? 思考  3 次课 ，冒泡的优化，插入排序，希尔排序，怎样去看 log 日志  O(n平方)
    // 为什么会慢？
    delete[](arr);
    delete[](arr1);
    delete[](arr2);
    delete[](arr3);
    // 对性能进行测试  看错误日志
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


