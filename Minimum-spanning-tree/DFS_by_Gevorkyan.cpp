#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // Бесконечность для инициализации

int DFS_by_Gevorkyan(const vector<vector<int>>& matrix) {
    int n = matrix.size();  // Количество вершин в графе
    vector<int> minEdgeWeight(n, INF); // Минимальный вес ребра для каждой вершины
    vector<bool> visited(n, false);    // Массив для отслеживания посещенных вершин
    int totalWeight = 0; // Возвращаемый вес

    // Начинаем с первой вершины (0)
    minEdgeWeight[0] = 0;

    for (int i = 0; i < n; ++i) {
        // Находим вершину с минимальным весом среди непосещенных
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && (u == -1 || minEdgeWeight[v] < minEdgeWeight[u])) {
                u = v;
            }
        }

        if (u == -1) {
            return -1; // Если не удалось найти непосещенную вершину, значит граф не связан
        }

        
        visited[u] = true; // Добавляем вес рёбер в общий вес
        totalWeight += minEdgeWeight[u];

        // Перебираем соседей вершины u и обновляем минимальные веса для соседей
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] != 0 && !visited[v] && matrix[u][v] < minEdgeWeight[v]) {
                minEdgeWeight[v] = matrix[u][v];
            }
        }
    }

    // Проверка, были ли все вершины посещены
    for (bool v : visited) {
        if (!v) {
            return -1;  // Если не все вершины были посещены, возвращаем -1 (граф не связный)
        }
    }

    return totalWeight;
}