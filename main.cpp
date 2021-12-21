#include <stdio.h>
/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> map;

        const int N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            //map[nums[i]] = i;
        }

        vector<int> res(2, 0);
        for (int i = 0; i < N; ++i)
        {
            auto itr = map.find(target - nums[i]);
            if (itr != map.end())
            {
                res[1] = i;
                res[0] = itr->second;
                return res;
            }
            map[nums[i]] = i;
        }

        return res;
    }
};

int main()
{
    int N, T;
    cin >> N >> T;

    vector<int> NUMS(N);
    for (int i = 0; i < N; ++i) { cin >> NUMS[i]; }

    Solution sol;
    vector<int> result = sol.twoSum(NUMS, T);
    cout << result[0] << "," << result[1] << endl;
}
// @lc code=end


