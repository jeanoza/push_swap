#include <stdio.h>

void swap(int a, int b, int *arr) {
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

void quickSort(int left,int right, int* data) {
	int pivot = left;
	int j = pivot;
	int i = left+1;

	if (left < right) {
		for (; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(j, i,data);
			}
		}
		swap(left,j, data);
		pivot = j;

		quickSort(left, pivot-1,data);
		quickSort(pivot+1, right, data);
	}

}

int main() {

	int arr[11] = { 5,4,3,2,1, 10, 11, 12 , 20, 14, 16};
	quickSort(0, 10, arr);
	// for (int i = 0; i < 11; i++) printf("%d ",arr[i]);

	return 0;
}