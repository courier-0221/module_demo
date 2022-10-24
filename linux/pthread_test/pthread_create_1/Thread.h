#ifndef _THREAD_H_
#define _THREAD_H_

#include <pthread.h>
#include <functional>
#include <iostream>
#include "Mutex.h"
#include "Condition.h"

class Thread
{
public:
	typedef std::function<void (void)> func;
	explicit Thread(func threadFunc);
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
    MutexLock _mutex;
    Condition _condition;
};

#endif // _THREAD_H_
