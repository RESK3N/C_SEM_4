#include<stdio.h>
#define size 5
#define infinity 9999

int find(int distance[],int visited[]){
    int min=infinity;
    int index=-1;
    for(int i=0; i<size;i++){
        if(!visited[i]&&distance[i]<min){
            min=distance[i];
            index=i;
        }
    }
    return index;
}
void prims(int graph[size][size],int start){
    int distance[size];
    int visited[size];
    int parent[size];

    //initializing array
    for(int i=0;i<size;i++){
        distance[i]=infinity;
        visited[i]=0;
    }
    distance[start]=0;
    parent[start]=-1;
    //updating values
    for(int i=0;i<size-1;i++){
        int u=find(distance,visited);
        visited[i]=1;

        for(int v=0;v<size;v++){
            if(!visited[i] &&
            graph[u][v]!=0 &&
            graph[u][v]<distance[v]){
                distance[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    printf("Edge:\tWeight:\n");
    for(int i=1;i<size;i++){
        printf("%d-%d\t\t%d\n",parent[i],i,graph[i][parent[i]]);
    }
}

int main(){
    int graph[size][size]={
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}};
    prims(graph,0);
}