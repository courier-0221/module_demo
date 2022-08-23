#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	写出二分法查找，要求在10分钟之内完成，并调试通过
*/

int digui_erfen(int *array, int size, int key, int low, int high)
{
	if ((array == NULL) || (low > high)){
		return -1;
	}
	
	int mid = (low + high) / 2, ret = -1;
	if (array[mid] == key){
		printf("find\n");
		return mid;
	}
	if (array[mid] > key){
		high = mid - 1;
		ret = digui_erfen(array, size, key, low, high);
	}
	if (array[mid] < key){
		low = mid + 1;
		ret = digui_erfen(array, size, key, low, high);
	}
	return ret;
}


void binary_search(int *array, int size, int key)
{
	if (array == NULL){
		exit(-1);
	}
	int low = 0, high = size - 1;
	while (low <= high){
		int mid = (low + high) / 2;
		if (array[mid] == key){
//			printf("find\n");
			return;
		}
		if (array[mid] > key){
			high = mid - 1;
		}
		if (array[mid] < key){
			low = mid + 1;
		}
	}
	printf("not find\n");
}


int main(void)
{
	int array[] = { 1, 3, 6, 9, 12, 16, 18, 21, 32 };
	int len = sizeof(array) / sizeof(*array);
	//binary_search(array, len, 9);

	if (digui_erfen(array, len, 7, 0, len - 1) > 0){
		printf("find\n");
	}
	else{
		printf("no find\n");
	}

	system("pause");
	return 0;
}