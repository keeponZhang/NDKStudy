//
// Created by hcDarren on 2018/8/5.
//

#ifndef NDK_DAY34_AS_LINKEDLIST_HPP
#define NDK_DAY34_AS_LINKEDLIST_HPP

#include <assert.h>

// 单链表节点
template<class E>
struct Node {
    Node<E> *next;
    Node<E> *prev;
    E value;

public:
    Node(E value, Node<E> *prev, Node<E> *next) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
    Node(E value,  Node<E> *next) {
        this->value = value;

        this->prev = prev;
    }
};

// list
template<class E>
class LinkedList {
public:
    // 头指针
    Node<E> *head = NULL;
    // 集合的长度
    int len = 0;
    /**
     * 尾节点（最后）
     */
    Node<E> *last = NULL;

public:
    /**
     * 添加数据
     * @param e 元素
     */
    void push(E e);

    int size();

    E get(int index);

    // remove insert
    void insert(int index, E e);

    E remove(int index);

    ~LinkedList();

    Node<E> *node(int i);

    void linkLast(E e);

    void linkBefore(Node<E> *pNode, E e);

    E unlink(Node<E> *pNode);
};

template<class E>
void LinkedList<E>::push(E e) {
    // 双向链表添加一个数据
    linkLast(e);
    // 单向向链表添加一个数据
//    Node<E> *new_node = new Node<E>(e, NULL);
//    if (head) {// 0 -> 1 -> 2 -> 3
////如果是单向链表，需要找到last节点
//        // 方法1:找到尾巴节点，有一个特定就是 next 节点为空
////       Node<E>* h = head;
////        while(h){
////            if(h->next == NULL){
////                break;
////            }
////            h = h->next;
////        }
//        //此时h为为节点
//   //     Node<E> *last = h;
////        last->next = new_node;
//        // 每一次都需要找到最后一个节点  50000
//        // 记录 last 节点
//// 方法2:找到尾巴节点
////         Node<E> *last = node(len - 1);
////         last->next = new_node;// O(1)
////如果是双向链表，直接给last节点赋值
//        last->next = new_node;
//    } else {
//        head = new_node;
//    }
//    last = new_node;

    len++;
}

template<class E>
Node<E> *LinkedList<E>::node(int index) { // O(n)
    if(index < len >> 1){
        // 从前往后变量
        Node<E> *cur = head;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur;
    }
    else{
        // 从后往前遍历
        Node<E> *cur = last;
        for (int i = len - 1; i > index; i--) {
            cur = cur->prev;
        }
        return cur;
    }
}

template<class E>
int LinkedList<E>::size() {
    return len;
}

template<class E>
E LinkedList<E>::get(int index) {
    assert(index >= 0 && index < len);
    return node(index)->value;
}

template<class E>
void LinkedList<E>::insert(int index, E e) {// len = 4
    assert(index >= 0 && index <= len);
    // 考虑边界  0
    if (index == len) {
        linkLast(e);
    } else {
        linkBefore(node(index), e);
    }

    /*Node<E> *new_node = new Node<E>(e, NULL);
    if (index == 0) {
        Node<E> *h = head;
        head = new_node;
        new_node->next = h;
    } else {
        // 考虑最后一个位置
        Node<E> *prev = node(index - 1);
        Node<E> *next = prev->next;// NULL
        prev->next = new_node;
        new_node->next = next;
    }*/

    len++;
}

template<class E>
E LinkedList<E>::remove(int index) {
    // 考虑边界问题  0  ， len , mid
    assert(index >= 0 && index < len);

    return unlink(node(index));

    /*if (index == 0) {
        Node<E> *h = head;
        head = h->next;
        // 释放
        delete h;
    } else {
        Node<E> *prev = node(index - 1);
        // 删除的节点
        Node<E> *cur = prev->next;
        prev->next = cur->next;
        delete cur;
    }*/
}

template<class E>
LinkedList<E>::~LinkedList() {
    // 析构释放内存 ？
}

template<class E>
void LinkedList<E>::linkLast(E e) {
    Node<E> *l = last;
    Node<E> *new_node = new Node<E>(e, l, NULL);
    last = new_node;

    if (head) {
        l->next = new_node;
    } else {
        head = new_node;
    }
}

template<class E>
void LinkedList<E>::linkBefore(Node<E> *cur, E e) {
    Node<E> *prev = cur->prev;// NULL
    Node<E> *new_node = new Node<E>(e, prev, cur);
    // 当前的上一个节点 = 新增的节点
    cur->prev = new_node;
    // 上一个节点的 next -> 新增的节点  , 0 特殊处理
    if (prev) {
        prev->next = new_node;
    } else {// 0
        head = new_node;
    }
}

template<class E>
E LinkedList<E>::unlink(Node<E> *cur) {
    // 左右两个节点
    Node<E> *prev = cur->prev;
    Node<E> *next = cur->next;

    E value = cur->value;

    // 有两个为空的情况， 严谨 ，思维灵活
    if(prev){
        prev->next = next;
    } else {
        head = next;
    }

    if(next){
        next->prev = prev;
    } else {
        last = prev;
    }

    delete cur;
    len--;
    return value;
}

#endif //NDK_DAY34_AS_TEST_H