
#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();
    vector<bool> rowZeros(R, false);
    vector<bool> colZeros(C, false);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowZeros[i] = true;
                colZeros[j] = true;
            }
        }
    }

    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (rowZeros[i] || colZeros[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}
