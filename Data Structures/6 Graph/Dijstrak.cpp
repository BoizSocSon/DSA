#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;

const int maxn = 100001;
int n, m;
vector<pair<int, int>> adj[maxn];

void Nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
}

const ll INF = 1e9;

void dijkstra(int s){
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while(!Q.empty()){
        // Chọn ra đỉnh có khoảng cách từ s nhỏ nhất
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if(kc > d[u]) 
            continue;
        // Relaxation: Cập nhật khoảng cách từ s cho tới mọi đỉnh kề với u
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
}

int main(){

}