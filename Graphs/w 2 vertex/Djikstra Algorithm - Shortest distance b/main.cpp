#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int findMinVertex(int *distance, bool *visited, int n)
{
    int minVertex = -1;
    for(int i = 0; i<n; i++)
    {
        if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex]) )
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void djikstra(int **edges, int n)
{

    bool *visited = new bool[n];
    int *distance = new int[n];

    for(int i =0; i<n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;

    for(int i = 0; i<n-1; i++)
    {
        int minVertex = findMinVertex(distance,visited,n);
        visited[minVertex] = true;
        for(int j = 0; j<n; j++)
        {
            if(edges[minVertex][j]!= 0 && !visited[j])
            {
                int newDistance = distance[minVertex]+edges[minVertex][j];
                if(distance[j]>newDistance)
                {
                    distance[j] = newDistance;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete[] visited;
    delete [] distance;
}
// 5 7 0 1 4 0 2 8 1 3 5 1 2 2 2 3 5 2 4 9 3 4 4
int main()
{
    int n;
    int e;
    cout<<"Enter number of vertices"<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>e;

    int** edges = new int*[n];
    for(int i = 0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0 ; j<n ; j++)
        {
            edges[i][j] = 0;
        }
    }


    for(int i = 0; i < e; i++)
    {
        int f;
        int s;
        int weight;
        cout<<"Enter first and second vertex and weight"<<endl;
        cin>>f;
        cin>>s;
        cin>>weight;

        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    djikstra(edges,n);

    return 0;
}
