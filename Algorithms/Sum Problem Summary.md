# Leetcode Sum Problem Summary

also can be called two pointers problem

---

Based on C++

### 1. Two Sum (Leetcode 1)
<https://leetcode.com/problems/two-sum/description/>

The dataset isn't large so just enumerate the whole solution space to get the answer.

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
        return res;
        
    }
};
```
### 2. Three Sum (Leetcode 15)
<https://leetcode.com/problems/3sum/description/>

Enumerate one value as target and use two pointers (one move from the head and the other from the tail) to get the answer in O(n), so the total time complexity is O(n^2).

Pay attention to removing duplicates triplets.
Every time you move the pointer(i, he, ta), make sure the pointer get a new value(jump the same value positions).

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp(3); // allocate the memory for onece, beat 93%
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); i++) {
            int he = i + 1, ta = nums.size() - 1, aim = -nums[i];
            while(he < ta) {
                int sum = nums[he] + nums[ta];
                if (sum < aim) he++;
                else if (sum > aim) ta--;
                else {
                    tmp[0] = nums[i];
                    tmp[1] = nums[he];
                    tmp[2] = nums[ta];
                    res.push_back(tmp);
                    while(he < ta && nums[he] == tmp[1]) he++;
                    while(he < ta && nums[ta] == tmp[2]) ta--;
                }
            }
            while(i + 2 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
```

### 3. 3Sum Closest(Leetcode 16)
<https://leetcode.com/problems/3sum-closest/description/>

```C++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res, dis = -1;
        for (int i = 0; i + 2 < nums.size(); i++) {
            int he = i+1, ta = nums.size() - 1;
            while (he < ta) {
                int sum = nums[i] + nums[he] + nums[ta];
                if (dis == -1 || dis > abs(sum - target)) {
                    dis = abs(sum - target);
                    res = sum;
                    if (dis == 0)
                        return res;
                }
                if (sum < target) he++;
                else ta--;
            }
        }
        return res;
    }
};
```

