#include <bits/stdc++.h>
using namespace std;

#define e 2.71828

void modified_newton(double (*func)(double), double (*f1)(double), double (*f2)(double), double x1)
{
	double tol = 0.000001;
	double x = x1;
	double fx = func(x);
	double f1x = f1(x);
	double f2x = f2(x);

	int max_iters = 1000;
	int iter = 0;
	while(abs(fx) > tol)
	{
		iter++;
		f1x = f1(x);
		f2x = f2(x);
		x = x - (fx * f1x)/ (f1x * f1x - fx * f2x);
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

double f(double x)
{
	return pow(e, x) - x - 1;
}

double f1(double x)
{
	return pow(e, x)- 1;
}

double f2(double x)
{
	return pow(e, x);
}

int main()
{
	modified_newton(f, f1, f2, 10);
	return 0;
}

