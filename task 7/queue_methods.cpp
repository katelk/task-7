#include "queue.h"
queue::queue(const queue& a) : head(nullptr), tail(nullptr)
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

void queue::push(int e)
{
    node* n = new node;
    n->data = e;
    n->next = nullptr;
    if (head == nullptr) head = n;
    else tail->next = n;
    tail = n;
}

int queue::pop()
{
    node* t = head;
    if (t == nullptr) throw STACK_UNDERFLOW;
    int e = t->data;

    head = t->next;
    delete t;

    if (head == nullptr) tail = nullptr;

    return e;
}

size_t queue::size() const
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

list& queue::operator = (const list& a)
{
    if (this == &a) return *this;
    const queue& a2 = dynamic_cast<const queue&>(a);

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


queue& queue::operator = (const queue& a)
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

queue& queue::operator = (queue&& a)
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