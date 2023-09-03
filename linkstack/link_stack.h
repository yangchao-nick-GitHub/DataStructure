#ifndef LINK_STACK_H
#define LINK_STACK_H

#include <stdlib.h>
#include <iostream>

typedef void* DATATYPE;

typedef struct StackNode {
public:
    StackNode():m_data(nullptr), m_next(nullptr) {};
    StackNode(DATATYPE data):m_data(data), m_next(nullptr) {};
    DATATYPE m_data;
    StackNode *m_next;
    
}StackNode;

class LinkStack {
public:
    LinkStack();
    ~LinkStack();
    bool IsEmpty();
    size_t StackSize();
    void StackPush(DATATYPE data);
    DATATYPE StackPop();
    DATATYPE StackTop();
    DATATYPE GetPosStackItem(size_t pos);

private:
    StackNode* AllocateNode(DATATYPE data);
    struct StackNode *m_head;
    size_t m_size;
};

LinkStack::LinkStack()
{
    m_head = AllocateNode(nullptr);
    if (nullptr == m_head) {
        std::cout << "LinkStack error" << std::endl;
        return ;
    }
    m_size = 0;
}

LinkStack::~LinkStack()
{
    struct StackNode *pre = NULL;
    struct StackNode *cur = NULL;
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

size_t LinkStack::StackSize()
{
    return m_size;
}

bool LinkStack::IsEmpty()
{
    return m_size == 0;
}

StackNode* LinkStack::AllocateNode(DATATYPE data)
{
    StackNode *node = new StackNode();
    if (nullptr == node) {
        std::cout << "AllocateNode error" << std::endl;
        return nullptr;
    }
    node->m_data = data;
    node->m_next = nullptr;
    return node;
}

void LinkStack::StackPush(DATATYPE data) // 前插法
{
    if (nullptr == m_head) {
        return ;
    }
    StackNode *node = AllocateNode(data);
    if (nullptr == node) {
        std::cout << "StackPush error" << std::endl; 
        return ;
    }
    node->m_next = m_head->m_next;
    m_head->m_next = node;
    m_size++;
}

DATATYPE LinkStack::StackPop()
{
    if (nullptr == m_head) {
        std::cout << "StackPop error" << std::endl;
        return nullptr;
    }
    StackNode *top = m_head->m_next;
    if (nullptr == top) {
        return nullptr;
    }
    m_head->m_next = top->m_next;
    DATATYPE data = top->m_data;
    free(top);
    top = nullptr;
    m_size--;
    return data;
}

DATATYPE LinkStack::StackTop()
{
    if (nullptr == m_head) {
        std::cout << "StackTop error" << std::endl;
        return nullptr;
    }
    return m_head->m_next->m_data;
}

DATATYPE LinkStack::GetPosStackItem(size_t pos) // pos:1 - size;
{
    if (nullptr == m_head) {
        return nullptr;
    }
    if (pos < 1 || pos > m_size) {
        return nullptr;
    }
    size_t tmp_pos = 0;
    StackNode *cur = m_head;
    while (cur != NULL) {
        cur = cur->m_next;
        tmp_pos++;
        if (tmp_pos == pos) {
            break;
        }
    }
    if (tmp_pos != pos) {
        return nullptr;
    }
    return cur->m_data;
}

#endif
