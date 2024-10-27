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
		delete current;
		current = current -> next;
	}
	delete current;
}

void IntList::push_front(int value) 
{
	IntNode* newNode = new IntNode(value);
	if (head == nullptr) 
	{
		head = newNode;
		tail = newNode;
	}
	else 
	{
		newNode -> next = head;
		head = newNode;
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

const int & IntList::front() const
{
	return head -> value;
}

const int & IntList::back() const
{
	return tail -> value;
}

ostream & operator<<(ostream & out, const IntList & list)
{
	IntNode* current = list.head;
	while (current != nullptr) 
	{
		if (current == list.tail) 
		{
			out << current -> value;
		}
		else 
		{
			out << current -> value << " ";
		}
		current  = current -> next;
	}
	return out;
	
}

IntList::IntList(const IntList &cpy)
{
	if (cpy.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else if (cpy.head -> next == nullptr)
	{
		head = cpy.head;
		tail = cpy.head;
	}
	else
	{
		IntNode* current = cpy.head -> next;
		head = cpy.head;
		tail = cpy.head;
		while (current != nullptr)
		{
			tail -> next = current;
			tail = tail -> next;
			current = current -> next;
		}
	}
}

IntList & IntList::operator=(const IntList &rhs)
{
	delete this;
	if (rhs.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else if (rhs.head -> next == nullptr)
	{
		head = rhs.head;
		tail = rhs.head;
	}
	else
	{
		IntNode* current = rhs.head -> next;
		head = rhs.head;
		tail = rhs.head;
		while (current != nullptr)
		{
			tail -> next = current;
			tail = tail -> next;
			current = current -> next;
		}
	}
	return *this;
}

void IntList::clear()
{
	IntNode* current = head;
	while (current != nullptr) 
	{
		delete current;
		current = current -> next;
	}
	delete current;
}

void IntList::selection_sort()
{
	IntNode* current = head;
	while (current != nullptr && current -> next != nullptr) 
	{
		IntNode* min = current;
		
		for (IntNode* i = current -> next; i != nullptr; i = i -> next) 
		{
			if (i -> value < min -> value) 
			{
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

void IntList::remove_duplicates() {
	IntNode* current = head;
	IntNode* checkNode;
	
	while (current != nullptr && current -> next != nullptr) {
		checkNode = current;
		
		while (checkNode -> next != nullptr) {
			if (current -> value == checkNode -> next -> value) {
				IntNode* deleteNode = checkNode -> next;
				checkNode -> next = checkNode -> next -> next;
				delete deleteNode;
				
				if (checkNode -> next == nullptr) {
					tail = checkNode;
				}
			}
			else {
				checkNode = checkNode -> next;
			}
		}
		
		current = current -> next;
	}
}

void IntList::push_back(int value)
{
	IntNode* newNode = new IntNode(value);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail -> next = newNode;
		tail = newNode;
	}
}