#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int s = 0, e = nums.size() - 1, l, t = nums.size() - k;
        while (s <= e) {
            l = sorting(nums, s, e);
            if (l < t) s = l + 1;
            else if (l > t) e = l - 1;
            else break;
        }
        return nums[l];
    }
    int sorting(vector<int>& nums, int s, int e) {
        int pivot = nums[s], i = s, j = e;
        while (i < j) {
            while (nums[j] >= pivot && j > i) j--;
            if (j > i) nums[i++] = nums[j];
            while (nums[i] <= pivot && i < j) i++;
            if (i < j) nums[j--] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }
};
int main() {
	int t = 2;
    vector<int> nums = { 3,2,1,5,6,4 };// 1 2 3 4 5 6   1 2 1 5 6 4   
    Solution solution;
    cout << solution.findKthLargest(nums, t);
	return 0;
}
