#include <bits/stdc++.h>
using namespace std;

#define e 2.71828 
#define smooth_factor 100000 

void newton(double (*func)(double), double (*func1)(double), double x1, double tol)
{
	double x = x1;
	double fx = func(x);

	int max_iters = 1000;
	int iter = 0;
	cout<<endl<<"Iterations, x, f(x) : "<<iter<<" "<<x<<" "<<fx;
	while(abs(fx * smooth_factor) > tol)
	{
		iter++;
		x = x - fx / func1(x);
		fx = func(x);
		cout<<endl<<"Iterations, x, f(x) : "<<iter<<" "<<x<<" "<<(fx * smooth_factor);
		if(iter > max_iters)
			break;
	}
	cout<<endl<<"With newton method function converged ";
	cout<<endl<<"in iterations, x, fx : "<<iter<<" "<<x<<" "<<(fx * smooth_factor);
	cout<<endl<<endl;
	return ;
}

void secnat(double (*func)(double), double x1, double x2, double tol)
{
	double fx1 = func(x1);
	double fx2 = func(x2);
	double temp;

	int max_iters = 1000;
	int iter = 0;
	cout<<endl<<"Iterations, x1, x2, f(x1), f(x2) : "<<iter<<" "<<x1<<" "<<x2<<" "<<fx1<<" "<<fx2;
	while(abs(fx1 * smooth_factor) > tol)
	{
		iter++;
		temp = x1;
		x1 = x1 - fx1 * (x2 - x1) / (fx2 - fx1);
		fx2 = fx1;
		x2 = temp;
		fx1 = func(x1);
		cout<<endl<<"Iterations, x1, x2, f(x1), f(x2) : "<<iter<<" "<<x1<<" "<<x2<<" "<<(fx1 * smooth_factor)<<" "<<(fx2 * smooth_factor);
		if(iter > max_iters)
			break;
	}
	cout<<endl<<"With secant method function converged ";
	cout<<endl<<"in iterations, x, fx : "<<iter<<" "<<x1<<" "<<(fx1 * smooth_factor);
	cout<<endl<<endl;
	return ;	
}

void solve(double (*func)(double), double (*func1)(double), double x1, double x2, double tol)
{
	newton(func, func1, x1, tol);
	secnat(func, x1, x2, tol);
}

double f(double x)
{
	return (log(x*x + 1) - pow(e, 0.4 *x) * cos(3.142 * x)) / smooth_factor;
}

double f1(double x)
{
	return ((2 * x) / (x * x + 1) - pow(e, 0.4 * x) * (0.4 * cos(3.142 * x) - 3.142 * sin(3.142 * x))) / smooth_factor;
}

int main()
{
	/*for func */
	cout<<endl<<endl<<"Calling the methods for function f"<<endl;
	cout<<endl<<endl<<"Find the negative root : "<<endl;
	double tol = 0.000000001;
	solve(f, f1, -10, -0, tol);

	cout<<endl<<endl<<"Find the first positive root : "<<endl;
	tol = 0.000000001;
	solve(f, f1, 0, 1, tol);

	cout<<endl<<endl<<"Find the second positive root : "<<endl;
	tol = 0.000000001;
	solve(f, f1, 1, 2.0, tol);

	cout<<endl<<endl<<"Find the third positive root : "<<endl;
	tol = 0.000000001;
	solve(f, f1, 2.1, 3.0, tol);

	cout<<endl<<endl<<"Find the fourth positive root : "<<endl;
	tol = 0.000000001;
	solve(f, f1, 3, 4.0, tol);

	cout<<endl<<endl<<"Find the 25th positive root : "<<endl;
	tol = 0.000000001;
	solve(f, f1, 24.2, 25.0, tol);
}


