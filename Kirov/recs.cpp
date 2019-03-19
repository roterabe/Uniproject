#include <iostream>
using namespace std;

bool s_is_p(string s, int start, int end)
{ 
    if (start >= end) return true;
    if (s[start] == s[end]) return s_is_p(s, start + 2, end - 2);
    else return false;
}
int main() {
    string s;
    cin >> s;
    cout << s_is_p(s, 0, s.length() - 1) << endl;
    return 0;
}