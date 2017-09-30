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

inline double f1(double x) { return atan(x); }

int main()
{
/*
Part 1 of q1
*/
	vector<vector<double> > dp_table_1 = newton_interpolation_table_maker(
											f1, 0, 6, 11);
	cout<<"\n Find the Newton’s forward interpolating polynomial of degree 10 that interpolates the";
	cout<<"\n function atan at 11 equally spaced points in the interval [0,6]. Print the coefficients";
	cout<<"\n of the polynomial.\n";
	
	for(int i=0; i<11; i++)
		cout<<"\nCoefficients of x^"<<i<<" are : "<<dp_table_1[0][i];
	cout<<"\n\n";





/*
Part 2 of q1
*/
	cout<<"Compute and print the difference between the polynomial and the";
	cout<<"	function at 33 equally spaced points in the interval ";
	cout<<"[0, 8]. What conclusion can be drawn?";
	vector<vector<double> > dp_table_2 = newton_interpolation_table_maker(
											f1, 0, 8, 33);
	double diff = (double)8 / 32;
	for(int i=0; i<33; i++)
	{	
		double x =  0 + diff * i;
		double actual = f1(x);
		double predicted = newton_interpolation_predictor(0, 8, 33, dp_table_2, x);
		cout<<"\nDifference in actual and predicted is : ";
		std::cout.precision(8);
		std::cout.setf( std::ios::fixed, std:: ios::floatfield );
		cout<<x<<" "<<actual<<" "<<predicted<<" "<<(predicted - actual);
	}
	cout<<"\n\n";
	
	cout<<"Conclusion : The result is very good and with 33 pointswe were able to get error < 1e^-5\n\n";
	return 0;
}

