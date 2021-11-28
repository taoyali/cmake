#include <iostream>
#include "intSLList.h"

IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty(); )
    {
        p = head->next;
        delete head;
        head = p;       
    }
}

void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el, head);
    if (tail == 0)
    {
        tail = head;
    }    
}


void IntSLList::addToTail(int el) {
    if (tail != 0)
    {
        tail->next = new IntSLLNode(el, 0);
        tail = tail->next;
    } else {
        head = tail = new IntSLLNode(el, 0);
    }
}

int IntSLList::deleteFromHead() {
    int info = head->info;
    IntSLLNode *tmp = head;
    if (head == tail) {
        head = tail = 0;
    } else {
        head = head->next;
    }
    delete tmp;
    return info;
}

int IntSLList::deleteFromTail() {
    int info = tail->info;
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        IntSLLNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)    // 没有执行体，tmp = tmp->next就是需要的逻辑
        delete tail;
        tail = tmp;
        tail->next = 0;
        
        tail = 0;
    }
    return info;
}

void IntSLList::deleteNode(int el) {
    if (head != 0) {
        if (head == tail && el == head->info) {
            delete head;
            head = tail = 0;
        } else if (el == head->info)
        {
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;
        } else {
            IntSLLNode *pre, *tmp;
            for (pre = head, tmp = head->next; 
                tmp != 0 && tmp->info != el; pre = pre->next, tmp = tmp->next);
        
            if (tmp != 0)
            {
                pre->next = tmp->next;
                if (tmp == tail)
                {
                    tail = pre;
                }
                delete tmp;
            }
        }
    }
}

bool IntSLList::isInList(int el) const {
    IntSLLNode *node;
    for (node = head; node != 0 && el != node->info; node = node->next);
    return node != 0;
}