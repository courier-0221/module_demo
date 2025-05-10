# https://www.runoob.com/python3/python3-iterator-generator.html

"""
迭代器有两个基本的方法:iter() 和 next()。
字符串，列表或元组对象都可用于创建迭代器：
"""

# 使用迭代器

my_list = [1, 2, 3, 4, 5]
# Create an iterator object
my_iterator = iter(my_list)
# Iterate over the elements in the iterator
while True:
    try:    
        element = next(my_iterator)
        print(element)
    except StopIteration:
        break


# 创建一个迭代器

print("-"*60)

class MyNumbers:
  def __iter__(self):
    self.a = 1
    return self
 
  def __next__(self):
    x = self.a
    self.a += 1
    return x
 
myclass = MyNumbers()
myiter = iter(myclass)
 
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))