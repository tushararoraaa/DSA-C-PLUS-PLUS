#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
    int source;
    int destination;
    int weight;


};

bool compare(Edge e1, Edge e2){
    return e1.weight<e2.weight;      // this is for increasing sort
}

int findParent(int v, int* parents){
    if(parents[v]==v){
        return v;
    }
    return findParent(parents[v],parents);
}

void kruskals(Edge* input , int n, int e){
    sort(input,input+e, compare);

    Edge* output = new Edge[n-1];
    int* parents = new int[n];
    for(int i =0; i<n ; i++){
        parents[i] = i;
    }

    int count = 0;
    int i = 0;
    while(count!=n-1){
        Edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source,parents);
        int destParent = findParent(currentEdge.destination,parents);

        if(sourceParent!=destParent){
            output[count] = currentEdge;
            count++;
        }
        i++;
    }

    for(int i = 0; i<n-1; i++){
       if(output[i].source<output[i].destination){
        cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
       }else{
           cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
       }

    }



}

int main()
{
   int n , e;
   cout<<"Enter no. of vertices"<<endl;
   cin>>n;
   cout<<"Enter no. of edges"<<endl;
   cin>>e;

   Edge* input = new Edge[e];

   for(int i = 0; i<e; i++){
    int source,destination,weight;
    cout<<"Enter Source , Destionation & weight"<<endl;
    cin>>source>>destination>>weight;
    input[i].source = source;
    input[i].destination = destination;
    input[i].weight = weight;

   }

   kruskals(input,n,e);

    return 0;
}
