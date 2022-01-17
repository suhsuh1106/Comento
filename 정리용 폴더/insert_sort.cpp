#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 삽입정렬
void insertionSort(int arr[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++) {
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		//printf("%d ", i);
		arr[j + 1] = temp;
	}
}

// Quick 정렬
void quick_sort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot]) {
			i++;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			j--;
		}
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

// merge 정렬
void merge(int data[], int p, int q, int r, int sorted[]) {
	int i = p, j = q + 1, k = p;
	while (i <= q && j <= r) {
		if (data[i] <= data[j]) sorted[k++] = data[i++];
		else sorted[k++] = data[j++];
	}
	while (i <= q) sorted[k++] = data[i++];
	while (j <= r) sorted[k++] = data[j++];
	for (int a = p; a <= r; a++) data[a] = sorted[a];
}
void mergeSort(int data[], int p, int r, int sorted[]) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(data, p, q, sorted);
		mergeSort(data, q + 1, r, sorted);
		merge(data, p, q, r, sorted);
	}
}


// 출력
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//배열 생성
void arr_init(int * arr, int n) {
	for (int i = 0; i <= n - 1; i++){
		arr[i] = rand() % 1000;
		//arr[i] = i;
		//arr[i] = n - 1 - i;

		//printf("%d ", arr[i]);
	}
}

// 실행 속도 측정
int main()
{
	//int arr_size = 10000000;
	int arr_size = 1000000;
	int* arr = (int*)malloc(sizeof(int) * arr_size);
	int n = arr_size;

	clock_t start1, end1, start2, end2, start3, end3;
	float res1, res2, res3;

	// 배열 생성
	int* sorted = (int*)malloc(sizeof(int) * arr_size);
	for (int i = 0; i <= arr_size - 1; i++) {
		sorted[i] = 0;
	}
	arr_init(arr, n);
	/*----------------------------Insert sort------------------------------------*/
	start1 = clock();
	insertionSort(arr, n);
	end1 = clock();
	res1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf(" Insert sort 소요된 시간 : %.3f \n", res1);
	//printArray(arr, n);
	/*---------------------------------------------------------------------------*/	arr_init(arr, n);
	/*----------------------------Quick sort-------------------------------------*/
	start2 = clock();
	quick_sort(arr, 0, arr_size-1);
	end2 = clock();
	res2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
	printf(" Quick sort 소요된 시간 : %.3f \n", res2);
	//printArray(arr, n);
	/*---------------------------------------------------------------------------*/
	arr_init(arr, n);
	/*----------------------------Merge sort-------------------------------------*/
	start3 = clock();
	mergeSort(arr, 0, arr_size-1, sorted);
	end3 = clock();
	res3 = (float)(end3 - start3) / CLOCKS_PER_SEC;
	printf(" Merge sort 소요된 시간 : %.3f \n", res3);
	//printArray(arr, n);
	/*---------------------------------------------------------------------------*/

	free(arr);
	free(sorted);

	return 0;
}
