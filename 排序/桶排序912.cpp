class Solution {
public:
    void insertsort(vector<int>& nums) {
	int sorted = 0;
	while (sorted<nums.size())
	{	
		for (int i = sorted; i >0 ; i--)
		{
			if (nums[i] < nums[i - 1]) {
				int tmp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = tmp;
			}
			else {
				break;
			}
		}
		sorted++;
	}
}

void bucketsort(vector<int>& nums,int bucketcount) {
    if (nums.size() <= 1) return;
	int Min = INT_MAX;
	int Max = INT_MIN;
	for (int num : nums) {
		Min = min(Min, num);
		Max = max(Max, num);
	}
	int offset = -Min;
	int bucketsize = (Max - Min) / bucketcount + 1;//这里卡了，错误使用nums.size()/bucketcount了
	vector<vector<int>>sum(bucketcount);

	//开始把元素分配好到每个桶
	for (int num : nums) {
		int index = (num+offset) / bucketsize;//这里不确定是不是少写细节了
		sum[index].push_back(num);
	}
	//对每个桶进行排序
	for (vector<int> &i : sum) {
		insertsort(i);
	}
	//合并有序桶
	int cnt = 0;
	for (int i = 0; i < bucketcount; i++) {
		for (int j = 0; j < sum[i].size(); j++) {
			nums[cnt] = sum[i][j];
			cnt++;
		}
	}
}


    vector<int> sortArray(vector<int>& nums) {
        int sz= nums.size();
        //int k = sz/2;
        int k = max(1, (int)sqrt(sz));
        bucketsort(nums,k);
        return nums;
    }
};