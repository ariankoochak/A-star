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
int prevNode;
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
		fFunc[i] = gFunc[i] = closeNode[i] = -1;
	}
	gFunc[nowNode] = 0;
	fFunc[nowNode] = hFunc[nowNode];
	closeNode[nowNode] = 1;
}

int findEdge(int a,int b){
	for(int i = 0; i < edgeNum;i++){
		if((graph[i][1] == a && graph[i][0] == b) || (graph[i][1] == b && graph[i][0] == a))
			return graph[i][2];
	}
	return 0;
}

void setGforNeighbors(int nowNum){
	for(int i = 0;i < vertexNum;i++){
		int bEdge = findEdge(nowNum, i);
		if(bEdge != 0 && closeNode[i] == -1){
			gFunc[i] = bEdge + gFunc[nowNum];
			fFunc[i] = gFunc[i] + hFunc[i];
		}
	}
}
void selectNextNode(){
	int minNum = -1;
	int minF = 100000;
	for(int i = 0;i < vertexNum;i++){
		if(fFunc[i] != -1 && minF > fFunc[i] && closeNode[i] == -1){
			minNum = i;
			minF = fFunc[i];
		}
	}
	
	nowNode = minNum;
}
int main() {
	nowNode = 12;
	destNode = 4;
	prepareArrays();
	path[pathCounter++] = nowNode;
	while(nowNode != destNode){
		setGforNeighbors(nowNode);
		selectNextNode();
		closeNode[nowNode] = 1;
		cout<<endl;
		path[pathCounter++] = nowNode;
	}
	cout<<"Your best Path :";
	for(int i = 0;i < vertexNum;i++){
		if(path[i] == 0)
			break;
		cout<<" "<<path[i]<<" ";
	}
	return 0;
}
