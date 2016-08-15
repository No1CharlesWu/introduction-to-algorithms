#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
using namespace std;

void Merge(int arr[],int p,int q,int r);//�ϲ��㷨
void MergeSort(int arr[],int p,int r);//�ϲ�����

int main()
{
	int arr[10] = {3,1,5,7,8,2,4,0,9,6};
	int arr2[11] = {1,3,5,7,8,2,4,0,10,9,6};

	MergeSort(arr,1,10);
	MergeSort(arr2,1,11);

	for(int i = 0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	for(int i = 0;i<11;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\n");

	return 0;
}

/*
���������㷨��
���룺δ��������飬����Ԫ�صĸ���
������������������

�㷨���ɣ�
���������Ϊ�����֣�
1.�ֽ⣺��ԭ����ֽ��һϵ�������⡣
2.������õݹ�ķ�������������⡣
3.�ϲ�����������Ľ���ϲ���ԭ����Ľ⡣

�ϲ�����Ĺؼ��ǣ�
���������������������кϲ�����һ��A[p..q]��A[p+1..r]�����������ֽ⡣
							  �ֽ���������顣ʹ�ñȽ�����ķ����ϲ���

ʹ�õݹ�ķ�����

ʹ�÷�Χ�����д������顣
*/
void Merge(int arr[],int p,int q,int r)//�ϲ��㷨
{
	int i,j,k;
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = new int[n1+1];		//����������������
	int *R = new int[n2+1];

	for(i = 0;i<n1;i++) 	L[i] = arr[p+i-1];//��arr[p..r] ��ֵ����������L��R
	for(j = 0;j<n2;j++)     R[j] = arr[q+j];
	L[n1] = INT_MAX;			//���������һλ���������棬�򻯴���
	R[n2] = INT_MAX;

	for(i = j = 0,k = p-1;k<r;k++)
	{
		if(L[i] <= R[j])		//�Ƚ�����			
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	delete []L;					//ɾ�������ͷ��ڴ�
	delete []R;
}
void MergeSort(int arr[],int p,int r)//�ϲ�����
{
	int q;
	if(p<r)
	{
		q = (p+r)/2;
		MergeSort(arr,p,q);
		MergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
}

