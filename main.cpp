#include <iostream>

using namespace std;

const int vertexNum = 13;
const int edgeNum = 18;
int fFunc[vertexNum];
int hFunc[vertexNum] = {9,7,8,8,0,6,3,6,4,4,3,6,10};
int gFunc[vertexNum];
int path[vertexNum];
int pathCounter = 0;
int closeNode[vertexNum];
int nowNode;
int destNode;
int graph[edgeNum][3]={
    {0,1,3},
    {0,3,4},
    {0,12,7},
    {1,3,4},
    {1,7,1},
    {1,12,2},
    {2,11,2},
    {2,12,3},
    {3,5,5},
    {4,6,2},
    {4,10,5},
    {5,7,3},
    {6,7,2},
    {8,9,6},
    {8,10,4},
    {8,11,4},
    {9,10,4},
    {9,11,4},
};


void prepareArrays(){
    for(int i = 0;i < vertexNum;i++){
        gFunc[i] = 10000000;
        fFunc[i] = 10000000;
        closeNode[i] = -1;
    }
    gFunc[nowNode] = 0;
}

int minFFunc(){
    int res = 100000;
    for(int i = 0;i < vertexNum;i++){
        if(res > fFunc[i] && closeNode[i] != 1)
            res = i;
    }
    return res;
}

void fFuncUpdate(int vertex){
    for(int i = 0;i < edgeNum;i++){
        if(graph[i][0] == vertex && gFunc[graph[i][1]] > (gFunc[vertex] + graph[i][2])){
            gFunc[graph[i][1]] = gFunc[vertex] + graph[i][2];
            fFunc[graph[i][1]] = gFunc[graph[i][1]] + hFunc[graph[i][1]];
        }
        else if (graph[i][1] == vertex && gFunc[graph[i][0]] > (gFunc[vertex] + graph[i][2]))
        {
            gFunc[graph[i][0]] = gFunc[vertex] + graph[i][2];
            fFunc[graph[i][0]] = gFunc[graph[i][0]] + hFunc[graph[i][0]];
        }
    }
}

int main() {
    nowNode = 12;
    destNode = 4;
    prepareArrays();
    while(nowNode != destNode){
        path[pathCounter] = nowNode;
        pathCounter++;
        fFuncUpdate(nowNode);
        closeNode[nowNode] = 1;
        nowNode = minFFunc();
    }
    for(int i = 0;i < vertexNum;i++){
        cout<<path[i]<<"  ,   ";
    }
}
