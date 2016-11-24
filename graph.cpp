#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdio>
#include <utility>
#include <set>
#include <algorithm>
#include <list>

using namespace std;

vector <string> parseFile(char * fileName);

vector <string> parseFile(char * fileName){
	ifstream myFile;
	myFile.open(fileName);

	vector<string> lines;
	string line;

	if(myFile.is_open()){
		while(getline(myFile, line)){
			lines.push_back(line);
		}
	}
	else{
		cout<<"Unable to open the file"<<endl;
	}
	return lines;
}

class Graph{
	int V; //number of vertices
	list<int>*adj;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	void AddEdge(int v, int w);
	void DFS(int v);
};

Graph::Graph(int V){
	this -> V = V;
	adj = new list<int>[V];
}

int main ()
{
	vector <string> lines = parseFile("file.txt");

	int length = lines.size();

	for(int i = 0; i < length; i++){
		cout<<lines[i]<<endl;
	}

	return 0;
}