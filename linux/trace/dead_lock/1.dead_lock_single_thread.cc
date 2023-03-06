#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>

//单线程内对互斥锁嵌套加锁

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static int counter = 0;

void func2(void);

void func1(void)
{ 
	pthread_mutex_lock(&mutex);
	++counter;
    printf("func1 counter.%d\n", counter);
	sleep(1);
    // 其他函数中同样加锁，导致死锁
    if (5 == counter)
    {
        func2();
    }
	pthread_mutex_unlock(&mutex);
}

void func2(void)
{
	pthread_mutex_lock(&mutex);
	--counter;
    printf("func2 counter.%d\n", counter);
	sleep(1);
	pthread_mutex_unlock(&mutex);
}

void* start_routine(void* arg)
{
	while (1)
	{
        func1();
	}
}

int main()
{
	pthread_t tid;
	if (pthread_create(&tid, NULL, &start_routine, NULL) != 0)
	{
		_exit(1);
	}
	
    //sleep(5); 
	pthread_join(tid, NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}