#include <limits>
#include <iostream>
#include <vector>
#include <climits>
#include "Algorithms.h"


// Структура для представления рёбер графа
struct Edge {
    int src, dest, weight;
};

// Функция для поиска (find) в Union-Find структуре
int find(std::vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Функция объединения (union) двух поддеревьев
void Union(std::vector<int>& parent, std::vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Алгоритм Борувки для поиска минимального остовного дерева (МОД), принимающий матрицу смежности
int Boruvki_by_Merenkova(std::vector<std::vector<int>>& matrix) {
    int V = matrix.size();  // Количество вершин
    std::vector<Edge> edges;  // Список рёбер

    // Преобразуем матрицу смежности в список рёбер
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (matrix[i][j] != 0 && matrix[i][j] != INT_MAX) {  // INT_MAX используется для отсутствующих рёбер
                edges.push_back({i, j, matrix[i][j]});
            }
        }
    }

    int E = edges.size();
    std::vector<int> parent(V);
    std::vector<int> rank(V, 0);

    // Инициализация Union-Find структуры
    for (int v = 0; v < V; ++v)
        parent[v] = v;

    int numTrees = V;
    int MSTweight = 0;

    // Основной цикл алгоритма Борувки
    while (numTrees > 1) {
        // Инициализация минимальных рёбер для каждого компонента
        std::vector<Edge> cheapest(V, { -1, -1, INT_MAX });

        // Находим минимальное ребро для каждого компонента
        for (int i = 0; i < E; ++i) {
            int set1 = find(parent, edges[i].src);
            int set2 = find(parent, edges[i].dest);

            if (set1 != set2) {
                if (edges[i].weight < cheapest[set1].weight)
                    cheapest[set1] = edges[i];
                if (edges[i].weight < cheapest[set2].weight)
                    cheapest[set2] = edges[i];
            }
        }

        // Добавляем выбранные минимальные рёбра в МОД
        for (int i = 0; i < V; ++i) {
            if (cheapest[i].weight != INT_MAX) {
                int set1 = find(parent, cheapest[i].src);
                int set2 = find(parent, cheapest[i].dest);

                if (set1 != set2) {
                    MSTweight += cheapest[i].weight;
                    Union(parent, rank, set1, set2);
                    numTrees--;
                }
            }
        }
    }

    return MSTweight;
}