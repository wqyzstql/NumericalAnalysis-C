// 霍纳法求多项式F(x)=c1+c2x+c3x^2+...+cn-x^(n-1)
// F(x)=c1+x(c2+x(c3+...+x(cn)))

#include <iostream>
#include <vector>

using namespace std;

double nest(int d, vector<double> c, double x, const vector<double> b = { 0 }) {
	bool is_b = 0;
	if (b.size() == c.size() - 1) {
		is_b = 1;
	}
	double y = c[d], tmp = (is_b) ? b[d - 1] : 0;
	y *= (x - tmp);
	for (int i = d - 1; i >= 0; i--) {
		y = y + c[i];
		if (i != 0) {
			tmp = (is_b) ? b[i - 1] : 0;
			y *= (x - tmp);
		}
	}
	return y;
}

int main() {
	int d = 3;
	vector<double> c(d + 1, 0);
	c = { 1, 1.0 / 2, 1.0 / 2, -1.0 / 2};
	double x = 1.0;
	cout << nest(d, c, x, {0, 2, 3});
	return 0;
}
