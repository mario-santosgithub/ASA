#include <iostream>
#include <string>
#include <vector>

// Constants
#define FRIEND 1
#define NOFRIEND 0

// prototypes
void h1(std::vector<std::vector<int>> table);
void h2(std::vector<std::vector<int>> table);
void matrix(std::vector<std::vector<int>> table);

// global variables
int pnumber/* N */, fnumber/* M */;

int main() {

    int i, j, k, first, second;

    std::string firstInput, str;
    getline(std::cin, firstInput);
    str = firstInput[0];
    pnumber = std::stoi(str);
    str = firstInput.back();
    fnumber = std::stoi(str);

    
    std::vector<std::vector<int>> table(pnumber, std::vector<int>(fnumber+1, NOFRIEND));

    for(i=0; i < fnumber; i++) {
        std::cin >> first >> second;
        table[first-1][second-1] = FRIEND;
    }

    std::cout << "Histograma 1" << std::endl;
    h1(table);

    std::cout << "Histograma 2" << std::endl;
    h2(table);

    std::cout << std::endl;
    matrix(table);

    return 0;
}


void h1(std::vector<std::vector<int>> table) {
    int i, j, k;
    for(k=0; k < pnumber; k++) { // number max of friends is total-1

        int counter = 0;
        for(i=0; i < pnumber; i++) {

            int friends = 0;
            for(j=0; j <= fnumber; j++) {
                if (table[i][j] == FRIEND) {
                    friends++;
                }
            }
            if (friends == k) {
                counter++;
            }
        }
        std::cout << counter << std::endl;
    }
    i = pnumber;
    while(i<fnumber) {
        std::cout << 0 << std::endl;
        i++;
    }
}

void h2(std::vector<std::vector<int>> table) {
    int i, j, k;
    for(k=0; k < fnumber; k++) { // number max of friends is total-1
        int counter = 0;

        for(j=0; j < pnumber; j++) {
            int friends = 0;
            for(i=0; i < fnumber; i++) {
                if (table[i][j] == FRIEND) {
                    friends++;
                }
            }
            if (friends == k) {
                counter++;
            }
        }
        if (k <= fnumber) {
            std::cout << counter << std::endl;
        }
    }
    i = fnumber;
    while(i<pnumber) {
        std::cout << 0 << std::endl;
        i++;
    }
}

void matrix(std::vector<std::vector<int>> table) {
    int i, j, k;
    for(k=0; k < pnumber; k++) {
        for(i=0; i < pnumber; i++) {

            int friends = 0; // in common
            for(j=0; j <= fnumber; j++) {

                if ((table[k][j] == table[i][j]) && (table[k][j] == FRIEND)) {
                        friends++;
                }   
            }
            std::cout << friends << " ";
        }
        std::cout << std::endl;
    }
}
