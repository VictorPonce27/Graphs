#ifndef Graphs_h
#define Graphs_h

// using namespace std;
#include<queue> 
#include<stack> 

template <class T> 
class GraphsM{
private:
    vector<vector<bool>> adjMatrix; 
    vector<T> vert;
    int vertNum; 
    int arcNum;
    int find_vert(T vert);
    void DFS_search(T vert, vector<bool> &done); 

public:
    GraphsM(vector<vector<T>> list, int vertNum, int arcNum);
    void print(); 
    void BFS(T start); 
    void DFS(T start); 
};

template <class T>
GraphsM<T>::GraphsM(vector<vector<T>> list, int vertNum, int arcNum){
    this->vertNum = vertNum;
    this->arcNum = arcNum; 
    int org = 0; 
    int tar = 1; 
    for(int i = 0; i<vertNum; i++){
        vector<bool> temp;
        for(int j = 0; j<vertNum; j++){
            temp.push_back(false); 
        }
        adjMatrix.push_back(temp); 
    }
    for(vector<T> edge:list){
        T temp = edge[org]; 
        int pos = find_vert(temp); 
        if(pos < 0){ // not found
            vert.push_back(temp); 
        }
        else{
            T temp = edge[tar]; 
            int pos = find_vert(temp); 
            if(pos < 0){ // not found
                vert.push_back(temp); 
            }
        }
    }
    sort(vert.begin(), vert.end()); 
    for(vector<T> edge: list){
        int posSource = find_vert(edge[org]);
        int posTarget = find_vert(edge[tar]); 
        adjMatrix[posSource][posTarget] = true;  
    }
}   


template<class T> 
int GraphsM<T>::find_vert(T num){
    typename vector<T>::iterator it;
    it = find(vert.begin(), vert.end(), num);
    if(it != vert.end()){
        return (it-vert.begin());
    }
    else{
        return -1; 
    }
}

template<class T> 
void GraphsM<T>::print(){
    for(T val : vert){
        cout<<" " << val; 
    }
    cout<<endl;
    for(int i = 0; i<vertNum; i++){
        cout<< vert[i]<<" ";
        for(int j = 0; j<vertNum; j++){
            if(adjMatrix[i][j]){
                cout<<"T" <<" "; 
            }
            else{
                cout<<"F"<<" "; 
            }
            
        }
        cout<<endl;
    }
}

template <class T> 
void GraphsM<T>::BFS(T start){
    queue<int> temp; 
    vector<bool> done(vert.size(), false); 

    temp.push(vert[start]); 
    done[start] = true; 
    
    while(!temp.empty()){
        T at = temp.front(); 
        cout<< at << " "; 
        int pos = find_vert(at); 
        for(int adj = 0; adj<vert.size();adj++){
            if(adjMatrix[pos][adj]){
                if(!done[adj]){
                    temp.push(vert[adj]); 
                    done[adj] = true;
                }
            }
        }
        temp.pop(); 
    }
    
}

template<class T> 
void GraphsM<T>::DFS(T start){
    vector<bool> done(vert.size(),false); 
    DFS_search(vert[start], done); 
    cout<<endl;
}

template <class T>
void GraphsM<T>::DFS_search(T vert, vector<bool> &done){
    int pos = find_vert(vert); 
    if(!done[pos]){
        cout<< this->vert[pos] << " "; 
        done[pos] = true; 
        for(int adj = 0; adj < this->vert.size(); adj++){
            if(adjMatrix[pos][adj]){
                if(!done[adj]){
                    DFS_search(this->vert[adj], done); 
                }
            }
        }
    }
}


#endif// Graphs_h