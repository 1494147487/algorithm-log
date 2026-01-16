class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int h = 1;
        int n = nums.size();
        if(n == 0)return nums;
        while(h<n/2){
            h = h*2;
        }
        while(h>=1){
            int sortindex = h;
            while(sortindex<n){
                for(int i = sortindex;i>=h;i-=h){//i>=0这里卡了,把i>=h写成i>=0了
                    if(nums[i]<nums[i-h]){
                        int t = nums[i];
                        nums[i] = nums[i-h];//num[i-h]写成num[i-1]了
                        nums[i-h] = t;
                    }else{
                        break;
                    }
                }
                sortindex++;
            }
            h = h/2;
        }
        return nums;
    }
};