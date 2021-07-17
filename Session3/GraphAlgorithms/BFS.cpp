#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
 
// Implementing Breadth First Search
class Graph
{
    public:
    map<int, bool> visited; // Keeps track of alredy visited nodes
    map<int, vector<int>> adj_list; // Adjacency List of the Graph
    queue<int> node_queue; // Node Queue for BFS
    map<int,int> distance; // Distance of nodes from the source nodes
 
    // Adding an Edge to the Graph
    void addEdge(int v, int w)
    {
        adj_list[v].push_back(w); 
    }
 
    // BFS Algorithm Begins
    void BFS(int s)
    {
        // Push the source node into the Queue
        node_queue.push(s);
        visited[s] = true;
        distance[s] = 0;
        
        while(!node_queue.empty())
        {
            // Getting the latest node from the Queue
            int v = node_queue.front();
            node_queue.pop();
            cout<<v<<" ";
         
            // Iterating over all the nodes adjacent to the given node 'v' and adding them to the queue if they are not in the node queue
            vector<int>::iterator i;
            for (i = adj_list[v].begin(); i != adj_list[v].end(); i++)
            {
                if(!visited[*i])
                {
                    // Mark the neighbour as visited for the next iteration
                    visited[*i] = true;
                    // Push the adjacent nodes onto the queue
                    node_queue.push(*i);
                    // Increased distance of adjacent nodes from source node by 1
                    distance[*i] = distance[v]+1;
                }
            }
        }
        cout<<endl;
    }
};
 
// Driver code
int main()
{
    Graph g;
    
    
    /*         0
           /   |   \
          1     2 --3
        /  \     |   \    
        4   \    |    6
               5      **/
    
    // Initializing the Graph's Adjacency List
    g.addEdge(0,1); g.addEdge(0,2); g.addEdge(0,3); 
    g.addEdge(1,4); g.addEdge(1,5);
    g.addEdge(2,0); g.addEdge(2,3); g.addEdge(2,5);
    g.addEdge(3,0); g.addEdge(3,2); g.addEdge(3,6);
    g.addEdge(4,1);
    g.addEdge(5,1); g.addEdge(5,2);
    g.addEdge(6,3);
 
    cout<<"Breadth First Search Visits the Nodes in this order:\n";
    g.BFS(0);
    
    // Prints distance of Nodes from the Source Node
    map<int, int>::iterator i;
    for(i=g.distance.begin(); i!=g.distance.end(); i++)
        cout<<i->first<<":"<<i->second<<endl;
 
    return 0;
}
