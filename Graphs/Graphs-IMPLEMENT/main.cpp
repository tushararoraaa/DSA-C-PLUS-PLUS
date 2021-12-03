#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_DFS(int** edges, int n,int sv, bool* visited)
{
    cout<<sv<<endl;
    visited[sv] = true;

    for(int i = 0; i<n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1)
        {
            if(visited[i])
            {
                continue;
            }
            print_DFS(edges,n,i,visited);
        }
    }
    delete[] visited;
}

void print_BFS(int **edges, int n, int sv, bool* visited)
{

    queue<int> q1;
    q1.push(sv);
    visited[sv] = true;
    while(!q1.empty())
    {
        int cv = q1.front();
        cout<<cv<<endl;
        for(int i = 0; i<n; i++)
        {
            if(i==cv)
            {
                continue;
            }
            if(edges[cv][i] == 1 && !visited[i])
            {
                q1.push(i);
                visited[i] = true;
            }

        }
        q1.pop();
    }

    delete[] visited;
}

void DFS(int** edges, int n)
{
    bool* visited = new bool[n];
    for(int i = 0; i<n; i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i<n ; i++)
    {
        if(!visited[i])
        {
            print_DFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

void BFS(int** edges, int n)
{
    bool* visited = new bool[n];
    for(int i = 0; i<n; i++)
    {
        visited[i] = false;
    }

    for(int i = 0; i<n ; i++)
    {
        if(!visited[i])
        {
            print_BFS(edges, n, i, visited);
        }
    }
    delete [] visited;
}

bool hasPath_BFS(int **edges, int n, int sv, int ev)
{
    if(sv == ev)
    {
        return true;
    }
    bool *visited = new bool[n];
    for(int i = 0; i<n; i++)
    {
        visited[i] = false;
    }
    queue<int> q1;
    q1.push(sv);
    visited[sv] = true;
    while(!q1.empty())
    {
        int cv = q1.front();
        q1.pop();
        for(int i = 0; i<n; i++)
        {
            if(edges[cv][ev]==1)
            {
                return true;
            }
            if(edges[cv][i] == 1 && !visited[i])
            {
                q1.push(i);
                visited[i] = true;
            }

        }

    }
    return false;

    delete[] visited;

}

vector<int>* getPathBFS(int** edges, int n,int sv, int ev, bool* visited){
    if(sv==ev){
        visited[sv] = true;
        vector<int> *output = new vector<int>;
        output->push_back(sv);
        return output;
    }
    queue <int> q;
    q.push(sv);
    visited[sv] = true;
    unordered_map<int,int> m;
    m[sv] = -1;
    bool done = false;

    while(!q.empty() && !done){
        int temp = q.front();
        q.pop();

        for(int i = 0; i<n; i++){

            if(edges[temp][i]==1 && !visited[i] && temp!=i){
                m[i] = temp;
                q.push(i);
                visited[i]=true;
                if(i==ev){
                    done = true;
                    break;
                }
            }
        }
    }
    vector<int>* output = new vector<int>;
    if(done){
        for(int i = ev; i!= -1;){
            output->push_back(i);
            i = m.at(i);
        }
        return output;
    }else{
        return NULL;
    }
}

// 7 8 0 1 0 2 1 3 1 4 3 5 4 5 5 6 6 2

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
        cout<<"Enter first and second vertex"<<endl;
        cin>>f;
        cin>>s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }



//    bool* visited = new bool[n];
//    for(int k = 0 ; k<n ; k++)
//    {
//        visited[k] = false;
//    }
//
//    bool* visited2 = new bool[n];
//    for(int k = 0 ; k<n ; k++)
//    {
//        visited2[k] = false;
//    }
//
//
//    print_DFS(edges,n,0,visited);           //FOR CONTINUOUS GRAPH
//    print_BFS(edges,n,0, visited2);          //FOR CONTINUOUS GRAPH
    cout<<"DFS:- "<<endl;
    DFS(edges,n);                           //FOR DISCONTINUOUS GRAPH
    cout<<"BFS:- "<<endl;
    BFS(edges, n);                          //FOR DISCONTINUOUS GRAPH

    if(hasPath_BFS(edges,n,0,6))
    {
        cout<<"Path Found using BFS"<<endl;
    }
    else
    {
        cout<<"Oops! No Path Found(BFS)"<<endl;
    }

    bool* visited = new bool[n];
    for(int k = 0 ; k<n ; k++)
    {
        visited[k] = false;
    }

    vector<int> *path = getPathBFS(edges,n,0,6,visited);

    if(path!=NULL){
        vector<int>::iterator itr;
        for(itr = path->begin(); itr != path->end(); itr++){
            cout<<*itr<<" ";
        }
    }
    delete[] visited;
    delete [] edges;
    return 0;
}
