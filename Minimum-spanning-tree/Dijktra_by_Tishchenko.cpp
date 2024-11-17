#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int weight;
    int to;
    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }
};

int dijkstra_by_Tishenko(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    std::vector<bool> inMST(n, false);
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

    std::vector<int> parent(n, -1);

    inMST[0] = true;
    for (int v = 0; v < n; ++v) {
        if (matrix[0][v] != 0) {
            pq.push({ matrix[0][v], v });
            parent[v] = 0;
        }
    }

    int totalWeight = 0;
    int edgesUsed = 0;

    while (!pq.empty() && edgesUsed < n - 1) {
        Edge current = pq.top();
        pq.pop();

        if (inMST[current.to]) continue;

        inMST[current.to] = true;
        totalWeight += current.weight;
        edgesUsed++;

        for (int v = 0; v < n; ++v) {
            if (matrix[current.to][v] != 0 && !inMST[v]) {
                pq.push({ matrix[current.to][v], v });
                if (parent[v] == -1) {
                    parent[v] = current.to;
                }
            }
        }
    }

    if (edgesUsed == n - 1) {
        std::cout << "Минимальное остовное дерево (в буквенном формате):\n";
        for (int i = 1; i < n; ++i) {
            char u = 'A' + parent[i];
            char v = 'A' + i;
            std::cout << u << " - " << v << " (вес: " << matrix[parent[i]][i] << ")\n";
        }
    }
    else {
        std::cout << "Невозможно построить минимальное остовное дерево." << std::endl;
    }

    return (edgesUsed == n - 1) ? totalWeight : -1;
}
