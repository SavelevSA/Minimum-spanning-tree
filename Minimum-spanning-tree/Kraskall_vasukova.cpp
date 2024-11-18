#include <iostream>
#include <vector>
#include <algorithm>
#include "Algorithms.h"

using namespace std;

// ������������� �����
struct Edge {
    int start, end, weight;
};

// ��������� ���� ���� �� ����
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// ����� ��� ���������� ������� ���������������� ��������
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    //����� ������ ����
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    //����������� �������� �� ����� ��������
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            }
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int Kraskall_by_Vasukova(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<Edge> edges;

    // ���������� ���� �� ������� ��������� 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { 
            if (matrix[i][j] != 0) {
                edges.push_back({ i, j, matrix[i][j] });
            }
        }
    }

    // ���������� ���� �� ���� �� �����������
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(n);
    int TotalWeight = 0;

    // �������� ��������
    for (const Edge& edge : edges) {
        int u = edge.start;
        int v = edge.end;

        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            TotalWeight += edge.weight;
        }
    }

    return TotalWeight;
}