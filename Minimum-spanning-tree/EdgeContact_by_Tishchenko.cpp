#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

int findParent(int v, std::vector<int>& parent) {
    if (parent[v] != v) {
        parent[v] = findParent(parent[v], parent);  
    }
    return parent[v];
}

void unionSets(int u, int v, std::vector<int>& parent) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV) {
        parent[rootU] = rootV;  
    }
}

int EdgeContact_by_Tishchenko(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();  

    std::vector<int> parent(n);
    std::iota(parent.begin(), parent.end(), 0);  

    int mstWeight = 0;

    while (n > 1) {
        int minWeight = std::numeric_limits<int>::max();
        int u = -1, v = -1;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] > 0 && findParent(i, parent) != findParent(j, parent)) {  
                    if (matrix[i][j] < minWeight) {
                        minWeight = matrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            unionSets(u, v, parent);  
            mstWeight += minWeight;    
            --n;  
        }
    }

    return mstWeight;
}