
#ifndef H_ARRAY_STACK_H
#define H_ARRAY_STACK_H

#include <stdlib.h>
#define internal_allocate malloc
#define internal_deallocate free

typedef struct internal_hook {
    void* (*allocate)(size_t size);
    void (*deallocate)(void *pointer);
}internal_hook;


template<class T>
class ArrayStack {
public:
    ArrayStack(int size);
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



#endif








