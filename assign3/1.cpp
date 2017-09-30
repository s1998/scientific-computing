#include <bits/stdc++.h>
using namespace std;

void newton(double (*func)(double), double (*func1)(double), double x1)
{
	double tol = 0.000001;
	double x = x1;
	double fx = func(x);

	int max_iters = 1000;
	int iter = 0;
	while(abs(fx) > tol)
	{
		iter++;
		x = x - fx / func1(x);
		fx = func(x);
		cout<<endl<<"Iterations, x, f(x) : "<<iter<<" "<<x<<" "<<fx;
		if(iter > max_iters)
			break;
	}
	cout<<endl<<"With newton method function converged ";
	cout<<endl<<"within tolerance of 0.000001 in iterations, x, fx : "<<iter<<" "<<x<<" "<<fx;
	cout<<endl<<endl;
	return ;
}

void secnat(double (*func)(double), double x1, double x2)
{
	double tol = 0.000001;
	double fx1 = func(x1);
	double fx2 = func(x2);
	double temp;

	int max_iters = 1000;
	int iter = 0;
	while(abs(fx1) > tol)
	{
		iter++;
		temp = x1;
		x1 = x1 - fx1 * (x2 - x1) / (fx2 - fx1);
		fx2 = fx1;
		x2 = temp;
		fx1 = func(x1);
		cout<<endl<<"Iterations, x1, x2, f(x1), f(x2) : "<<iter<<" "<<x1<<" "<<x2<<" "<<fx1<<" "<<fx2;
		if(iter > max_iters)
			break;
	}
	cout<<endl<<"With secant method function converged ";
	cout<<endl<<"within tolerance of 0.000001 in iterations, x, fx : "<<iter<<" "<<x1<<" "<<fx1;
	cout<<endl<<endl;
	return ;	
}

void solve(double (*func)(double), double (*func1)(double), double x1, double x2)
{
	newton(func, func1, x1);
	secnat(func, x1, x2);
}

double fa(double x)
{
	return pow(x, 3) - 2 * pow(x, 2) - 5;
}

double fa1(double x)
{
	return 3 * pow(x, 2) - 4 * x;
}

double fb(double x)
{	
	return pow(x, 3) + 4.001 * pow(x, 2) + 4.002 * x + 1.101;
}

double fb1(double x)
{
	return 3 * pow(x, 2) + 8.002 * x + 4.002;
}

double fc(double x)
{
	return pow(x, 5) - pow(x, 4) + 2 * pow(x, 3) - 3 * pow(x, 2) + x -4;
}

double fc1(double x)
{
	return 5 * pow(x, 4) - 4 * pow(x, 3) + 6 * pow(x, 2) - 6 * x + 1;
}

int main()
{
	/*for func a*/
	cout<<endl<<endl<<"Calling the methods for function a"<<endl;
	solve(fa, fa1, 2, 3);

	cout<<endl<<endl<<"Calling the methods for function b"<<endl;
	solve(fb, fb1, -3, -2.5);
	solve(fb, fb1, -1, -0.75);
	solve(fb, fb1, -0.5, -0.4);

	cout<<endl<<endl<<"Calling the methods for function c"<<endl;
	solve(fc, fc1, 1, 2);
}


