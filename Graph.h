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

        bool validate(int a, int b, std::vector<bool> vec){
            if(a == b)
                return false;
            if(vec[a] == false && vec[b] == false)
                return false;
            if(vec[a] == true && vec[b] == true)
                return false;
            return true;
        }
        void kruskals(){
            DisjointSet ds(_size);
            std::list<int> data;
            for(unsigned int i = 0; i < _islandList.size(); i++){
                data.push_back(_islandList.at(i)._islandNumber - 1);
            }
            std::vector<std::string> edges;
            std::string from,to,tmp;
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
                from = translate(a), to = translate(b);
                tmp = "(" + from + ", " + to + ')';
                edges.push_back(tmp);
                numberOfEdges++;
                minimumCostEdge += min; 
            }
            for(unsigned int i = 0; i < edges.size(); i++){
                std::cout << edges.at(i) << " ";
            }
            std::cout << std::endl;
            std::cout << "Total length of the route = " << minimumCostEdge << " miles" << std::endl;
            std::cout << "Total estimate to construct the bridges in the route = " << minimumCostEdge << "*" << 250000 << " = " << minimumCostEdge*250000 << "$" << std::endl;

        }
        void prims(){
            std::vector<bool> visited(_size, false);
            std::vector<std::string> edges;
            std::string from,to,tmp;
            visited[0] = true;
            int numberOfEdges, minimumCostEdge;
            numberOfEdges = minimumCostEdge = 0;
            while(numberOfEdges < _size - 1){
                int min = 100, a = -1, b = -1;
                for(int i = 0; i < _size; i++){
                    for(int j = 0; j < _size; j++){
                        if(_weightMatrix[i][j] < min && validate(i,j,visited) && _weightMatrix[i][j] != -1){
                            min = _weightMatrix[i][j], a = i, b = j;
                        }
                    }
                }
                if(a != b != -1){
                    from = translate(a);
                    to = translate(b);
                    tmp = "(" + from + ", " + to + ')';
                    edges.push_back(tmp);
                    numberOfEdges++;
                    minimumCostEdge += min;
                    visited[a] = true;
                    visited[b] = true;
                }
            }
            for(unsigned int i = 0; i < edges.size(); i++){
                std::cout << edges.at(i) << " ";
            }
            std::cout << std::endl;
            std::cout << "Total length of the route = " << minimumCostEdge << " miles" << std::endl;
            std::cout << "Total estimate to construct the bridges in the route = " << minimumCostEdge << "*" << 250000 << " = " << minimumCostEdge*250000 << "$" << std::endl;
        }
        int getSize(){return _size;}

    private:
        int ** _weightMatrix;
        int _size;
        std::vector<Island> _islandList;
};