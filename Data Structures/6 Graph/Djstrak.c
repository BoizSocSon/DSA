#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Cấu trúc để biểu diễn một cạnh
typedef struct {
    int vertex;
    int weight;
} Edge;

// Cấu trúc để biểu diễn đồ thị
typedef struct {
    int numVertices;
    Edge** adjList;  // Danh sách kề, mảng các con trỏ tới các cạnh
    int* adjSize;    // Số lượng đỉnh kề cho mỗi đỉnh
} Graph;

// Hàm khởi tạo đồ thị
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjList = (Edge**)malloc(vertices * sizeof(Edge*));
    graph->adjSize = (int*)calloc(vertices, sizeof(int));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Hàm thêm cạnh vào đồ thị
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjSize[src]++;
    graph->adjList[src] = (Edge*)realloc(graph->adjList[src], graph->adjSize[src] * sizeof(Edge));
    graph->adjList[src][graph->adjSize[src] - 1].vertex = dest;
    graph->adjList[src][graph->adjSize[src] - 1].weight = weight;
}

// Hàm tìm đỉnh có khoảng cách nhỏ nhất chưa được thăm
int minDistance(int dist[], int visited[], int n) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Thuật toán Dijkstra
void dijkstra(Graph* graph, int start) {
    int n = graph->numVertices;
    int dist[n];
    int visited[n];

    // Khởi tạo khoảng cách và mảng đánh dấu visited
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    // Tìm đường đi ngắn nhất
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        // Cập nhật khoảng cách cho các đỉnh kề của đỉnh u
        for (int i = 0; i < graph->adjSize[u]; i++) {
            int v = graph->adjList[u][i].vertex;
            int weight = graph->adjList[u][i].weight;
            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // In kết quả
    printf("Khoảng cách từ đỉnh %d đến các đỉnh khác:\n", start);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Đỉnh %d: Không thể tới\n", i);
        else
            printf("Đỉnh %d: %d\n", i, dist[i]);
    }
}

int main() {
    int vertices = 3;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 2);

    int start = 0;
    dijkstra(graph, start);

    // Giải phóng bộ nhớ
    for (int i = 0; i < vertices; i++) {
        free(graph->adjList[i]);
    }
    free(graph->adjList);
    free(graph->adjSize);
    free(graph);

    return 0;
}
