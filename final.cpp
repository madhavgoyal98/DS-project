#include<iostream>
#include<stack>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define NODES 10

struct node
{
    string name;
    string category;
};


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

//function for source and destination
void dij(int graph[NODES][NODES], struct node vertex[NODES], int src, int dest)
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

    //cout<<"******************"<<endl;
    cout<<minDist[dest];

    stack<string> temp;

    int j = dest;
    while(parent[j] != -1)
    {
        temp.push(vertex[j].name);
        j = parent[j];
    }

    while(!temp.empty())
    {
        cout<<" "<<temp.top();
        temp.pop();
    }    
}


//function for source and category
void dij(int graph[NODES][NODES], struct node vertex[NODES], int src, string category)
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

    int dest = NODES+1, min = 100000;

    for(int i = 0; i<NODES; i++)
    {
        if(minDist[i]<=min && category == vertex[i].category && src != i)
        {
            min = minDist[i];
            dest = i;
        }
    }

    //cout<<"\n\n******************"<<endl;
    cout<<vertex[dest].name<<" ";
    cout<<minDist[dest];

    stack<string> temp;

    int j = dest;
    while(parent[j] != -1)
    {
        temp.push(vertex[j].name);
        j = parent[j];
    }

    while(!temp.empty())
    {
        cout<<" "<<temp.top();
        temp.pop();
    }    
}

//command-line input format  source, option(Destination/category), Destination/category
int main(int argc, char *argv[])
{
    int graph[NODES][NODES] = {{0, 2, 5, 0, 3, 0, 0, 0, 0, 0}, 
                                {2, 0, 0, 0, 8, 0, 7, 13, 0, 0}, 
                                {5, 0, 0, 6, 4, 0, 0, 0, 0, 0}, 
                                {0, 0, 6, 0, 1, 9, 10, 0, 0, 0}, 
                                {3, 8, 4, 1, 0, 11, 0, 0, 0, 0}, 
                                {0, 0, 0, 9, 11, 0, 0, 0, 0, 12}, 
                                {0, 7, 0, 10, 0, 0, 0, 15, 5, 2}, 
                                {0, 13, 0, 0, 0, 0, 15, 0, 15, 14}, 
                                {0, 0, 0, 0, 0, 0, 5, 15, 0, 16}, 
                                {0, 0, 0, 0, 0, 12, 2, 14, 16, 0}};

    struct node vertex[NODES]; 

    vertex[0].name="AjantaHospital";
    vertex[0].category="Hospital"; 

    vertex[1].name="Mocha"; 
    vertex[1].category="FoodPlace";

    vertex[2].name="EasyDay";
    vertex[2].category="Grocery"; 

    vertex[3].name="Pantaloons"; 
    vertex[3].category="ClothShopping";

    vertex[4].name="CafeCoffeeDay";
    vertex[4].category="FoodPlace";

    vertex[5].name="Dominos"; 
    vertex[5].category="FoodPlace";

    vertex[6].name="LifePlusHospital";
    vertex[6].category="Hospital"; 

    vertex[7].name="MaxGrocery";
    vertex[7].category="Grocery"; 

    vertex[8].name="AnandHospital";
    vertex[8].category="Hospital"; 

    vertex[9].name="PizzaHut";
    vertex[9].category="FoodPlace";

    string src, dest, cat;
    int destIndex, srcIndex;

    src = argv[1];

    for(int i = 0; i<NODES; i++)
    {
        if(vertex[i].name == src)
        {
            srcIndex = i;
        }
    }


    if(atoi(argv[2]) == 1)
    {
        dest = argv[3];

        for(int i = 0; i<NODES; i++)
        {
            if(vertex[i].name == dest)
            {
                destIndex = i;
            }
        }

        dij(graph, vertex, srcIndex, destIndex);
    }
    else if(atoi(argv[2]) == 2)
    {
        cat = argv[3];

        dij(graph, vertex, srcIndex, cat);
    }


    return 0;
}
