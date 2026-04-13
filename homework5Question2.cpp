// Martin Wu Question 2

#include <iostream>
#include <string>
using namespace std;

class Pizza {
private:
    int type; 
    int size;
    int toppings;

public:
    static const int DEEP_DISH = 1;
    static const int HAND_TOSSED = 2;
    static const int PAN = 3;
    static const int SMALL = 1;
    static const int MEDIUM = 2;
    static const int LARGE = 3;

    Pizza() {
        type = HAND_TOSSED;
        size = MEDIUM;
        toppings = 0;
    }

    void setType(int t) {
        type = t;
    }

    void setSize(int s) {
        size = s;
    }

    void setToppings(int t) {
        toppings = t;
    }

    int getType() const {
        return type;
    }

    int getSize() const {
        return size;
    }

    int getToppings() const {
        return toppings;
    }

    void outputDescription() const {
        string typeStr, sizeStr;

        if (type == DEEP_DISH) {
            typeStr = "Deep Dish";
        } else if (type == HAND_TOSSED) {
            typeStr = "Hand Tossed";
        } else {
            typeStr = "Pan";
        }                         

        if (size == SMALL) {
            sizeStr = "Small";
        } 
        else if (size == MEDIUM) {
            sizeStr = "Medium";
        }
        else {
            sizeStr = "Large";
        }              

        cout << sizeStr << " " << typeStr << " pizza with " << toppings << " topping(s)" << endl;
    }

    double computePrice() const {
        double basePrice = 0.0;
        if (size == SMALL) {
            basePrice = 10.0;
        }
        else if (size == MEDIUM) {
            basePrice = 14.0;
        }
        else {
            basePrice = 17.0;
        }
        return basePrice + (toppings * 2.0);
    }
};

int main() {
    Pizza pizza1;
    pizza1.setType(Pizza::DEEP_DISH);
    pizza1.setSize(Pizza::SMALL);
    pizza1.setToppings(3);

    cout << "Pizza 1: ";
    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl;

    cout << endl;

    Pizza pizza2;
    pizza2.setType(Pizza::HAND_TOSSED);
    pizza2.setSize(Pizza::LARGE);
    pizza2.setToppings(5);

    cout << "Pizza 2: ";
    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl;

    cout << endl;

    return 0;
}