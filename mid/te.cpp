#include <string>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int solution(int num) {
	long long n = num;
	int answer = 1;
	while (n != 1)
	{
		if (answer > INT_MAX) return -1;
		if (n & 1) n = (n * 3) + 1;
		else n /= 2;
		answer++;
	}
	return answer;
}
int main() {
	int min = INT_MAX;
	for (int i = 100; i < 1000; i++)
		if (solution(i) < min) 
			min = solution(i);

	cout <<	min << " ";

	cout << endl;

}
