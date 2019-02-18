//
// Created by Adam Levin on 2/17/19.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


#ifndef TRAINING1_BUSROUTE_H
#define TRAINING1_BUSROUTE_H


class point{
public:
    point(int col = 0, int row = 0, int type = 1, int dist = 0) : col(col),row(row),type(type), dist(dist){}
    int col;
    int row;
    int type;
    int dist;

};

// inheritance for point class
class house : public point{
public:
    house(int col =0, int row = 0, int type = 0){
        this->col = col;
        this->row = row;
        this->type = type;
        stopdist = -1;
        dist = 0;
    }
    int stopdist;
};


//class
class busroute : public house{
public:
    busroute(vector<vector<int>> & grid);
    int bfs(vector<vector<int>> & grid, point start);
    void printhousedist();
    bool isvisited(vector<point> & visited, point p);
private:
    vector<house> * dist;
};









#endif //TRAINING1_BUSROUTE_H
