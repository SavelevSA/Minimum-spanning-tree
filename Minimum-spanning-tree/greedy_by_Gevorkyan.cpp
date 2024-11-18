#include <vector>
#include <algorithm>
#include <climits>
#include "Algorithms.h"
#include <iostream>

using namespace std;

// Функция для поиска минимального остовного дерева с помощью жадного метода
int greedy_by_Gevorkyan(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Массив для отслеживания посещённых вершин
    vector<bool> visited(n, false);

    // Переменная для хранения общего веса минимального остовного дерева
    int totalWeight = 0;

    // Жадным методом строим остовное дерево
    visited[0] = true;  // Начинаем с первой вершины

    int edges = 0;  // Количество рёбер в дереве

    while (edges < n - 1) {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        // Находим минимальное ребро, которое соединяет уже добавленную вершину с не добавленной
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                for (int j = 0; j < n; ++j) {
                    cout << matrix[i][j] << endl;
                    if (!visited[j] && matrix[i][j] > 0 && matrix[i][j] < minWeight) {
                        minWeight = matrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Добавляем найденное ребро в остовное дерево
        if (u != -1 && v != -1) {
            visited[v] = true;
            totalWeight += minWeight;
            edges++;
        }
    }

    return totalWeight;
}