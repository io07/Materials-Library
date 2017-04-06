# About the Parition Operation in Quick Sort

---

Based on C++

### 1. Dividing into two groups (< and >=), double pointers

```C++
#include <stack>
using namespace std;

template<typename T>
void qsort(T lst[], int length) {
    /*
     * 功能：对数组升序快排，迭代实现
     * 参数：lst：待排序的数组，length：数组的长度
     * 返回值：无
     */

    stack<pair<int, int>> trace;
    trace.push(make_pair(0, length - 1));   // 将数组首尾压栈

    while (!trace.empty()) {
        auto top = trace.top(); // 将栈顶元素保存下来
        trace.pop();    // 弹出栈顶

        int i = top.first;  // 取出首尾地址
        int j = top.second;

        T pivot = lst[i];  // 取第一个数为基准

        while (i < j) { // 循环直至 i,j 相遇
            while (i < j and lst[j] >= pivot) j--;
            lst[i] = lst[j];    // 从右向左扫描，将比基准小的数填到左边
            while (i < j and lst[i] < pivot) i++;
            lst[j] = lst[i];    //  从左向右扫描，将比基准大的数填到右边
        }

        lst[i] = pivot; // 将 基准数 填回

        if (i > top.first) trace.push(make_pair(top.first, i - 1));
        if (j < top.second) trace.push(make_pair(j + 1, top.second));
    }
}
```

### 2. Dividing into two groups (< and >=), one pointer
```C++
int partition(vector<int> &vi, int low, int up)
{
    int pivot = vi[up];
    int i = low-1;
    for (int j = low; j < up; j++)
    {
        if(vi[j] <= pivot)  
        {  
            i++;  
            swap(vi[i], vi[j]);  
        }  
    }
    swap(vi[i+1], vi[up]);
    return i+1;
}
```

### 3. Dividing into three groups (1) < key (2) = key (3) > key, one pointer
From LeetCode 75. Sort Colors https://leetcode.com/problems/sort-colors/#/description
```C++
class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        // it seems like part operation that <key =key >key which I meet in msra
        int a = 0, b = 0, c = nums.size()-1;
        while (b <= c) { // !!! <= not < !!!!
            if (nums[b] == 0) {
                swap(nums[a], nums[b]);
                a++;
                b++;
            }
            else if (nums[b] == 1)
                b++;
            else{
                swap(nums[b], nums[c]);
                c--;
            }
        }
    }
};
```

```C++
class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        // it seems like part operation that <key =key >key which I meet in msra
        int a = 0, b = 0, c = nums.size()-1, key = 1;
        while (b < c) {
            while (b < c && nums[c] > key) { c--;}
            while (b < c && nums[b]<= key) {
                if (nums[b] < key) {
                    swap(nums[a], nums[b]);
                    a++;
                }
                b++;
            }
            swap(nums[c], nums[b]);
        }
        if (nums[b] < key) // !!!! pay attention !!!!
            swap(nums[b], nums[a]);
    }
};
```
