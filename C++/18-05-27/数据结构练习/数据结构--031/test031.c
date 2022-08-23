#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	时钟的时分秒针每天重叠几次？时分每天相遇几次？分秒每小时遇到几次？
需要知道的是
	时分每小时相遇一次(1小时==60分)，一天相遇24次
	分秒每分钟相遇一次(1分钟==60秒)，一小时相遇60次
	时分秒要看时分每天相遇几次
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