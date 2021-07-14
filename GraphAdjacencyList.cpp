#include <iostream>
#include<vector>
using namespace std;

void printAdjacencyList(vector<vector<int> > adj_list)
{
    // Printing Adjacency List
	for(int i = 0; i < adj_list.size(); i++)
	{ 
	    cout<<"Node "<<i<<" -> ";
	    cout<<"[ ";
	    
	    for(int j = 0; j < adj_list[i].size(); j++)
	    {
	        cout<<adj_list[i][j]<<" ";
	    }
	    
	    cout<<"]"<<endl;
	}
}

int main() 
{
	vector<vector<int> > adj_list(6); // Create an Adjacency list for the Graph. Nodes are labelled 1,2,3,4,5
	// For Node 1, ignore Node 0 if printed or set i = 1
	adj_list[1].push_back(4);
	
	// Node 2
	adj_list[2].push_back(4);
	adj_list[2].push_back(5);
	
	// Node 3 
	adj_list[3].push_back(5);
	
	// Node 4
	adj_list[4].push_back(1);
	adj_list[4].push_back(2);
	adj_list[4].push_back(5);
	
	// Node 5
	adj_list[5].push_back(2);
	adj_list[5].push_back(3);
	adj_list[5].push_back(4);
	
	//typedef vector<vector<int> >::iterator iter; // Defining an iterator over a vector
    printAdjacencyList(adj_list);
}
