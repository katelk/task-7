#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <cstddef>

enum ERR_CODE { STACK_UNDERFLOW };

struct node
{
    int data;
    struct node* next;
};

class list
{
public:
    virtual void push(int e) = 0;
    virtual int pop() = 0;
    virtual const int& getFront() const = 0;
    virtual int isEmpty() const = 0;
    virtual size_t size() const = 0;
    virtual list& operator = (const list& a) = 0;
    virtual void free() = 0;
    friend std::ostream& operator <<(std::ostream& stream, list& a)
    {
        a.print(stream);
        return stream;
    }
    friend std::istream& operator >> (std::istream& in, list& a)
    {
        int e;
        in >> e;
        a.push(e);
        return in;
    }

    class iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;

        iterator(node* curr_node = nullptr) : curr_node(curr_node) {}

        int operator*() const { return curr_node->data; }
        int& operator -> () { return curr_node->data; }

        iterator& operator++() {
            curr_node = curr_node->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator r = *this;
            curr_node = curr_node->next;
            return r;
        }

        bool operator!=(const iterator& other) const {
            return curr_node != other.curr_node;
        }

        bool operator==(const iterator& other) const {
            return curr_node == other.curr_node;
        }

    private:
        node* curr_node;
    };

    virtual iterator begin() = 0;
    virtual iterator end() = 0;

    class const_iterator {
    public:
        using iterator_category = std::forward_iterator_tag;

        const_iterator(const node* curr_node = nullptr) : curr_node(curr_node) {}

        int operator*() const { return curr_node->data; }
        const int& operator -> () { return curr_node->data; }

        const_iterator& operator++() {
            curr_node = curr_node->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator r = *this;
            curr_node = curr_node->next;
            return r;
        }

        bool operator!=(const const_iterator& other) const {
            return curr_node != other.curr_node;
        }

        bool operator==(const const_iterator& other) const {
            return curr_node == other.curr_node;
        }

    private:
        const node* curr_node;
    };

    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;

protected:
    virtual void print(std::ostream& stream) const = 0;
};

#endif // LIST_H_INCLUDED

