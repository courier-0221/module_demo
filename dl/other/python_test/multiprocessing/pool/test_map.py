import multiprocessing

# map(func, iterable, chunksize=None): 
# 同步执行函数 func，并返回一个结果列表。
# iterable 是一个可迭代对象，包含传递给函数的参数。
# chunksize 是一个可选的参数，用于指定每个进程一次处理的数据块大小。这个方法会阻塞直到所有函数执行完成并返回结果。


# 传递单个参数
def square(x):
    return x ** 2

def test1():
    data_list = [1, 2, 3, 4, 5]
    with multiprocessing.Pool(processes=4) as pool:
        result = pool.map(square, data_list)
        print(result)


# 传递多个参数 方式1
def add(x, y):
    return x + y

def test2():
    data_list1 = [1,3,5,7,9]
    data_list2 = [2,4,6,8,10]
    # iter_data = [(x,y) for x,y in zip(data_list1, data_list2)]
    # print(iter_data)
    data = list(zip(data_list1, data_list2))
    print(data)

    with multiprocessing.Pool(processes=4) as pool:
        results = pool.starmap(add, data)
        print(results)  # 输出 [3, 7, 11]


# 传递多个参数 方式2
def add(param):
    return param[0] + param[1]

def test3():
    data_list1 = [1,3,5,7,9]
    data_list2 = [2,4,6,8,10]
    # iter_data = [(x,y) for x,y in zip(data_list1, data_list2)]
    # print(iter_data)
    data = list(zip(data_list1, data_list2))
    print(data)

    with multiprocessing.Pool(processes=4) as pool:
        results = pool.map(add, data)
        print(results)  # 输出 [3, 7, 11]

if __name__ == '__main__':
    # test1()
    # test2()
    test3()