#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>


// Prototypes
void problemOne();
void getSolutionsP1(int number);
void problemTwo();
void getSolutionsP2(int number);


// Global variables
std::unordered_map<int, int> umap;
std::vector<int> firstInput, aux, ac, al;
int maxLength = 0, counter=0, size1 = 1, size2 = 0;

// Main function
int main() {
    int problem;
    std::cin >> problem; // reads the problem (first input line)

    if (problem == 1) {
        problemOne();
    }
    else if (problem == 2) {
        problemTwo();
    }
    return 0;
}

// Funtion to solve problem 1
void problemOne() {

    int f;
    std::string str, temp;
    std::stringstream ss;

    std::cin >> f;
    firstInput.push_back(f);
    al.push_back(1);
    ac.push_back(1);

    std::getline(std::cin, str);
    ss << str;

    maxLength = 1;
    counter = 1;

    if (str == "") { std::cout << maxLength << " " << counter << std::endl; return; }
    
    while (!ss.eof()) {
  
        ss >> temp;
  
        if (std::stringstream(temp) >> f) {
            al.push_back(1);
            ac.push_back(1);
            size1++;
            getSolutionsP1(f);
            firstInput.push_back(f);
        }
        temp = "";
    }

    std::cout << maxLength << " " << counter << std::endl;
    return;    
}


void getSolutionsP1(int number) {
    int len=1, count=1;
    for (int i=0; i < size1-1; i++) {

        if (number > firstInput[i]) {
            if (al[i] + 1 > len) {

                len = al[i] + 1;
                count = ac[i];
                if (len > maxLength) { 
                    maxLength = len;
                    counter = 0;
                }
            }
            else if (al[i] + 1 == len) {
                count += ac[i];
            }
        }
    }
    al[size1-1] = len;
    ac[size1-1] = count;

    if (len == maxLength) { counter += count; }
}

void problemTwo() {

    int f;
    std::string str, temp;
    std::stringstream ss, ss1;
    std::cin >> f;
    firstInput.push_back(f);
    umap[f] = f;
    aux.push_back(0);

    std::getline(std::cin, str);
    ss << str;
    
    // receives the first input and stores it in a vector
    while (!ss.eof()) {
        ss >> temp;
        if (std::stringstream(temp) >> f) {
            firstInput.push_back(f);
            umap[f] = f;
            size1++;
            aux.push_back(0);
        }
        temp = "";
    }

    
    // second input
    std::cin >> f;
    getSolutionsP2(f);
    size2++;

    std::getline(std::cin, str);
    ss1 << str;


    while(!ss1.eof()) {
        ss1 >> temp;
        if (std::stringstream(temp) >> f) {
            if(umap.find(f) != umap.end()) {
                getSolutionsP2(f);
                size2++;
            }
        }
        temp = "";
    }
    for (int i=0; i<size1; i++) {
		if (aux[i] > maxLength) {
            maxLength = aux[i];
        }
    }

    std::cout << maxLength << std::endl;

}


void getSolutionsP2(int number) {
    
    int length = 0;
    for (int i=0; i < size1; i++) {
        
        if (number == firstInput[i] && length+1 > aux[i]) {
            aux[i] = length + 1;
            
        }
        if (number > firstInput[i] && aux[i] > length) {
            //printf("number: %d\n", number);
            //printf("firstInput: %d\n", firstInput[i]);
            length = aux[i];

        }
    }
}
