#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <list>
struct Node{
    Node():_key(-1),_rank(0),_parent(nullptr){}
    Node(int key):_key(key),_rank(0),_parent(nullptr){}
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

        void makeSet(std::list<int> data){
            int val;
            for(int i = 0; i < _size; i++){
                val = data.front();
                _arr[i] = new Node(val);
                data.pop_front();   
            }
        }

        int find(int x){
            for(int i = 0; i < _size; i++){
                if(_arr[i]->_key == x){
                    Node * tmp = _arr[i];
                    while(tmp->_parent){
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
            if(_arr[index1]->_rank > _arr[index2]->_rank){
                _arr[index2]->_parent = _arr[index1];
                _arr[index1]->_rank = _arr[index1]->_rank > _arr[index2]->_rank ? _arr[index1]->_rank : _arr[index2]->_rank;
                _arr[index1]->_rank++;
            }
            else if(_arr[index1]->_rank < _arr[index2]->_rank){
                _arr[index1]->_parent = _arr[index2];
                _arr[index2]->_rank = _arr[index2]->_rank > _arr[index1]->_rank ? _arr[index2]->_rank : _arr[index1]->_rank;
                _arr[index2]->_rank++;
            }
            else{
                if(_arr[index1]->_key < _arr[index2]->_key){
                _arr[index2]->_parent = _arr[index1];
                _arr[index1]->_rank = _arr[index1]->_rank > _arr[index2]->_rank ? _arr[index1]->_rank : _arr[index2]->_rank;
                _arr[index1]->_rank++;
                }
                else{
                    _arr[index1]->_parent = _arr[index2];
                    _arr[index2]->_rank = _arr[index2]->_rank > _arr[index1]->_rank ? _arr[index2]->_rank : _arr[index1]->_rank;
                    _arr[index2]->_rank++;
                }
            }
            
        }

        void pathCompression(int element){
            int parent = find(element);
            Node * parentNode;
            for(int i = 0; i < _size; i++){
                if(_arr[i]->_key == parent){
                    parentNode = _arr[i];
                }
            }
            for(int i = 0; i < _size; i++){
                if(_arr[i]->_key == element){
                    Node * tmp = _arr[i];
                    Node * tmp2 = tmp;
                    while(tmp){
                        tmp2 = tmp2->_parent;
                        tmp->_parent = parentNode;
                        tmp = tmp2;
                    }
                }
            }
        }

        void printPath(int element){
            Node * tmp;
            for(int i = 0; i < _size; i++){
                if(_arr[i]->_key == element){
                    tmp = _arr[i];
                    while(tmp){
                    std::cout << "Element: " << tmp->_key << std::endl;
                    tmp = tmp->_parent;
                    }
                }
            }
        }
    private:
        Node ** _arr;
        int _size;
};

