#include <bits/stdc++.h>
using namespace std;

double gaussian_quadratur_three_point(
	double (* func) (double),
	double a,
	double b)
{
	double t1 = 5 * func((a + b) / 2 - sqrt(3.0/5.0) * (b - a) / 2);
	double t2 = 8 * func((a + b) / 2);
	double t3 = 5 * func((a + b) / 2 + sqrt(3.0/5.0) * (b - a) / 2);

	return (b-a) * (t1 + t2 + t3) / 18;
} 

double gaussian_quadratur_three_point_n_int(
	double (* func) (double),
	double a,
	double b,
	double n_intervals)
{
	double ans = 0;
	double diff = (b - a) / n_intervals;
	for(int i = 0; i < n_intervals; i++)
		ans += gaussian_quadratur_three_point(func, a + i*diff, a + (i+1)*diff);
	return ans;
} 

double func1 (double x)
{
	return x*x*x*x*x;
}

double func2 (double x)
{
	return sin(x) / x;
}

int main()
{
	cout<<"\n\nQ3 part b q1 : ";
	cout<<"\nWith n = 1  : "<<gaussian_quadratur_three_point_n_int(func1, 0, 1, 1 );
	cout<<"\nWith n = 2  : "<<gaussian_quadratur_three_point_n_int(func1, 0, 1, 2 );
	cout<<"\nWith n = 10 : "<<gaussian_quadratur_three_point_n_int(func1, 0, 1, 10);
	

	cout<<"\n\nQ3 part b q2 : ";
	cout<<"\nWith n = 1  : "<<gaussian_quadratur_three_point_n_int(func2, 0, 1, 1 );
	cout<<"\nWith n = 2  : "<<gaussian_quadratur_three_point_n_int(func2, 0, 1, 2 );
	cout<<"\nWith n = 3  : "<<gaussian_quadratur_three_point_n_int(func2, 0, 1, 3 );
	cout<<"\nWith n = 4  : "<<gaussian_quadratur_three_point_n_int(func2, 0, 1, 4 );
	cout<<endl<<endl;
	return 0;
}
