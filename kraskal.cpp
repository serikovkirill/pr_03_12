#include <algorithm> //Алгоритм Краскала
#include <iostream>
#include <vector>
using namespace std;
struct edge { //ребра
    int x, y; 
};
int main() {
    int n, m;
    cin >> n >> m;
    vector <edge> graph(m); 
    vector <edge> tree;  //дерево
    vector <int> var(1000,n); //вершины
    for (int i = 0; i < n; i++) {
        var[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[i].x = a;
        graph[i].y = b;
    }
    for (int i = 0; i < m; i++) {
        int a = graph[i].x;
        int b = graph[i].y;
        if (var[a] != var[b]) {
            tree.push_back(graph[i]);
            int old_var = var[b], new_var = var[a];
            for (int j = 0; j < n; j++) {
                if (var[j] == old_var) {
                    var[j] = new_var;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++) { 
        cout << tree[i].x << " " << tree[i].y;
        if (i != n - 2) {
            cout << endl;
        }
    }
    return 0;
}