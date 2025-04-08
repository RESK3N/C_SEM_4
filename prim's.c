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
    
}