
#include <iostream>
#include <random>
#include <vector>
#include<cmath>
void selection(int array[], int n, int num)
{
	int max = array[num];
	int maxi = num;
	for (int i = num; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			maxi = i;
		}
	}
	array[maxi] = array[num];
	array[num] = max;
	if (n > num)
	{
		selection(array, n, num + 1);
	}
}
                           
void move(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int qpart(int array[], int n, int r)
{
	int t = n;
	for (int i = r; i < t; i++)
	{
		
		if (array[i] > array[t])
		{
			move(array[i], array[t - 1]);
			move(array[t - 1], array[t]);
			t = t - 1;
			i = i - 1;
		}
	}
	
	
	for (int j = r; j <= n; j++)
	{
		std::cout << array[j] << " ";
	}
	std::cout << std::endl;
	return(t);
}

void qsort(int array[], int n, int r)
{
	
	int t = n;
	t = qpart(array, n, r);
	
	if (t - r + 1 > 1)
	{
		qsort(array, t - 1, r);
	}
	if (n - t)
	{
		qsort(array, n, t + 1);
	}
}

void treesort(int array[], int n)
{
	if (n > 2)
	{
		for (int i = n / 2; i >= 0; i--)
		{
			if (array[i] > array[2*i] && 2 * i < n)
			{
				move(array[i], array[2 * i]);
			}
			if (array[i] > array[2 * i + 1] && 2 * i + 1 < n)
			{
				move(array[i], array[2 * i + 1]);
			}
		}
		for (int i = 0; i < 5; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << std::endl;
		move(array[0], array[n - 1]);
		treesort(array, n - 1);
	}
}
int main()
{
	int a[5] = { 15,34, 10, 33, 12 };
	treesort(a, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << a[i] << std::endl;
	}
}

