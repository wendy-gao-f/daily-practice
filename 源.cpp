#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        if (nums1.size() == 0) nums1 = nums2;
        else {
            nums1[m] = 2000000000;
            while (j < n) {
                if (nums2[j] < nums1[i]) {
                    nums1.erase(nums1.end() - 1);
                    nums1.insert(nums1.begin() + i, nums2[j]);
                    j++;
                }
                i++;
            }
        }
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    solution.merge(nums1,3,nums2,3);
    vector<int>::iterator it = nums1.begin();
    for (; it != nums1.end(); it++) cout << *it << " ";
    return 0;
}