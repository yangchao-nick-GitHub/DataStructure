#include "link_stack.h"
#include <iostream>

int main()
{
    const char* arr[] = {"123", "456", "789"};
    LinkStack stack;
    stack.StackPush((void*)arr[0]);
    stack.StackPush((void*)arr[1]);
    stack.StackPush((void*)arr[2]);
    char *str = (char*)stack.GetPosStackItem(3);
    std::cout << str << std::endl;
    std::cout << stack.StackSize() << std::endl;
    std::cout << stack.IsEmpty() << std::endl;
    stack.StackPop();
    stack.StackPop();
    stack.StackPop();
    std::cout << stack.StackSize() << std::endl;
    std::cout << stack.IsEmpty() << std::endl;

    return 0;
}

