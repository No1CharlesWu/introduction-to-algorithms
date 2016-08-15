#include<stdlib.h>
#include<stdio.h>
/*
��������
���룺δ��������飬Ҫ��������Ԫ�ص���ʼ�±�ͽ����±�
������������е�����

�㷨���ɣ�
�ͺϲ�����Ƚ�����
1.�ֽ⣺������A[p..r]�ֳ�L[p..q-1] ��R[p+1..r] ���顣����L[]��С��A[q]��R[]������A[q]��
2.�����ͨ���ݹ���ÿ�������
3.�ϲ�������ϲ�����

Partition �ǿ�������ľ��裺
��A[r]Ϊ��Ԫ��������A[r]�ĺ�С��A[r]�ķָ

ʹ�÷�Χ��
��ͨ���׶���
��������ͨ����������������ʹ��ѡ����Ϊ��ƽ�������൱��
�����ܹ����о͵����������⻷����Ҳ�ܺܺõĹ���
*/

//������A[p..r]�ķָ�
int Partition(int A[],int p,int r)
{
	int x = A[r];
	int i = p-1;
	int j;
	for(j = p;j<=r-1;j++)
	{
		if(A[j]<x)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;
	
	return i+1;
}
//��������
void QuickSort(int A[],int p,int r)
{
	if(p<r)
	{
		int q = Partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
	}
}


int main()
{
	int arr[10] = {1,0,3,2,4,9,8,5,3,7};
	QuickSort(arr,0,9);

	for(int i = 0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
