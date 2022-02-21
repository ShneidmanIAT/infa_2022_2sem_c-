#include <iostream>
#include <random>
#include <ctime> 
int randm(int a, int b)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist(a, b);
	return dist(rng);
}
void random_move(int array[], unsigned int k, int m, int n)
{
	int r = 0;
	for (int i = 0; i < k; i++)
	{
		if (array[i * 3 + 1] != 0)
		{ 
			r = randm(1, 4);
			if (r == 1)
			{
				array[i * 3 + 2] = -n;
			}
			if (r == 2)
			{
				array[i * 3 + 2] = -1;
			}
			if (r == 3)
			{
				array[i * 3 + 2] = 1;
			}
			if (r == 4)
			{
				array[i * 3 + 2] = n;
			}
		}
	}
}
void linear_random_move(int array[], unsigned int k, int n)
{
	int r = 0;
	for (int i = 0; i < k; i++)
	{
		if (array[i * 3 + 1] != 0)
		{
			r = randm(1, 2);
			if (r == 1)
			{
				array[i * 3 + 2] = -1;
			}
			if (r == 2)
			{
				array[i * 3 + 2] = 1;
			}
		}
	}
}

void check_collision(int array[], unsigned int k, int m, int n)
{
	for (int i = 0; i < k; i++)
	{
		if ((array[i * 3 + 1] / n == 0) || (array[i * 3 + 1] / n == m - 1) || (array[i * 3 + 1] % n == n - 1) || (array[i * 3 + 1] % n == 0))
		{
			array[i * 3 + 2] = 0;
		}
		for (int j = 0; j < i; j++)
		{
			int a = array[i * 3 + 1] - array[j * 3 + 1];
			if ((a == 1) || (a == -n) || (a == -1) || (a == n))
			{
				array[i * 3 + 2] = 0;
				array[j * 3 + 2] = 0;
			}
			if (array[i * 3 + 1] + array[i * 3 + 2] == array[j * 3 + 1] + array[j * 3 + 2])
			{
				array[j * 3 + 2] = 0;
			}
		}
	}
}
void linear_check_collision(int array[], unsigned int k, int n)
{
	for (int i = 0; i < k; i++)
	{
		if ((array[i * 3 + 1] % n == n - 1) || (array[i * 3 + 1] % n == 0))
		{
			array[i * 3 + 2] = 0;
		}
		for (int j = 0; j < i; j++)
		{
			int a = array[i * 3 + 1] - array[j * 3 + 1];
			if ((a == 1) || (a == -1))
			{
				array[i * 3 + 2] = 0;
				array[j * 3 + 2] = 0;
			}
			if (array[i * 3 + 1] + array[i * 3 + 2] == array[j * 3 + 1] + array[j * 3 + 2])
			{
				array[j * 3 + 2] = 0;
			}
		}
	}
}

void move(int array[], unsigned int k, unsigned int m, unsigned int n)
{
	for (int i = 0; i < k; i++)
	{
		array[i * 3 + 1] = array[i * 3 + 1] + array[i*3 + 2];
	}
}
void process(int particles[], unsigned int k, int m, int n)
{
	int pos = 0;
	bool flag = true;
	for (int i = 0; i < k; i++)
	{
		while (flag)
		{
			flag = false;
			pos = randm(0, m - 1) * n + randm(0, n - 1);
			for (int j = 0; j < i; j++)
			{
				if (pos == particles[j * 3 + 1])
				{
					flag = true;
				}
			}
		}
		particles[i * 3] = i;
		particles[i * 3 + 1] = pos;
		particles[i * 3 + 2] = 12;
		flag = true;
	}
	flag = true;
	bool drawflag;
	while (flag)
	{
		flag = false;

		random_move(particles, k, m, n);
		check_collision(particles, k, m, n);
		move(particles, k, m, n);
		for (int i = 0; i < k; i++)
		{
			if (particles[i * 3 + 2] != 0)
			{
				flag = true;
			}
			//std::cout << particles[i * 3] << " " << particles[i * 3 + 1] << " " << particles[i * 3 + 2] << std::endl;
		}
		//std::cout << std::endl;

		/*for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				drawflag = false;
				for (int l = 0; l < k; l++)
				{
					if (particles[l * 3 + 1] == i * n + j)
					{
						drawflag = true;
					}
				}
				if (drawflag)
				{
					std::cout << 0;
				}
				else
				{
					std::cout << "+";
				}
			}
			std::cout << std::endl;
		}*/
	}
	//std::cout << "movement ended////////////////////////////////////";
 }
void linear_process(int particles[], unsigned int k, int n)
{
	int m = 1;
	int pos = 0;
	bool flag = true;
	for (int i = 0; i < k; i++)
	{
		while (flag)
		{
			flag = false;
			pos = randm(0, n - 1);
			for (int j = 0; j < i; j++)
			{
				if (pos == particles[j * 3 + 1])
				{
					flag = true;
				}
			}
		}
		particles[i * 3] = i;
		particles[i * 3 + 1] = pos;
		particles[i * 3 + 2] = 12;
		flag = true;
	}
	flag = true;
	bool drawflag;
	while (flag)
	{
		flag = false;

		linear_random_move(particles, k, n);
		linear_check_collision(particles, k, n);
		move(particles, k, m, n);
		for (int i = 0; i < k; i++)
		{
			if (particles[i * 3 + 2] != 0)
			{
				flag = true;
			}
			//std::cout << particles[i * 3] << " " << particles[i * 3 + 1] << " " << particles[i * 3 + 2] << std::endl;
		}
		//std::cout << std::endl;

		/*for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				drawflag = false;
				for (int l = 0; l < k; l++)
				{
					if (particles[l * 3 + 1] == i * n + j)
					{
						drawflag = true;
					}
				}
				if (drawflag)
				{
					std::cout << 0;
				}
				else
				{
					std::cout << "+";
				}
			}
			std::cout << std::endl;
		}*/
	}
	//std::cout << "movement ended////////////////////////////////////";
}

int main()
{
	int m = 50;//matrix[m*n]
	int n = 50;
	const int k = 2250;
	int a;
	int particles[k * 3];//[number, position, moving(-1, -7, 1, 7 or 0 if not moving)]
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		process(particles, k, m, n);
	}
	std::cout << "runtime = " << clock() / 1000.0 << std::endl; // время работы программы    
	std::cout << "n = " << n << std::endl;
	
	

}
