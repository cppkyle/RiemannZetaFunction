#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

complex<long double> RiemannZeta(complex<long double> in, int range) {
	complex<long double> sum(0,0);
      
	for (int i = 1; i <= range; i++) {
		sum  += pow(pow((long double)i, in), complex<long double>(-1,0));
	}

	return sum;
}

void bruteForce(long double realRange, long double imagRange, long double realStep, long double imagStep);

void input() {
	long double r, i;
	printf("Enter real part: ");
	scanf("%Lf", &r);
	printf("Enter imaginary part: ");
	scanf("%Lf", &i);
	complex<long double> z = RiemannZeta(complex<long double>(r, i), 1000);
	printf("%.50Lf%+.50Lfi\n", real(z), imag(z));
	return;
}

void inputBrute() {
	long double rr, ri, sr, si;
	printf("Enter real range: ");
	scanf("%Lf", &rr);
	printf("Enter imaginary range: ");
	scanf("%Lf", &ri);
	printf("Enter real step: ");
	scanf("%Lf", &sr);
	printf("Enter imaginary step: ");
	scanf("%Lf", &si);
	bruteForce(rr, ri, sr, si);
	return;
}

long double hypotenuse(long double x, long double y) {
	// Calculates Hypotenuse for (0,0) and (x,y)
	return sqrt(pow(x, 2) + pow(y, 2));
}

void bruteForce(long double realRange, long double imagRange, long double realStep, long double imagStep) {
	complex<long double> closestSum(1000, 0);
	long double closestRealParameter, closestImagParameter;
	long double closestDistanceFromZero = 1000;
	for (long double r = -realRange; r <= realRange; r += realStep) {
		for (long double i = -imagRange; i <= imagRange; i += imagStep) {
			complex<long double> nowSum = RiemannZeta(complex<long double>(r, i), 1000);
			long double distanceFromZero = hypotenuse(real(nowSum), imag(nowSum));
			//printf("[DEBUG] %.50Lf%+.50Lfi\n[DEBUG] %.50Lf%+.50Lfi\n[DEBUG] %.50Lf\n\n", real(nowSum), imag(nowSum), r, i, distanceFromZero);
			if (closestDistanceFromZero > distanceFromZero) {
				closestRealParameter = r;
				closestImagParameter = i;
				closestSum = nowSum;
				closestDistanceFromZero = distanceFromZero;
			}
		}
	}
	printf("Closest Sum to 0 is: %.50Lf%+.50Lfi\nWith parameter: %.50Lf%+.50Lfi\n", real(closestSum), imag(closestSum), closestRealParameter, closestImagParameter);
	return;
}

int main(int argc, char *argv[])
{
// Using printf() for continuity
       char in;
	printf("[1] Riemann Function\n[2] Brute Force (Find 0)\nInput: ");
      scanf("%c", &in);
      if (in == '1') {
      input();
     } else if (in == '2') {
      inputBrute();
     } else {
       printf("Input valid value!\n");
       return 0;
    }
      
}
