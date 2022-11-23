#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement_more_than_n_by_2(vector<int> &nums)
{

    // int n = nums.size();      /// -----> 
    // unordered_map<int, int> map;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     map[nums[i]]++;
    // }
    
    // for (auto x : map)
    // {
    //     if (x.second > n / 2)
    //      return x.first;
    // }

    // moore voting algo
    int count = 1, val = nums[0];      // optimal app 
    for (int i = 1; i < nums.size(); i++)
    {
        if (count == 0)
            val = nums[i];
        if (nums[i] == val)
            count++;
        else
            count--;
    }
    return val;
}

vector<int> majorityElement_more_than_n_by_3(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    vector<int> res;
    for (auto x : map)
    {
        if (x.second > n / 3)
            res.push_back(x.first);
    }
    return res;
}

int main()
{
    int n;
    cout << "Enter the size of the array  : ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
     cout << "Maximun element : " << majorityElement_more_than_n_by_2(nums);

    
    return 0;
}