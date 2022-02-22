#include <iostream>
#include <random>
#include <ctime> 
//вероятность остаться на месте
//два типа частиц

	
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<int> dist(1, 10000);

void random_move(int array[], unsigned int k, int m, int n)
{
	int r = 0;
	for (int i = 0; i < k; i++)
	{
		if (array[i * 4 + 3] > 0)
		{ 
			r = dist(rng) % 5 + 1;
			if (r == 1)
			{
				array[i * 4 + 2] = -n;
			}
			if (r == 2)
			{
				array[i * 4 + 2] = -1;
			}
			if (r == 3)
			{
				array[i * 4 + 2] = 1;
			}
			if (r == 4)
			{
				array[i * 4 + 2] = n;
			}
			if (r == 5)
			{
				array[i * 4 + 2] = 0;
			}
		}
	}
}
void linear_random_move(int array[], unsigned int k, int n)
{
	int r = 0;
	for (int i = 0; i < k; i++)
	{
		if (array[i * 4 + 3] != 0)
		{
			r = dist(rng) % 2 + 1;
			if (r == 1)
			{
				array[i * 4 + 2] = -1;
			}
			if (r == 2)
			{
				array[i * 4 + 2] = 1;
			}
		}
	}
}

void check_collision(int array[], unsigned int k, int m, int n)
{
	for (int i = 0; i < k; i++)
	{
		if ((array[i * 4 + 1] / n == 0) || (array[i * 4 + 1] / n == m - 1) || (array[i * 4 + 1] % n == n - 1) || (array[i * 4 + 1] % n == 0))
		{
			array[i * 4 + 3] = - std::abs(array[i * 4 + 3]);
			array[i * 4 + 2] = 0;
		}
		for (int j = 0; j < i; j++)
		{
			int a = array[i * 4 + 1] - array[j * 4 + 1];
			if (((a == 1) || (a == -n) || (a == -1) || (a == n)) and (std::abs(array[i * 4 + 3]) == std::abs(array[j * 4 + 3])))
			{
				array[i * 4 + 3] = - std::abs(array[i * 4 + 3]);
				array[j * 4 + 3] = - std::abs(array[j * 4 + 3]);
				array[i * 4 + 2] = 0;
				array[j * 4 + 2] = 0;
			}
			if ((array[i * 4 + 1] + array[i * 4 + 2] == array[j * 4 + 1] + array[j * 4 + 2]) and (std::abs(array[i * 4 + 3]) == std::abs(array[j * 4 + 3])))
			{
				array[j * 4 + 3] = - std::abs(array[j * 4 + 3]);
				array[j * 4 + 2] = 0;
			}
		}
	}
}
void linear_check_collision(int array[], unsigned int k, int n)
{
	for (int i = 0; i < k; i++)
	{
		if ((array[i * 4 + 1] % n == n - 1) || (array[i * 4 + 1] % n == 0))
		{
			array[i * 4 + 2] = 0;
		}
		for (int j = 0; j < i; j++)
		{
			int a = array[i * 4 + 1] - array[j * 4 + 1];
			if ((a == 1) || (a == -1))
			{
				array[i * 4 + 3] = 0;
				array[j * 4 + 3] = 0;
			}
			if (array[i * 4 + 1] + array[i * 4 + 2] == array[j * 4 + 1] + array[j * 4 + 2])
			{
				array[j * 4 + 3] = 0;
			}
		}
	}
}

void move(int array[], unsigned int k, unsigned int m, unsigned int n)
{
	for (int i = 0; i < k; i++)
	{
		array[i * 4 + 1] = array[i * 4 + 1] + array[i * 4 + 2];
	}
}
int process(int particles[], unsigned int k, int m, int n)
{
	int pos = 0;
	int counter = 0;
	bool flag = true;
	for (int i = 0; i < k; i++)
	{
		while (flag)
		{
			flag = false;
			pos = (dist(rng) % (m - 1) + 1) * n + dist(rng) % (n - 1) + 1;
			for (int j = 0; j < i; j++)
			{
				if (pos == particles[j * 4 + 1])
				{
					flag = true;
				}
			}
		}
		particles[i * 4] = i;
		particles[i * 4 + 1] = pos;
		particles[i * 4 + 2] = 0;
		particles[i * 4 + 3] = dist(rng) % 2 + 1;
		flag = true;
	}
	flag = true;
	bool drawflag;
	while (flag)
	{
		flag = false;
		counter++;
		random_move(particles, k, m, n);
		check_collision(particles, k, m, n);
		move(particles, k, m, n);
		for (int i = 0; i < k; i++)
		{
			if (particles[i * 4 + 3] > 0)
			{
				flag = true;
			}
			std::cout << particles[i * 4] << " " << particles[i * 4 + 1] << " " << particles[i * 4 + 2] << " " << particles[i * 4 + 3] << std::endl;
		}
		std::cout << std::endl;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int type = 0;
				drawflag = false;
				for (int l = 0; l < k; l++)
				{
					if (particles[l * 4 + 1] == i * n + j)
					{
						drawflag = true;
						type = particles[l * 4 + 3];
					}
				}
				if (drawflag)
				{
					std::cout << std::abs(type);
				}
				else
				{
					std::cout << "+";
				}
			}
			std::cout << std::endl;
		}
	}
	std::cout << "movement ended////////////////////////////////////";
	return counter;
 }
int linear_process(int particles[], unsigned int k, int n)
{
	int m = 1;
	int counter = 0;
	int pos = 0;
	bool flag = true;
	for (int i = 0; i < k; i++)
	{
		while (flag)
		{
			flag = false;
			pos = dist(rng) % (n - 1) + 1;
			for (int j = 0; j < i; j++)
			{
				if (pos == particles[j * 3 + 1])
				{
					flag = true;
				}
			}
		}
		particles[i * 4] = i;
		particles[i * 4 + 1] = pos;
		particles[i * 4 + 2] = 12;
		flag = true;
	}
	flag = true;
	bool drawflag;
	while (flag)
	{
		flag = false;
		counter++;
		linear_random_move(particles, k, n);
		linear_check_collision(particles, k, n);
		move(particles, k, m, n);
		for (int i = 0; i < k; i++)
		{
			if (particles[i * 4 + 3] != 0)
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
	return counter;
}

int main()
{
	int m = 7;//matrix[m*n]
	int n = 7;
	const int k = 5;
	int particles[k * 4];//[number, position, moving(-1, -7, 1, 7 or 0 if not moving)]
	srand(time(0));
	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += process(particles, k, m, n);
	}
	std::cout << sum/100;
	std::cout << "runtime = " << clock() / 1000.0 << std::endl; // время работы программы    
	std::cout << "n = " << n << std::endl;
	
	

}
