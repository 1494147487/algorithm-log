#include<iostream>
#include<vector>
using namespace std;

class Teap {//根节点对应数组下标1，最新加的叶节点对应数组数量值的下标
	private:
		vector<int> arr;
		int size;
	public:
		Teap():arr(111111) {  //构造函数
			size = 0;
		}

		// 新增：原地建堆构造函数
		//Teap(vector<int>& nums) : arr(111111) {
		//	// 将数据复制到arr中（从下标1开始）
		//	size = nums.size();
		//	for (int i = 0; i < size; i++) {
		//		arr[i + 1] = nums[i];
		//	}

		//	// Floyd建堆法：O(n)时间建堆，直接调用你的sink函数
		//	for (int i = size / 2; i >= 1; i--) {
		//		sink(i);  // 直接使用你的sink函数
		//	}
		//}

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

int main() {

	Teap teap;
	teap.add(3);
	teap.add(4);
	teap.add(1);
	teap.add(2);
	cout << teap.pop() << endl;
	cout << teap.pop() << endl;
	cout << teap.pop() << endl;
	cout << teap.pop() << endl;

}