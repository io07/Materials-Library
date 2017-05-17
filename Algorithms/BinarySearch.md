# Four Styles of BinarySearch

-----

Based on C++

### 1.(lower_bound) Find the first one no less than (>=) the key
```C++
int he = -1, ta = len; // 有限区域 [0~len-1]
while(ta - he > 1)
{
     int mid = (ta + he) >> 1;
     if(target <= nums[mid]) ta = mid;
     else he = mid;
}
return ta;
```

### 2.(upper_bound) Find the first one larger than (>) the key
```C++
int he = -1, ta = len;
while(ta - he > 1)
{
     int mid = (ta + he) >> 1;
     if (target < nums[mid]) ta = mid;
     else he = mid;
}
return ta;
```
### 3.Find the last one no larger than the key (<=) the key
```C++
int he = -1, ta = len;
while(ta - he > 1)
{
     int mid = (ta + he) >> 1;
     if (nums[mid] <= target) he = mid;
     else ta = mid;
}
return he;
```
### 4.Find the last one less than the key (<) the key
```C++
int he = -1, ta = len;
while(ta - he > 1)
{
     int mid = (ta + he) >> 1;
     if (nums[mid] < target) he = mid;
     else ta = mid;
}
return he;
```

if 条件中的符号一定是 <= or <
