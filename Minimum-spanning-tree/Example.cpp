#include <iostream>
#include "Example.h"
#include <vector>
using namespace std;

int example(vector< vector<int> >& matrix)
{
    int sum = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        cout << i << ": ";
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << '\t';
            sum += matrix[i][j];
        }
        cout << endl;
    }
    cout << sum;
    return sum;
}