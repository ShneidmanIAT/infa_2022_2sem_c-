// zachet.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void find_peaks(int* nums, int n)
{
    int* poshills = new int[n];
    int* hills = new int[n];
    int numhills = 0;
    int j = 0;
    bool flag = false;
    for (int i = 1; i < n - 1; i++)
    {
        if ((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
        {
            hills[numhills] = nums[i];
            poshills[numhills] = i;
            numhills++;
        }
        if ((nums[i] > nums[i - 1]) && (nums[i] == nums[i + 1]))
        {
            j = i;
            while (nums[j] == nums[j + 1])
            {
                if (j + 1 == n)
                {
                    break;
                }
                j++;
                if (nums[j] > nums[j + 1])
                {
                    flag = true;
                }
            }
            if (flag)
            {
                hills[numhills] = nums[i];
                poshills[numhills] = i;
                numhills++;
            }
            flag = false;
        }
    }
    for (int i = 0; i < numhills; i++)
    {
        std::cout << poshills[i];
    }
    std::cout << std::endl;
    for (int i = 0; i < numhills; i++)
    {
        std::cout << hills[i];
    }
    delete[] hills;
    delete[] poshills;
}
int main()
{
    int n;
    std::cin >> n;
    int* nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }
    find_peaks(nums, n);
    delete[] nums;
}

