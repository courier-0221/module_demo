# Fiber

使用linux下ucontext_t来实现。

## 实现思路

一个进程中又一个主线程，同样一个线程中也又一个主协程，采用的模型为主协程中可以创建子协程，协程执行完毕后可以调度回主协程，不能在子协程中再创建子协程，这样不可控。

每个协程对应一个fiber对象，如果一个线程中有一个子协程和主协程做切换，那就有两个fiber对象存在

每个线程中维护两个线程本地变量（管理主协程和子协程的指针）

​	a.记录当前线程正在执行的协程(t_fiber指针)（它可以调整，有可能因为调度指向主协程也有可能因为调度指向子协程）

​	b.记录当前线程的主协程(t_master_fiber)）（它尽量不动，只记录主协程）



## 方法

### 普通方法



### static 方法

1.SetThis	（更新t_fiber）

​	给当前线程正在执行的协程指针赋值，t_fiber

2.GetThis	（更新t_master_fiber）

​	首先判断当前线程中有没有正在处理的协程，如果有则返回，如果没有说明线程中从来没有创建过协程需要调用无参构造函数来创建主协程(t_master_fiber初始化)



# Scheduler

## 功能

实现可以让协程在线程之间切换

scheduler   -->   thread   -->   fiber

​	              1:N					1:M

1个scheduler中可以有多个thread，1个thread中可以有多个fiber，最后的模型是N:M，(thread:N fiber:M)



## 调度器的基本构成

1.线程池，分配一组线程

2.协程调度器，将协程，指定到相应的线程上执行

细节：

​	线程池：

​	协程队列：一些需要执行的协程放进去，协程队列成员支持两种，一种是function，另外一种是fiber实例对		象，同时还需要一个线程id用来指定该协程是不是要在对应的线程里面执行

​		<function<void()>, fiber,threadid>

使用：

​	调用scheduler(cb/fiber)



调度器方法

1.有参构造函数

​	其中一个参数为*是否使用当前调用线程*，如果使用则创建一个协程并指定协程处理函数，如果不适用

2.开始start

​	创建线程池

3.停止stop

​        分为两种情况，是否用了use_caller

​		如果使用了需要在创建了schedule的线程去执行stop，没有使用可以在任意线程执行stop

4.协程处理函数run

​	1).设置当前线程的scheduler

​	2).设置当前线程的run对应的fiber

​	3).协程调度循环while(true)

​		a.协程消息队列里面是否有任务

​		b.无任务执行，执行idle

