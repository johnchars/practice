## Ubuntu OS

### 1. Grep 

在指定路径下搜索内容，去除二进制文件，打印行号和当前内容前3行，适合找崩溃问题

```shell
# grep --context|before-context|after-context=3
grep --before-context=3 --binary-files=without-match --recursive --line-number "search content" .
```



# C++

### 1. 智能指针

#### 1.1 shared_ptr

shared_ptr\<T\>（其中 T 表示指针指向的具体数据类型）的定义位于\<memory\>头文件，并位于 std 命名空间中。智能指针向堆内存申请空间时，会配备一个计数值(int型)。

*构造shared_ptr*

```c++
#include <memory>
std::shared_ptr<int> p1;             //不传入任何实参
std::shared_ptr<int> p2(nullptr);    //传入空指针 nullptr, 初始计数为0
std::shared_ptr<int> p3(new int(10));
std::shared_ptr<int> p3 = std::make_shared<int>(10);

// 拷贝构造函数，移动构造函数
std::shared_ptr<int> p4(p3);
//或者 std::shared_ptr<int> p4 = p3;

std::shared_ptr<int> p5(std::move(p4)); 
//或者 std::shared_ptr<int> p5 = std::move(p4);
```

成员函数

get() 返回一个shared_ptr内部的普通指针

多个 shared_ptr 智能指针可以共同使用同一块堆内存



1.2 unique_ptr

每个 unique_ptr 指针都独自拥有对其所指堆内存空间的所有权。

构建方法

```c++
std::unique_ptr<int> p1();
std::unique_ptr<int> p2(nullptr);
std::unique_ptr<int> p3(new int);
std::unique_ptr<int> p4(new int);
std::unique_ptr<int> p5(std::move(p4));//正确，调用移动构造函数
```

需要注意的是，unique_ptr没有拷贝构造函数，没有类似于make_shared\<T\>() 模板函数的方法



1.3 weak_ptr

该类型指针通常不单独使用（没有实际用处），只能和 shared_ptr 类型指针搭配使用。

借助 weak_ptr 类型指针， 我们可以获取 shared_ptr 指针的一些状态信息。

*需要注意的是*

当 weak_ptr 类型指针的指向和某一 shared_ptr 指针相同时，weak_ptr 指针并不会使所指堆内存的引用计数加 1；同样，当 weak_ptr 指针被释放时，之前所指堆内存的引用计数也不会因此而减 1。也就是说，weak_ptr 类型指针并不会影响所指堆内存空间的引用计数。



## Container

### vector



### map



### set



### std::sort

- reference https://yt.droid.ac.cn/dili/ros_release.git

- 原型

```c++
// 直接使用<进行比较
template <class RandomAccessIterator>
  void sort (RandomAccessIterator first, RandomAccessIterator last);
// 使用自定义的comp函数比较两者关系
template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

- example

```c++
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```



# Glog

写入指定的文件

FLAGS_log_dir设置想要写入的目录

CHECK()函数的自定义
```c++
// glog/src/logging.cc
void InstallFailureFunction(void (*fail_func)()) {
  g_logging_fail_func = (logging_fail_func_t)fail_func;
}

// glog/src/utilities.cc
InstallFailureFunction(&DumpStackTraceAndExit);
```
当前的glog版本
```shell
libgoogle-glog-dev/bionic,now 0.3.5-1 arm64 [installed]
  library that implements application-level logging.
```