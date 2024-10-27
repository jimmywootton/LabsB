#include <iostream>
using namespace std;
#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    _name = "none";
    _description = "none";
    _price = 0;
    _quantity = 0;

}

ItemToPurchase::ItemToPurchase(string n, string d,int p, int q)
{
    _name = n;
    _description = d;
    _price = p;
    _quantity = q;
}

void ItemToPurchase::setName(string n)
{
    _name = n;
}

string ItemToPurchase::name()
{
    return _name;
}

void ItemToPurchase::setPrice(int p)
{
    _price = p;
}

int ItemToPurchase::price()
{
    return _price;
}

void ItemToPurchase::setQuantity(int q)
{
    _quantity = q;
}
int ItemToPurchase::quantity()
{
    return _quantity;
}

void ItemToPurchase::setDescription(string d)
{
    _description = d;
}

string ItemToPurchase::description()
{
    return _description;
}

void ItemToPurchase::printItemCost()
{
    cout << _name << " " << _quantity << " @ $" << _price << " = $" << _quantity * _price << endl;
}

void ItemToPurchase::printItemDescription()
{
    cout << _name << ": " <<_description << endl;
}
