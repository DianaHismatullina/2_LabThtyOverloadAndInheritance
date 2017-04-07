// Lab__3OperatorOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class �verload
{
public:
	double *Mas;
	unsigned int L;

public:
	�verload(double *M, unsigned int l)
	{
		L = l;
		Mas = new double[l];
		for (unsigned int i = 0; i<l; ++i) Mas[i] = M[i];
	}
	
	�verload() 
	{ 
		Mas = 0; 
		L = 0; 
	}

	~�verload()
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
	
	�verload & operator =(�verload& v2)
	{
		L = v2.L;
		Mas = new double[L];
		for (unsigned int i = 0; i<L; ++i) Mas[i] = v2.Mas[i];
		return *this;
	}
	
	friend �verload & operator -(double *x, �verload& v2);
	
	friend �verload & operator +(double *x, �verload& v2);
};

�verload & operator +(double *x, �verload& v2)
{
	double *p = new double[v2.L];
	for (unsigned int i = 0; i < v2.L; ++i) p[i] = x[i] + v2.Mas[i];
	�verload *pV = new �verload(p, v2.L);
	delete[] p;
	return *pV;
}

�verload & operator -(double *x, �verload& v2)
{
	double *p = new double[v2.L];
	for (unsigned int i = 0; i < v2.L; ++i) p[i] = v2.Mas[i] - x[i];
	�verload *pV = new �verload(p, v2.L);
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
	�verload V1(M, n);
	

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
	�verload V2;
	V2 = m1 + V1;
	V2.print();

	cout << "\n Massiv with the difference: ";
	�verload V3;
	V3 = m1 - V1;
	V3.print();

	system("pause");
	return 0;
}
