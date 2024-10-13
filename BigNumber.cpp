#include"BigNumber.h"
BigNumber BigNumber::operator = (const BigNumber& other)
{
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
	return*this;
}
BigNumber BigNumber::operator / (const BigNumber& other)const
{
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
	BigNumber diff(result);
	diff.copyString(diff.number, diff.number + l);
	delete[] result;
	return diff;
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
	delete[]number;
	numberLength = 0;
	number = nullptr;
}
BigNumber::BigNumber(const BigNumber& bigNum)
{
	if (bigNum.number == nullptr || bigNum.number[0] == '\0')
	{
		number = nullptr;
		numberLength = 0;
		return;
	}
	numberLength = bigNum.numberLength;
	number = new char[numberLength + 1];
	int i = 0;
	for (; i < numberLength; i++)
	{
		number[i] = bigNum.number[i];
	}      
	number[numberLength] = '\0';
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
