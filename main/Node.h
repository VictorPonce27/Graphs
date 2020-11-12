#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

template<class T>
struct Node{
    T data;
    Node<T> *next;
    Node<T> *prev;
    
    Node(T);
    Node(T, Node<T>*, Node<T>*);
    void print(); 
};

template<class T>
Node<T> :: Node(T data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

template<class T>
Node<T> :: Node(T data, Node<T> *next, Node<T> *prev){
    this->data = data;
    this->next = next;
    this->prev = prev;
}
template<class T> 
void Node<T>::print(){
    cout<<data<<endl;
}

