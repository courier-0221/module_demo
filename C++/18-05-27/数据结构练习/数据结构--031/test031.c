#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
��Ŀ��
	ʱ�ӵ�ʱ������ÿ���ص����Σ�ʱ��ÿ���������Σ�����ÿСʱ�������Σ�
��Ҫ֪������
	ʱ��ÿСʱ����һ��(1Сʱ==60��)��һ������24��
	����ÿ��������һ��(1����==60��)��һСʱ����60��
	ʱ����Ҫ��ʱ��ÿ����������
*/


void get_clock_meet_times(void)
{
	int hour = 24;
	int minute = 60;
	int second = 60;

	int h_m_s_meet = 0;
	int h_m_meet = 0;
	int m_s_one_hour_meet = 0;

	int h, m, s;

	for (h = 0; h < hour; h++){
		for (m = 0; m < minute; m++){
			if (h == m){
				h_m_meet++;
			}
			for (s = 0; s < second; s++){
				if (s == m && h == 0){
					m_s_one_hour_meet++;
				}
				//if (h == m == s){
				if (h == m && h == s && m == s){
					h_m_s_meet++;
				}
			}
		}
	}
	printf("h_m_s_meet--->%d\n", h_m_s_meet);
	printf("h_m_meet--->%d\n", h_m_meet);
	printf("m_s_one_hour_meet--->%d\n", m_s_one_hour_meet);

}

int main(void)
{
	get_clock_meet_times();

	system("pause");
	return 0;
}