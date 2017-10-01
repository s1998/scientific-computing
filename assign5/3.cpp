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
	vector<double> x(41), fx(41);
	for(int i = 0; i < 41; i++)
	{
		x[i] = -5 + 10 * (double)i / 40;
		fx[i] = func(x[i]);
	}

	vector<vector<double> > coefficients = cubic_spline_generator_natural(x, fx);

	double new_x;
	double total_error = 0;
	for(int i = 0; i < 101; i++)
	{
		new_x = 0 + 5 * (double)i / 100;
		double fx_new = func(new_x);
		double sx_new = cubic_spline_predictor_natural(
							coefficients,
							x,
							new_x);
		std::cout.precision(8);
		std::cout.setf( std::ios::fixed, std:: ios::floatfield );
		cout<<"\nThe difference in actual and predicted is (actual predicted difference): ";
		cout<<fx_new<<" "<<sx_new<<" "<<(fx_new - sx_new);
		total_error += abs(fx_new - sx_new);
	}

	cout<<"\nTotal error : "<<total_error<<"\n\n";
	
	return 0;
}






