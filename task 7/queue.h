#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "list.h"

class queue : public list
{
public:

    // конструктор пустого списка
    queue() : head(nullptr), tail(nullptr) {};

    // конструктор копирования
    queue(const queue& a);

    // конструктор перемещения
    queue(queue&& a) : head(a.head), tail(a.tail)
    {
        a.head = nullptr;
        a.tail = nullptr;
    };

    ~queue() { while (head != nullptr) (*this).pop(); }

    void free() override { while (head) (*this).pop(); }

    void push(int e) override;

    int pop();

    const int& getFront() const override
    {
        if (!head) throw STACK_UNDERFLOW;
        return head->data;
    }

    int isEmpty() const override { return head == nullptr; };

    size_t size() const override;

    list& operator = (const list& a);

    queue& operator = (const queue& a);

    queue& operator = (queue&& a);

    iterator begin() override { return iterator(head); };
    iterator end() override { return iterator(); };

    const_iterator cbegin() const override { return const_iterator(head); };
    const_iterator cend() const override { return const_iterator(); };

    const_iterator begin() const override { return const_iterator(head); };
    const_iterator end() const override { return const_iterator(); };

private:
    node* head;
    node* tail;
};

#endif // QUEUE_H_INCLUDED
