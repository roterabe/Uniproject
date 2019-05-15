#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>

using namespace std;

int rand_int(){
    return rand() % 20 + 1;
}

void swap(int &xp, int &yp) 
{ 
    int temp = xp; 
    xp = yp; 
    yp = temp; 
} 

void my_Function(void) {
    static unsigned int call_count = 0;
    call_count++;
    cout << "Swap count: " << call_count << endl;
}

void bubblesort(vector<int> a, int sz){
    int i, j;
    j = 0; 
    while(!is_sorted(a.begin(), a.end())){
 //  for (i = 0; i < sz-1; i++){       
  
       if(j == sz){
       j = 0;
       }
           if (a[j] > a[j+1]) {
              swap(a[j], a[j+1]);
              my_Function();
           }
              j++; 
        
        }
}



bool issort(vector<int> a, int sz){
    for (int i=1; i<sz; i++)
		if (a[i]<a[i-1])
			return false;
	return true;
}

void printvec(vector<int> a){
    for (auto e:a){
        cout << e << " ";
    }
}

int main(){
    //int sz = 0;
    int large = 20;
    vector<int> a = vector<int>(large);
    time_t  t0, t1;
    clock_t c0, c1;
    //reverse(a.begin(), a.end());
    srand ( time(NULL) );

    for (int i = 0; i < large; i++){
        a[i]=rand_int();
    }

    t0 = time(NULL);
    c0 = clock();
    bubblesort(a, large);

    c1 = clock();
    t1 = time(NULL);

    cout << "Elapsed wall clock time: " << ((long) (t1 - t0)) << endl;
    cout << "Elapsed wall clock time :" << (double) (c1 - c0)/CLOCKS_PER_SEC << endl;
	cout << "is sorted: " << is_sorted(a.begin(), a.end()) << endl;
    printvec(a);

    return 0;
}