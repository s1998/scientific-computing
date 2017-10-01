#include <bits/stdc++.h>
using namespace std;

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

double func1 (double x)
{
	return 1 / (1 + x*x);
}

double func2 (double x)
{
	return sqrt(1 - x*x) - x;
}

int main()
{
	double error = 1;

	int n_intervals = 0;
	cout<<"\nIntegrating for func1\n";
	while(error > 5 * 1e-6)
	{
		n_intervals++;
		error = abs(3.14159265359 - 
					4 * integration_simpson_one_third_rule(func1, 0, 1, n_intervals));
		cout<<endl<<"No of intervals and error : "<<n_intervals<<"  "<<error;
	}

	error = 1;
	cout<<"\n\n\nIntegrating for func2\n";
	n_intervals = 0;
	while(error > 5 * 1e-6)
	{
		n_intervals++;
		error = abs(3.14159265359/8 - 
					integration_simpson_one_third_rule(func2, 0, 1.0 / sqrt(2.0), n_intervals));
		cout<<endl<<"No of intervals and error : "<<n_intervals<<"  "<<error;
	}

	cout<<"\n\nGraphs are present as 2a and 2b\n\n\n";
	return 0;
}
