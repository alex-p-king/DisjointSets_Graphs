#pragma once
#include <iostream>

struct Node{
    Node():_key(-1),_rank(0),_parent(this){}
    Node(int key):_key(key),_rank(0),_parent(this){}
    int _key;
    int _rank;
    Node * _parent;
};



class DisjointSet{
    public:
        DisjointSet(int size){
            _arr = new Node*[size];
            _size = size;
        }
        int find(int x){
            for(int i = 0; i < _size; i++){
                if(_arr[i]->_key == x){
                    Node * tmp = _arr[i];
                    while(_arr[i]->_parent->_key != _arr[i]->_key){
                        tmp = tmp->_parent;
                    }
                    return tmp->_key;
                }
            }
            return -1;
        }
        void Union(int r1, int r2){
            int root1 = find(r1);
            int root2 = find(r2);
            if(root1 == -1 || root2 == -1){
                std::cout << "Could not union sets\n";
                return;
            }
            int index1 = -1;
            int index2 = -1;
            for(int i = 0 ; i <_size; i++){
                if(_arr[i]->_key == root1){
                    index1 = i;
                }
                if(_arr[i]->_key == root2){
                    index2 = i;
                }
            }
            if(_arr[index1]->_key < _arr[index2]->_key){
                _arr[index2]->_parent = _arr[index1];
                _arr[index1]->_rank = _arr[index1]->_rank > _arr[index2]->_rank ? _arr[index1]->_rank : _arr[index2]->_rank;
                _arr[index1]->_rank++;
            }
            else{
                _arr[index1]->_parent = _arr[index2];
                _arr[index1]->_rank = _arr[index2]->_rank > _arr[index1]->_rank ? _arr[index2]->_rank : _arr[index1]->_rank;
            }
        }
    private:
        Node ** _arr;
        int _size;
};

