#include <bits/stdc++.h>
using namespace std;

#define e 2.71828 

void newton(double (*func)(double), double (*func1)(double), double x1)
{
	double tol = 0.000000001;
	double x = x1;
	double fx = func(x);

	int max_iters = 1000;
	int iter = 0;
	cout<<endl<<"Iterations, x, f(x) : "<<iter<<" "<<x<<" "<<fx;
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
	cout<<endl<<"within tolerance of 0.000000001 in iterations, x, fx : "<<iter<<" "<<x<<" "<<fx;
	cout<<endl<<endl;
	return ;
}

void secnat(double (*func)(double), double x1, double x2)
{
	double tol = 0.000000001;
	double fx1 = func(x1);
	double fx2 = func(x2);
	double temp;

	int max_iters = 1000;
	int iter = 0;
	cout<<endl<<"Iterations, x1, x2, f(x1), f(x2) : "<<iter<<" "<<x1<<" "<<x2<<" "<<fx1<<" "<<fx2;
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
	cout<<endl<<"within tolerance of 0.000000001 in iterations, x, fx : "<<iter<<" "<<x1<<" "<<fx1;
	cout<<endl<<endl;
	return ;	
}

void solve(double (*func)(double), double (*func1)(double), double x1, double x2)
{
	newton(func, func1, x1);
	secnat(func, x1, x2);
}

double f(double x)
{
	return 0.435 * (pow(e, x) - 1) - (1.564 - pow(e, x)) * x;
}

double f1(double x)
{
	return 0.435 * pow(e, x) - (1.564 - pow(e, x)) + pow(e, x) * x;
}

int main()
{
	/*for func */
	cout<<endl<<endl<<"Calling the methods for function f"<<endl;
	solve(f, f1, 0.15, 0.05);

}


