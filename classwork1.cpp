#include <iostream>

int check(int num) {
    bool flag = false;
    for (int j = 2; j < num / 2 + 1; j++)
    {
        if (num % j == 0)
        {
            flag = true;
        }
    }
    if (flag)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
   
bool checkpol(int &num) {
    int old = num;
    int newnum = 0;
    int a = 10;
    while (old > 0)
    {
        newnum = newnum * 10;
        newnum += old % 10;
        old = old / 10;
    }
    num = newnum;
    return (newnum == num);
}

bool brackets(int num) {
    bool flag = true;
    char ch;
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        std::cin >> ch;
        if ((int)ch == 40) 
        {
            sum++;
        }
        if ((int)ch == 41)
        {
            sum--;
        }
        if (sum < 0)
        {
            flag = false;
            break;
        }
    }
    if (sum != 0) {
        flag = false;
    }
    return flag;
}
void triangle(int n)
{
    for (int j = 0; j < n+1; j++)
    {

        for (int i = 0; i < n + 1 - j; i++)
        {
            std::cout << char((int) 'A' + i);
        }
        if (j > 0) 
        {
            std::cout << ' ';
        }
        for (int b = 0; b < 2*std::max(j-1,0); b++)
        {
            std::cout << ' ';
        }
        for (int i = n - 1 - std::max((j-1), 0); i >=0 ; i--)
        {
            std::cout << char((int)'A' + i);
        }
        std::cout << '\n';
    }
}

int main()
{
    int n;
    std::cin >> n;
    checkpol(n);
    std::cout << "\n" << n;
}

