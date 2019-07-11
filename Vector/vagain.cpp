//This program

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct /*LineItems*/ LineItem
{
    string name;
    double price;
    int qty;
};

void printSubtotal(double sum)
{
    cout << "Subtotal: $" << sum << endl;
}

void printBill(const vector<LineItem> &items) /*const vector<string> &names, const vector<double> &prices, const vector<int> &qtys)*/
{
    cout << "--" << endl;
    double total = 0;
    for (auto item : items)
    {
        total += item.price * item.qty;
        cout << item.name << "$" << item.price << " x" << item.qty << endl;
    }
    cout << "--" << endl
         << "Total: $" << total << endl;
}

int main()
{
    double sum = 0;
    string name;
    double price;
    int qty;
    vector<LineItem> items;

    cout << fixed << setprecision(2);

    while (cin >> name >> price >> qty)
    {
        sum += price * qty;
        printSubtotal(sum);
        LineItem item;
        item.name = name;
        item.price = price;
        item.qty = qty;
        items.push_back(item);
    }
    printBill(items);
    return 0;
}