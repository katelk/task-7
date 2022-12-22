#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "list.h"

class Stack : public List
{
public:

    // конструктор пустого списка
    Stack() : top(nullptr) {};

    // конструктор копирования
    Stack(const Stack& a);

    // конструктор перемещения
    Stack(Stack&& a) : top(a.top) { a.top = nullptr; };

    ~Stack() { while (top != nullptr) (*this).pop(); }

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

    List& operator = (const List& a);

    Stack& operator = (const Stack& a);

    Stack& operator = (Stack&& a);

    const_iterator cbegin() const override { return const_iterator(top); };
    const_iterator cend() const override { return const_iterator(); };

    const_iterator begin() const override { return const_iterator(top); };
    const_iterator end() const override { return const_iterator(); };

    iterator begin() override { return iterator(top); };
    iterator end() override { return iterator(); };

private:
    node* top;
};

#endif // STACK_H_INCLUDED
