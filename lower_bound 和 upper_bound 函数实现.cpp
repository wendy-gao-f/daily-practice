class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() == 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int start = 0, end = nums.size() - 1, mid, first, last;
        while (end - start != 0) {//寻找第一个位置
            mid = (start + end) / 2;
            if (nums[mid] < target) start = mid + 1;
            else end = mid;
        }
        if(target != nums[start]) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        else first = start;
        result.push_back(first);
        start = 0;
        end = nums.size() - 1;
        while (end - start != 0) {//寻找最后一个位置
            mid = (start + end) / 2;
            if (nums[mid] > target) end = mid;
            else start = mid + 1;
        }
        if(nums[end] == target) last = end;
        else last = end - 1;
        result.push_back(last);
        return result;
    }
};
