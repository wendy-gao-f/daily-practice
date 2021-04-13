#include<iostream>
#include<vector>
using namespace std;
/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() == 0) {
            result.push_back(-1);
            result.push_back(-1);
        }
        else {
            int start = 0, end = nums.size() - 1, mid, first, last;
            while (end - start != 0) {//寻找第一个位置
                mid = (start + end) / 2;
                if (mid < target) start = mid + 1;
                else end = mid;
                cout << "start:" << start << "end:" << end << endl;
            }
            if (target == start) first = start;
            else first = start + 1;
            result.push_back(first);
            start = 0;
            end = nums.size() - 1;
            while (end - start != 0) {//寻找最后一个位置
                mid = (start + end) / 2;
                if (mid > target) end = mid;
                else start = mid + 1;
            }
            if (target == end) last = end;
            else last = end - 1;
            result.push_back(last);
        }
        return result;
    }
};
*/
class Solution {//1    0
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, mid, right = nums.size() - 1;
        while (right >= left) {
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                if (target >= nums[mid] && target <= nums[right])
                    return two(mid, right, nums, target);
                else {
                    right = mid - 1;
                    continue;
                }
            }
            else if (nums[mid] > nums[right]) {
                if (target >= nums[left] && target <= nums[mid])
                    return two(left, mid, nums, target);
                else {
                    left = mid + 1;
                    continue;
                }
            }
            else {
                if (target == nums[right]) return true;
                else right--;
            }
        }
        return false;
    }
    bool two(int left, int right, vector<int>& nums, int target) {
        int mid;
        while (right > left) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] == target) return true;
        else return false;
    }
};
int main() {
    vector<int> nums = {1};
    int target = 0;
    Solution solution;
    cout<<solution.search(nums, target);
}