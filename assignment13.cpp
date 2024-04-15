#include <iostream>
#include <string>
using namespace std;
class MenuItem {
protected:
    string name,category;;
    double price;
    
public:
    MenuItem(string name, double price, string category) : name(name), price(price), category(category) {}
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    string getCategory() const {
        return category;
    }
};
class Order {
protected:
    MenuItem items[10];
    int itemCount;
public:
    Order() : itemCount(0) {}
    void addItem(const MenuItem& item) {
        if (itemCount < 10) {
            items[itemCount++] = item;
        } else {
            cout << "Maximum limit reached. Cannot add more items." << endl;
        }
    }

    void displayOrder() const {
        cout << "Order Details:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << items[i].getName() << " - $" << items[i].getPrice() << endl;
        }
    }
    double calculateTotal() const {
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i].getPrice();
        }
        return total;
    }
};
class Bill : public Order {
public:
    void generateBill() const {
        displayOrder();
        cout << "Total: $" << calculateTotal() << endl;
    }
};
int main() {
    MenuItem item1("Burger", 10.99, "Main Course");
    MenuItem item2("Pizza", 7.99, "Starter");
    Order order;
    order.addItem(item1);
    order.addItem(item2);
    Bill bill;
    bill.generateBill();

    return 0;
}
