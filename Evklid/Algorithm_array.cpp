#include <iostream>
#include <array>
#include <cmath>
using namespace std;

int main(){
    int a;
    int b;
    int tmp;

    cout << "Enter two numbers:" << endl;
    cin >> a >> b;

    int br=0;
    int x=a;
    int y=b;

    while (x%y !=0) {
        br++;
        tmp = x;
        x = y;
        y = tmp%y;

    }

    int** arr = new int*[4];
    for (int i = 0; i<4; i++){
        arr[i] = new int[br+2];
    }
    for (int i = 0; i<4; i++){
        for (int j = 0; j<br+2; j++){
        arr[i][j] = -1;
        }
    }
    for (int i = 0; i<4; i++){
        for (int j = 0; j<br+2; j++){

    }

    }
arr[0][0] = a;
arr[0][1] = b;
arr[2][0] = 1;
arr[2][1] = 0;
arr[3][0] = 0;
arr[3][1] = 1;

for (int i = 2; i < br + 2; i++){
    arr[0][i] = arr[0][i-2] % arr[0][i-1];
    arr[1][i-1] = arr[0][i-2] / arr[0][i-1];
}
arr[1][br+1] = arr[0][br] / arr[0][br+1];

for (int i = 2; i < br+2; i++){
    arr[2][i] = arr[1][i-1] * arr[2][i-1] + arr[2][i-2];
    arr[3][i] = arr[1][i-1] * arr[3][i-1] + arr[3][i-2];
}

 for (int i = 0; i<4; i++){
        for (int j = 0; j<br+2; j++){
    }
    }

    int sign_multi = 1;
    for (int i = 0; i < br+2; i++){
        cout << arr[0][i] << " = ";
        cout << ((sign_multi == 1) ? " + " : " - ");
        cout << a << " * " << arr[2][i];

        sign_multi = sign_multi * -1;
        cout << ((sign_multi == 1) ? " + " : " - ");
        cout << b << " * " << arr[3][i];
        cout << endl;
    }
    return 0;
}

