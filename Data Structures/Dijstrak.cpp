#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define V 5  // số lượng đỉnh trong đồ thị

// Hàm thêm cạnh vào đồ thị (dưới dạng danh sách kề)
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

// Hàm tìm đường đi ngắn nhất từ đỉnh nguồn src đến các đỉnh còn lại
void dijkstra(vector<pair<int, int>> adj[], int src) {
    // Mảng lưu khoảng cách ngắn nhất từ src đến mỗi đỉnh
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Hàng đợi ưu tiên để tìm đỉnh có khoảng cách nhỏ nhất chưa được xét
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Duyệt qua tất cả các đỉnh kề của u
        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            // Nếu có đường đi ngắn hơn đến v qua u, cập nhật khoảng cách
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // In ra khoảng cách từ đỉnh src đến các đỉnh khác
    cout << "Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << "\n";
}

int main() {
    // Khởi tạo danh sách kề cho đồ thị
    vector<pair<int, int>> adj[V];

    // Thêm các cạnh vào đồ thị
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 5);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 4, 2);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 3, 0, 7);
    addEdge(adj, 3, 2, 6);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 2, 9);
    addEdge(adj, 4, 3, 2);

    int src = 0;  // Đỉnh bắt đầu là 0
    dijkstra(adj, src);

    return 0;
}
