#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
    return (nums[0] - 1) * (nums[1] - 1);
}

int main()
{
    vector<int> v = {3, 4, 5, 2};
    cout << maxProduct(v);

    return 0;
}