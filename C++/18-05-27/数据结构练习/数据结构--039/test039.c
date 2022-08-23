#include <stdio.h>
#include <string.h>

/*
题目：
	商汤科技嵌入式软件工程师第一套题中编程题一
	n个数(其中数可重复)求出其中第m大的数
*/

int find_m_max(int *array, int len,int m)
{
	if (array == NULL){
		return -1;
	}
	int ret = 0;
	//选择
	//for (int i = 0; i < len; i++){
	//	for (int j = i; j < len; j++){
	//		if (array[i] > array[j]){
	//			char tmp = array[i];
	//			array[i] = array[j];
	//			array[j] = tmp;
	//		}
	//	}
	//}
	////插入
	//for (int i = 0; i < len; i++){
	//	for (int j = i+1; j < len; j++){
	//		if (array[j] < array[i]){
	//			char tmp = array[i];
	//			array[i] = array[j];
	//			array[j] = tmp;
	//		}
	//	}
	//}

	//冒泡
	for (int i = 0; i < len; i++){
		for (int j = len - 1; j > i; j--){
			if (array[j] < array[j-1]){
				char tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}

	for (int i = 0; i < len; i++){
		printf("%d\t", array[i]);
	}
	printf("\n");

	for (int i = 0; i < len; i++){
		if (array[i] < array[i + 1]){
			m--;
		}
		if (m == 0){
			return array[i];
		}
	}
	return -1;
}




int main(int argc, char *argv[])
{
	int array[] = { 5, 4, 3, 2, 1, 3, 4, 9, 8, 7, 6, 5 };
	int len = sizeof(array) / sizeof(*array);

	printf("第m大的数为：%d\n", find_m_max(array, len, 5));

	system("pause");
	return 0;
}
