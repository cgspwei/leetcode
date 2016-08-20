// Copyright (c) 2016,
// All rights reserved.
//
// Author: cgspwei <cgspwei@gmail.com>
// Created: 08/20/16
// Description:
//
// Two Sum
// Given an array of integers, return indices of the two numbers such that they add up to a specific target
// You may assume that each input would have exactly one solution
//
// Example:
// Given nums = [2, 7, 11, 15], target = 9
// Because nums[0] + nums[1] = 2 + 7 = 9
// return [0, 1]

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.empty() || nums.size() < 2) {
        return vector<int>();
    }
    unordered_map<int, int> dict;
    vector<int> result;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (dict.find(target - nums[i]) == dict.end()) {
            dict[nums[i]] = i;
        } else {
            result.push_back(dict[target - nums[i]]);
            result.push_back(i);
            return result;
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> result = twoSum(nums, target);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
