#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int mid = (n / 2);
        int count = 0;
        int previous = mid - 1;
        int ptr1 = 0, ptr2 = 0, midElement = -1, previousElement = -1;
        while (ptr1 < n1 && ptr2 < n2)
        {
            if (nums1[ptr1] <= nums2[ptr2])
            {
                if (count == previous)
                {
                    previousElement = nums1[ptr1];
                }
                else if (count == mid)
                {
                    midElement = nums1[ptr1];
                }
                ptr1++;
                count++;
            }
            else if (nums1[ptr1] > nums2[ptr2])
            {
                if (count == previous)
                {
                    previousElement = nums2[ptr2];
                }
                else if (count == mid)
                {
                    midElement = nums2[ptr2];
                }
                ptr2++;
                count++;
            }
        }
        while (ptr1 < n1)
        {
            if (count == previous)
            {
                previousElement = nums1[ptr1];
            }
            else if (count == mid)
            {
                midElement = nums1[ptr1];
            }
            ptr1++;
            count++;
        }
        while (ptr2 < n2)
        {
            if (count == previous)
            {
                previousElement = nums2[ptr2];
            }
            else if (count == mid)
            {
                midElement = nums2[ptr2];
            }
            ptr2++;
            count++;
        }
        if (n % 2 == 0)
        {
            return ((double)midElement + (double)previousElement) / 2.00000;
        }
        else
        {
            return midElement;
        }
    }
};

// Driver code
int main()
{
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median is: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Median is: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}