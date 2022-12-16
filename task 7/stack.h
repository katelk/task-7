#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "list.h"

class stack : public list
{
public:

    // конструктор пустого списка
    stack() : top(nullptr) {};

    // конструктор копирования
    stack(const stack& a);

    // конструктор перемещения
    stack(stack&& a) : top(a.top) { a.top = nullptr; };

    ~stack() { while (top != nullptr) (*this).pop(); }

    void free() override { while (top) (*this).pop(); }

    void push(int e);

    int pop() override;

    const int& getFront() const override
    {
        if (!top) throw STACK_UNDERFLOW;
        return top->data;
    }

    int isEmpty() const override { return top == nullptr; }

    size_t size() const override;

    list& operator = (const list& a);

    stack& operator = (const stack& a);

    stack& operator = (stack&& a);

    iterator begin() override { return iterator(top); };
    iterator end() override { return iterator(); };

    const_iterator cbegin() const override { return const_iterator(top); };
    const_iterator cend() const override { return const_iterator(); };

    const_iterator begin() const override { return const_iterator(top); };
    const_iterator end() const override { return const_iterator(); };

private:
    node* top;
};

#endif // STACK_H_INCLUDED
