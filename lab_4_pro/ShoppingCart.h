#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iostream> 
#include <vector>
using namespace std;


#include "ItemToPurchase.h"

class ShoppingCart
{
    public:
        ShoppingCart();
        ShoppingCart(string n,string d);
        string customerName();
        string date();
        void addItem(ItemToPurchase a);
        void removeItem(string r);
        void modifyItem(ItemToPurchase m);
        int numItemsInCart();
        int costOfCart();
        void printTotal();
        void printDescription();
    private:   
        string _customerName;
        string _currentDate;
        vector <ItemToPurchase> _cartItems;
};

#endif