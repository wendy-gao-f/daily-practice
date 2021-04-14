class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) return true;
            else return false;
        }
        else {
            int flag = *(nums.end() - 1);
            int bound = (nums.size() - 1) / 2;
            int start = 0, end = nums.size()-1;
            while (nums[bound] <= nums[bound + 1]) {
                if (nums[bound] > flag) {
                    start = bound + 1;
                    bound = (bound + nums.size()) / 2;
                }
                else if(nums[bound] < flag){
                    bound = (start + bound)/2;
                    if (bound == 0) {
                        bound = -1;
                        break;
                    }
                }
                else {//µÈÓÚ
                    if (target == flag) return true;
                    else {
                        end--;
                        flag = nums[end];
                        bound = (start + end) / 2;
                        if (bound == 0) {
                            bound = -1;
                            break;
                        }
                    }
                }
            }
            if (target > flag) {
                start = 0;
                end = bound;
                return two(nums, target, start, end);
            }
            else if (target < flag) {
                start = bound + 1;
                end = nums.size() - 1;
                return two(nums, target, start, end);
            }
            else return true;
        }
    }
    bool two(vector<int>& nums, int target, int start, int end) {
        int mid;
        while (end - start > 0) {
            mid = (start + end) / 2;
            if (nums[mid] > target) end = mid;
            else if (nums[mid] < target) start = mid + 1;
            else return true;
        }
        if (nums[start] == target) return true;
        else return false;
    }
};
