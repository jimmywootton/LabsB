#ifndef SORTEDSET_H
#define SORTEDSET_H

#include "IntList.h"
class SortedSet: public IntList
{
    public:
        SortedSet();
        SortedSet(const SortedSet& );
        SortedSet(const IntList& );
        ~SortedSet();
        bool in(int value);
        SortedSet & operator|(SortedSet &);
        SortedSet & operator&(SortedSet &);
        void add(int data);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);
        SortedSet & operator|=(SortedSet &);
        SortedSet & operator&=(SortedSet &);
};
#endif
