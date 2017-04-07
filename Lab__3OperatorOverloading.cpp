// Lab__3OperatorOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Îverload
{
public:
	double *Mas;
	unsigned int L;

public:
	Îverload(double *M, unsigned int l)
	{
		L = l;
		Mas = new double[l];
		for (unsigned int i = 0; i<l; ++i) Mas[i] = M[i];
	}
	
	Îverload() 
	{ 
		Mas = 0; 
		L = 0; 
	}

	~Îverload()
	{
		if (L>0) delete[] Mas;
	}

	void print()
	{
		cout << "\n Massiv: \n";
		for (unsigned int i = 0; i<L; ++i)
			cout << Mas[i] << " ";
	}
	
	double& operator[](unsigned int i)
	{
		return Mas[i];
	}
	
	Îverload & operator =(Îverload& v2)
	{
		L = v2.L;
		Mas = new double[L];
		for (unsigned int i = 0; i<L; ++i) Mas[i] = v2.Mas[i];
		return *this;
	}
	
	friend Îverload & operator -(double *x, Îverload& v2);
	
	friend Îverload & operator +(double *x, Îverload& v2);
};

Îverload & operator +(double *x, Îverload& v2)
{
	double *p = new double[v2.L];
	for (unsigned int i = 0; i < v2.L; ++i) p[i] = x[i] + v2.Mas[i];
	Îverload *pV = new Îverload(p, v2.L);
	delete[] p;
	return *pV;
}

Îverload & operator -(double *x, Îverload& v2)
{
	double *p = new double[v2.L];
	for (unsigned int i = 0; i < v2.L; ++i) p[i] = v2.Mas[i] - x[i];
	Îverload *pV = new Îverload(p, v2.L);
	delete[] p;
	return *pV;
}

int main()
{
	double *M;
	unsigned int n;
	cout << "Massiv lenght = "; cin >> n;
	M = new double[n];
	cout << "\n Enter the initial Massiv: ";
	for (unsigned int i = 0; i < n; ++i)
	{
		cout << "\n Element number "<< i+1 << " = ";
		cin >> M[i];
	}
	Îverload V1(M, n);
	

	double *m1;
	m1 = new double[n];
	cout << "\n Enter the Massiv for the sum and difference: ";
	for (unsigned int i = 0; i < n; ++i)
	{
		cout << "\n Element number " << i + 1 << " = ";
		cin >> m1[i];
	}

	cout << "\n Massiv for the sum and difference: ";
	for (unsigned int i = 0; i<n; ++i)
		cout << m1[i] << " ";

	cout << "\n Initial Massiv: ";
	V1.print();

	cout << "\n Massiv with the sum: ";
	Îverload V2;
	V2 = m1 + V1;
	V2.print();

	cout << "\n Massiv with the difference: ";
	Îverload V3;
	V3 = m1 - V1;
	V3.print();

	system("pause");
	return 0;
}
