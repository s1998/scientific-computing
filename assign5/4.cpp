#include <bits/stdc++.h>
using namespace std;

// Generates the coefficients for cubic spline natural
vector<vector<double> > cubic_spline_generator_natural(
	vector<double>& x,
	vector<double>& fx)
{
	// n -> no of points - 1, n intervals
	int n = x.size()-1;
	vector<double> h(n+1), alpha(n+1), l(n+1), u(n+1), z(n+1);
	vector<double> a(n+1), b(n+1), c(n+1), d(n+1);
	
	for(int i=0; i<=n; i++)
		a[i] = fx[i];

	for(int i = 0; i < n; i++)
		h[i] = x[i+1] - x[i];

	for(int i = 1; i < n; i++)
		alpha[i] = 3 * (a[i+1] - a[i]) / h[i] - 3 * (a[i] - a[i-1]) / h[i-1];

	l[0] = 1, u[0] = 0, z[0] = 0;
	for(int i = 1; i < n; i++)
	{
		l[i] = 2 * (x[i+1] - x[i-1]) - h[i-1] * u[i-1];
		u[i] = h[i] / l[i];
		z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
	}
	l[n] = 1, z[n] = 0, c[n] = 0;

	for(int i = n-1; i >= 0; i--)
	{
		c[i] = z[i] - u[i] * c[i+1];
		b[i] = (a[i+1] - a[i]) / h[i] - h[i] * (c[i+1] + 2*c[i]) / 3;
		d[i] = (c[i+1] - c[i]) / (3*h[i]);
	}

	vector<vector<double> > ans (4, vector<double>(n));
	for(int i = 0; i < n; i++)
		ans[0][i] = a[i], ans[1][i] = b[i], ans[2][i] = c[i], ans[3][i] = d[i];

	return ans;

}

inline double func(double x)
{
	return 1 / (1 + x*x);
}

double cubic_spline_predictor_natural(
	vector<vector<double> >& coefficients,
	vector<double>& initial_points,
	double x)
{
	int intervals = initial_points.size() - 1;
	double a = initial_points[0];
	double b = initial_points[initial_points.size() - 1];
	double diff = (b - a) / intervals;
	int interval = floor((x - a) / diff)-1;

	double ai = coefficients[0][interval], 
	       bi = coefficients[1][interval],
	       ci = coefficients[2][interval],
	       di = coefficients[3][interval],
	       xi = initial_points[interval],
	       h  = x - xi;
	// cout<<endl<<x<<" "<<interval<<" "<<intervals<<" "<<ai<<" "<<bi<<" "<<ci<<" "<<di<<" "<<xi<<" "<<h<<endl;
	return ai + bi * h + ci * h * h + di * h * h * h;
}


int main()
{
	vector<double> x = {0, 3, 5, 8, 13};
	vector<double> dx = {0, 255, 383, 623, 993};
	vector<double> sx = {75, 77, 80, 74, 72};
	vector<vector<double> > coefficients_d = cubic_spline_generator_natural(x, dx);
	vector<vector<double> > coefficients_s = cubic_spline_generator_natural(x, sx);

	double d_10 = cubic_spline_predictor_natural(
							coefficients_d,
							x,
							10);
	
	double s_10 = cubic_spline_predictor_natural(
							coefficients_s,
							x,
							10);

	cout<<"Distance and speed at t = 10 : "<<d_10<<" "<<s_10<<endl;
	return 0;
}





