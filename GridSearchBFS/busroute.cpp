//
// Created by Adam Levin on 2/17/19.
//

#include "busroute.h"



busroute::busroute(vector<vector<int>> & grid) {
    dist = new vector<house>();
    for (int i = 0; i < (int)grid.size(); i++){
        for (int j = 0; j < (int) grid[0].size(); j++){
            if (grid[i][j] == 1){ // if at a house
                cout << " house " << i << " "<< j << endl;
                house temp = house(j,i,grid[i][j]);
                point start = point(j,i,type);
                temp.stopdist = bfs(grid, start);
                (*dist).push_back(temp);
            }
        }
    }

}

int busroute::bfs(vector<vector<int>> & grid, point start) {
    vector<point> visited;
    visited.push_back(start);
    point cur, temp1, temp2, temp3, temp4;
    queue<point> q;
    q.push(start);
    while(!q.empty()){
        cur = q.front();
        q.pop();

        if (cur.col + 1  < (int) grid[0].size()){
            temp1 = point(cur.col + 1, cur.row, grid[cur.row][cur.col+1],cur.dist + 1);
            if (!isvisited(visited,temp1)){
                if (temp1.type == 3) { // is a bus stop
                    return temp1.dist;
                } else if (temp1.type == 2) { // is a street
                    q.push(temp1);
                    visited.push_back(temp1);
                }
            }
        }
        if(cur.col -1  > -1){
            temp2 = point(cur.col - 1, cur.row, grid[cur.row][cur.col-1],cur.dist + 1);
            if (!isvisited(visited,temp2)) {
                if (temp2.type == 3) { // is a bus stop
                    return temp2.dist;
                } else if (temp2.type == 2) { // is a street
                    q.push(temp2);
                    visited.push_back(temp2);
                }
            }
        }
        if (cur.row + 1  < (int)grid.size()){
            temp3 = point(cur.col, cur.row + 1, grid[cur.row + 1][cur.col],cur.dist + 1);
            if (!isvisited(visited,temp3)) {
                if (temp3.type == 3) { // is a bus stop
                    return temp3.dist;
                } else if (temp3.type == 2) { // is a street
                    q.push(temp3);
                    visited.push_back(temp3);
                }
            }
        }
        if(cur.row -1  > -1){
            temp4 = point(cur.col, cur.row - 1, grid[cur.row - 1][cur.col],cur.dist + 1);
            if (!isvisited(visited,temp4)) {
                if (temp4.type == 3) { // is a bus stop
                    return temp4.dist;
                } else if (temp4.type == 2) { // is a street
                    q.push(temp4);
                    visited.push_back(temp4);
                }
            }
        }

    }
    return -1;
}

void busroute::printhousedist() {
    for (int i = 0; i < dist->size(); i++){
        cout << "Distance to closest bus stop for house located at: ("
                << (*dist)[i].col << "," << (*dist)[i].row << "), is " << (*dist)[i].stopdist << "." << endl;
    }
}

bool busroute::isvisited(vector<point> &visited, point p) {
    for (int i = 0; i < visited.size(); i++){
        if (visited[i].row == p.row && visited[i].col == p.col){
            return true;
        }
    }
    return false;
}
