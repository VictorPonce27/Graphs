#include <iostream>
#include <vector> 
#include <algorithm>
#include <string> 
using namespace std;
#include "GraphsM.h"
#include "Graphs.h"
int main(){
    
    // vector<vector<char>> list = {{'A','B'},{'A','E'},{'A','H'},{'B','A'},{'B','C'},
    // {'B','E'},{'C','B'},{'C','D'},{'C','E'},{'C','F'},{'D','C'},{'E','A'},{'E','B'},{'E','C'},{'E','G'},
    // {'E','H'},{'F','C'},{'F','J'},{'G','E'},{'G','J'},{'H','A'},{'E','A'},{'H','E'},{'H','I'},{'H','J'},
    // {'I','H'},{'J','F'},{'J','G'},{'J','H'}};
    // Graphs<char> graph(list,10,26); 
    // GraphsM<char> graph2(list, 10,26); 

    vector<vector<int>> list = {{0,3,4},{0,4,8},{1,6,5},{2,6,9},{3,7,8},{4,2,3},{5,1,9},{5,6,7},{5,7,8},{7,5,9}};

    return 0;
}
