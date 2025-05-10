import multiprocessing
from multiprocessing import Pool
'''
def add(x, y, result_queue):
    result_queue.put(x + y)

# 创建一个队列，用于存储每个任务的返回值
result_queue = multiprocessing.Queue()

# 创建两个进程
process1 = multiprocessing.Process(target=add, args=(1, 2, result_queue))
process2 = multiprocessing.Process(target=add, args=(3, 4, result_queue))

# 启动进程
process1.start()
process2.start()

# 等待所有进程完成
process1.join()
process2.join()

# 获取每个任务的返回值并打印
while not result_queue.empty():
    result = result_queue.get()
    print(result)
'''

def add(x, y):
    return x + y

# 创建一个进程池，其中包含 4 个进程
with Pool(4) as p:
    # 将两个参数列表捆绑在一起
    args = list(zip([1, 2, 3, 4], [10, 20, 30, 40]))
    print(args)
    result = p.starmap(add, args)

print(result)  # 输出 [11, 22, 33, 44]
