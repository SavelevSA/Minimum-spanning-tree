#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();  // ������������� ��� �������������

// ������� ��� ���������� ���� ������������ ��������� ������ � �������������� ��������� �����
int example(const vector<vector<int>>& matrix) {
    int n = matrix.size(); // ���������� ������ � �����
    vector<int> minEdgeWeight(n, INF); // ����������� ��� ����� ��� ������ �������
    vector<bool> inMST(n, false);      // ����, ������������, ������ �� ������� � MST

    // �������� � ������ ������� (0)
    minEdgeWeight[0] = 0;
    int totalWeight = 0;

    for (int i = 0; i < n; ++i) {
        // ���� ������� u � ����������� ����� �����, ������� ��� �� � MST
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || minEdgeWeight[j] < minEdgeWeight[u])) {
                u = j;
            }
        }

        // ��������� ������� u � MST
        inMST[u] = true;
        totalWeight += minEdgeWeight[u];

        // ��������� ����������� ���� ��� ������� ������� u
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] && !inMST[v] && matrix[u][v] < minEdgeWeight[v]) {
                minEdgeWeight[v] = matrix[u][v];
            }
        }
    }

    // ���������� ����� ��� ������������ ��������� ������
    return totalWeight;
}