#include<stdio.h>
#include"aaa.h"
void print1(int a[])
{
	for (int i = 0; i < MAX+1; i++)
		printf("%d  ", a[i]);
	printf("\n");
}
void swap1(int& a, int& b)
{
	int temp = a; a = b; b = temp;
}

bool maopao(int a[])
{
	int temp = 0;
	if (a == NULL)
		return false;
	for(int i=0;i<MAX;i++)
		for (int j = i+1; j < MAX; j++)
		{
			if (a[j] < a[i])
				swap1(a[j], a[i]);

		}
	return true;
}

bool charu(int a[])
{
	int t = 1;
	if (a == NULL)
		return false;
	for(int i=1;i<MAX;i++)
		for (int j =0; j <i; j++)
		{
			if (a[i] < a[j])
			{
				swap1(a[i], a[j]);
				t++;
			}
			printf("NO%d: ", t);
			print1(a);
		}
	return 0;
}

bool shell(int a[])
{
	if (a == nullptr)
		return 0;
	int t = MAX / 2;
	int j,k = 0;
	for(;t>=1;t=t/2)
		for (int i = t; i < MAX; i++)
		{
			if (a[i] < a[i - t])
			{
				int temp = a[i];
				for (j = i - t; j >= 0 && temp < a[j]; j -= t)
				{
					a[j + t] = a[j];
				}
				a[j + t] = temp;
			}
			print1(a);
		}
	return 1;
}

void kuaisu(int a[])
{
	int low = 0, high = MAX - 1;
	QuickSort(a, low, high);

}
void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int t = Partition(a, low, high);
		QuickSort(a, low, t - 1);
		QuickSort(a, t + 1, high);
	}
}
int Partition(int a[], int low, int high)
{
	int pivot = a[low];
	while (low < high)
	{
		while (low<high && a[high]>pivot)high--;
		a[low] = a[high];
		while (low < high && a[low] <= pivot)low++;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}

void xuanze(int a[])
{
	for (int i = 0; i < MAX-1; i++)
	{
		int t = i;
		for (int j = i + 1; j < MAX; j++)
		{
			if (a[j] < a[t])
				t = j;
		}
		if (t != 0)swap1(a[i], a[t]);
	}

}

void dui(int a[])
{
	int b[MAX + 1] = { 0 };
	for (int i = 0; i < MAX; i++)
	{
		b[i + 1] = a[i];
	}
	Bigroot(b, MAX); 
	for (int i = MAX; i >1; i--)
	{
		swap1(b[i], b[1]);
		HeadAdjust(b, 1, i-1);
		print1(b);
	}

	for (int i = 0; i < MAX; i++)
	{
		a[i]=b[i + 1];
	}

}
void Bigroot(int a[],int nums)
{
	for (int i = nums / 2; i > 0; i--)
		HeadAdjust(a, i, nums);

}
void HeadAdjust(int a[], int k, int nums)
{
	a[0] = a[k];
	for (int i = 2 * k; i <= nums; i *= 2)
	{
		if (i < nums && a[i] < a[i + 1])i++;
		if (a[0] >= a[i]) break;
		else { a[k] = a[i]; k = i; }
	}
	a[k] = a[0];
}


void guibing(int a[])
{
	int* p = (int*)malloc(sizeof(int) * MAX);
	Mergsort(a, 0, MAX, p);
}
void Mergsort(int a[], int low, int high,int*p)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		Mergsort(a, low, mid,p);
		Mergsort(a, mid + 1, high,p);
		Merge(a, low, mid, high, p);
	}
}
void Merge(int a[], int low, int mid, int high, int* p)
{
	int i, j, k;
	for (i = low; i <= high; i++)
		p[i] = a[i];
	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
	{
		if (p[i] <= p[j])
			a[k] = p[i++];
		else
			a[k] = p[j++];

	}
	while (i <= mid)a[k++] = p[i++];
	while (j <= high)a[k++] = p[j++];
	
}


