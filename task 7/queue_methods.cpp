#include "queue.h"
Queue::Queue(const Queue& a) : head(nullptr), tail(nullptr)
{
    node* t = a.head;

    while (t != nullptr)
    {
        node* n = new node;
        n->data = t->data;
        n->next = nullptr;
        if (head == nullptr) head = n;
        else tail->next = n;
        tail = n;
        t = t->next;
    }
}

void Queue::push(int e)
{
    node* n = new node;
    n->data = e;
    n->next = nullptr;
    if (head == nullptr) head = n;
    else tail->next = n;
    tail = n;
}

int Queue::pop()
{
    node* t = head;
    if (t == nullptr) throw STACK_UNDERFLOW;
    int e = t->data;

    head = t->next;
    delete t;

    if (head == nullptr) tail = nullptr;

    return e;
}

size_t Queue::size() const
{
    size_t n = 0;
    node* t = head;

    while (t != nullptr)
    {
        n++;
        t = t->next;
    }

    return n;
}

List& Queue::operator = (const List& a)
{
    if (this == &a) return *this;
    const Queue& a2 = dynamic_cast<const Queue&>(a);

    node* t = a2.head;

    while (t != nullptr)
    {
        node* n = new node;
        n->data = t->data;
        n->next = nullptr;
        if (head == nullptr) head = n;
        else tail->next = n;
        tail = n;
        t = t->next;
    }

    return *this;
}


Queue& Queue::operator = (const Queue& a)
{
    if (this == &a) return *this;

    (*this).free();

    node* t = a.head;
    while (t != nullptr)
    {
        (*this).push(t->data);
        t = t->next;
    }
    return *this;
}

Queue& Queue::operator = (Queue&& a)
{
    this->free();
    delete head;
    delete tail;
    head = a.head;
    tail = a.tail;
    a.head = nullptr;
    a.tail = nullptr;
    return *this;
}