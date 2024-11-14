#include <limits>
#include <vector>
#include <climits>

using namespace std;

// Структура для представления ребра
struct Edge {
    int u, v, weight;
};

// Функция для нахождения минимального остовного дерева с помощью алгоритма Прима
int Prim_by_Chigladze(std::vector<std::vector<int>>& matrix) {
    int V = matrix.size(); // Количество вершин графа
    if (V == 0) return 0;  // Если граф пустой, возвращаем 0

    // Массив для хранения MST (включены ли вершины в остовное дерево)
    std::vector<bool> inMST(V, false);

    // Массив для хранения минимальных ключей (минимальных ребер для каждой вершины)
    std::vector<int> key(V, INT_MAX);

    // Массив для хранения родительских вершин
    std::vector<int> parent(V, -1);

    // Начнем с вершины 0 (это можно изменить)
    key[0] = 0;

    // Алгоритм Прима
    for (int count = 0; count < V - 1; count++) {
        // Находим вершину с минимальным ключом, которая еще не включена в MST
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Включаем вершину u в MST
        inMST[u] = true;

        // Обновляем значения ключей для соседей вершины u
        for (int v = 0; v < V; v++) {
            // Если существует ребро между вершинами u и v, и v не включена в MST,
            // и вес ребра меньше текущего ключа для вершины v
            if (matrix[u][v] && !inMST[v] && matrix[u][v] < key[v]) {
                key[v] = matrix[u][v];
                parent[v] = u;
            }
        }
    }

    // Теперь можно возвращать итоговый результат (например, сумму весов MST)
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        totalWeight += matrix[i][parent[i]];  // Добавляем вес ребра в MST
    }

    return totalWeight;  // Возвращаем общий вес минимального остовного дерева
}