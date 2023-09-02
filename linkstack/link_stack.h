#ifndef LINK_STACK_H
#define LINK_STACK_H

#include <stdlib.h>
#include <iostream>
template<class T>
struct StackNode {
public:
    StackNode(T data):m_data(data), m_next(nullptr) {};
    T m_data;
    struct StackNode<T> *m_next;
};

template<class T>
class LinkStack {
public:
    LinkStack();
    ~LinkStack();
private:
    struct StackNode<T> *m_head;
    int m_size;
};

template<class T>
LinkStack<T>::LinkStack()
{
    m_head = new struct StackNode<T>;
    if (nullptr == m_head) {
        std::cout << "LinkStack error!";
    }
    m_size = 0;
}

template<class T>
LinkStack<T>::~LinkStack()
{
    struct StackNode<T> *pre = NULL;
    struct StackNode<T> *cur = NULL;
    if (nullptr == m_head) {
        return ;
    }

    cur = m_head->m_next;
    while (cur != NULL) {
        pre = cur;
        cur = cur->m_next;
        free(pre);
    }

    free(m_head);
}

#endif