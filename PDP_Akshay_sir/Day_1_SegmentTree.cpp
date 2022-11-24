#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void updateUtil(vector<int> &SegmentTree, vector<int> &arr, int i, int index, int change_val, int sl, int sr)
{
    if (i < 0 || i >= SegmentTree.size())
        return;
    if (index >= sl && index <= sr)
    {
        SegmentTree[i] += change_val;
        int mid = (sl + sr) / 2;
        updateUtil(SegmentTree, arr, 2 * i + 1, index, change_val, sl, mid);
        updateUtil(SegmentTree, arr, 2 * i + 2, index, change_val, mid + 1, sr);
    }
}

void update(vector<int> &SegmentTree, vector<int> &arr, int index, int val)
{
    int change_val = val - arr[index];
    arr[index] = val;

    updateUtil(SegmentTree, arr, 0, index, change_val, 0, arr.size() - 1);
}

int RangeSumUtil(vector<int> &SegmentTree, vector<int> &arr, int i, int l, int r, int sl, int sr)
{
    if (r < sl || l > sr)
        return 0;
    else if (l <= sl && sr <= r)
        return SegmentTree[i];
    else
    {
        int mid = (sl + sr) / 2;
        return RangeSumUtil(SegmentTree, arr, 2 * i + 1, l, r, sl, mid) + RangeSumUtil(SegmentTree, arr, 2 * i + 2, l, r, mid + 1, sr);
    }
}

int RangeSum(vector<int> &SegmentTree, vector<int> &arr, int l, int r)
{
    if (l < 0 || r > arr.size() - 1)
    {
        cout << "Invalid Range " << endl;

        return -1;
    }
    return RangeSumUtil(SegmentTree, arr, 0, l, r, 0, arr.size() - 1);
}

int SegmentTreeUtil(vector<int> &SegmentTree, vector<int> &arr, int i, int sl, int sr)
{
    if (sl == sr)
    {
        SegmentTree[i] = arr[sl];
        return SegmentTree[i];
    }
    else
    {
        int mid = (sl + sr) / 2;
        SegmentTree[i] = SegmentTreeUtil(SegmentTree, arr, 2 * i + 1, sl, mid) + SegmentTreeUtil(SegmentTree, arr, 2 * i + 2, mid + 1, sr);
        return SegmentTree[i];
    }
}

void BuildSegmentTree(vector<int> &SegmentTree, vector<int> &arr)
{

    SegmentTreeUtil(SegmentTree, arr, 0, 0, arr.size() - 1);
}
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int c, l, r, index, val;
    cout << "Enter the no of queries : ";
    cin >> q;

    int size = 2 * (pow(2, ceil(log2(n)))) - 1;
    cout << "Size : " << size << endl;
    vector<int> SegmentTree(size, 0);

    BuildSegmentTree(SegmentTree, arr);
    printArray(SegmentTree);

    while (q--)
    {
        cout << "Enter the choice : ";
        cin >> c;
        switch (c)
        {
        case 0: // update
            cout << "Enter the index and val : ";
            cin >> index >> val;
            update(SegmentTree, arr, index, val);
            printArray(arr);
            break;
        case 1: // rangeSum
            cout << "Enter the range : ";
            cin >> l >> r;
            cout << "Sum : " << RangeSum(SegmentTree, arr, l, r) << endl;
            break;
        }
    }
    return 0;
}
