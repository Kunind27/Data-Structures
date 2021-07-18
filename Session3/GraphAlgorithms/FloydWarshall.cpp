#include <iostream>
#include <vector>

using namespace std;
#define mp make_pair

// Implementing the Floyd-Warshall Algorithm - All Pairs Within One Go
const int INF = int(1e8);
const int N = 4;

void propagateNegativeCycles(auto distance, auto next_node, int N)
{
    // Propagating Negative Cycles
    for(int k=0; k<N;k++)
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(distance[i][k]+distance[k][j]<distance[i][j])
                {
                    distance[i][j] = -INF;
                    next_node[i][j] = -1;
                }
            }
        }
    }
}

void floyd_warshall(auto distance, auto next_node, int N)
{
    // Loops Over all Intermediate Node Connections - Necessary to be on the ext loop
    for(int k=0; k<N;k++)
    {
        // Loops Over Source Nodes
        for(int i=0; i<N; i++)
        {
            // Relaxing the Edges - j loops over all the other nodes given a source node
            for(int j=0; j<N; j++)
            {
                if(distance[i][k]+distance[k][j]<distance[i][j])
                {
                    distance[i][j] = distance[i][k]+distance[k][j];
                    next_node[i][j] = next_node[i][k];
                }
            }
        }
    }
    
    propagateNegativeCycles(distance, next_node, N);
    
}

void getPath(auto distance, auto next_node, int source, int target, vector<int> path)
{
    // Check if there exists a path between source and target nodes
    if(distance[source][target]==INF)
    {
        cout<<"No Such Path"<<endl;
        return;
    }
    
    // Checks for negative cycles in between
    for(int at = source; at!=target; at = next_node[at][target])
    {
        if(at==-1)
        {
            cout<<"No Such Path"<<endl;
            return;
        }
        path.push_back(at);
    }
    
    // Checks for negative cycles at the target node
    if(next_node[source][target]==-1)
    {
        cout<<"No Such Path"<<endl;
        return;
    }
    path.push_back(target);
    
    // Prints the Path
    cout<<"Path to reach "<<target<<" from "<<source<<" is:\n";
    for(auto i = path.begin(); i!=path.end(); i++)
    {
        cout<<*i<<"->";
    }
    cout<<endl;
}

int main()
{
    int distance[N][N];
    int adj_list[N][N] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };;
    
    // To calculate path
    int next_node[N][N]; 
    vector<int> path;
    
    // Initializing the Distance Arrays
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i==j)
            {
                distance[i][j]=0;
                next_node[i][j] = j;
            }
            else if(adj_list[i][j])
            {
                distance[i][j] = adj_list[i][j];
                next_node[i][j] = j;
            }
            else
                distance[i][j] = INF;
        }
    }
    
    // Floyd Warshall Begins
    floyd_warshall(distance, next_node, N);
    
    // Printing the Path
    int source = 3;
    int target = 0;
    getPath(distance, next_node, source, target, path);
    
    return 0;
}
