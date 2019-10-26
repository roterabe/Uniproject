#include <iostream>
using namespace std;

int main()
{
	char line[100];
	int egn[10];

	cin.getline(line, 99);
	int i = 0;
	while ((line[i] != '\0') && (i < 10)) {
		egn[i] = line[i] - '0';
			cout << egn[i] << endl;
			i++;

	}
	return 0;
}

