#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define mp make_pair

// Implementing Dijkstra's Algorithm - need Adjacency Lists NOT Edge List
// Default Priority Queues in C++ are Max Heap. Need to Multiply and re-Multiply (after popping) to get something similar to min  Heap
const int INF = int(1e8);
priority_queue<pair<int,int>> node_queue;

void printPath(int path[], int s, int targetNode)
{
    int node = targetNode;
    cout<<"Path to Target Node via Source Node:"<<endl;
    cout<<node;
    while(node!=s)
    {
        cout<<"<-"<<path[node];
        node = path[node];
    }
  cout<<endl;
}

void dijkstra(vector<pair<int,int>> adj_list[], int distance[], bool visited[], int path[], int N, int s, int target)
{
    // Pushing the Source Node into the priority Queue
    node_queue.push({s,0});
    path[s] = 0;
    
    while(!node_queue.empty())
    {
        // Getting the Minimum Value Node from the Min-Heap 
        int node = node_queue.top().first;
        int dist = node_queue.top().second;
        dist = -dist; // Make it positive since priority queues are Max Heaps
        node_queue.pop();
        visited[node] = true;
        
        if(distance[node] < dist) // Older Copies of Nodes in the Queue are rejected
           continue;
        
        // Iterating over all the Edges of the Current Node to Relax Them
        for(int i=0; i<adj_list[node].size(); i++)
        {
            int adj_node = adj_list[node][i].first;
            int w = adj_list[node][i].second;
            
            // Do only if those Nodes haven't been visited yet - Invariant of Algo
            if(!visited[adj_node] && (distance[node] + w < distance[adj_node]))
            {
                distance[adj_node] = distance[node] + w;
                node_queue.push(make_pair(adj_node, -w));
                path[adj_node] = node;
            }
        }
    }
    
    // Printing All the Distances
    for(int i=0; i<N; i++)
        cout<<i<<":"<<distance[i]<<endl;
    
    // Printing Path to a given Node
    printPath(path, s, target);
}

int main()
{
    const int N = 5; // No. of nodes
    int s = 1; // Source Node
    
    // Other Graph Parameters
    int distance[N];
    bool visited[N] = {};
    int path[N] = {};
    vector<pair<int,int>> adj_list[N];
    
    for(int i=0; i<N; i++)
        distance[i] =INF; // Initializing the Distance Array for all the nodes
    distance[s] = 0;
    
    // Initializing the Graph
    adj_list[0].push_back(mp(1,1)); adj_list[0].push_back(mp(3,2));
    adj_list[1].push_back(mp(2,2)); adj_list[1].push_back(mp(0,1));
    adj_list[2].push_back(mp(3,2)); adj_list[2].push_back(mp(4,8)); adj_list[2].push_back(mp(1,2));
    adj_list[3].push_back(mp(4,3)); adj_list[3].push_back(mp(2,2));
    
    // Dijkstra's Algorithm
    dijkstra(adj_list, distance, visited, path, N, s, 4);
    
    return 0;
}
