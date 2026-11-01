#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Shopping {
private:
    int productID[10];
    string productName[10];
    double price[10];
    int quantity[10];
    int count;

public:
    Shopping() {
        count = 5;

        productID[0] = 101;
        productName[0] = "Laptop";
        price[0] = 55000;

        productID[1] = 102;
        productName[1] = "Mobile";
        price[1] = 20000;

        productID[2] = 103;
        productName[2] = "Headphones";
        price[2] = 1500;

        productID[3] = 104;
        productName[3] = "Keyboard";
        price[3] = 1000;

        productID[4] = 105;
        productName[4] = "Mouse";
        price[4] = 500;

        for (int i = 0; i < count; i++) {
            quantity[i] = 0;
        }
    }

    void displayProducts() {
        cout << "\n========== AVAILABLE PRODUCTS ==========\n";

        cout << left << setw(12) << "Product ID"
             << setw(18) << "Product"
             << "Price (Rs.)\n";

        for (int i = 0; i < count; i++) {
            cout << left << setw(12) << productID[i]
                 << setw(18) << productName[i]
                 << price[i] << endl;
        }
    }

    void purchaseProduct() {
        int id, qty;

        cout << "\nEnter Product ID: ";
        cin >> id;

        cout << "Enter Quantity: ";
        cin >> qty;

        if (qty <= 0) {
            cout << "Invalid Quantity!\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            if (productID[i] == id) {
                quantity[i] += qty;

                cout << "\nProduct Added to Cart Successfully!\n";
                return;
            }
        }

        cout << "\nProduct Not Found!\n";
    }

    void generateBill() {
        double total = 0;
        double discount = 0;
        double finalAmount;

        cout << fixed << setprecision(2);

        cout << "\n============= SHOPPING BILL =============\n";

        cout << left << setw(18) << "Product"
             << setw(10) << "Qty"
             << setw(12) << "Price"
             << "Amount\n";

        for (int i = 0; i < count; i++) {
            if (quantity[i] > 0) {
                double amount = price[i] * quantity[i];

                cout << left << setw(18) << productName[i]
                     << setw(10) << quantity[i]
                     << setw(12) << price[i]
                     << amount << endl;

                total += amount;
            }
        }

        if (total >= 50000) {
            discount = total * 0.10;
        }
        else if (total >= 20000) {
            discount = total * 0.05;
        }

        finalAmount = total - discount;

        cout << "\nTotal Amount: Rs. " << total;
        cout << "\nDiscount: Rs. " << discount;
        cout << "\nFinal Amount: Rs. " << finalAmount;

        cout << "\n==========================================\n";
        cout << "Thank You for Shopping!\n";
    }
};

int main() {
    Shopping shop;
    int choice;

    do {
        cout << "\n===== ONLINE SHOPPING SYSTEM =====\n";
        cout << "1. Display Products\n";
        cout << "2. Purchase Product\n";
        cout << "3. Generate Bill\n";
        cout << "4. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.displayProducts();
                break;

            case 2:
                shop.purchaseProduct();
                break;

            case 3:
                shop.generateBill();
                break;

            case 4:
                cout << "\nThank You! Visit Again.\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}
