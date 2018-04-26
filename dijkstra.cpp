#include<iostream>
#include<stack>
using namespace std;

#define NODES 6

int findMin(int minDist[], bool stree[])
{
    int min = 100000, index;

    for(int i = 0; i<NODES; i++)
    {
        if(stree[i] == false && minDist[i]<=min)
        {
            min = minDist[i];
            index = i;
        }
    }

    return index;
}

void dij(int graph [NODES][NODES], int src)
{
    int minDist[NODES];
    int parent[NODES];
    bool stree[NODES];

    for(int i = 0; i<NODES; i++)
    {
        minDist[i] = 100000;
        stree[i] = false;
    }

    minDist[src] = 0;
	parent[src] = -1;

    for(int i = 0; i<NODES-1; i++)
    {
        int u = findMin(minDist, stree);

        stree[u] = true;

        for(int v = 0; v<NODES; v++)
        {
            if(!stree[v] && (graph[u][v]>0) && (minDist[u] != 100000) && (minDist[u] + graph[u][v]<minDist[v]))
            {
                parent[v] = u;
                minDist[v] = minDist[u] + graph[u][v];
            }
        }
    }


    for(int i = 0; i<NODES; i++)
    {
        cout<<i<<"  "<<minDist[i]<<endl;

        stack<int> temp;
        int j = i;
        while(parent[j] != -1)
        {
            temp.push(j);
            j = parent[j];
        }

        while(!temp.empty())
        {
            cout<<temp.top()<<"  ";
            temp.pop();
        }

        cout<<"\n\n";
    }
}

int main()
{
    int graph[NODES][NODES] = {{0,5,0,6,10,0},
                               {5,0,1,0,2,7},
                               {0,1,0,0,0,8},
                               {6,0,0,0,3,0},
                               {10,2,0,3,0,4},
                               {0,7,8,0,4,0}};
    dij(graph, 1);

    return 0;
}
