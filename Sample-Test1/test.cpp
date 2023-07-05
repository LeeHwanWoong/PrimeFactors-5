#include "pch.h"
#include "../Project5/calc.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(Calc::calMinus(5,4), 1);
  EXPECT_EQ(Calc::calMinus(5,1), 4);
  EXPECT_EQ(Calc::calMinus(1,5), 4);
  EXPECT_EQ(Calc::calMinus(2,3), 1);
}

TEST(TestCaseName, fibo) {
	Fibo* f = new Fibo();

	EXPECT_EQ(f->fibo(0), 0);
	EXPECT_EQ(f->fibo(1), 1);
	EXPECT_EQ(f->fibo(2), 1);
	EXPECT_EQ(f->fibo(3), 2);
	EXPECT_EQ(f->fibo(4), 3);
	EXPECT_EQ(f->fibo(5), 5);
	EXPECT_EQ(f->fibo(6), 8);
	EXPECT_EQ(f->fibo(7), 13);
	EXPECT_EQ(f->fibo(8), 21);
	EXPECT_EQ(f->fibo(9), 34);
}

TEST(TestCaseName, bank)
{
	Bank b;

	EXPECT_EQ(10000, b.getAccount());

	b.setAccount(20000);
	EXPECT_EQ(20000, b.getAccount());
}

TEST(TestCaseName, bankwithdraw)
{
	Bank b(20000);

	EXPECT_EQ(20000, b.getAccount());

	b.withdraw(10000);
	EXPECT_EQ(10000, b.getAccount());
}

TEST(TestCaseName, bankdeposit)
{
	Bank b(30000);

	EXPECT_EQ(30000, b.getAccount());

	b.deposit(20000);
	EXPECT_EQ(50000, b.getAccount());
}

TEST(TestCaseName, Profit_5percent)
{
	Bank b(10000);

	EXPECT_EQ(10000, b.getAccount());

	b.profit_5Percent();
	EXPECT_EQ(10500, b.getAccount());
}

TEST(TestCaseName, setProfit)
{
	Bank b(10000);

	EXPECT_EQ(10000, b.getAccount());

	b.setProfit(10);
	b.profit_SetPercent();
	EXPECT_EQ(11000, b.getAccount());
}

TEST(TestCaseName, AfterNYear)
{
	Bank b(10000);

	EXPECT_EQ(10000, b.getAccount());

	b.setProfit(10);
	EXPECT_EQ(12100, b.profit_NYear(2));
	EXPECT_EQ(13310, b.profit_NYear(3));
	EXPECT_EQ(14641, b.profit_NYear(4));
}

TEST(TestCaseName, Prime1)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(2);
	expected.push_back(2);
	expected.push_back(3);

	EXPECT_EQ(pf.getPrimeFactor(12), expected);
}

TEST(TestCaseName, Prime2)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(2);
	expected.push_back(5);
	expected.push_back(7);

	EXPECT_EQ(pf.getPrimeFactor(70), expected);
}