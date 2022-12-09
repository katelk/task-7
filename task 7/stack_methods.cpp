#include "stack.h"

stack::stack(const stack& a) : top(new node)
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

void stack::push(int e)
{
    node* t = new node;

    t->data = e;
    t->next = top;
    top = t;
}

int stack::pop()
{
    if (!top) throw STACK_UNDERFLOW;

    node* t = top;
    int e = t->data;

    top = t->next;
    delete t;

    return e;
}

size_t stack::size() const
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

list& stack::operator = (const list& a)
{
    if (this == &a) return *this;
    const stack& a2 = dynamic_cast<const stack&>(a);


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

void stack::print(std::ostream& stream) const
{
    for (const_iterator it = (*this).cbegin(); it != (*this).cend(); ++it)
    {
        stream << *it << " ";
    }
}

stack& stack::operator = (const stack& a)
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

stack& stack::operator = (stack&& a)
{
    this->free();
    delete top;
    top = a.top;
    a.top = nullptr;
    return *this;
}

