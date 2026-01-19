class Solution {
public:
    void sortColors(vector<int>& nums) {
        int Max = INT_MIN;
        int Min = INT_MAX;
        for(int num:nums){
            Max = max(Max,num);
            Min = min(Min,num);
        }

        int offset = -Min;
        int len = Max - Min + 1;
        vector<int>count(len,0);
        vector<int>sorted(nums.size());

        for(int num:nums){
            count[num+offset]++;
        }

        for(int i = 1;i<count.size();i++){
            count[i] += count[i-1];
        }

        for(int i =nums.size()-1;i>=0;i--){
            sorted[count[nums[i]+offset]-1] = nums[i];//这里卡了
            count[nums[i]+offset]--;
        }

        for(int i = 0;i<nums.size();i++){
            nums[i] = sorted[i];
        }

    }
};