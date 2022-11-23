#include <iostream>
#include <vector>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.


// time complexity O(nm + nm(n+m)) === O(n^3)
// space complexity O(nm)
void setZeroes_1(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> val;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
                temp.push_back(0);
            else
                temp.push_back(1);
        }
        val.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                    matrix[i][k] = 0;
                for (int l = 0; l < n; l++)
                    matrix[l][j] = 0;
            }
        }
    }
}

// time complexity O(2nm )
// space complexity O(n + m )
void setZeroes_2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 1), col(m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 0 || col[j] == 0)
                matrix[i][j] = 0;
        }
    }
}

// time complexity O(2nm )
// space complexity O(1)
void setZeroes_3(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int first_col = 1;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            first_col = 0;
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j > 0; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if (first_col == 0)
            matrix[i][0] = 0;
    }
}

int main()
{
    int n, m, val;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            cin >> val;
            temp.push_back(val);
        }
        matrix.push_back(temp);
    }
    setZeroes_3(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}