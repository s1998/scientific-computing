#include <bits/stdc++.h>
using namespace std;

void newton_imaginary(
	double (*g)(double, double), 
	double (*gx)(double, double), 
	double (*gy)(double, double), 
	double (*h)(double, double), 
	double (*hx)(double, double), 
	double (*hy)(double, double), 
	double x1,
	double y1)
{
	double tol = 0.00000000001;
	double x = x1;
	double y = y1;
	double gxy = g(x, y);
	double hxy = h(x, y);
	double gxy_x = gx(x, y);
	double hxy_x = hx(x, y);
	double gxy_y = gy(x, y);
	double hxy_y = hy(x, y);

	int max_iters = 1000;
	int iter = 0;
	while(abs(gxy) > tol || abs(hxy) > tol)
	{
		iter++;
		gxy_x = gx(x, y);
		hxy_x = hx(x, y);
		gxy_y = gy(x, y);
		hxy_y = hy(x, y);
		x = x - (gxy*hxy_y - hxy*gxy_y) / (gxy_x*hxy_y - hxy_x*gxy_y);
		y = y - (hxy*gxy_x - gxy*hxy_x) / (gxy_x*hxy_y - hxy_x*gxy_y);
		gxy = g(x, y);
		hxy = h(x, y);
		
		cout<<endl<<"Iterations, x, y, g(x, y), h(x, y) : "<<iter<<" "<<x<<" "<<y<<" "<<gxy<<" "<<hxy;
		if(iter > max_iters)
			break;
	}
	cout<<endl<<"With newton method function converged ";
	cout<<endl<<"within tolerance of 0.000001 in iterations, x, y, g(x, y), h(x, y) : "<<iter<<" "<<x<<" "<<y<<" "<<gxy<<" "<<hxy;
	cout<<endl<<endl;
	return ;
}

double g(double x, double y)
{
	return 2*x*x*x - 6*x*y*y -6*x + 6*y -6;
}

double gx(double x, double y)
{
	return 6*x*x - 6*y*y -6;
}

double gy(double x, double y)
{
	return -12*x*y + 6;
}

double h(double x, double y)
{
	return -2*y*y*y + 6*x*x*y - 6*y -6*x + 6;
}

double hx(double x, double y)
{
	return 12*x*y - 6;
}

double hy(double x, double y)
{
	return -6*y*y + 6*x*x -6 ;
}

int main()
{
	newton_imaginary(g, gx, gy, h, hx, hy, 1, 1);
	return 0;
}


