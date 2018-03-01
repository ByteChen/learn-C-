#pragma once
#include<string>
using namespace std;

class Sales_item {
public:
	Sales_item() = default;
	//使用委托构造函数
	Sales_item(const std::string s, unsigned count, double gain) :bookNo(s), units_sold(count), revenue(gain) {}
	Sales_item(const std::string s) :Sales_item(s, 0, 0) {}
	Sales_item(std::istream& is) :Sales_item("", 0, 0) { read(is, *this); }	//空字符串用""而不是''; 尽量不使用cin做变量名
	
	friend istream& read(std::istream& is, Sales_item& it);
	friend ostream& print(ostream& os, const Sales_item &it);
	friend ostream& operator<<(ostream& os, Sales_item& rhs);
	friend istream& operator >> (istream& is, Sales_item& rhs);
	friend Sales_item operator + (const Sales_item& lhs, const Sales_item& rhs);
	friend void operator += (Sales_item& lhs, const Sales_item& rhs);	//若定义成成员函数，则不必要写lhs。
	friend bool operator == (const Sales_item& lhs, const Sales_item& rhs);
	friend bool operator != (const Sales_item& lhs, const Sales_item& rhs) { return !(lhs == rhs); }

	string isbn() const { return bookNo; }
	Sales_item& combine(const Sales_item lhs);
	double get_avg() const
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
	
	bool same_isbn(const Sales_item rhs) const { return bookNo == rhs.bookNo; }
	

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;	//总价
};

istream& read(istream& is, Sales_item& it)
{
	is >> it.bookNo >> it.units_sold >> it.revenue;
	return is;
}

ostream& print(ostream& os, const Sales_item &it)
{
	os << "The printed book is: " << it.bookNo << " " << it.units_sold << " " << it.revenue << endl;
	return os;
}

Sales_item add(const Sales_item &lhs, const Sales_item &rhs)
{
	if (lhs.isbn() == lhs.isbn())
	{
		Sales_item ret = lhs;
		ret.combine(rhs);
		return ret;
	}
	else
		cerr << "Books must be same isbn!\n";
	return Sales_item();
}

Sales_item& Sales_item::combine(const Sales_item rhs)
{
	if (bookNo == rhs.isbn())
	{
		units_sold  += rhs.units_sold;
		revenue		+= rhs.revenue;
	}
	else
		cerr << "Books must be same isbn!\n";
	return *this;
}

ostream& operator<<(ostream& os, Sales_item& rhs)
{
	os << "The content of this sales item is:" << endl;
	os << "bookNo: " << rhs.bookNo << endl;
	os << "units_sold: " << rhs.units_sold << endl;
	os << "revenue: " << rhs.revenue << endl;
	return os;
}

istream& operator >> (istream& is, Sales_item& rhs)
{
	is >> rhs.bookNo >> rhs.units_sold >> rhs.revenue;
	return is;
}

Sales_item operator + (const Sales_item& lhs, const Sales_item& rhs)
{
	if (lhs.bookNo != rhs.bookNo)
	{
		cerr << "These books must be same ISBN !" << endl;
		return Sales_item();
	}
	Sales_item ret(lhs);
	ret.units_sold += rhs.units_sold;
	ret.revenue += rhs.revenue;
	return ret;
}

void operator += (Sales_item& lhs, const Sales_item& rhs)
{
	if (lhs.bookNo == rhs.bookNo)
	{
		lhs.units_sold += rhs.units_sold;
		lhs.revenue += rhs.revenue;
		return;
	}
	else
	{
		cerr << "operator+= : Books must be in same ISBN!!" << endl;
	}
}

inline bool operator == (const Sales_item& lhs, const Sales_item& rhs)
{
	return  lhs.bookNo == rhs.bookNo &&
			lhs.units_sold == rhs.units_sold &&
			lhs.revenue == rhs.revenue;
}