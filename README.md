# DS_sort
2021-2022春-数据结构（2）小组实验（四）

## 请用CMakeList提供的两个对应的配置文件运行项目！！！
（通过右上角进行选择）

## —、目的和要求

1. 掌握各种排序算法思想和实现。

2. 分析各种排序算法性能，讨论它们的适用情况。
3. 根据实际问题的需要，选择相应的排序算法解决实际问题。



## 二、实验内容

### 快速排序算法的改进

对快速排序算法而言，若能合理地选择基准数据元素，使得每次划分后的两个子表中的元素个数尽可能接近，则可以加速排序速度。请设计1-2种基准数据元素选择策略，从而改进教材中实现的快速排序算法，并利用实验结果进行性能比较。

### DNA排序

字符串的逆序数是指字符串中逆序字符对的数目。例如：字符串“ DAABEC”的逆序数为5，因为D 大于右边4个字符，E大于字符C；又如：字符串“AACEDGG” 的逆序数为1 (只有E与D逆序），它近似已排好序；而字符串“ZWQM”的逆序数为6，它完全逆序。

现要求对DNA字符串（只由A、C、G、T四个字符组成，长度为m）进行分类。分类方法是根据DNA字符串的逆序数从小到大进行排序（自己实现排序算法），逆序数相等的DNA串再按照字符串的字典序从大到小排列。



【输入数据】

第一行包含两个正整数n和m，其中n（0<n<=100）表示DNA字符串的数目，m（0<m<=50）表示DNA字符串的长度。接下来n行每行为一个长度为m的DNA字符串。

【输出数据】

输出分类好的DNA字符串，每行一个DNA字符串，一共n行。

【输入样例】

6    10
AACATTAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

【输出样例】

CCCGGGGGGA
GATCAGATTT
AACATTAAGG
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA

