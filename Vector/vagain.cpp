//This program 

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct /*LineItems*/LineItem {
    string name;
    double price;
    int qty;
    /*vector<string> names;
    vector<double> prices;
    vector<int> qtys;*/
    /*void add(string name, double price, int qty) {
        names.push_back(name);
        prices.push_back(price);
        qtys.push_back(qty);
    }
    int size() const {
        return names.size();
    }*/
};

void printSubtotal(double sum) {
    cout << "Subtotal: $" << sum << endl;
}

void printBill(const vector<LineItem> &items)/*const vector<string> &names, const vector<double> &prices, const vector<int> &qtys)*/ {
    cout << "--" << endl;
    double total = 0;
    for(auto item : items) {
        total += item.price * item.qty;
        cout << item.name << "$" << item.price << " x" << item.qty << endl;
    }
    cout << "--" << endl << "Total: $" << total << endl;
    
    }
    

    /*for(int i = 0; i<items.prices.size(); i++) {
        total += items.prices[i] * items.qtys[i];
        cout << items.names[i] << "$" << items.prices[i] << "x" << items.qtys[i] << endl;*/
    
    //cout << "--" << endl << "Total: " << endl;
    


int main() {
double sum = 0;
string name;
double price;
int qty;
vector<LineItem> items;
//LineItems items;
/*vector<string> names;
vector<double> prices;
vector<int> qtys;*/

cout << fixed << setprecision(2);

while(cin >> name >> price >> qty) {
    sum += price * qty;
    printSubtotal(sum);
    LineItem item;
    item.name = name;
    item.price = price;
    item.qty = qty;
    items.push_back(item);
    /*sum += price * qty;
    printSubtotal(sum);
    items.add(name, price, qty);*/
}
printBill(items);
    return 0;
}