#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class minpq {
	private:
		vector<int>heap;
		int size;

	public:

		minpq(int capcity) {//构造
			heap.resize(capcity);
			size = 0;
		}

		void push(int value) {//增
			size++;
			heap[size] = value;//在树的底层最右边加入
			int index = size;
			//if (parent(index) < 1)return;
			swim(index);

		}

		int pop() {//删
			if (size == 0)return -1;
			int res = heap[1];
			heap[1] = heap[size];
			heap[size] = 0;
			size--;
			sink(1);
			
			return res;
		}

		int get(int node) {//查
			return heap[1];
		}

		int left(int a) {
			return a * 2;
		}

		int right(int a) {
			return a * 2+1;
		}

		int parent(int a) {
			return a / 2;
		}

		void swim(int node) {//上浮
			while (node > 1 && heap[parent(node)] > heap[node]) {
				swap(heap[node], heap[parent(node)]);
				node = parent(node);
			}
		}

		void sink(int node) {//下沉
			int Min =  node;
			 
			if (left(node) <= size&& heap[Min] > heap[left(node)]) {
				Min = left(node);
			}
			if (right(node) <= size&& heap[Min] > heap[right(node)]) {
				Min = right(node);
			}
			if (Min != node) {
				swap(heap[Min], heap[node]);
				sink(Min);
			}
		}
};

int main() {
	minpq pq(100);
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(9);
	pq.push(15);


	cout << pq.pop() << endl;
	cout << pq.pop() << endl;
	cout << pq.pop() << endl;
	cout << pq.pop() << endl;
	cout << pq.pop() << endl;
	cout << pq.pop() << endl;
	cout << pq.pop() << endl;

}