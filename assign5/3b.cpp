#include <bits/stdc++.h>
using namespace std;

vector<vector<double> > newton_interpolation_table_maker(
	double (*func)(double),
	double a,
	double b,
	int points)
{
	double diff = (b - a) / (points - 1);
	vector<vector<double> > dp_table(points , vector<double> (points , 0)); 
	for(int col = 0; col < points; col++)
		for(int row = 0; row < (points - col); row++)
			// cout<<col<<" "<<row<<" \n",
			dp_table[row][col] = (col == 0) ? 
						func(a + diff * row ) : 
						(dp_table[row+1][col-1] - dp_table[row][col-1]) / (col * diff);
	return dp_table;
}

double newton_interpolation_predictor(
	double a,
	double b,
	int points,
	vector<vector<double> >const &dp_table,
	double x)
{
	double diff = (b - a) / (points - 1);
	double ans = 0;
	for(int i = 0; i<points; i++)
		{	
			double temp = dp_table[0][i];
			for(int j = 0; j<i; j++)
				temp *= (x - (a + diff*j));
			ans += temp;
		}
	return ans;
}

inline double func(double x)
{
	return 1 / (1 + x*x);
}

int main()
{
	vector<vector<double> > dp_table = newton_interpolation_table_maker(
											func, -5, 5, 41);
	double diff = (double)5 / 100;
	for(int i=0; i<100; i++)
	{	
		double x =  0 + diff * i;
		double actual = func(x);
		double predicted = newton_interpolation_predictor(-5, 5, 41, dp_table, x);
		cout<<"\nDifference in actual and predicted is (x, actual, predicted, difference): \n";
		std::cout.precision(8);
		std::cout.setf( std::ios::fixed, std:: ios::floatfield );
		cout<<x<<" "<<actual<<" "<<predicted<<" "<<(predicted - actual);
	}

	cout<<"\n\nBecause of its oscillation property (low at -5, high at 0 and again low at 5)\n";
	cout<<" the divided difference polynomial is not \n";
    cout<<"suitable to interpolate the given data. The common \n";
    cout<<"cubic spline interpolation leads to a smoother interpolation.";
	cout<<"\n\n";
	
	return 0;
}







