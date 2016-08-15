#include<stdio.h>
#include<stdlib.h> 
#include<limits.h>

/*
�������㷨��
���룺δ��������飬����Ԫ�صĸ���
������������е�����

ע��:���������Ǵ��±�Ϊ1��Ԫ�ؿ�ʼ������

�㷨���ɣ�
1.�����ѣ���������������鰴���ѵķ�ʽ������
2.���ֶѵ����ʣ��ڽ����ѵ�ʱ��Ҫʹ�ø����PARENT��i���Ĺؼ��ִ������Ҷ���LEFT��i����RIGHT��i���Ĺؼ���
3.�����򣺴Ӷ���ȥ����㲢���½����ѵĵ���������

�ؼ��ʣ�
HeapSize��ʵ���ڶ��е�Ԫ�ظ���
length	�����������Ԫ�ظ���
��ϵ��HeapSize <= length 

ʵ��ʹ�ã�
���ȼ����У���4����������
����ͨ����4��������ʵ�ֶԶ��е����ȼ��Ĳ�����
���磺������ֵ��
	  ����Ԫ�ء�
	  ������ֵ��ɾ����Ԫ���ٶ�����
*/
#define max 6000
int HeapSize;
int A[max];
//���ֶ��������
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
//������
void BuildMaxHeap(int A[],int length)
{
	HeapSize = length;
	for(int i = length/2;i>=1;i--)
		MaxHeapify(A,i);
}
//�������㷨
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


//��Ԫ��key��ֵ���ӵ�A[i]�У�key����С��A[i]��ԭʼ��ֵ
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
//��Ԫ��key���뵽����A[]�У������ֶ���������
void MaxHeapInsert(int A[],int key)
{
	HeapSize++;
	A[HeapSize] = INT_MIN;
	HeapIncreaseKey(A,HeapSize,key);
}
//��������A[]�����ؼ��ֵ�Ԫ��
int HeapMaximum(int A[])
{
	return A[1];
}
//ȥ������������A[]�����ؼ��ֵ�Ԫ��
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
