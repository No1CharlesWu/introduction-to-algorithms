#include<stdio.h>
#include<stdlib.h> 
#include<limits.h>

/*
堆排序算法：
输入：未排序的数组，数组元素的个数
输出：生序排列的数组

注意:数组排列是从下标为1的元素开始！！！

算法技巧：
1.建立堆，将杂乱无序的数组按最大堆的方式建立。
2.保持堆的性质：在建立堆的时候，要使得父结点PARENT（i）的关键字大于左右儿子LEFT（i）和RIGHT（i）的关键字
3.堆排序：从堆中去掉结点并重新建立堆的迭代法排序。

关键词：
HeapSize：实际在堆中的元素个数
length	：整个数组的元素个数
关系：HeapSize <= length 

实际使用：
优先级队列（后4个函数）：
可以通过这4个函数，实现对队列的优先级的操作。
例如：获得最大值。
	  插入元素。
	  获得最大值并删除此元素再堆排序
*/
#define max 6000
int HeapSize;
int A[max];
//保持堆最大性质
void MaxHeapify(int A[],int i)
{
	int largest;
	int l = 2*i;
	int r = 2*i+1;
	if(l<=HeapSize&&A[l]>A[i])
		largest = l;
	else
		largest = i;

	if(r<=HeapSize&&A[r]>A[largest])
		largest = r;

	if(largest != i)
	{
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;

		MaxHeapify(A,largest);
	}
}
//建立堆
void BuildMaxHeap(int A[],int length)
{
	HeapSize = length;
	for(int i = length/2;i>=1;i--)
		MaxHeapify(A,i);
}
//堆排序算法
void HeapSort(int A[],int length)
{
	BuildMaxHeap(A,length);

	for(int i = length;i>=2;i--)
	{
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;

		HeapSize--;

		MaxHeapify(A,1);
	}
}


//把元素key的值增加到A[i]中，key不能小于A[i]的原始的值
void HeapIncreaseKey(int A[],int i,int key)
{
	if(key<A[i])
		puts("error:new key is smaller than current key\n");
	A[i] = key;
	while(i>1&&A[i/2]<A[i])
	{
		int temp = A[i];
		A[i] = A[i/2];
		A[i/2] = temp;
		i = i/2;
	}
}
//把元素key插入到数组A[]中，并保持堆最大的性质
void MaxHeapInsert(int A[],int key)
{
	HeapSize++;
	A[HeapSize] = INT_MIN;
	HeapIncreaseKey(A,HeapSize,key);
}
//返回数组A[]中最大关键字的元素
int HeapMaximum(int A[])
{
	return A[1];
}
//去掉并返回数组A[]中最大关键字的元素
int HeapExtractMax(int A[])
{
	if(HeapSize < 1)
		puts("error:heap underflow\n");

	int maxcount = A[1];
	A[1] = A[HeapSize];
	HeapSize--;
	MaxHeapify(A,1);
	return maxcount; 
}
int main()
{
	int arr[10] = {10,0,3,2,4,9,8,5,3,7};
	HeapSort(arr,9);

	for(int i = 1;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
