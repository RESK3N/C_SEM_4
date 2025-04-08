//dijkstra
#include<stdio.h>
#define size 5
#define infinity 9999

int find(int distance[],int visited[]){
    int min=infinity;
    int index=-1;
    for (int i = 0; i < size; ++i) {
        if(!visited[i]&& distance[i]<min){
            min=distance[i];
            index=i;
        }

    }
    return index;
}
void dj(int graph[size][size],int start){
    int distance[size];
    int visited[size];
    for(int i=0;i<size;i++){
        distance[i]=infinity;
        visited[i]=0;
    }
    distance[start]=0;
    for(int i=0;i<size;i++){
        int u=find(distance,visited);
        visited[u]=1;
        for(int v=0;v<size;v++){
            if(!visited[v]&&
            graph[u][v]!=0 &&
            distance[u]+graph[u][v]<distance[v]){
                distance[v]=distance[u]+graph[u][v];
            }
        }
    }
    printf("Node\tDistance from node %d\n",start);
    for(int i=0;i<size;i++){
        printf("%d\t%d\n",i,distance[i]);
    }
}
int main(){
    int graph[size][size]={
            {0, 10, 0, 30, 100},
            {10, 0, 50, 0, 0},
            {0, 50, 0, 20, 10},
            {30, 0, 20, 0, 60},
            {100, 0, 10, 60, 0}
    };
    dj(graph,0);
}