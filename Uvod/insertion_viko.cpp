#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

void insertionSort(int arr[], int n)  
{  
    int Buf, j;  
    for (int i = 1; i < n; i++) 
    {  
        Buf = arr[i]; 
        j = i - 1;  

        while (j >= 0 && arr[j] > Buf) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = Buf;  
    }  
}  

    int main(){int arr[] = { 12, 11, 13, 5, 6 };  

    int n = 5;  

    time_t  t0, t1;
    clock_t c0, c1;

   // t0 = time(NULL);
    c0 = clock();

    insertionSort(arr, n);  

    c1 = clock();
   // t1 = time(NULL);

    //reverse(a.begin(), a.end());
    //srand ( time(NULL) );


    //cout << "Elapsed wall clock time: " << ((long) (t1 - t0)) << endl;
    cout << "Elapsed wall clock time :" << (double)(c1 - c0)/CLOCKS_PER_SEC << endl;
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " "; 
    }
    cout<<endl;
    
  
    return 0;  
}  