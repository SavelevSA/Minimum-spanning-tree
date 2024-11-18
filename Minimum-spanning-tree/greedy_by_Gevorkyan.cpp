#include <vector>
#include <algorithm>
#include <climits>
#include "Algorithms.h"
#include <iostream>

using namespace std;

// ������� ��� ������ ������������ ��������� ������ � ������� ������� ������
int greedy_by_Gevorkyan(const vector<vector<int>>& matrix) {
    int n = matrix.size();

    // ������ ��� ������������ ���������� ������
    vector<bool> visited(n, false);

    // ���������� ��� �������� ������ ���� ������������ ��������� ������
    int totalWeight = 0;

    // ������ ������� ������ �������� ������
    visited[0] = true;  // �������� � ������ �������

    int edges = 0;  // ���������� ���� � ������

    while (edges < n - 1) {
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        // ������� ����������� �����, ������� ��������� ��� ����������� ������� � �� �����������
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

        // ��������� ��������� ����� � �������� ������
        if (u != -1 && v != -1) {
            visited[v] = true;
            totalWeight += minWeight;
            edges++;
        }
    }

    return totalWeight;
}