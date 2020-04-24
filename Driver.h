#pragma once
#include <iostream>




class Driver{
    public:
        Driver();

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
                    //MakeSet
                    break;
                }
                case 2:{
                    //Union
                    break;
                }
                case 3:{
                    //Find
                    break;
                }
                case 4:{
                    //PathCompression
                    break;
                }
                case 5:{
                    //PrintPath
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


};