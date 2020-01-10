// Compare elements of 2 arrays and print index and value at match

#include <iostream>

using std::cout;

int comparetwoarrays( const int array1[], const int array2[], int array_size1, int array_size2 );

int main ()
{
    int const ARRAY_SIZE1 = 500;
    int const ARRAY_SIZE2 = 10;
    int array1[ARRAY_SIZE1] = {0};
    int array2[ARRAY_SIZE2] = {0};

    // give arr values

    comparetwoarrays( array1, array2, 20, ARRAY_SIZE2 );
}

  int comparetwoarrays( const int array1[], const int array2[], int array_size1, int array_size2 )
{
    for( int g = 0; g < array_size2; g++ )
    {
        for ( int t = 0; t < array_size1; t++ )
        {
            if ( array2[g] == array1[t])
            {
                if (g == t)
                {
                    cout << "match at \"" << array2[g] << "\" on arr2 at index " << g;
                    cout << ", match at \"" << array1[t] << "\" on arr1 at index " << t << "\n";
                    cout << "match at \"" << array1[t] << "\" at index " << t << "\n";
                }
                else
                {
                    cout << "no match at = " << array2[g] << ", index on array2 = " << g <<", index on array1 = " << t << " no match at = " << array1[t] << "\n";
                }
            }
        }
    }
}