import multiprocessing

# imap_unordered(func, iterable, chunksize=None)
# 同步执行函数 `func`，并返回一个迭代器。`iterable` 和 `chunksize` 参数的含义与 `map` 方法相同。这个方法会立即返回一个迭代器对象，函数执行的结果会在迭代器被遍历时逐个返回。
# 不保证返回结果的顺序与输入的顺序一致。


# 传递单个参数
def fn(a):
    # Some unrelated code 
    return a

def test1():
    data = [1,2,3,4,5,6,7,8,9]
    result = []
    with multiprocessing.Pool(processes=4) as pool:
        for res in pool.imap_unordered(fn, data):
            result.append(res)
            print(res)
        print(result)
        
        # 这样写不能执行，需要使用for来驱动
        # res = pool.imap_unordered(fn, data)
        # print(res)


# 传递多个参数
def add(param):
    return param[0] + param[1]

def test2():
    data_list1 = [1,3,5,7,9]
    data_list2 = [2,4,6,8,10]
    # iter_data = [(x,y) for x,y in zip(data_list1, data_list2)]
    # print(iter_data)
    data = list(zip(data_list1, data_list2))
    print(data)

    result = []

    with multiprocessing.Pool(processes=4) as pool:
        for res in pool.imap_unordered(add, data):
            result.append(res)
        print(result)  # 输出 [3, 7, 11]


if "__main__" == __name__:
    # test1()
    test2()
