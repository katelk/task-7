#include "stack.h"

Stack::Stack(const Stack& a) : top(new node)
{
    node* t = a.top;
    node** n = &top;

    while (t != nullptr)
    {
        *n = new node;

        (*n)->data = t->data;
        (*n)->next = nullptr;
        n = &((*n)->next);
        t = t->next;
    }
}

void Stack::push(int e)
{
    node* t = new node;

    t->data = e;
    t->next = top;
    top = t;
}

int Stack::pop()
{
    if (!top) throw STACK_UNDERFLOW;

    node* t = top;
    int e = t->data;

    top = t->next;
    delete t;

    return e;
}

size_t Stack::size() const
{
    size_t n = 0;
    node* t = top;

    while (t != nullptr)
    {
        n++;
        t = t->next;
    }
    return n;
}

List& Stack::operator = (const List& a)
{
    if (this == &a) return *this;
    const Stack& a2 = dynamic_cast<const Stack&>(a);


    node* t = a2.top;
    node** n = &top;

    while (t != nullptr)
    {
        *n = new node;

        (*n)->data = t->data;
        (*n)->next = nullptr;
        n = &((*n)->next);
        t = t->next;
    }

    return *this;
}


Stack& Stack::operator = (const Stack& a)
{
    if (this == &a) return *this;

    (*this).free();

    node* t = a.top;
    node** n = &top;

    while (t != nullptr)
    {
        *n = new node;

        (*n)->data = t->data;
        (*n)->next = nullptr;
        n = &((*n)->next);
        t = t->next;
    }
    return *this;
}

Stack& Stack::operator = (Stack&& a)
{
    this->free();
    delete top;
    top = a.top;
    a.top = nullptr;
    return *this;
}

