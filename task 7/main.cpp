#include "list.h"
#include "queue.h"
#include "stack.h"

int main()
{
    queue l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);
    l.pop();
    queue l2;
    queue& ss = l;
    l2 = ss;
    std::cout << l2 << std::endl;
    std::cout << l2.size() << std::endl;


    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    stack s2(s);
    std::cout << s2 << std::endl;
    std::cout << s2.size() << std::endl;
    return 0;
}