#include <iostream>
#include <cmath>
using namespace std;
 
#define ERR_MASK_TO_SHORT -101
#define ERR_MASK_TO_LONG -102
#define OK 1

struct t_set_info {
    char* subset;
    int subset_size;


};
 
 
bool isSet(char* a, int s);
void printSet(char* a, int s);
void makeSet(char*& a, int& s);
 
int makeSubSet(char* a, int s,
             char* mask, int ms,
             char*& suba, int& subs);
 
int makeMask(char* a, int s,
             char* suba, int subs,
             char*& mask, int& ms);
 
 
int main() {
    int sz;
    char* arr;
    char cmd = 'y';
    while (cmd != 'n') {
 
    cout <<  "Enter number of elements: ";
    cin >> sz;
 
    arr = new char[sz];
    cout << "Enter " << sz << " element values: ";
    for (int i = 0; i < sz; i++) {
        cin >> arr[i];
    }
 
    bool isSetOK = false;
    isSetOK = isSet(arr, sz);
    cout <<  (isSetOK ? "This is a set!" : "NOT a set!") << endl;
 
    if (!isSetOK) {
        makeSet(arr, sz);
    }
    printSet(arr, sz);
 
    int all_masks_size = pow(2,sz); 
    char** all_masks = new char*[all_masks_size];
    for (int i = 0; i < all_masks_size; i++) {
        all_masks[i] = new char[sz];
    }
    int c;
    int pos;
    for (int i = 0; i < all_masks_size; i++) {
        c = i;
        pos = sz - 1;

        while (c !=0) {
            //make int into char
            all_masks[i][pos] = (c%2) + '0';
            c = c/2;
            pos--;
        }
        for (int j = 0; j <= pos; j++) {
            all_masks[i][j] = '0';
        }
        //printSet(all_masks[i], sz);
    }
//new arr with all masks with their sizes
    t_set_info* set_infos = new t_set_info[all_masks_size];

    for (int i = 0; i < all_masks_size; i++) {
        makeSubSet(arr, sz, all_masks[i], sz, set_infos[i].subset, set_infos[i].subset_size);
        printSet(set_infos[i].subset, set_infos[i].subset_size);
    }
//delete arr and optimize
    for (int i = 0; i < all_masks_size; i++) {
        delete [] all_masks[i];

    }
    delete [] all_masks;
    all_masks = NULL;

    for (int i = 0; i < all_masks_size; i++) {
        delete set_infos[i].subset;
    }
    delete [] set_infos;
    set_infos = NULL;

    delete[] arr;
    arr = NULL;
    cout << "Do you want to continue (y/n): ";
    cin >> cmd;
    
    }
    return 0;


}
 
bool isSet(char* a, int s) {
    bool isOK = true;
    for (int i = 0; (i < s) && isOK; i++) {
        for (int j = i+1; (j < s) && isOK; j++) {
            if (a[i] == a[j]) {
                isOK = false;
            }
        }
    }
    return isOK;
}
 
void printSet(char* a, int s) {
    for (int i = 0; i < s; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
 
void makeSet(char*& a, int& s) {
    int c = 0;
    int i, j;
    for (i = 0; i < s; i++) {
        for (j = i+1; j < s; j++) {
            if (a[i] == a[j]) {
                break;
            }
        }
        if (j == s) {
            c++;
        }
    }
 
    char* aN = new char[c];
    c = 0;
    for (i = 0; i < s; i++){
        for (j = 0; j < c; j++) {
            if (a[i] == aN[j]) {
                break;
            }
        }
        if (j == c) {
            aN[c] = a[i];
            c++;
        }
    }
 
    delete[] a;
    a = aN;
    s = c;
 
}
 
 
 
int makeSubSet(char* a, int s,
             char* mask, int ms,
             char*& suba, int& subs) {
 
    if (s > ms) {
        return ERR_MASK_TO_SHORT;
    }
    if (s < ms) {
        return ERR_MASK_TO_LONG;
    }
 
 
    int c = 0;
    for (int i = 0; i < ms; i++){
        c += mask[i] - '0';
    }
    suba = new char[c];
    subs = c;
 
    c = 0;
    for (int i = 0; i < s; i++) {
        if (mask[i] == '1') {
            suba[c] = a[i];
            c++;
        }
    }
 
    return OK;
}
 
 
int makeMask(char* a, int s,
             char* suba, int subs,
             char*& mask, int& ms) {
    mask = new char[s];
    ms = s;
 
    for (int i = 0; i < ms; i++) {
        mask[i] = '0';
    }
 
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < subs; j++) {
            if (a[i] == suba[j]) {
                mask[i] = '1';
                break;
            }
        }
    }
 
    return OK;
 
}