#include <stdio.h>
#include <limits.h>

#define V 6

int minDistance(int dist[], int visited[]) {
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++) {
		if (!visited[v] && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void printSolution(int dist[]) {
	printf("顶点 \t 距离源点的最短距离\n");
	for (int i = 0; i < V; i++) {
		printf("%d \t %d \n",i,dist[i]);
	}
}

void dijkstra(int graph[V][V], int src) {
	int dist[V];
	int visited[V];
	
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		visited[i] = 0;
	}
	dist[src] = 0;
	
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist,visited);
		visited[u] = 1;
		
		for (int v = 0; v < V; v++) {
			if (!visited[v] 
			&& graph[u][v] 
			&& dist[u] != INT_MAX
			&& dist[u] + graph[u][v] < dist[v]) 
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist);
}

int main() {
    // 图的邻接矩阵表示
    int graph[V][V] = {
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 0, 3, 0},
        {0, 7, 0, 0, 2, 1},
        {0, 0, 3, 2, 0, 5},
        {0, 0, 0, 1, 5, 0}
    };

    // 从顶点0开始计算最短路径
    dijkstra(graph, 0);

    return 0;
}

