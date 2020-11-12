#ifndef GBP_h
#define GBP_h

#include<queue>
#include<stack> 

template<class T> 
class Graphs{
private:
    vector<vector<T>> adjList; 
    vector<T> vert; 
    int numVert; 
    int numEdges;
    int find_vert(T vert);
    void DFS_search(T vert, vector<bool> &done); 
public:
    Graphs(vector<vector<T>> list, int numVert, int numEdges);
    void print(); 
    void BFS(T start); 
    void DFS(T start); 
};


template <class T>
Graphs<T>::Graphs(vector<vector<T>> list, int numVert, int numEdges){
    this->numEdges = numEdges; 
    this->numVert = numVert; 
    int org = 0; 
    int tar = 1; 
    for(vector<T> edge:list){
        T temp = edge[org]; 
        int pos = find_vert(temp); 
        if(pos >= 0){
            adjList[pos].push_back(edge[tar]); 
         }
        else{
            vert.push_back(temp); 
            adjList.push_back(edge); 
        }
    }

    if(vert.size() < numVert){
        for(vector<T> edge:list){
            T temp = edge[tar];
            int pos = find_vert(temp); 
            if (pos<0){
                vert.push_back(temp);
                vector<T> tempVert; 
                tempVert.push_back(temp); 
                adjList.push_back(tempVert);
            } 
        }   
    }

}

template<class T> 
int Graphs<T>::find_vert(T num){
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
void Graphs<T>::print(){
    for(vector<T> edge:adjList){
        for(T node:edge){
            cout<<node<<"->";
        }
        cout<<endl;
    }
}

template<class T> 
void Graphs<T>::BFS(T start){
    queue<int> temp; 
    vector<bool> done (vert.size(),false); 

    temp.push(start); 
    done[start] = true; 
    
    while(!temp.empty()){
        start = temp.front(); 
        for(int adj = 0; adj<adjList[start].size();adj++){
            int pos = find_vert(adjList[start][adj]); 
            if(!done[pos]){
                temp.push(pos); 
                done[pos] = true; 

            }
        }
        cout<<vert[start] << " "; 
        temp.pop(); 
    }
}


template<class T> 
void Graphs<T>::DFS(T start){
    vector<bool> done(vert.size(),false); 
    DFS_search(vert[start], done); 
    cout<<endl;
}

template <class T>
void Graphs<T>::DFS_search(T vert, vector<bool> &done){
    int pos = find_vert(vert); 
    if(!done[pos]){
        cout<< this->vert[pos] << " "; 
        done[pos] = true; 
        for(auto adj: adjList[pos]){
            int posAdj = find_vert(adj); 
            if(!done[posAdj]){
                DFS_search(adj, done); 
            }
        }
    }
}

#endif //GBP_h