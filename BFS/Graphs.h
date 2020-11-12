#ifndef GBP_h
#define GBP_h

template<class T> 
class Graphs{
private:
    vector<vector<T>> adjList; 
    vector<T> vert; 
    int numVert; 
    int numEdges;
    int find_vert(T vert);
public:
    Graphs(vector<vector<T>> list, int numVert, int numEdges);
    void print(); 
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


#endif //GBP_h