#include <stdio.h>
#include <limits.h>
#define V 5 // số lượng đỉnh trong đồ thị

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];  // Mảng lưu khoảng cách ngắn nhất từ src đến các đỉnh
    int sptSet[V]; // Mảng đánh dấu đỉnh đã xét hay chưa

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // Khởi tạo tất cả khoảng cách là vô cùng
        sptSet[i] = 0;  // Chưa đỉnh nào được chọn
    }

    dist[src] = 0; // Khoảng cách từ src đến chính nó là 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {{0, 10, 0, 0, 5},
                       {0, 0, 1, 0, 2},
                       {0, 0, 0, 4, 0},
                       {7, 0, 6, 0, 0},
                       {0, 3, 9, 2, 0}};

    int src = 0; // Đỉnh bắt đầu là 0
    dijkstra(graph, src);

    return 0;
}
