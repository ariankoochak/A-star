#include <iostream>

using namespace std;

const int vertexNum = 13;
const int edgeNum = 18;
int fFunc[vertexNum];
int hFunc[vertexNum] = {9,7,8,8,0,6,3,6,4,4,3,6,10};
int gFunc[vertexNum];
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
        fFunc[i] = 10000000;
    }
}

void fFuncUpdate(int vertex){
    for(int i = 0;i < edgeNum;i++){
        if(graph[i][0] == vertex && fFunc[graph[i][1]] > (graph[i][2] + gFunc[vertex] + hFunc[graph[i][1]])){             //check gN , not fN for min
            fFunc[graph[i][1]] = (graph[i][2] + gFunc[vertex] + hFunc[graph[i][1]]);
            gFunc[graph[i][1]] = gFunc[vertex] + graph[i][2];
        }
        else if (graph[i][1] == vertex && fFunc[graph[i][0]] > (graph[i][2] + gFunc[vertex] + hFunc[graph[i][0]]))
        {
            fFunc[graph[i][0]] = (graph[i][2] + gFunc[vertex] + hFunc[graph[i][0]]);
            gFunc[graph[i][0]] = gFunc[vertex] + graph[i][2];
        }
    }
}

int main() {
    // cout<<"enter origin \n";
    // cin>> nowNode;
    // cout << "enter dest \n";
    // cin >> destNode;
    nowNode = 12;
    gFunc[nowNode] = 0;
    prepareArrays();
    fFuncUpdate(nowNode);
    for(int i = 0; i < vertexNum;i++){
        cout<<fFunc[i]<<" , ";
    }
    cout<<endl;
    for (int i = 0; i < vertexNum; i++)
    {
        cout << gFunc[i] << " , ";
    }
    fFuncUpdate(1);
    cout<<"\n\n";
    for (int i = 0; i < vertexNum; i++)
    {
        cout << fFunc[i] << " , ";
    }
    cout << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        cout << gFunc[i] << " , ";
    }
}
