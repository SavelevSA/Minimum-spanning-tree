
#include <limits>
#include <iostream>
#include <vector>
#include <climits>
#include "Algorithms.h"
#include <climits> // Для использования INT_MAX
#include <utility> // Для использования пары

using namespace std;

#define V 5 // Количество вершин в графе (можно изменить по необходимости)

// Функция для нахождения минимального остовного дерева с помощью алгоритма Прима
void primMST(int graph[V][V]) {
    // Массив для хранения MST (включены ли вершины в остовное дерево)
    bool inMST[V];

    // Массив для хранения минимальных ключей (минимальных ребер для каждой вершины)
    int key[V];

    // Массив для хранения родительских вершин
    int parent[V];

    // Инициализация всех ключей как бесконечность, parent как -1, и inMST как false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

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
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Выводим результаты
    cout << "Ребра минимального остовного дерева (MST):\n";
    for (int i = 1; i < V; i++) {
        cout << "Вершина " << i << " соединена с вершиной " << parent[i]
             << " весом " << graph[i][parent[i]] << endl;
    }
}

