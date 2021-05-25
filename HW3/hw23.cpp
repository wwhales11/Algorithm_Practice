#include <iostream>
#include <cstdlib>
#include <cstring>
#define BASE 10

using namespace std;

typedef struct la {
	int sign;
	int len;
	int digits[256];
} la;
void create(la &u, char *str);
void lmult(la u, la v, la &r);

int main(){

	char *str;
	la u, v, r;

		str = (char *) malloc(256);
		cin >> str;
		create(u, str);
		free(str);
		
		str = (char *) malloc(256);
		cin >> str;
		create(v, str);
		free(str);

		cout << "u.sign : " << u.sign << endl;
		cout << "u.len : " << u.len << endl;
		cout << "v.sign : " << v.sign << endl;
		cout << "v.len : " << v.len << endl;

		lmult(u, v, r);

		for (int i = r.len - 1; i>=0; i--){
			cout << r.digits[i];
		}
		cout << "\n";
return 0;
}
void lmult(la u, la v, la &r){
	r.sign = (u.sign == v.sign) ? u.sign: 1;
	r.len = u.len + v.len - 1;
	for (int i = 0; i < r.len; i++)
		r.digits[i] = 0;
	for (int i = 0; i < v.len; i++)
		for (int j = i; j < i + u.len; j++)
			r.digits[j] += v.digits[i] * u.digits[j];
	int carry = 0, i = 0;
	for (; i < r.len; i++) {
		int d = r.digits[i] + carry;
		r.digits[i] = d % BASE;
		carry = d / BASE;
	}
	if (carry > 0)
		r.digits[i++] = carry;
	r.len = i;

	cout << "lmult : " << r.sign << " " << r.len << endl;

	for (int i=0; i<r.len; i++){
		cout << r.digits[i];
	}
	cout << endl;
}
void create(la &u, char *str){
	u.sign = 0;
	u.len = (strlen(str));

	if (str[0] == '-'){		// str 배열 '-' 제거후 배열당기기 
		str[0] = 0;
		u.sign = 1;
		memmove(str-1, str, u.len);
		u.len -= 1;
	}
	for (int i=0; i<((u.len-1)/2); i++){
		swap(str[i], str[u.len-1-i]);
	}
	for (int i=0; i<u.len; i++){	// str 문자열 u 배열에 거꾸로 넣기
		if (str[i] == '0') u.digits[i] = 0; 
		if (str[i] == '1') u.digits[i] = 1;
		if (str[i] == '2') u.digits[i] = 2;
		if (str[i] == '3') u.digits[i] = 3;
		if (str[i] == '4') u.digits[i] = 4;
		if (str[i] == '5') u.digits[i] = 5; 
		if (str[i] == '6') u.digits[i] = 6; 
		if (str[i] == '7') u.digits[i] = 7;
		if (str[i] == '8') u.digits[i] = 8;
		if (str[i] == '9') u.digits[i] = 9;
	}
	for (int i=0; i<u.len; i++){
		cout << u.digits[i];
	}
	cout << endl;
}
