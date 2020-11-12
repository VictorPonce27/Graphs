#ifndef BFS_h
#define BFS_h 

#include <queue>
#include "Graphs.h"

template<class T> 
class BFS{
private:
    queue<T> temp; 
    Graphs<T> graph;
    int start; 
public:
    BFS(Graphs<T> graph, int start);
    
};

template<class T> 
BFS<T>::BFS(Graphs<T> graph, int start){
    this->graph = graph; 
    this->start = start; 
}




#endif //BFS_h 