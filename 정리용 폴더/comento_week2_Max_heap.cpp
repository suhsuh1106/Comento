#include<iostream>

using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	//노드 인덱스값을 통해 비교하고, 큰쪽이랑 key값을 swap, 바뀐쪽 인덱스 통해 재귀
	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	//왼쪽이 큰가
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	//오른쪽이 큰가
	if (largest != i) {
		swap(arr[i], arr[largest]);
		//largest값이 다르면 key 값 변경

		heapify(arr, n, largest);
		//sub-tree로 진행
	}
	cout << "여기 실행됨1" << endl;
}

void heap_sort(int arr[], int n) {
	int mid = n / 2 - 1;
	for (int i = mid; i >= 0; i--) {
		heapify(arr, n, i);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int arr[] = { 3,1,65,4,1,7,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heap_sort(arr, n);

	cout << "Max heap으로 구현되었을 시 \n";
	printArray(arr, n);
}
