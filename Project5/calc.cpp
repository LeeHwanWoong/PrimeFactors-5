#include <vector>
using namespace std;

class Calc
{
public:
	static int calMinus(int a, int b)
	{
		return ((a > b) ? (a - b) : (b - a));
	}
private:
};

class Fibo
{
public:
	Fibo()
	{
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i < 100000; ++i)
		{
			arr[i] = -1;
		}
	}

	int fibo(int i)
	{
		if(arr[i] != -1)
		{
			return arr[i];
		}

		arr[i] = fibo(i - 1) + fibo(i - 2);

		return arr[i];
	}
private:
	int arr[100000];
};

class Bank
{
public:
	Bank()
	:balance(10000)
	{}
	Bank(int init)
	:balance(init)
	{}

	int getAccount()
	{
		return balance;
	}

	void setAccount(int money)
	{
		balance = money;
	}

	void withdraw(int money)
	{
		balance = (balance >= money) ? (balance - money) : (0);
	}

	void deposit(int money)
	{
		balance += money;
	}

	int profit_5Percent()
	{
		setProfit(5);
		return profit_SetPercent();
	}

	void setProfit(int _percent)
	{
		percent = _percent;
	}

	int profit_SetPercent()
	{
		return balance = balance * (100 + percent) / 100;
	}

	int profit_NYear(int n)
	{
		int ret = balance;

		for (int i = 0; i < n; ++i)
			ret = ret * (100 + percent) / 100;

		return ret;
	}
private:
	int balance;
	int percent;
};

class PrimeFactor
{
public:
	vector<int> getPrimeFactor(int num)
	{
		vector<int> ret;

		while(num != 1)
		{
			for (int i = 2; i <= num; ++i)
			{
				if(num % i == 0)
				{
					num /= i;
					ret.push_back(i);
					break;
				}
			}
		}

		return ret;
	}
private:
};