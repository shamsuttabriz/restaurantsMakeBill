/**
Project Name: Restaurant Bill Management
Name: Md.shamsut tabriz
Email: shamsuttabriz.md@gmail.com
*/


#include <bits/stdc++.h>
using namespace std;

/// TASK 01 START
class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
private:
    double total_tax;
public:
    Restaurant () {
        this -> total_tax = 0;
    }
    void setTax (double tax) {
        this -> total_tax += tax;
    }
    /// input item
    void inputItem(int n) {
        if (n <= 12) {
            for (int i = 0; i < n; i++) {
                cin >> food_item_codes[i];
                getchar();
                getline (cin, food_item_names[i]);
                cin >> food_item_prices[i];
            }
        }
        else {
            cout << "Invalid Item!" << endl;
        }
    }

    /// show item

    void ShowItem(int n) {
        cout << "\t\t\t\t Make Bill \t\t" << endl;
        cout << "\t--------------------------------------------------------------\t" << endl;
        cout << "Item code" << "\t\t\t" << "Item name" << "\t\t\t" << "Item prices" << endl;
        for (int i = 0; i < n; i++) {
            cout << food_item_codes[i] <<" \t\t\t " << food_item_names[i] << "\t\t\t" << food_item_prices[i] << endl;
        }
    }

    ///  searchFoodCode

    int searchFoodCode (int n, int x) {
        for (int i = 0; i < n; i++) {
            if (food_item_codes[i] == x) {
                return i;
            }
        }
        return -1;
    }

};

int main()
{
    Restaurant item;

    /// TASK 02 START
    int n;
    cout << "Please enter your total item: ";
    cin >> n;
    item.inputItem(n);

    Flag:
    /// TASK 03 START
    item.ShowItem(n);

    /// TASK 04 START
    int tableNo;
    cout << "\nEnter Table No: ";
    cin >> tableNo;

    int totalItem;
    cout << "Enter Number of Items: ";
    cin >> totalItem;

    int code[totalItem];
    int quantity[totalItem];
    int findcode;
    for (int i = 0; i < totalItem; i++) {
        check:
            cout << "Enter code " << i+1 << ": ";
            cin >> findcode;
            int temp = item.searchFoodCode(n, findcode);
            if (temp >= 0) {
               code[i] = temp;
            }
            else {
               goto check;
            }
        cout << "Enter quantity " << i+1 << ": ";
        cin >> quantity[i];
    }


    /// TASK 05 START

    cout << "\t\t\t\t Bill Summary \t\t" << endl;
    cout << "\t--------------------------------------------------------------\t" << endl;
    cout << "Enter Table no: " << tableNo << endl;
    cout << "Item code" << "\t" << "Item name" << "\t\t\t" << "Item prices" << "\t" << "Item Quantity" << "\t" << "Total Prices" << endl;
    int sum = 0;
    for (int i = 0; i < totalItem; i++) {
        int totalPrice = quantity[i] * item.food_item_prices[code[i]];
        sum += totalPrice;
        cout << item.food_item_codes[code[i]] << "\t\t" << item.food_item_names[code[i]] << "\t\t" << item.food_item_prices[code[i]] << "\t\t" << quantity[i] << "\t\t" << totalPrice << endl;
    }
    double tax = sum * 5.0 / 100;
    item.setTax(tax);
    cout << "Tax" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t\t\t\t" << tax << endl;
    cout << "__________________________________________________________________________________________________________________\n";
    double netTotal = tax + sum;
    cout << "NET TOTAL" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t\t\t" << netTotal << " Taka" << endl;


    cout << "\nDo you want continue: then press any key, if not press t: ";
    char c;
    cin >> c;
    if (c != 't') {
        goto Flag;
    }

    return 0;
}
