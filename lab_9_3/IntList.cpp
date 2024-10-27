#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}


   ostream & operator<<(ostream &out, const IntList &rhs) 
   {
        if (rhs.head == 0) 
        {
            return out;
        }
        operator<<(out, rhs.head);
        return out;
   }


   bool IntList::exists(int value) const
    {
       
        if (head == 0) {
            return false;
        }
        if (head -> value == value) {
            return true;
        }
        return exists(head -> next, value);
        
   }
   
   bool IntList::exists(IntNode *temp, int value) const {
       
        if (temp == 0) {
            return false;
        }
        if (temp -> value == value)
        {
            return true;
        }
        return exists(temp ->next, value);
        
   }
   
   
ostream & operator<<(ostream &out, IntNode * rhs) {
    if (rhs == 0) {
            return out;
    }
    out << rhs -> value;
    if (rhs -> next != 0) {
            out << " ";
    }
    operator<<(out, rhs -> next);
    return out;
}