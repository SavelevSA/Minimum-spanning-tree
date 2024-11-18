#include <iostream>
#include <vector>
#include <algorithm>
#include "Algorithms.h"

using namespace std;

// Представление ребра
struct Edge {
    int start, end, weight;
};

// Сравнение двух рёбер по весу
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Класс для реализации системы непересекающихся множеств
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    //Поиск сжатия пути
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    //Объединение множеств по рангу деревьев
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            }
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int Kraskall_by_Vasukova(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<Edge> edges;

    // Извлечение рёбер из матрицы смежности 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { 
            if (matrix[i][j] != 0) {
                edges.push_back({ i, j, matrix[i][j] });
            }
        }
    }

    // Сортировка рёбер по весу по возрастанию
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(n);
    int TotalWeight = 0;

    // Алгоритм Краскала
    for (const Edge& edge : edges) {
        int u = edge.start;
        int v = edge.end;

        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            TotalWeight += edge.weight;
        }
    }

    return TotalWeight;
}