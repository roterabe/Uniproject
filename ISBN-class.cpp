#include <iostream>
using namespace std;

int main() {
  char line[100];
  int isbn[10];

  cin.getline(line , 99);
  int i = 0;
  int pos = 0;
  while((line[i] != '\0') && (pos<10)) {
  if (line[i]>='0' && line[i] <='9') {
  isbn[pos]= line[i]-'0';
  pos++;
  }
  i++;
  }
  for (i=0; i<10; i++) {
  cout << isbn[i] << " ";
  }
  int sum = 0;
  bool is_Valid=false;
  for(i=0; i<10; i++){
    sum+=isbn[i]*(10-i);
  }
    is_Valid=((sum%11)==0);
    cout<< "The ISBN is:" << (is_Valid ? " ": "not ") << "valid";

  return 0;
}

