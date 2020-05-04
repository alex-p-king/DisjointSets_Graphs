#pragma once
#include <string>
#include <iostream>
#include <vector>
struct Island{
    explicit Island(std::string name, int islandNumber):_name(name),_islandNumber(islandNumber){}
    std::string _name;
    int _islandNumber;
    friend std::ostream& operator<<(std::ostream& o, Island i){
        o << i._name << " " << i._islandNumber;
        return o;
    }
};
class Graph{
    public:
        Graph(int size, int ** arr){
            _size = size;
            _weightMatrix = new int*[_size];
            for(int i = 0; i < _size; i++){
                _weightMatrix[i] = new int[_size];
            }
            for(int i = 0; i < _size; i++){
                for(int j = 0; j < _size; j++){
                    _weightMatrix[i][j] = arr[i][j];
                }
            }
        }
        ~Graph(){
            for(int i = 0; i < _size; i++){
                delete[] _weightMatrix[i];
            }
        }
        void printWeights(){
            std::cout << "printing weights" << std::endl;
            for(int i = 0; i < _size; i++){
                for(int j = 0; j < _size; j++){
                    std::cout << _weightMatrix[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        void printIslands(){
            std::cout << "printing islands\n";
            for(int i = 0; i < _size; i++ ){
                std::cout << _islandList.at(i) << " ";
            }
            std::cout << std::endl;
        }
        void setIslandList(std::vector<Island> i){
            _islandList = i;
        }

    private:
        int ** _weightMatrix;
        int _size;
        std::vector<Island> _islandList;
};