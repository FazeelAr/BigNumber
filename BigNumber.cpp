#include"BigNumber.h"
BigNumber BigNumber::operator = (const BigNumber& other)
{
	cout << "\nassignment:";
	if (this == &other)
	{
		return*this;
	}
	this->~BigNumber();
	if (other.number == nullptr || other.number[0] == '\0')
	{
		cout << "d\n";
		return*this;
	}
	numberLength = getStringLength(other.number);
	number = new char[numberLength + 1];
	for (int i = 0; i < numberLength; i++)
	{
		number[i] = other.number[i];
	}
	number[numberLength] = '\0';
	//cout << "\nreturn";
	return*this;
}
BigNumber BigNumber::operator / (const BigNumber& other)const
{
	cout << "kgdfjuk";
	this->print();
	BigNumber div{ *this }, count{"0"};
	div.print();
	while (div > "0")
	{
		div = div - other;
		count.operator++(1);
	}
	return count;
}
BigNumber BigNumber::operator % (const BigNumber& other)const
{
	BigNumber div{ *this }, count{ "0" };
	while (div > "0")
	{
		div = div - other;
		count.operator++(1);
	}
	return div;
}
//BigNumber BigNumber::operator = (BigNumber&& other)
//{
//	cout << "\nMOVE::assignment::NUM";
//	if (this == &other)
//	{
//		return*this;
//	}
//	this->~BigNumber();
//	if (other.number == nullptr || other.number[0] == '\0')
//	{
//		cout << "d\n";
//		return*this;
//	}
//	numberLength = getStringLength(other.number);
//	number = new char[numberLength + 1];
//	for (int i = 0; i < numberLength; i++)
//	{
//		number[i] = other.number[i];
//	}
//	number[numberLength] = '\0';
//	other.number = nullptr;
//	other.numberLength = 0;
//	//cout << "\nreturn";
//	return*this;
//}
int BigNumber::getStringLength(const char* p)const
{
	if (p == nullptr || p[0] == '\0')
	{
		return 0;
	}
	int i = 0;
	while (p[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
bool BigNumber::operator==(const BigNumber& other)const
{
	if (this->compare(other) != 0)
	{
		return false;
	}
	return true;
}
bool BigNumber::operator>(const BigNumber& other)const
{
	if (this->compare(other) > 0)
	{
		return true;
	}
	return false;
}
bool BigNumber::operator<(const BigNumber& other)const
{
	return (*this > other || *this==other) ? false : true;
}
bool BigNumber::operator>=(const BigNumber& other)const
{
	return(*this > other || *this == other) ? true : false;
}
bool BigNumber::operator<=(const BigNumber& other)const
{
	return(*this < other || *this == other) ? true : false;
}
bool BigNumber::operator!=(const BigNumber& other)const
{
	return(*this == other) ? false : true;
}
BigNumber BigNumber::operator-(const BigNumber& other)const
{
	int maxSize = numberLength;
	char* result = new char[maxSize + 1];

	int borrow = 0;
	int i = numberLength - 1;
	int j = other.numberLength - 1;
	int k = maxSize - 1;

	while (i >= 0) 
	{
		int diff = number[i--] - '0' - borrow;
		if (j >= 0)
			diff -= other.number[j--] - '0';
		if (diff < 0) 
		{
			diff += 10;
			borrow = 1;
		}
		else 
		{
			borrow = 0;
		}
		result[k--] = '0' + diff;
	}
	result[maxSize] = '\0';
	int l = 0;
	while (result[l] != '\0' && result [l] == '0')
	{
		l++;
	}
	/*if (l == numberLength)
	{
		number[1] = '\0';
	}*/
	BigNumber diff(result);
	diff.copyString(diff.number, diff.number + l);
	delete[] result;
	return diff;
	/*BigNumber sub{ "" };
	sub.numberLength = numberLength;
	int l1 = numberLength;
	int otherLength = other.numberLength - 1;
	int* carry = new int[l1];
	for (int i = 0; i < l1; i++)
	{
		carry[i] = 0;
	}
	sub.number = new char[sub.numberLength + 1];
	sub.number[l1] = '\0';
	l1 = l1 - 1;
	while (l1 >= 0)
	{
		if (number[l1] < other.number[otherLength])
		{
			int i = l1 - 1;
			while (number[i] == '0')
			{
				i--;
			}
			while (i != l1)
			{
				number[i] = number[i] - 1;
				i++;
				carry[i] = 10;
			}
		}
		int temp = carry[l1] + (number[l1] - '0');
		if (otherLength >= 0)
		{
			temp = temp - (other.number[otherLength] - '0');
		}
		sub.number[l1] = temp + '0';
		l1--;
		otherLength--;
	}
	int i = 0;
	while (number[i] != '\0' && number[i] == '0')
	{
		i++;
	}
	if (i == numberLength)
	{
		number[1] = '\0';
	}
	return sub;*/
}
BigNumber BigNumber::operator + (const BigNumber& other)const
{
	if (number == nullptr || number[0] == '\0')
	{
		return*this;
	}
	if (other.number == nullptr || other.number[0] == '\0')
	{
		return *this;
	}
	int maxSize = (numberLength > other.numberLength) ? numberLength : other.numberLength;
	char* result = new char[maxSize + 2]; // Extra space for possible carry
	int carry = 0;
	int i = numberLength - 1;
	int j = other.numberLength - 1;
	int k = maxSize;
	while (i >= 0 || j >= 0 || carry > 0) {
		int sum = carry;
		if (i >= 0)
			sum += number[i--] - '0';
		if (j >= 0)
			sum += other.number[j--] - '0';
		result[k--] = '0' + sum % 10;
		carry = sum / 10;
	}
	result[maxSize + 1] = '\0';
	BigNumber sum(result + (k + 1));
	delete[] result;
	return sum;
	/*int l1 = getStringLength(number);
	int l2 = getStringLength(num.number);
	int carry = 0;
	int bigLength = (l1 >= l2) ? l1 : l2;
	int originaLength = bigLength;
	BigNumber addNum{ "" };
	addNum.~BigNumber();
	addNum.number = new char[bigLength + 1];
	addNum.number[bigLength] = '\0';
	bigLength = bigLength - 1;
	l1 = l1 - 1;
	l2 = l2 - 1;
	addNum.numberLength = originaLength;
	while (bigLength >= 0)
	{
		int sum;
		sum = carry;
		if (l1 >= 0)
		{
			sum = sum + (number[l1] - '0');
		}
		if (l2 >= 0)
		{
			sum = sum + (num.number[l2] - '0');
		}
		addNum.number[bigLength] = (sum % 10) + '0';
		carry = (sum > 9) ? 1 : 0;
		l1 = l1 - 1;
		l2 = l2 - 1;
		bigLength = bigLength - 1;
		if (bigLength == -1 && carry == 1)
		{
			addNum.reSize(originaLength + 2);
			addNum.number[0] = '1';
		}
	}
	cout << '\n' << addNum.numberLength;*/
	//return addNum;
}
BigNumber BigNumber::operator++()
{
	*this = this->operator+("1");
	return *this;
}
BigNumber BigNumber::operator++(int)
{
	BigNumber cpy{ *this };
	*this = this->operator+("1");
	return cpy;
}
void BigNumber::print()const
{
	if (number == nullptr || number[0] == '\0')
	{
		cout << '\n' << 0;
		return;
	}
	cout << '\n' << number;
}
BigNumber::BigNumber()
{
	//cout << "\ndefault:";
	number = nullptr;
	numberLength = 0;
}
void BigNumber::setNumber(const char* num)
{
	if (num == nullptr || num[0] == '\0')
	{
		return;
	}
	this->~BigNumber();
	int len = getStringLength(num);
	numberLength = len;
	number = new char[numberLength + 1];
	copyString(number, num);
}
BigNumber::BigNumber(const char* num)
{
	//cout << "\nconst char*::NUM:  "<<num;
	if (num == nullptr || num[0] == '\0')
	{
		number = nullptr;
		numberLength = 0;
		return;
	}
	numberLength = getStringLength(num);
	number = new char[numberLength+1];
	copyString(number, num);
}
BigNumber::~BigNumber()
{
	//cout << "\ndestructor::NUM:  ";
	delete[]number;
	numberLength = 0;
	number = nullptr;
}
//BigNumber::BigNumber(BigNumber&& other)
//{
//	//cout << "\nmove::NUM";
//	number = other.number;
//	numberLength = other.numberLength;
//	other.number = nullptr;
//	other.numberLength = 0;
//}
BigNumber::BigNumber(const BigNumber& bigNum)
{
	if (bigNum.number == nullptr || bigNum.number[0] == '\0')
	{
		number = nullptr;
		numberLength = 0;
		return;
	}
	//cout << "\ncopy constructor::NUM ";// << bigNum.number;
	numberLength = bigNum.numberLength;
	number = new char[numberLength + 1];
	int i = 0;
	for (; i < numberLength; i++)
	{
		number[i] = bigNum.number[i];
	}      
	number[numberLength] = '\0';
	//cout << "\ndone";
}
int BigNumber::compare(const BigNumber& other)const
{
	if (number == nullptr)
	{
		return -1;
	}
	else if (other.number == nullptr)
	{
		return 1;
	}
	if (getStringLength(number) > getStringLength(other.number))
	{
		return 1;
	}
	else if (getStringLength(number) < getStringLength(other.number))
	{
		return -1;
	}
	int i = 0;
	while (number[i] != '\0' && other.number[i] != '\0' && number[i] == other.number[i])
	{
		i++;
	}
	int res = number[i] - other.number[i];
	if (res > 0)
	{
		return 1;
	}
	else if (res < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
BigNumber BigNumber::operator*(const BigNumber& other)const
{
	BigNumber multiply{ *this };
	if (number == nullptr || other.number == nullptr)
	{
		return multiply;
	}
	BigNumber count{ "1" };
	while (count != other)
	{
		multiply = multiply.operator+(*this);
		++count;
	}
	return multiply;
}
BigNumber::operator int()
{
	if (number==nullptr||number[0]=='\0')
	{
		exit(0);
	}
	int k = 0;
	while (number[k] != '\0')
	{
		if ((number[k] < '0' || number[k] > '9') && number[k] != '.')
		{
			//cout << "wrong string";
			exit(0);
		}
		k++;
	}
	int num = 0;
	int i = 0;
	bool negative = false;
	if (number[0] == '-')
	{
		i = 1;
		negative = true;
	}
	while (number[i] != '\0' && number[i] != '.')
	{
		num = (num * 10) + (number[i] - '0');
		i++;
	}
	if (negative)
	{
		return num = num * -1;
	}
	return num;
}
void BigNumber::reSize(int size)
{
	char* temp = new char[size];
	int i = numberLength - 1;
	for(int j = numberLength; j > 0; j--)
	{
		temp[j] = number[i];
		i--;
	}
	temp[size - 1] = '\0';
	this->~BigNumber();
	number = temp;
	numberLength = size - 1;
}
int BigNumber::getNumberLength(long long int num)const
{
	int i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return i;
}
void BigNumber::copyString(char* des, const char* src)
{
	if (des == nullptr || src == nullptr)
	{
		return;
	}
	int i = 0;
	while (src[i] != '\0')
	{
		des[i] = src[i];
		i = i + 1;
	}
	des[i] = '\0';
}
BigNumber b{ "6" };