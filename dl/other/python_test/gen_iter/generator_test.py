# https://www.runoob.com/python3/python3-iterator-generator.html
# 在 Python 中，使用了 yield 的函数被称为生成器（generator）。

def countdown(n):
    while n > 0:
        yield n
        n -= 1
 
# 创建生成器对象
generator = countdown(5)
 
# 访问方式1：通过迭代生成器获取值
print(next(generator))  # 输出: 5
print(next(generator))  # 输出: 4
print(next(generator))  # 输出: 3
 
# 访问方式2：使用 for 循环迭代生成器
for value in generator:
    print(value)  # 输出: 2 1