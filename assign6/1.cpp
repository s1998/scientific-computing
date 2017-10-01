#include <bits/stdc++.h>
using namespace std;

double integration_trapezoid_rule(
	double (* func) (double),
	double a,
	double b,
	double n_intervals)
{
	double ans = 0;
	double diff = (b - a) / n_intervals;
	// (x_(i+1) - x_i) * (f (x_i) + f(x_(i+1)) / 2
	for(int i = 0; i < n_intervals; i++)
		ans += (diff / 2.0 ) * (func(a + i * diff) + func(a + (i + 1) * diff));
	
	return ans;
} 


double integration_simpson_one_third_rule(
	double (* func) (double),
	double a,
	double b,
	double n_intervals)
{
	double ans = 0;
	double diff = (b - a) / n_intervals;
	double temp = diff / 3;
	for(int i = 0; i < n_intervals + 1; i++)
		{
			if(i == 0 || i == n_intervals)
				ans += temp * func(a + i * diff);
			else if(i%2)
				ans += temp * 4 * func(a + i * diff);
			else
				ans += temp * 2 * func(a + i * diff);
		}
	return ans;
} 


double integration_simpson_three_eighth_rule(
	double (* func) (double),
	double a,
	double b,
	double n_intervals)
{
	double ans = 0;
	double diff = (b - a) / n_intervals;
	double temp =  3 * diff / 8;
	for(int i = 0; i < n_intervals + 1; i++)
		{
			if(i == 0 || i == n_intervals)
				ans += temp * func(a + i * diff);
			else if(i%3)
				ans += temp * 3 * func(a + i * diff);
			else
				ans += temp * 2 * func(a + i * diff);
		}
	return ans;
} 

// double test_func(double x)
// {
// 	return 2*x;
// }

// double test_func(double x)
// {
// 	 return 1 + x*x;
// }

double func(double x)
{
	return 1 / (1 + x*x);
}

int main()
{
	// Testing with linear function, should give exact results
	// cout<<integration_simpson_one_third_rule(test_func1, 0, 5, 500)<<endl;
	// cout<<integration_trapezoid_rule(test_func1, 0, 5, 500)<<endl;
	
	//Calculations at :
	//http://formulas.tutorvista.com/math/simpson-s-rule-formula.html
	// cout<<integration_simpson_three_eighth_rule(test_func2, 1, 5, 4)<<endl;

	int n_intervals = 10;
	cout<<"\nEvaluation with no of intervals : "<<n_intervals<<endl;
	cout<<"Trapezoidal            : "<<integration_trapezoid_rule(func, 0, 1, n_intervals)<<endl;
	cout<<"Simpson's one third    : "<<integration_simpson_one_third_rule(func, 0, 1, n_intervals)<<endl;
	cout<<"Simpson's three eighth : "<<integration_simpson_three_eighth_rule(func, 0, 1, n_intervals)<<endl;

	n_intervals = 100;
	cout<<"\nEvaluation with no of intervals : "<<n_intervals<<endl;
	cout<<"Trapezoidal            : "<<integration_trapezoid_rule(func, 0, 1, n_intervals)<<endl;
	cout<<"Simpson's one third    : "<<integration_simpson_one_third_rule(func, 0, 1, n_intervals)<<endl;
	cout<<"Simpson's three eighth : "<<integration_simpson_three_eighth_rule(func, 0, 1, n_intervals)<<endl;

	n_intervals = 200;
	cout<<"\nEvaluation with no of intervals : "<<n_intervals<<endl;
	cout<<"Trapezoidal            : "<<integration_trapezoid_rule(func, 0, 1, n_intervals)<<endl;
	cout<<"Simpson's one third    : "<<integration_simpson_one_third_rule(func, 0, 1, n_intervals)<<endl;
	cout<<"Simpson's three eighth : "<<integration_simpson_three_eighth_rule(func, 0, 1, n_intervals)<<endl;
	
	cout<<endl<<"Expected : 0.78539816339 \n\nSimpson's one third worked best in all the cases.\n\n\n";
	// 0.78539816339
	return 0;
}

