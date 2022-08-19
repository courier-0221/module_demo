#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <functional>
#include <iostream>

class Thread
{
public:
	typedef std::function<void (void)> func;
	Thread(func threadFunc);
	virtual ~Thread();

	void Start();
	void Join();

	void SetAutoDelete(bool autoDelete);

private:
	static void* ThreadRoutine(void* arg);
	void Run();
	pthread_t threadId_;
	bool autoDelete_;
	func thread_func_;
};

#endif // _THREAD_H_
