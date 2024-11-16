#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // ������������� ��� �������������

int DFS_by_Gevorkyan(const vector<vector<int>>& matrix) {
    int n = matrix.size();  // ���������� ������ � �����
    vector<int> minEdgeWeight(n, INF); // ����������� ��� ����� ��� ������ �������
    vector<bool> visited(n, false);    // ������ ��� ������������ ���������� ������
    int totalWeight = 0; // ������������ ���

    // �������� � ������ ������� (0)
    minEdgeWeight[0] = 0;

    for (int i = 0; i < n; ++i) {
        // ������� ������� � ����������� ����� ����� ������������
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && (u == -1 || minEdgeWeight[v] < minEdgeWeight[u])) {
                u = v;
            }
        }

        if (u == -1) {
            return -1; // ���� �� ������� ����� ������������ �������, ������ ���� �� ������
        }

        
        visited[u] = true; // ��������� ��� ���� � ����� ���
        totalWeight += minEdgeWeight[u];

        // ���������� ������� ������� u � ��������� ����������� ���� ��� �������
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] != 0 && !visited[v] && matrix[u][v] < minEdgeWeight[v]) {
                minEdgeWeight[v] = matrix[u][v];
            }
        }
    }

    // ��������, ���� �� ��� ������� ��������
    for (bool v : visited) {
        if (!v) {
            return -1;  // ���� �� ��� ������� ���� ��������, ���������� -1 (���� �� �������)
        }
    }

    return totalWeight;
}