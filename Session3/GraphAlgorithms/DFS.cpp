#include <iostream>
#include <vector>
#include <map>

using namespace std;
 
// Graph represented by an Adjacency List
class Graph
{
    public:
    map<int, bool> visited;
    map<int, vector<int>> adj_list;
 
    // Adding an Edge to the Graph
    void addEdge(int v, int w)
    {
        adj_list[v].push_back(w); 
    }
 
    // DFS Algorithm Begins
    void DFS(int v)
    {
        // Return if already visited this node
        if(visited[v])
            return;
        
        // Mark current Node as visited and print it
        visited[v] = true;
        cout << v << " ";
     
        // Iterating over all the nodes adjacent to the given node 'v' and recursively doing DFS
        vector<int>::iterator i;
        for (i = adj_list[v].begin(); i != adj_list[v].end(); i++)
            DFS(*i);
    }
};
 
// Driver code
int main()
{
    Graph g;
    
    
    /*         0
           /   |   \
          1     2   3
        /  \     |       
        4   \    |
               5      **/
    
    // Initializing the Graph's Adjacency List
    g.addEdge(0,1); g.addEdge(0,2); g.addEdge(0,3); 
    g.addEdge(1,4); g.addEdge(1,5);
    g.addEdge(2,0); g.addEdge(2,5);
    g.addEdge(3,0);
    g.addEdge(4,1);
    g.addEdge(5,1); g.addEdge(5,2);
 
    cout<<"Graph Node Traversal Order :\n";
    g.DFS(0);
 
    return 0;
}
