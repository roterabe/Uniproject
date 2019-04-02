#include <iostream>
#include <vector>
#include <algorithm>

//prints vector
void print(std::vector<char> word){
    for (auto i:word){
        std::cout << i << " ";
    }
}

//prints bool vector 
void print1(std::vector<bool> found){
    for (auto i:found){
        std::cout << i << " ";
    }
}

//finds positions of letters and times found
void find(std::vector<char> word, std::vector<bool> &found, int &times){
    for (int i = 0; i < word.size(); i++){
        int pos = 0;
        if(word[i] == 'a' || word[i] == 'A'){
         found[i] = 1;
         times += 1;
         pos = i;
         std::cout << "Position: " << pos << " ";
        }
    }
}


int main(){

    std::vector<bool> found;
    int sz;
    int times = 0;
        std::string w;
        std::cin >> w;
    std::vector<char> word(w.begin(), w.end());
    
    //fill boolean vector with zeroes
    for(auto i:word){
        found.push_back(0);
    }
    
    find(word, found, times);

    std::cout << std::endl;
    std::cout << "We found \"u\" in " << w << ": " << times << " times." << std::endl; 

    return 0;
}