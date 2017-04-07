// Lab__3ClassInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


class Ellipse
{
	double a, b, x, y;
public:
	Ellipse(double a, double b, double x, double y)
	{
		this->a = a; this->b = b;
		this->x = x; this->y = y;
	}
	virtual void print()
	{
		cout << "\na = " << a << "   x = " << x;
		cout << "\nb = " << b << "   y = " << y;
	}
	virtual double MainAxis(double a, double b)
	{
		if (a > b) return 1;
		else if (b > a) return 2;
		else if (a == b) return 0;
	}
};

class Ellipsoid : public Ellipse
{
	double c, z;
public:
	Ellipsoid(double a, double b, double c, double x, double y, double z) :
		Ellipse(a, b, x, y)
	{
		this->c = c;
		this->z = z;
	}
	void print() // Переопределенный метод print
	{
		Ellipse::print();
		cout << "\nc = " << c; cout << "   z = " << z;
	}
	double MainAxis(double a, double b, double c)
	{
		double n;
		n = Ellipse::MainAxis(a, b);
		if (n > c) return n;
		if (c > n) return 3;
		if ((c == 0) && (n == 0)) return 0;
		else return n + 3;
	}
};

int main()
{
	Ellipse Ee(3, 2, -1, 4);
	Ellipsoid Ed(1, 4, 2, 3, -2, -4);

	cout << "\nEllipse: ";
	Ellipse *pp;
	pp = &Ee;
	pp->print();
	double n;
	n = pp->MainAxis(3, 2);
	if (n == 0) cout << "\nThe figure is equidistant from all axes";
	if (n == 1) cout << "\nThe figure is located along the axis X";
	if (n == 2) cout << "\nThe figure is located along the axis Y";

	cout << "\nEllips: ";
	pp = &Ed;
	pp->print();
	n = pp->MainAxis(1, 4);
	if (n == 0) cout << "\nThe figure is equidistant from all axes";
	if (n == 1) cout << "\nThe figure is located along the axis X";
	if (n == 2) cout << "\nThe figure is located along the axis Y";
	if (n == 3) cout << "\nThe figure is located along the axis Z";
	if (n == 4) cout << "\nThe figure is located along the axis X and Y";
	if (n == 5) cout << "\nThe figure is located along the axis X and Z";
	if (n == 6) cout << "\nThe figure is located along the axis Y and Z";

	system("pause");
	return 0;
}


