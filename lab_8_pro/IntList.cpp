#include <iostream>

using namespace std;

#include "IntList.h"

IntList::IntList() 
{
	head = nullptr;
	tail = nullptr;
}

IntList::~IntList() 
{
	IntNode* current = head;
	while (current != nullptr) 
    {
		IntNode* nextNode = current -> next;
		delete current;
		current = nextNode;
	}
	delete current;
}

IntList::IntList(const IntList &cpy) 
{
	head = nullptr;
	tail = nullptr;
	IntNode* current = cpy.head;
	while (current != nullptr) 
    {
		push_back(current -> value);
		current = current -> next;
	}
}

void IntList::push_front(int value) 
{
	if (head == nullptr) 
    {
		IntNode* newNode = new IntNode(value);
		head = newNode;
		tail = newNode;
	}
	else 
    {
		IntNode* newNode = new IntNode(value);
		newNode -> next = head;
		head = newNode;
	}
}

void IntList::push_back(int value) 
{
	IntNode* newNode = new IntNode(value);
	if (head == nullptr) 
    {
		head = newNode;
		tail = newNode;
	}
	else 
    {
		tail -> next = newNode;
		tail = newNode;
	}
}

void IntList::pop_front()
{
	IntNode* current = head;
	if (head != nullptr) 
	{
		if (head -> next != nullptr)
		{
			head = current -> next;
			delete current;
		}
		else
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
	}
}

bool IntList::empty() const 
{
	return head == nullptr;
}

void IntList::clear() 
{
	IntNode* current = head;
	
	while (current != nullptr) 
    {
		IntNode* nextNode = current -> next;
		delete current;
		current = nextNode;
	}
	
	delete current;
	
	head = nullptr;
	tail = nullptr;
}

const int & IntList::front() const 
{
	return head -> value;
}

const int & IntList::back() const 
{
	return tail -> value;
}

void IntList::selection_sort() 
{
	IntNode* current = head;
	while (current != nullptr && current -> next != nullptr) 
    {
		IntNode* min = current;
		for (IntNode* i = current -> next; i != nullptr; i = i -> next) 
        {
			if (i -> value < min -> value) {
				min = i;
			}
		}
		if (min != current) 
        {
			int temp = min -> value;
			min -> value = current -> value;
			current -> value = temp;
		}
		
		current = current -> next;
	}
}

void IntList::insert_ordered(int value) 
{
	IntNode* newNode = new IntNode(value);
	if (head == nullptr) 
    {
		head = newNode;
		tail = newNode;
	}
	else if (head -> value >= newNode -> value) 
    {
		newNode -> next = head;
		head = newNode;
	}
	else if (newNode -> value >= tail -> value) 
    {
		tail -> next = newNode;
		tail = newNode;
	}
	else 
    {
		IntNode* current = head;
		while (current -> next != nullptr && current -> next -> value <= newNode -> value) 
        {
			current = current -> next;
		}
		newNode -> next = current -> next;
		current -> next = newNode;
	}
}

void IntList::remove_duplicates() 
{
	IntNode* current = head;
	IntNode* checkNode;
	
	while (current != nullptr && current -> next != nullptr) 
    {
		checkNode = current;
		
		while (checkNode -> next != nullptr) {
			if (current -> value == checkNode -> next -> value) 
            {
				IntNode* deleteNode = checkNode -> next;
				checkNode -> next = checkNode -> next -> next;
				delete deleteNode;
				
				if (checkNode -> next == nullptr) {
					tail = checkNode;
				}
			}
			else 
            {
				checkNode = checkNode -> next;
			}
		}
		
		current = current -> next;
	}
}

IntList & IntList::operator=(const IntList &rhs) 
{
	if (this == &rhs) {
		return *this;
	}
	else {
		clear();
		
		IntNode* current = rhs.head;
		while (current != nullptr) {
			push_back(current -> value);
			current = current -> next;
		}
		
		return *this;
	}
}

ostream & operator<<(ostream &out, const IntList &rhs) 
{
	IntNode* current = rhs.head;
	while (current != nullptr) {
		if (current == rhs.tail) {
			out << current -> value;
		}
		else {
			out << current -> value << " ";
		}
		current = current -> next;
	}
	return out;
}
