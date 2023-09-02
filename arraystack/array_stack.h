
#ifndef H_ARRAY_STACK_H
#define H_ARRAY_STACK_H

#include <stdlib.h>
#include <assert.h>
#include <iostream>
#define internal_allocate malloc
#define internal_deallocate free

typedef struct internal_hook {
    void* (*allocate)(size_t size);
    void (*deallocate)(void *pointer);
}internal_hook;


template<class T>
class ArrayStack {
public:
    ArrayStack(int size = 10);
    ~ArrayStack();
    void StackPush(T data);
    T StackPop();
    T StackTop();
    bool IsEmpty();
    T GetPosStackItme(int pos);
    static internal_hook m_hook;

private:
    T* m_item;
    int m_capacity;
    int m_size;
};

template<class T>
internal_hook ArrayStack<T>::m_hook = { internal_allocate,  internal_deallocate};


/*
    1. 默认参数在声明时指定
    2. 类模板构造析构函数实现放在头文件中
*/
template<class T>
ArrayStack<T>::ArrayStack(int size) 
    :m_item(nullptr), m_capacity(size), m_size(0) 
{
    m_item = new T[size];
    if (nullptr == m_item) {
        std::cout << "allocate error\n";
    }
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    if (m_item) {
        delete[] m_item;
        m_item = nullptr;
    }
    
}

template<class T>
void ArrayStack<T>::StackPush(T data)
{
    assert(m_item);
    if (m_size >= m_capacity) {
        std::cout<< "stack is full!\n";
        return ;
    }
    m_item[m_size++] = data;
}

template<class T>
bool ArrayStack<T>::IsEmpty()
{
    return m_size == 0;
}

template<class T>
T ArrayStack<T>::StackPop()
{
    assert(m_item);
    if (m_size <= 0) {
        std::cout << "stack is empty\n";
        return 0;
    }
    return m_item[--m_size]; 
}

template<class T>
T ArrayStack<T>::StackTop()
{
    assert(m_item);
    if (m_size <= 0) {
        std::cout << "stack is empty\n";
        return 0;
    }
    return m_item[m_size - 1]; 
}

template<class T>
T ArrayStack<T>::GetPosStackItme(int pos)
{
    assert(m_item);
    if (pos < 0 || pos > m_capacity) {
        return 0;
    }
    return m_item[pos - 1];
}

#endif








