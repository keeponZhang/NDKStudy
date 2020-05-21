//
// Created by hcDarren on 2018/6/24.
//

#ifndef NDK_DAY252_ARRAYLIST_H
#define NDK_DAY252_ARRAYLIST_H

#include <malloc.h>
#include <android/log.h>

//-------------------- 声明 -----------------------//

template<class E>
class ArrayList {
private:
    // 长度，数组，当前角标
    E *array = NULL;// 当前数组的指针
    int len = 0;// 数组大小
    int index = 0;// 当前角标
public:
    ArrayList();

    ArrayList(int len);

    void add(E e);

    E remove(int index);

    E get(int index);

    ~ArrayList();

    int size();

    // 拷贝构造函数

private:
    void ensureCapacityInternal(int capacity);

    void grow(int capacity);
};

//-------------------- 实现 -----------------------//

template<class E>
ArrayList<E>::ArrayList() {}

// 每次实现方法都得添加
template<class E>
ArrayList<E>::ArrayList(int len) {
    if (len <= 0) {
        return;
    }
    this->len = len;
    this->array = (E *) malloc(sizeof(E) * len);
}

template<class E>
ArrayList<E>::~ArrayList() {
    __android_log_print(ANDROID_LOG_ERROR,"TAG","析构函数");
    if (this->array) {
        free(this->array);
        this->array = NULL;
    }
}

template<class E>
int ArrayList<E>::size() {
    return this->index;
}

template<class E>
void ArrayList<E>::add(E e) {
    ensureCapacityInternal(index + 1);  // Increments modCount!!
    this->array[index++] = e;
}

template<class E>
void ArrayList<E>::ensureCapacityInternal(int capacity) {
    if (this->array == NULL) {
        capacity = 10;
    }
    if (capacity - len > 0) {
        // 创建新的数组
        grow(capacity);
    }
}

// 扩容数组的大小
template<class E>
void ArrayList<E>::grow(int capacity) {
    // 扩容
    int new_len = len + (len >> 1);
    if (capacity - new_len > 0) {
        new_len = capacity;
    }

    // 创建新的数组
    E *new_arr = (E *) malloc(sizeof(E) * new_len);

    if (this->array) {
        // 原来的数据拷贝进来
        memcpy(new_arr,this->array, sizeof(E) * index);// sizeof(E)*index 字节
        free(this->array);// 内存泄漏
    }

    this->array = new_arr;
    this->len = new_len;
}

template<class E>
E ArrayList<E>::get(int index) {
    return this->array[index];
}

template<class E>
E ArrayList<E>::remove(int index) {
    // 自己做 remove 和 拷贝构造函数
}

#endif //NDK_DAY252_ARRAYLIST_H
