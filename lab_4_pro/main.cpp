#include <iostream>
using namespace std;

#include "ShoppingCart.h"

void printMenu(ShoppingCart &m)
{
    char choice;
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: " << endl;
    cin >> choice;
    bool option = true;
    while (option)
    {
        if (choice == 'a' || choice == 'd' || choice == 'c' || choice == 'i' || choice == 'o' || choice == 'q')
        {
            option = false;
        }
        else
        {
            cout << "Choose an option: "  << endl;
            cin >> choice;
        }
    }
    
    if (choice == 'q')
    {
        exit(0);
    }
    if (choice == 'o')
    {
        cout <<  endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        m.printTotal();
    }
    if (choice == 'i')
    {
        m.printDescription();
    }
    if (choice == 'a')
    {
        ItemToPurchase add;
        string n;
        string d;
        int p;
        int q;
        cout <<  endl;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name: " << endl;
        cin.ignore();
        getline(cin, n);
        cout << "Enter the item description: " << endl;
        getline(cin, d);
        cout << "Enter the item price: " << endl;
        cin >> p;
        cout << "Enter the item quantity: " << endl << endl;
        cin >> q;
        add = ItemToPurchase(n,d,p,q);
        m.addItem(add);
    }
    if (choice == 'd')
    {
        string remove;
        cout <<  endl;
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove: " << endl;
        cin.ignore();
        getline(cin , remove);
        m.removeItem(remove);
    }
    if (choice == 'c')
    {
        ItemToPurchase mod;
        string modifyName;
        int modifyQuant;
        cout <<  endl;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name: " << endl;
        cin.ignore();
        getline(cin, modifyName);
        cout << "Enter the new quantity: " << endl;
        cin >> modifyQuant;
        mod.setName(modifyName);
        mod.setQuantity(modifyQuant);
        m.modifyItem(mod);
    }
}

int main()
{
    ShoppingCart mainCart;
    string name;
    string date;
    cout << "Enter customer's name: " << endl;
    getline(cin, name);
    cout << "Enter today's date: ";
    getline(cin, date);
    cout << endl;
    mainCart = ShoppingCart(name,date);
    cout << endl;
    cout << "Customer name: " << mainCart.customerName() << endl;
    cout << "Today's date: " << mainCart.date() << endl << endl;
    while (true)
    {
        printMenu(mainCart);
    }
}