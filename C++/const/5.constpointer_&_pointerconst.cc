#include <iostream>

// 参考博客：https://blog.csdn.net/jackystudio/article/details/11519817

int main(void)
{
	//定义变量
	int a=1;
 
	//定义常量
	const int b=2;
 
	//定义常量指针
	const int *ptr1=&a;
 
	//定义指针常量，必须赋值
	int* const ptr2=&a;
 
	//错误，不能把常量的地址赋给指针变量
	int *ptr3=&b;
 
	//正确，可以把常量的地址赋给常量指针
	const int* ptr4=&b;
 
	//错误，间接引用常量指针不可以修改内存中的数据
	*ptr1=3;
 
	//正确，间接引用指针常量可以修改内存中的数据
    *ptr2=4;
 
	//正确，常量指针可以指向其他变量
	ptr1=&b;
 
	//错误，指针常量不可以指向其他变量
	ptr2=&b;
 
	//常量指针常量，即不可以间接引用修改内存数据，也不可以指向别的变量
	const int * const ptr5=&a;
 
	//错误，不可以间接引用修改内存数据
	*ptr5=5;
 
	//错误，不可以修改指向的对象
	ptr5=&b;
 
	return 0;
}