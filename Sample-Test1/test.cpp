#include "pch.h"
#include "../Project5/calc.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(Calc::calMinus(5,4), 1);
  EXPECT_EQ(Calc::calMinus(5,1), 4);
  EXPECT_EQ(Calc::calMinus(1,5), 4);
  EXPECT_EQ(Calc::calMinus(2,3), 1);
}

TEST(TC_FIBO, fibo) {
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

TEST(TC_ACCOUNT, bank)
{
	Bank b;

	EXPECT_EQ(10000, b.getAccount());

	b.setAccount(20000);
	EXPECT_EQ(20000, b.getAccount());
}

TEST(TC_ACCOUNT, bankwithdraw)
{
	Bank b(20000);

	EXPECT_EQ(20000, b.getAccount());

	b.withdraw(10000);
	EXPECT_EQ(10000, b.getAccount());
}

TEST(TC_ACCOUNT, bankdeposit)
{
	Bank b(30000);

	EXPECT_EQ(30000, b.getAccount());

	b.deposit(20000);
	EXPECT_EQ(50000, b.getAccount());
}

TEST(TC_ACCOUNT, Profit_5percent)
{
	Bank b(10000);

	EXPECT_EQ(10000, b.getAccount());

	b.profit_5Percent();
	EXPECT_EQ(10500, b.getAccount());
}

TEST(TC_ACCOUNT, setProfit)
{
	Bank b(10000);

	EXPECT_EQ(10000, b.getAccount());

	b.setProfit(10);
	b.profit_SetPercent();
	EXPECT_EQ(11000, b.getAccount());
}

TEST(TC_ACCOUNT, AfterNYear)
{
	Bank b(10000);

	EXPECT_EQ(10000, b.getAccount());

	b.setProfit(10);
	EXPECT_EQ(12100, b.profit_NYear(2));
	EXPECT_EQ(13310, b.profit_NYear(3));
	EXPECT_EQ(14641, b.profit_NYear(4));
}

TEST(PRIME_TEST, Prime0)
{
	PrimeFactor pf;
	vector<int> expected;

	EXPECT_EQ(pf.getPrimeFactor(1), expected);
}

TEST(PRIME_TEST, Prime1)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(2);

	EXPECT_EQ(pf.getPrimeFactor(2), expected);
}

TEST(PRIME_TEST, Prime2)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(3);

	EXPECT_EQ(pf.getPrimeFactor(3), expected);
}

TEST(PRIME_TEST, Prime3)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(2);
	expected.push_back(2);

	EXPECT_EQ(pf.getPrimeFactor(4), expected);
}

TEST(PRIME_TEST, Prime4)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(2);
	expected.push_back(3);

	EXPECT_EQ(pf.getPrimeFactor(6), expected);
}

TEST(PRIME_TEST, Prime5)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(3);
	expected.push_back(3);

	EXPECT_EQ(pf.getPrimeFactor(9), expected);
}

TEST(PRIME_TEST, Prime6)
{
	PrimeFactor pf;
	vector<int> expected;

	expected.push_back(2);
	expected.push_back(2);
	expected.push_back(3);

	EXPECT_EQ(pf.getPrimeFactor(12), expected);
}

TEST(TC_BASEBALL, BaseBall1)
{
	BaseBallGame bbg("456");
	Result res = bbg.getResolve("456");

	EXPECT_TRUE(res.resolved);
	EXPECT_EQ(res.strikes, 3);
	EXPECT_EQ(res.balls, 0);
}

TEST(TC_BASEBALL, BaseBall2)
{
	BaseBallGame bbg("456");
	Result res = bbg.getResolve("123");

	EXPECT_FALSE(res.resolved);
	EXPECT_EQ(res.strikes, 0);
	EXPECT_EQ(res.balls, 0);
}

TEST(TC_BASEBALL, BaseBall3)
{
	BaseBallGame bbg("456");
	Result res = bbg.getResolve("645");

	EXPECT_FALSE(res.resolved);
	EXPECT_EQ(res.strikes, 0);
	EXPECT_EQ(res.balls, 3);
}

TEST(TC_BASEBALL, BaseBall4)
{
	BaseBallGame bbg("456");
	Result res = bbg.getResolve("651");

	EXPECT_FALSE(res.resolved);
	EXPECT_EQ(res.strikes, 1);
	EXPECT_EQ(res.balls, 1);
}

TEST(TC_BASEBALL, BaseBall5)
{
	BaseBallGame bbg("456");
	EXPECT_THROW(bbg.getResolve("12"), length_error);
	EXPECT_THROW(bbg.getResolve("1245"), length_error);
}

TEST(TC_BASEBALL, BaseBall6)
{
	BaseBallGame bbg("456");
	EXPECT_THROW(bbg.getResolve("12s"), invalid_argument);
	EXPECT_THROW(bbg.getResolve("as2"), invalid_argument);
}

TEST(TC_BASEBALL, BaseBall7)
{
	BaseBallGame bbg("456");
	EXPECT_THROW(bbg.getResolve("121"), invalid_argument);
	EXPECT_THROW(bbg.getResolve("666"), invalid_argument);
}