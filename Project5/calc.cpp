#include <vector>
#include <string>
#include <stdexcept>
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

struct Result
{
	bool resolved = false;
	int strikes = 0;
	int balls = 0;
};

class BaseBallGame
{
public:
	BaseBallGame()
	{
		answer[0] = '1';
		answer[1] = '2';
		answer[2] = '3';
	}

	BaseBallGame(string s)
	{
		CheckException(s);

		for (int i = 0; i < 3; ++i)
		{
			answer[i] = s[i];
		}
	}

	void CheckException(string s)
	{
		if(s.length() != 3)
		{
			throw length_error("length more than 3");
		}
		for (int i = 0; i < 3; ++i)
		{
			if(s[i] < '0' || s[i] > '9')
			{
				throw invalid_argument("must digit");
			}
		}
		if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2])
		{
			throw invalid_argument("duplicate digit");
		}
	}

	Result getResolve(string s)
	{
		CheckException(s);

		Result ret;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if(s[i] == answer[j])
				{
					if(i == j)
					{
						ret.strikes++;
					}
					else
					{
						ret.balls++;
					}
				}
			}
		}

		if(ret.strikes >= 3)
		{
			ret.resolved = true;
		}

		return ret;
	}
private:
	char answer[3];
};