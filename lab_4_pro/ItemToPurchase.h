#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <iostream>
using namespace std;

class ItemToPurchase
{
    public:
        ItemToPurchase();
        ItemToPurchase(string n, string d,int p, int q);
        void setName(string n);
        string name();
        void setPrice(int p) ;
        int price();
        void setQuantity(int q); 
        int quantity();
        void setDescription(string d);
        string description();
        void printItemCost();
        void printItemDescription();
    private:
        string _name;
        string _description;
        int _price;
        int _quantity;
        
};

#endif