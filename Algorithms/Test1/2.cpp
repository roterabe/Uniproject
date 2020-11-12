#include <iostream>

int main()
{
    int n[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int i = 0;
    bool f = n[i] % 4 == 0;
    do
    {
        f = n[++i];
    } while (!f);

    std::cout << n[i];
    return 0;
}