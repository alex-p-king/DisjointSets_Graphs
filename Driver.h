#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "DisjointSet.h"
#include <list>


class Driver{
    public:
        Driver(){
            
        }

        void menu(){
            std::cout << "***********************\n"
                      << "1) MakeSet\n"
                      << "2) Union\n"
                      << "3) Find\n"
                      << "4) PathCompression\n"
                      << "5) PrintPath\n"
                      << "6) BFS\n"
                      << "7) DFS\n"
                      << "8) Kruskal MST\n"
                      << "9) Prim MST\n"
                      << "10) Exit\n"
                      << "***********************\n"
                      << ">> ";
        }
        
        void run(){
            bool run = true;
            int choice;
            while(run){
                menu();
                std::cin >> choice;
                switch (choice)
                {
                case 1:{
                    std::ifstream infile;
                    infile.open("data.txt");
                    int num;
                    std::list<int> filedata;
                    while(!infile.eof()){
                        infile >> num;
                        filedata.push_back(num);
                    }
                    _set = new DisjointSet(filedata.size());
                    _set->makeSet(filedata);
                    std::cout << "The disjoint sets have been constructed.\n";
                    break;
                }
                case 2:{
                    //Union
                    int num1,num2;
                    std::cout << "Enter the first representative element: ";
                    std::cin >> num1;
                    std::cout << "Enter the second representative element: ";
                    std::cin >> num2;
                    _set->Union(num1,num2);
                    int representative = _set->find(num1);
                    std::cout << "Union on " << num1 << " and " << num2 << " has been done. The representative element is " << representative << std::endl;
                    break;
                }
                case 3:{
                    //Find
                    int key, rval;
                    std::cout << "Enter the element you would like to find: ";
                    std::cin >> key;
                    rval = _set->find(key);
                    if(rval == -1){
                        std::cout << key << "Sorry! " << key << " was not found!\n";
                    }
                    else{
                        std::cout << "Element " << key << " successfully found. The representative element is " << rval << std::endl;
                    }
                    break;
                }
                case 4:{
                    //PathCompression
                    break;
                }
                case 5:{
                    //PrintPath
                    int element;
                    std::cout << "Enter the element you want to find the path for: ";
                    std::cin >> element;
                    _set->printPath(element);
                    break;
                }
                case 6:{
                    //BFS
                    break;
                }
                case 7:{
                    //DFS
                    break;
                }
                case 8:{
                    //Kruskal MST
                    break;
                }
                case 9:{
                    //Prim MST
                    break;
                }
                case 10:{
                    run = false;
                }
                default:
                    break;
                }
            }
        }


    private:
        DisjointSet * _set;

};