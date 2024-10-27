#include <iostream>
using namespace std;

#include "SortedSet.h"
SortedSet::SortedSet():IntList ()
{
    head = 0;
    tail = 0;
}
SortedSet::SortedSet(const SortedSet &m):IntList(m)
{}

SortedSet::SortedSet(const IntList &m):IntList(m)
{
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet()
{}

bool SortedSet::in(int value)
{
    IntNode* current = head;
    while (current != nullptr)
    {
        if (value == current -> value)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
}

SortedSet & SortedSet::operator|(SortedSet & set)
{
    IntList newList;
    IntNode* current = head;
    while (current != nullptr)
    {
        newList.push_back(current -> value);
        current = current -> next;
    }
    current = set.head;
    while (current != nullptr)
    {
        newList.push_back(current -> value);
        current = current -> next;
    }
    newList.remove_duplicates();
    SortedSet* newSet = new SortedSet(newList);
    return *newSet;
}

SortedSet & SortedSet::operator&(SortedSet & set) 
{
	SortedSet* newSet = new SortedSet();
	
	IntNode* current = head;
	while (current != nullptr) {
		if (in(current -> value) && set.in(current -> value)) {
			newSet -> push_back(current -> value);
		}
		current = current -> next;
	}
	
	current = set.head;
	while (current != nullptr) {
		if (in(current -> value) && set.in(current -> value) && !newSet -> in(current -> value)) {
			newSet -> push_back(current -> value);
		}
		current = current -> next;
	}
	
	return *newSet;
}

void SortedSet::add(int value) 
{
	if (!in(value) ) 
    {
		IntList::insert_ordered(value);
	}
}

void SortedSet::push_front(int value) {
	add(value);
}

void SortedSet::push_back(int value) {
	add(value);
}

void SortedSet::insert_ordered(int value) {
	add(value);
}

SortedSet & SortedSet::operator|=(SortedSet & set)
{
    SortedSet* sset = new SortedSet();
    sset = &(*this | set);
    
    clear();
    
    IntNode* current = sset -> head;
    while (current != nullptr) {
        this -> push_back(current -> value);
        current = current -> next;
    }
    
    return *sset;
}

SortedSet & SortedSet::operator&=(SortedSet & set)
{
    SortedSet* sset = &(*this & set);
	
	clear();
	
	IntNode* current = sset -> head;
	while (current != nullptr) {
		this -> push_back(current -> value);
		current = current -> next;
	}
	
	return *sset;
}