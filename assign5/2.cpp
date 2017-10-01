#include <bits/stdc++.h>
using namespace std;

vector<double> thomas_tridiagonal_solver(
	vector<double>& d1,
	vector<double>& d2,
	vector<double>& d3,
	vector<double>& o)
{
	int no_of_vars = d1.size();
	assert(d1[0] == 0 && d3[no_of_vars-1] == 0);
	assert(d1.size() == d2.size() && d2.size() == d3.size());

	for(int i = 1; i < no_of_vars; i++)
	{
		double factor = d1[i] / d2[i-1];
		d1[i] -= d2[i-1] * factor;
		d2[i] -= d3[i-1] * factor;
		o[i]  -= o[i-1]  * factor;
		cout<<d1[i]<<" "<<d2[i]<<" "<<d3[i]<<" "<<o[i]<<endl;
	}

	vector<double> ans(no_of_vars);
	for(int i = no_of_vars-1; i>=0; i--)
	{
		ans[i] = (i == no_of_vars-1) ?
				  o[i] / d2[i]:
				  (o[i] - ans[i+1] * d3[i]) / d2[i]; 
	}
	return ans;
}

int main()
{
	/*
	 Small test : 
	 3 vars : -1, 0, 1
	*/
	// vector<double> d1{0, 3, 4};
	// vector<double> d2{1, 4, 5};
	// vector<double> d3{2, 5, 0};
	// vector<double> o{-1, 2, 5};

	// vector<double> ans = thomas_tridiagonal_solver(d1, d2, d3, o);
	// for(int i = 0; i<3; i++)
	// 	cout<<" Ti = "<<ans[i];
	// cout<<"\n\n";

	return 0;
}

