#include <iostream>
using namespace std;

#define STACK_MAX_SIZE 10
typedef void* StackType;
#define internal_allocate malloc
#define internal_allocate free



template<class T>
class ArrayStack {
public:
    typedef struct internal_hook {
        void* (*allocate)(size_t size);
        void (*deallocate)(void *pointer);
    }internal_hook;
    ArrayStack(int size = 100);
    ~ArrayStack();
    void StackPush(T data);
    T StackPop();
    T StackTop();
    bool IsEmpty();
    static internal_hook m_hook;

private:
    

    T* m_item;
    int m_capacity;
    int m_size;
};

template<class T>
ArrayStack<T>::ArrayStack(int size)
{
    m_capacity = size;
    m_size = 0;
    T *m_item = new T[m_capacity];
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
ArrayStack<T>::m_hook = { internal_allocate,  internal_allocate};



int main()
{
    ArrayStack<int> stack(10);
    return 0;
}