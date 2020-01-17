#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<char> Mem = vector<char>();
    vector<char> Vec = vector<char>();
    cout << "Enter string: "
         << "\n";
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        Vec.push_back(input[i]);
    }
    cout << "Enter number of non-repeating elements: "
         << "\n";
    int k = 0;
    cin >> k;
    cout << "shsh";

    for (int i = 0; i < Vec.size() - 1; i++)
    {
        char rem = Vec[i];
        //char save = rem;
        cout << Vec.pop_back() << endl;

        Mem.push_back(rem);
        for (int j = 1; j < Vec.size(); j++)
        {
            //cout << rem << " ";
            if (rem == input[j])
            {
                Mem.pop_back();
            }
        }
    }
    return 0;
}