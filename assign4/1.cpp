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

double f(double x)
{
	return pow(x, 4) - 3 * pow(x, 2) - 21;
}

double f1(double x)
{
	return 4 * pow(x, 3) - 6 * x;
}

int main()
{
	newton(f, f1, 1);
	return 0;
}

