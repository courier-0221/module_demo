#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/* ����һ��ָ���������������ϵ���ָ�� */
/* ���Զ���ָ���������������ϵ���ָ�� */
int a = 10;
int b = 20;
int c = 30;
int *ptr1 = &a;
int *ptr3 = NULL;

void FirstLevelPointerTest1(int *p)
{
	p = &b;
}

void FirstLevelPointerTest2(int *p)
{
	p = &c;
}

void TwoLevelPointerTest1(int **p)
{
	*p = &b;
}

void TwoLevelPointerTest2(int **p)
{
	*p = &c;
}

int main03() {
	//int N, K, max, min;
	//scanf("%d %d", &N, &K);

	//int array[1024] = {0}, tmp;
	//for (int i = 0; i<N; i++){
	//	scanf("%d", &tmp);
	//	array[i] = tmp;
	//}

	//for (int i = 0; i<N; i++){
	//	if ((array[i] - array[i + 1])>K){
	//		array[i] -= K;
	//	}
	//	else{
	//		array[i] += K;
	//	}
	//}

	//max = array[0]; min = array[0];
	//for (int i = 0; i < N; i++){
	//	if (array[i] > max){
	//		max = array[i];
	//	}
	//	if (array[i] < min){
	//		min = array[i];
	//	}
	//}
	//for (int i = 0; i < N; i++){ printf("%d\t", array[i]); }
	//printf("%d\n", max - min);

	//int a[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	//printf("%d\n", *(&a[1][1]));
	//printf("%d\n", *(*(a + 1) + 1));
	//printf("%d\n", (*(a + 1))[1]);
	//printf("%d\n", *(a[1] + 1));


	//printf("%d\n", *(a + 1)[1]);
	//printf("%d\n", *(a + 5));	//�ȼ���	printf("%d\n", a[5]);


	//int(*p)[4] = a;
	//printf("%d\n", p[1][1]);
	//printf("%d\n", *(*(p + 1) + 1));
	//printf("%d\n", (*(p + 1))[1]);
	//printf("%d\n", *(p[1] + 1));

	//unsigned long long ret = 0;
	//ret = get_squr(1 << 20);
	//printf("%llx\n", ret);

	//int array[][4] = { 0, 0 };
	//printf("%d\n", sizeof(array) / sizeof(*array));

	//int int_1_ = 0;

	//float a = 9.7;
	//printf("%d\n", (int)a);

	//char buf[256] = {0};
	//sprintf(buf + sprintf(buf, "%s", "abc%d"), "%s", "efg%%d");
	////sprintf(buf, "%s", "abc%d");
	////printf("%s\n", buf);

	//printf(buf, 300);
	////printf("%s\n", buf);

	//char c = 'a';
	//if ('a' < c <= 'z')
	//	printf("Low");
	//else 
	//	printf("UP");

	//int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//if (find(array, 0, 10, 8) >= 0)
	//	printf("find\n");
	//else
	//	printf("no find \n");

	//int array[] = { 21, 25, 49, 25, 16, 8 };
	//int len = sizeof(array) / sizeof(*array);
	//sort(array, 0, len - 1);

	//for (int i = 0; i < len; i++){
	//	printf("%d\t", array[i]);
	//}



	//printf("%d\n", duiqi1(0));

	//char buf[] = "1234567";
	//printf("%s\n", reverse_str(buf));

	/*char line[128] = { 0 };
	scanf("%s", line);
	printf("%s\n", line);*/


	/* ����һ��ָ���������������ϵ���ָ�� */
	/* ���һ��ջ�ռ��ָ�� */
	int *ptr2 = &a;
	FirstLevelPointerTest1(ptr2);
	FirstLevelPointerTest2(ptr2);
	printf("ptr2: %d\n", *ptr2);
	//result ====> 10

	/* �������ȫ������ָ�� */
	FirstLevelPointerTest1(ptr1);
	FirstLevelPointerTest2(ptr1);
	printf("ptr1: %d\n", *ptr1);
	//result ====> 10

	/* ����: ָ������������ʵ���ϻ���ֵ���ݣ�����ָ����ȫ�ֵĻ���ջ�ռ���ڵģ�ͳͳֵ���ݡ� */
	/* ������Ҫ����һ��ָ������������������ͨ��ָ������޸ı�����ֵ�� */
	/* ��Щ����û�з�װͷ���ʹ�õ��Ƕ���ָ�����������������Ҫע������һ��ָ������������������ԭ��ʵ�֡� */


	/* ���Զ���ָ���������������ϵ���ָ�� */
	/* ���һ��ջ�ռ��ָ�� */
	int *ptr4 = NULL;
	TwoLevelPointerTest1(&ptr4);
	TwoLevelPointerTest2(&ptr4);
	printf("ptr4: %d\n", *ptr4);
	//result ====> 10

	/* �������ȫ������ָ�� */
	TwoLevelPointerTest1(&ptr3);
	TwoLevelPointerTest2(&ptr3);
	printf("ptr3: %d\n", *ptr3);
	//result ====> 10


	/* 
		���ۣ�
			������
				int a = 10;
				int *ptr = &a;
			�����ýӿڣ�
				void test1(int z)
				void test2(int *ptr)
				void test3(int **ptr)
			�������
				������һ��ʵ�������洢�ռ�ı�����ͨ�����������ֿ���ʹ�ô洢�ռ䡣
				��������ʵ������ֵ���ݣ������������ַ���ݡ�ֵ�����и������ơ�
			�⣺
				�裺 a �ĵ�ַΪ0x1000��ptr�ĵ�ַΪ0x1002��
				����֪�� ����a ��Ӧ��ַ�д洢������Ϊ10�� ����ptr ��Ӧ��ַ�д洢������Ϊ ����a �ĵ�ַ��
				���� test1(a)
					ʵ������ֵ���ݣ�������a��Ӧ��ַ�д洢��ֵ���     Ҳ���ǰ� 10 ���ֵ����һ����Ρ�
				���� test2(ptr)
					ʵ������ֵ���ݣ�������ptr��Ӧ��ַ�д洢��ֵ���   Ҳ���ǰ� a�ĵ�ַ ���ֵ����һ����Ρ�
				���� test2(&a)
					ʵ������ֵ���ݣ�������a�ĵ�ַ���			      Ҳ���ǰ� a�ĵ�ַ ���ֵ����һ����Ρ�
				���� test3(&ptr)
					ʵ������ֵ���ݣ�������ptr�ĵ�ַ���				  Ҳ���ǰ� ptr�ĵ�ַ ���ֵ����һ�����
			
	*/

	/* ͨ��ָ���޸ı�����ֵ���ԡ� */
	/*int aaa = 1;
	int *ptrrr = &aaa;
	test(&aaa);
	printf("%d\n", *ptrrr);*/

	system("pause");
	return 0;
}


#define STRUCT(type) typedef struct _tar_##type type;\
struct _tar_##type

STRUCT(linklistnode)	//������	�����ܰ�������ȫ����
{
	int data;
	linklistnode *next;
};

STRUCT(student)	//ҵ����		
{
	linklistnode header;	//��ȫ������������
	int age;
	char name[10];
	int sex;
};

STRUCT(linklist)	//ͷ���
{
	linklistnode *head;
	int length;
};

void insert(linklist *ll, int data)
{
	linklistnode node;
	node.data = data;
	node.next = ll->head;

	ll->head = &node;
}

void display(linklist *ll)
{
	linklistnode *tmp = NULL;
	for (tmp = ll->head; tmp != NULL; tmp = tmp->next)
	{
		printf("%d\t", tmp->data);
	}
	printf("\n");
}

int main()
{
	linklist ll = { NULL, 0 };

	insert(&ll, 11);
	insert(&ll, 22);
	insert(&ll, 33);

	display(&ll);

	system("pause");
	return 0;
}