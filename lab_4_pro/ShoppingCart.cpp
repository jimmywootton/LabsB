#include <iostream> 
#include <vector>
using namespace std;

#include "ShoppingCart.h"



ShoppingCart::ShoppingCart()
{
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string n, string d)
{
    _customerName = n;
    _currentDate = d;
}

string ShoppingCart::customerName()
{
    return _customerName;
}
string ShoppingCart::date()
{
    return _currentDate;
}

void ShoppingCart::addItem(ItemToPurchase a)
{
   _cartItems.push_back(a);
}

void ShoppingCart::removeItem(string r)
{
    bool check = true;
    for (unsigned int i = 0; i < _cartItems.size();++i)
    {
        if (_cartItems.at(i).name() == r)
        {
            _cartItems.erase(_cartItems.begin() + i);
            check = false;
            cout << endl;
        }
    }
    if (check)
    {
        cout << "Item not found in cart. Nothing removed." << endl << endl;
    }
}
void ShoppingCart::modifyItem(ItemToPurchase m)
{
    bool check = true;
    for (unsigned int i = 0; i < _cartItems.size();++i)
    {
        if (_cartItems.at(i).name() == m.name())
        {
            if (m.description() != "none")
            {
                _cartItems.at(i).setDescription(m.description());
            }
            if (m.price() != 0)
            {
                _cartItems.at(i).setPrice(m.price());
            }
            if (m.quantity() != 0)
            {
                _cartItems.at(i).setQuantity(m.quantity());
            }
            check = false;
            cout << endl;
        }
    }
    if (check)
    {
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}

int ShoppingCart::numItemsInCart()
{
    int count = 0;
    for (unsigned int i = 0;i < _cartItems.size();++i)
    {
        count += _cartItems.at(i).quantity();
    }
    return count;
}

int ShoppingCart::costOfCart()
{
    int cost = 0;
    for (unsigned int i = 0;i < _cartItems.size();++i)
    {
        cost += (_cartItems.at(i).price() * _cartItems.at(i).quantity());
    }
    return cost;
}

void ShoppingCart::printTotal()
{
    cout << _customerName << "'s " << "Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    for (unsigned int i = 0;i < _cartItems.size();++i)
    {
        _cartItems.at(i).printItemCost();
    }
    if (numItemsInCart() == 0)
    {
        cout << "SHOPPING CART IS EMPTY"  << endl;
    }
    cout << endl;
    cout << "Total: $" << costOfCart() << endl << endl;
}

void ShoppingCart::printDescription()
{
    cout << endl;
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    cout << _customerName << "'s " << "Shopping Cart - " << _currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0;i < _cartItems.size();++i)
    {
        _cartItems.at(i).printItemDescription();
    }
    cout << endl;
}








