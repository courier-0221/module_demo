#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	������������x,y,z���������������С�������
˼·��
	������취����С�����ŵ�x�ϣ��Ƚ�x��y���бȽϣ����x>y��x��y��ֵ���н�����
	Ȼ������x��z���бȽϣ����x>z��x��z��ֵ���н�����������ʹx��С��

*/

void main(void)
{
	int x, y, z,tmp;
	scanf("%d\t%d\t%d", &x, &y, &z);

	if (x>y)
	{
		tmp = x; x = y; y = tmp;
	} /*����x,y��ֵ*/
	if (x>z)
	{
		tmp = z; z = x; x = tmp;
	}/*����x,z��ֵ*/
	if (y>z)
	{
		tmp = y; y = z; z = tmp;
	}/*����z,y��ֵ*/
	printf("small to big : %d\t%d\t%d\n", x, y, z);



	system("pause");
}