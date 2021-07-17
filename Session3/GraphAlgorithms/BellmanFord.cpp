#include <iostream>
#include <vector>

using namespace std;
const int INF = int(1e8);

// Implementing Bellman Ford Algorithm. Edge List Rep. is the most convenient
struct Edge
{
    int from, to, weight;
    
    // Constructor
    Edge(int source_node, int dest_node, int edge_wt)
    {
        from = source_node;
        to = dest_node;
        weight = edge_wt;
    }
};

struct Graph
{
    vector<Edge> edge_list;
    
    void add_edge(int v, int w, int weight)
    {
        edge_list.push_back(Edge(v,w,weight));
    }
    
    // Bellman Ford Algorithm Begins: s-> source Node
    void bellman_ford(int N, int s, int distance[])
    {
        for(int i=0; i<N-1; i++) // For N-1 iterations
        {
            // Relaxing the Edges Begins!
            for(auto i=edge_list.begin(); i!=edge_list.end(); i++)
            {
                if(distance[i->from]+i->weight < distance[i->to])
                    distance[i->to] = distance[i->from] + i->weight;
            }
        }
        
        // Figuring the Cycles present in the Graph
        for(int i=0; i<N-1; i++)
        {
            for(auto i=edge_list.begin(); i!=edge_list.end(); i++)
            {
                if(distance[i->to]+i->weight < distance[i->from])
                    distance[i->from] = INF;
            }
        }
    }
};

int main()
{
    const int N = 5; // No. of nodes
    int distance[N];
    
    for(int i=0; i<N; i++)
        distance[i] =INF; // Initializing the Distance Vector
    distance[0] = 0;
    
    // Initializing the Graph
    Graph g;
    g.add_edge(0,1,1); g.add_edge(0,3,2);
    g.add_edge(1,2,2);
    g.add_edge(2,3,2); g.add_edge(2,4,8);
    g.add_edge(3,4,3);
    
    g.bellman_ford(N, 0, distance);
    
    for(int i=0; i<N; i++)
        cout<<i<<": "<<distance[i]<<endl;
    return 0;
}
