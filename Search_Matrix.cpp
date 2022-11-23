#include <iostream>
using namespace std;
#include <vector>

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int i = 0, c = 0;
    int m = matrix.size(), n = matrix[0].size();

    for (i = 0; i < m; i++)
    {
        if (target >= matrix[i][0] && target <= matrix[i][n - 1])
        {
            c = 0;
            break;
        }
        else
            c++;
    }
    if (c == 0)
    {
        // for (int j = 0; j < n; j++)    // O(n)
        // {
        //     if (target == matrix[i][j])
        //     {
        //         return true;
        //     }
        // }
        int low = 0, high = n - 1;
        while (low <= high) // O(log n)
        {
            int mid = (low + high) / 2;
            if (matrix[i][mid] == target)
                return true;
            else if (matrix[i][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

// optimal solution
// perform binary search on full matrix 
bool searchMatrix_o(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = (n*m - 1);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int i = mid / n, j = mid % n;
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
int main()
{
    int n, m, c;
    cout << "enter ";
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        cout << "enter  row : ";
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            temp.push_back(c);
        }
        matrix.push_back(temp);
    }

    cout << searchMatrix_o(matrix, 3);
    return 0;
}