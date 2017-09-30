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

double g1(double x, double y)
{
	return x*x*x -3*x*y*y - x - 1;
}

double gx1(double x, double y)
{
	return 3*x*x - 3*y*y -1;
}

double gy1(double x, double y)
{
	return -6*x*y;
}

double h1(double x, double y)
{
	return -y*y*y + 3*x*x*y -y;
}

double hx1(double x, double y)
{
	return 6*x*y;
}

double hy1(double x, double y)
{
	return -3*y*y + 3*x*x -1 ;
}


double g2(double x, double y)
{
	return 2*x*x*x - 6*x*y*y -6*x + 6*y -6;
}

double gx2(double x, double y)
{
	return 6*x*x - 6*y*y -6;
}

double gy2(double x, double y)
{
	return -12*x*y + 6;
}

double h2(double x, double y)
{
	return -2*y*y*y + 6*x*x*y - 6*y -6*x + 6;
}

double hx2(double x, double y)
{
	return 12*x*y - 6;
}

double hy2(double x, double y)
{
	return -6*y*y + 6*x*x -6 ;
}

int main()
{
	newton_imaginary(g1, gx1, gy1, h1, hx1, hy1, 1, 1);
	newton_imaginary(g1, gx1, gy1, h1, hx1, hy1, 1, 0);
	newton_imaginary(g1, gx1, gy1, h1, hx1, hy1, 1, -1);
	newton_imaginary(g2, gx2, gy2, h2, hx2, hy2, 1, 1);
	return 0;
}


