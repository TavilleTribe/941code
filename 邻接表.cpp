#include <stdio.h>
#include <stdlib.h>

// 邻接表中的边节点
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// 邻接表
struct AdjList {
    struct AdjListNode* head;
};

// 图结构
struct Graph {
    int V;
    struct AdjList* array;
};

// 创建新的边节点
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// 创建图
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // 创建邻接表数组
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // 初始化每个邻接表为空
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// 添加边
void addEdge(struct Graph* graph, int src, int dest) {
    // 添加从src到dest的边
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // 如果是无向图，添加从dest到src的边
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// 打印图
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n 顶点 %d 的邻接表\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// 主函数
int main() {
    // 创建图
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // 打印图
    printGraph(graph);

    return 0;
}
