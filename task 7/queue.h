#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "list.h"

class Queue : public List
{
public:

    // конструктор пустого списка
    Queue() : head(nullptr), tail(nullptr) {};

    // конструктор копирования
    Queue(const Queue& a);

    // конструктор перемещения
    Queue(Queue&& a) : head(a.head), tail(a.tail)
    {
        a.head = nullptr;
        a.tail = nullptr;
    };

    ~Queue() { while (head != nullptr) (*this).pop(); }

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

    List& operator = (const List& a);

    Queue& operator = (const Queue& a);

    Queue& operator = (Queue&& a);

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
