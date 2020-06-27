// Stochastic.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>  // basic C++ input/output (e.g., cin, cout)
#include <string>
#include <vector>
#include <stdlib.h> 
#include<algorithm>
#include<cstdlib>
#include<time.h>
#include "stdarg.h"
#include "ConsoleApplication1.cpp"

using namespace std;

int andgate(int count, ...)
{
	int andvalue = 1;

	va_list args;
	va_start(args, count);
	while (count--)
	{
		andvalue *= va_arg(args, int);
	}
	va_end(args);

	return andvalue;
}

int orgate(int count, ...)
{
	int orvalue = 1;

	va_list args;
	va_start(args, count);
	while (count--)
	{
		if (va_arg(args, int) == 1)
		{
			orvalue = 1;
			break;
		}
	}
	va_end(args);

	return orvalue;
}

int xor2gate(int val1,int val2)
{
	int xorvalue = 1;

	if (val1 != val2)
	{
		xorvalue = 1;
	}
	else
		xorvalue = 0;

	return xorvalue;
}

int main()
{
	int outz = 0;
	int outo = 0;
	int rannum = 0;
	int ran1, ran2;
	int iteration = 256;
	int jug = 78;
	int suc = 0;
	double er = 0.05;//error ratio;

	srand((unsigned)time(NULL));

	vector<float> testcosvec = { 1,0,-0.5,0,0.04166667,0,0.001388889 };
	vector<float> bersteincos = Berstein(testcosvec);

	for (int j = 0; j < 1000; j++)
	{
		//outo = 0;
		//outz = 0;
		//for (int i = 0; i < iteration; i++)
		//{
		//	rannum = rand() % 100;
		//	if (rannum > jug)
		//		rannum = 0;
		//	else
		//		rannum = 1;
		//	ran1 = rannum;
		//	rannum = rand() % 100;
		//	if (rannum > jug)
		//		rannum = 0;
		//	else
		//		rannum = 1;
		//	ran2 = rannum;

		//	int result = andgate(2, ran1, ran2);
		//	if (result == 0)
		//		outz++;
		//	else
		//		outo++;
		//}
		//double ratio = (double)outo / iteration;
		///*cout << outo << endl;
		//cout << ratio << endl;*/
		//
		//double ok = ratio / 0.0625;
		//
		//if (ok > 0.9 && ok < 1.1)
		//	suc++;

		outo = 0;
		outz = 0;
		float jug2 = 0;
		int inputnum = bersteincos.size();
		//vector<float> berstein = { 0.8,0.8,0.8,0.8 };
		for (int i = 0; i < iteration; i++)
		{
			ran1 = 0;
			for (int j = 0; j < inputnum-1; j++)
			{
				rannum = rand() % 100;
				if (rannum > jug)
					rannum = 0;
				else
					rannum = 1;
				ran1 += rannum;

			}
			jug2 = 100 * bersteincos[ran1];
			rannum = rand() % 100;
			if (rannum > jug2)
				rannum = 0;
			else
				rannum = 1;
			//cout << rannum << endl;
			if (rannum == 0)
				outz++;
			else
				outo++;
		}
		double ratio = (double)outo / iteration;
		/*cout << outo << endl;
		cout << ratio << endl;*/

		double ok = ratio / 0.707;

		if (ok > 1-er && ok < 1+er)
			suc++;
	}
	/*cout << outo << "   " << outz << endl;
		cout << (float)outo / iteration << endl;*/
	cout << "ask for error ratio under " << er * 100 << " %" << endl;
	cout << "pass possibility: "<< (float)suc/10 << " %" << endl;


	return 0;
}


