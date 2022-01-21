#include <iostream>
#include <vector>

using namespace std;

// Colors to use on the DFS
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define PURPLE 3

// Prototypes
void graphVerify(int nodeNum);
void getSolutions1(int nodeNum);
void getSolutions2(int nodeNum);
void getSolutions3(int nodeNum);


// Global variables
int invalid = 0, targetV1, targetV2, solutions = 0;
int vertices; //vertices (n)
vector<vector<int>> graph;

// Main function
int main() {

    int arcs, x , y; //arcos (m) input x (v1) e y (v2)
    int counter=0;

    cin >> targetV1 >> targetV2;
    cin >> vertices >> arcs; 

    // we are going to have a number of vertices, so start the graph; tudo a 0
    // vector<vector<int>> graph(vertices, vector<int>(4, 0));
    graph.resize(vertices);
    for( int i = 0; i<vertices; i++){
        graph[i] = {0, 0, 0, WHITE};
    }
    
    if (arcs < 0) { invalid++; }
    if (vertices < 1) { invalid++; }

    while (cin >> x >> y) {
        counter++;
        if (graph[y-1][0] < 2 && invalid == 0) {

            graph[y-1][0]++; // number of parrents of this vertice
            if (graph[y-1][1] == 0) { graph[y-1][1] = x; } // add the first parrent
            else { graph[y-1][2] = x; } // add the second parent
        }
        else { invalid++; } // if number of parents == 2 then it's invalid, 
        // we cant add more

    }
    if (counter != arcs) {invalid++;}
    if (invalid != 0) { cout << "0" << endl; return 0; }

    //verify if cicles exist for every node(i) in vector
    for(int i=1; i <= vertices; i++){
        if(invalid == 0){ graphVerify(i);}
        else{ break;}
    }
    
    if(invalid != 0) { cout << "0" << endl; return 0;}

    getSolutions1(targetV1);
    getSolutions2(targetV2);

    for (int i=0; i < vertices; i++) {
        if (graph[i][3] == PURPLE) { 
            solutions++;
            cout << i+1 << " "; 
        }
    }
    if (solutions == 0) { cout << "-"; }

    cout << endl;
    return 0;
}


// its called for every node in the graph
// Function that verifies if the graph is valid
void graphVerify(int nodeNum) {

    if (graph[nodeNum-1][3] == GRAY) {
        invalid++;
        return;
    }

    if (graph[nodeNum-1][3] == WHITE) { graph[nodeNum-1][3] = GRAY; }
    
    if (graph[nodeNum-1][3] == BLACK) {return; }

    for (int j=1; j <= graph[nodeNum-1][0]; j++) {
        graphVerify(graph[nodeNum-1][j]);
    }
    //after all parents visited, white turns black
    graph[nodeNum-1][3] = BLACK;
}


void getSolutions1(int nodeNum){


    if (graph[nodeNum-1][3] == WHITE) { return; }

    if (graph[nodeNum-1][3] == BLACK) {
        graph[nodeNum-1][3] = WHITE;
    }

    for( int i=1; i <= graph[nodeNum-1][0]; i++){
        getSolutions1(graph[nodeNum-1][i]);
    }

}

void getSolutions2(int nodeNum){

    if (graph[nodeNum-1][3] == GRAY) { return; }
    // a possible solution
    if( graph[nodeNum-1][3] == WHITE){
        graph[nodeNum-1][3] = PURPLE;
        // his ancestrals (?) are marked with gray
        for (int i=1; i <= graph[nodeNum-1][0]; i++) {
            getSolutions3(graph[nodeNum-1][i]);
        }
    }

    if (graph[nodeNum-1][3] == BLACK) {
        for (int i=1; i <= graph[nodeNum-1][0]; i++) {
            getSolutions2(graph[nodeNum-1][i]);
        }
    }


}

void getSolutions3(int nodeNum) {

    //far common ancestors
    if (graph[nodeNum-1][3] == GRAY) {return;}

    if( graph[nodeNum-1][3] == WHITE || graph[nodeNum-1][3] == PURPLE){
        graph[nodeNum-1][3] = GRAY;
    }

    for( int i=1; i <= graph[nodeNum-1][0]; i++){
        getSolutions3(graph[nodeNum-1][i]);
    }
}
