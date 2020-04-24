#pragma once

class DisjointSet{
    public:
        explicit DisjointSet(int size);
        int find(int x)const;
        int find(int x);
        void unionSets(int r1, int r2);
    private:
        int * arr;

};

DisjointSet::DisjointSet(int size){
    arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = -1;
    }
}

void DisjointSet::unionSets(int r1, int r2){
    arr[r2] = r1;
}

int DisjointSet::find(int x)const{
    if(arr[x] < 0)
        return x;
    return find(arr[x]);
}

int DisjointSet::find(int x){
    if(arr[x] < 0)
        return x;
    return arr[x] = find(arr[x]);
}