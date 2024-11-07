#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // Бесконечность для инициализации

// Функция для нахождения веса минимального остовного дерева с использованием алгоритма Прима
int example(const vector<vector<int>>& matrix) {
    int n = matrix.size(); // Количество вершин в графе
    vector<int> minEdgeWeight(n, INF); // Минимальный вес ребра для каждой вершины
    vector<bool> inMST(n, false);      // Флаг, показывающий, входит ли вершина в MST

    // Начинаем с первой вершины (0)
    minEdgeWeight[0] = 0;
    int totalWeight = 0;

    for (int i = 0; i < n; ++i) {
        // Ищем вершину u с минимальным весом ребра, которая ещё не в MST
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || minEdgeWeight[j] < minEdgeWeight[u])) {
                u = j;
            }
        }

        // Добавляем вершину u в MST
        inMST[u] = true;
        totalWeight += minEdgeWeight[u];

        // Обновляем минимальные веса для соседей вершины u
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] && !inMST[v] && matrix[u][v] < minEdgeWeight[v]) {
                minEdgeWeight[v] = matrix[u][v];
            }
        }
    }

    // Возвращаем общий вес минимального остовного дерева
    return totalWeight;
}