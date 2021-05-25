// r - p - q 큰정수 알고리즘 중간식 (xz + wy)

#include <iostream>
#include <cmath>

using namespace std;

int size(int data);

int main(){

	int a, b, x, y, w, z, m;

	cout << "큰정수 두개입력 : \n";
	cin >> a >> b;

	m =  size(a > b ? a : b) / 2;

	x = a / pow(10, m);
	y = a - (x * pow(10, m));
	w = b / pow(10, m);
	z = b - (w * pow(10, m));

	cout << "m = " << m << endl << endl;

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "w = " << w << endl;
	cout << "z = " << z << endl << endl;

	cout << "r (x+y)(w+z) = " << (x + y) * (w + z) << endl;
	cout << "p (xw) = " << x * w << endl;
	cout << "q (yz) = " << y * z << endl << endl;

	cout << "r - p - q (xz + wy) = " << (x * z) + (w * y) << endl;
}
int size(int data)
{
	int pos = 1, i;


	if (data < 0) data *= (-1);

	for (i = 0; ; i++, pos++)
	{
		if ((data /= 10) <= 0)
			break;
	}
	return(pos);
}
