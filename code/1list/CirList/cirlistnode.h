#ifndef CIRLISTNODE_H
#define CIRLISTNODE_H
#include "cirlistnode.h"

template<class T>
class CirListNode
{
public:

    T data;
    CirListNode *next;
    CirListNode() = default;
    CirListNode(T data, CirListNode *next = nullptr) : data(data),
        next(next)
    {
    }
};

#endif // CIRLISTNODE_H
