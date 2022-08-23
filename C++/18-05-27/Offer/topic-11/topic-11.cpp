#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
* 1.ȫ�濼��ָ���������������Ƿ�Ϊ��������
* 2.д��ָ���Ķ����Ʊ�����13���Ϊ������1101��
* 3.����:10^1101 = 10^0001*10^0100*10^1000��
* 4.ͨ��&1��>>1����λ��ȡ1101��Ϊ1ʱ����λ����ĳ����۳˵����ս����
*/
class Solution 
{
public:
	double Power(double base, int exponent) 
	{
		double ret = 1.0;
		int exponentTmp = exponent;
		if (exponentTmp < 0)
		{
			exponentTmp = -exponentTmp;
		}

		while (exponentTmp != 0)
		{
			if (exponentTmp & 1)
			{
				ret *= base;
			}
			base *= base;
			exponentTmp = exponentTmp >> 1;
		}
		return (exponent > 0) ? ret : 1 / ret;
	}
};

int main(void)
{
	Solution s;
	cout << s.Power(2, 3) << endl;


	system("pause");
	return 0;
}