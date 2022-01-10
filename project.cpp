#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

// Prototypes for functions
void problemOne();
void getSolutionsP1(int number);
void problemTwo();
void getSolutionsP2(int number);

// Global variables
std::vector<int> firstInput, aux, ac, al;
int maxLength = 1, counter = 1, size1 = 1, size2 = 0;

// Main function
int main() {
    int problem;
    std::cin >> problem; // receives the problem (first input line)

    if (problem == 1) { problemOne(); }
    else if (problem == 2) { problemTwo(); }

    return 0;
}

// Function to solve problem one
void problemOne() {
    int number;
    std::string str, temp;
    std::stringstream ss;


    std::cin >> number;
    firstInput.push_back(number);
    al.push_back(1); // the maxlength is currently 1
    ac.push_back(1); // the counter is currently 1

    std::getline(std::cin, str); // gets the line, without the first number
    ss << str;

    // if only 1 number
    if (str == " ") { std::cout << maxLength << " " << counter << std::endl; return; }

    while (!ss.eof()) { // while it doesnt reach the end of the line
        ss >> temp;
        
        if (std::stringstream(temp) >> number) { // if its a number
            getSolutionsP1(number);
            size1++;
            firstInput.push_back(number);
        }
        temp = ""; // reset the string
    }
    
    std::cout << maxLength << " " << counter << std::endl;
    return;
}

// Function to get the solutions for problem one
void getSolutionsP1(int number) {
    int len = 1, count = 1;
    for (int i=0; i < size1; i++) { // check the previous numbers

        if (number > firstInput[i]) { // if number is bigger than a previous
            if (al[i]+1 > len) { // and the lenght+1 will be bigger

                len = al[i] + 1;
                count = ac[i];
                if (len > maxLength) {
                    maxLength = len;
                    counter = 0;
                }
            }
            else if (al[i] + 1 == len) { // if the same length is reached, add
                count += ac[i];     //  one to the count
            }
        }
    }
    al.push_back(len); // save the two values in the vectors
    ac.push_back(count);

    if (len == maxLength) { counter += count; }
}

// Function to solve problem two
void problemTwo() {

    int number;
    std::string str, temp;
    std::stringstream ss, ss1;
    std::unordered_map<int, int> umap; //used to save the first input values
    maxLength = 0;
    std::cin >> number;
    firstInput.push_back(number);
    umap[number] = number;
    aux.push_back(0); // the aux vector starts with the value at 0

    std::getline(std::cin, str);
    ss << str;

    // receives the first input and stores it
    while (!ss.eof()) {
        ss >> temp;
        if (std::stringstream(temp) >> number) {
            firstInput.push_back(number);
            umap[number] = number;
            size1++;
            aux.push_back(0); // the aux vector starts the value at 0
        }
        temp = "";
    }

    // second input
    std::cin >> number;
    getSolutionsP2(number);
    size2++;

    std::getline(std::cin, str);
    ss1 << str;

    while (!ss1.eof()) {
        ss1 >> temp;
        if (std::stringstream(temp) >> number) {
            if (umap.find(number) != umap.end()) {
                getSolutionsP2(number);
                size2++;
            }
        }
        temp = "";
    }

    std::cout << maxLength << std::endl;
}

// Funtion to get the solution to problem two
void getSolutionsP2(int number) {
    
    int length = 0;
    for (int i=0; i < size1; i++) {
        
        if (number == firstInput[i] && length+1 > aux[i]) {
            aux[i] = length + 1;
            if (length+1 > maxLength) {maxLength = length+1;}
            
        }
        if (number > firstInput[i] && aux[i] > length) {
            length = aux[i];

        }
    }
}
