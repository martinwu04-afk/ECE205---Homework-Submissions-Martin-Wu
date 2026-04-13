// Martin Wu Question 3

#include <iostream>
#include <string>
#include <vector>
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

class Order {
private:
    vector<Pizza> pizzas;

public:
    void addPizza(int type, int size, int toppings) {
        Pizza p;
        p.setType(type);
        p.setSize(size);
        p.setToppings(toppings);
        pizzas.push_back(p);
    }

    void outputOrder() const {
        cout << "Order Summary:" << endl;
        double total = 0.0;
        for (int i = 0; i < pizzas.size(); i++) {
            cout << i + 1 << ". ";
            pizzas[i].outputDescription();
            cout << "   Price: $" << pizzas[i].computePrice() << endl;
            total += pizzas[i].computePrice();
        }
        cout << "Total: $" << total << endl;
    }
};

int main() {
    Order order1;
    order1.addPizza(Pizza::DEEP_DISH, Pizza::SMALL, 3);
    order1.addPizza(Pizza::HAND_TOSSED, Pizza::LARGE, 5);
    order1.addPizza(Pizza::PAN, Pizza::MEDIUM, 0);
    cout << "Order 1:" << endl;
    order1.outputOrder();
    cout << endl;

    Order order2;
    order2.addPizza(Pizza::PAN, Pizza::LARGE, 4);
    order2.addPizza(Pizza::HAND_TOSSED, Pizza::SMALL, 2);
    cout << "Order 2:" << endl;
    order2.outputOrder();

    return 0;
}