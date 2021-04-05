class Solution {
public:
    int mySqrt(int x) {
        long int start = 1,end = x,mid;
        while(end-start!=0){
            mid = (start + end)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x) start = mid+1;
            else end = mid;
        }
        if(start*start > x) return start-1;
        else return start;
    }
   
};

