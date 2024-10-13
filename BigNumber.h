#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include<iostream>
using namespace std;
class BigNumber
{
	char* number;
	int numberLength;
	int getNumberLength(long long int num)const;
	void reSize(int size);
	void copyString(char* des, const char* src);
	int getStringLength(const char* p)const;
	int compare(const BigNumber& s2)const;
public:
	BigNumber();
	BigNumber(const char* num);
	BigNumber(const BigNumber& bigNum);
	~BigNumber();
	void print() const;
	void setNumber(const char* num);
	BigNumber operator = (const BigNumber& other);
	BigNumber operator + (const BigNumber& other)const;
	BigNumber operator++();
	BigNumber operator++(int);
	BigNumber operator - (const BigNumber& other)const;
	BigNumber operator * (const BigNumber& other)const;
	BigNumber operator / (const BigNumber& other)const;
	BigNumber operator % (const BigNumber& other)const;
	operator int();
	bool operator==(const BigNumber& other)const;
	bool operator>(const BigNumber& other)const;
	bool operator<(const BigNumber& other)const;
	bool operator>=(const BigNumber& other)const;
	bool operator<=(const BigNumber& other)const;
	bool operator!=(const BigNumber& other)const;
};
#endif // !BIGNUMBER_H
