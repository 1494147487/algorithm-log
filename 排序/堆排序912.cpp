class Teap {//根节点对应数组下标1，最新加的叶节点对应数组数量值的下标
	private:
		vector<int> arr;
		int size;
	public:
		Teap():arr(111111) {  //构造函数
			size = 0;
		}
		int right(int i) {
			return i * 2 + 1;
		}
		int left(int i) {
			return i * 2;
		}
		int parent(int i) {
			return i / 2;
		}
		int pop() {
			int ans = arr[1];
			arr[1] = arr[size];
			arr[size] = 0;
			size--;
			sink(1);//下沉操作
			return ans;
		}
		void add(int i) {
			size++;
			arr[size] = i;
			swim(size);
		}
		void sink(int i) {
			if (i >= size)return;
			int minval = arr[i];
			int index;
			if (left(i) <= size && arr[left(i)] < minval) {
				minval = arr[left(i)];
				index = left(i);
			}
			if (right(i) <= size && arr[right(i)] < minval) {
				minval = arr[right(i)];
				index = right(i);
			}
			if (minval == arr[i])return;
			swap(arr[i], arr[index]);
			sink(index);
		}
		void swim(int i) {
			if (i == 1)return;
			int value = arr[i];
			if (arr[i] < arr[parent(i)]) {
				swap(arr[i], arr[parent(i)]);
				swim(parent(i));
			}
		}
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        Teap teap;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            teap.add(nums[i]);
        }
        for(int i = 0;i<n;i++){
           nums[i] = teap.pop();
        }
        return nums;
    }
};