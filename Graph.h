#pragma once
#include "DisjointSet.h"
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

        void bfs(){
            std::vector<bool> visited(_size,false);
            std::vector<int> q;
            q.push_back(0);
            visited[0] = true;
            std::string from;
            std::string to;
            int tmp;
            while(!q.empty()){
                tmp = q[0];
                from = translate(q[0]);
                q.erase(q.begin());
                for(int i = 0; i < _size; i++){
                    if(_weightMatrix[tmp][i] >= 1 && (!visited[i])){
                        q.push_back(i);
                        to = translate(i);
                        std::cout << "(" << from << ", " << to << ") ";
                        visited[i] = true;
                    }
                }
            }
        } 
        void dfs(int num, std::vector<bool>& visited){
            
            visited[num] = true;
            for(int i = 0; i < _size; i++){
                if(_weightMatrix[num][i] >= 1 && (!visited[i])){
                    std::string from = translate(num);
                    std::string to = translate(i);
                    std::cout << "(" << from << ", " << to << ") "; 
                    dfs(i,visited);
                }
            }
        }
        std::string translate(int islandNumber){
            switch (islandNumber)
            {
            case 0:
                return "Tyrannosaurus Rex";
            case 1:
                return "Velociraptors";
            case 2:
                return "Indominous Rex";
            case 3:
                return "Mososaurus";
            case 4:
                return "Spinosaurus";
            default:
                break;
            }
        }

        void kruskals(){
            DisjointSet ds(_size);
            std::list<int> data = {0,1,2,3,4};
            ds.makeSet(data);
            int minimumCostEdge,numberOfEdges;
            minimumCostEdge = numberOfEdges = 0;
            while( numberOfEdges < _size - 1){
                int min = 100, a = -1, b = -1;
                for(int i = 0; i < _size; i++){
                    for(int j = 0; j < _size; j++){
                        if(ds.find(i) != ds.find(j) && _weightMatrix[i][j] < min && _weightMatrix[i][j] != -1){
                            min = _weightMatrix[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
                ds.Union(a,b);
                printf("Edge %d:(%d, %d) cost: %d\n",numberOfEdges++,a,b,min);
                minimumCostEdge += min; 
            }
            std::cout << "Minimum Cost: " << minimumCostEdge << std::endl;

        }
        void prims(){

        }

    private:
        int ** _weightMatrix;
        int _size;
        std::vector<Island> _islandList;
};