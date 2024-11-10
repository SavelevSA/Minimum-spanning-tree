#include <limits>
#include <iostream>
#include <vector>
#include <climits>
#include "Algorithms.h"


struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    std::vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges.resize(E);
    }

    // функция для добавления рёбра
    void addEdge(int i, int src, int dest, int weight) {
        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
    }
};

// Функция поиска (find) для Union-Find структуры
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

// Алгоритм Борувки для поиска мин. ост дерева (mst)
void boruvkaMST(Graph& graph) {
    int V = graph.V;
    int E = graph.E;
    std::vector<int> parent(V);
    std::vector<int> rank(V, 0);

    // Инициализация Union-Find структуры
    for (int v = 0; v < V; ++v)
        parent[v] = v;

    int numTrees = V;
    int MSTweight = 0;

    while (numTrees > 1) {
        // Инициализация минимальных рёбер для каждого компонента
        std::vector<Edge> cheapest(V, { -1, -1, INT_MAX });

        // Находим минимальное ребро для каждого компонента
        for (int i = 0; i < E; ++i) {
            int set1 = find(parent, graph.edges[i].src);
            int set2 = find(parent, graph.edges[i].dest);

            if (set1 != set2) {
                if (graph.edges[i].weight < cheapest[set1].weight)
                    cheapest[set1] = graph.edges[i];
                if (graph.edges[i].weight < cheapest[set2].weight)
                    cheapest[set2] = graph.edges[i];
            }
        }

        // Добавляем выбранные минимальные рёбра в МОД
        for (int i = 0; i < V; ++i) {
            if (cheapest[i].weight != INT_MAX) {
                int set1 = find(parent, cheapest[i].src);
                int set2 = find(parent, cheapest[i].dest);

                if (set1 != set2) {
                    MSTweight += cheapest[i].weight;
                    std::cout << "Ребро " << cheapest[i].src << " - " << cheapest[i].dest
                              << " включено в МОД с весом " << cheapest[i].weight << std::endl;
                    Union(parent, rank, set1, set2);
                    numTrees--;
                }
            }
        }
    }

    std::cout << "Вес МОД: " << MSTweight << std::endl;
}
