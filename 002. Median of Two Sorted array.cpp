/*
Problem Statement:
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Approach: 
1. Extra space and merge function
    Time and Space : O(n+m)
2. Merge function without using extra space
    Keep a couter variable
    Time: O(n+m) and space: O(1)
3. Using binary search
    Time: O(log(m+n)) and space: O(1)

    a. We try to partition the arrays in the way such that partition
    is valid
    b. We move the partition right or left based on elemets on the side of partion in both the arrays
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        if(arr2.size() < arr1.size()) return findMedianSortedArrays(arr2, arr1);
        
        int n1 = arr1.size(), n2 = arr2.size();
        int low = 0, high = n1;
        
        while(low <= high)
        {
            // cut1 on the first array
            int cut1 = (low+high)/2;
            // remaining element from the second array
            int cut2 = (n1+n2+1)/2 - cut1;
            
            // edge elements
            int left1 = (cut1 == 0)? INT_MIN : arr1[cut1-1];
            int left2 = (cut2 == 0)? INT_MIN : arr2[cut2-1];
            int right1 = (cut1 == n1)? INT_MAX : arr1[cut1];
            int right2 = (cut2 == n2)? INT_MAX : arr2[cut2];
            
            // if the partition is valid
            if(left1 <= right2 && left2 <= right1)
            {
                // eodd element
                if((n1 + n2)%2 != 0)
                {
                    // odd
                    return max(left1, left2);
                }
                else // even
                    return (max(left1, left2) + min(right1, right2))/2.0;
            }
            // move toe the left
            else if(left1 > right2)
            {
                high = cut1 - 1;
            }
            // move to right
            else
                low = cut1 + 1;
            
        }
        return 0.0;
    }
};