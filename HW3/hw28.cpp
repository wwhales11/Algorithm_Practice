/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAX 256 
#define BASE 10

using namespace std;

typedef struct la {
	int sign;	// 음수는 1, 양수는 0
	int len;
	int digits[MAX];
} la;

int count;
const int threshold = 1;

void create(la &u, char *str);
int compare(la u, la v);
void prod2(la u, la v, la &r);
void lsum(la u, la v, la &r);
void ldiff(la u, la v, la &r);
void ladd(la u, la v, la &r);
void lsub(la u, la v, la &r);
void lmult(la u, la v, la &r);
void pow1(la u, int m, la &v);
void div(la u, int m, la &v);
void rem(la u, int m, la &v);

int main(){

	int t;
	char *str;
	la u, v, r;
	la inputA[MAX];
	la inputB[MAX];

	cin >> t;
	for(int k=0; k<t; k++){			// 테스트 개수 
		str = (char *) malloc(MAX);
		cin >> str;
		create(u, str);
		inputA[k] = u;
		free(str);

		str = (char *) malloc(MAX);
		cin >> str;
		create(v, str);
		inputB[k] = v;
		free(str);
	}
	for(int k=0; k<t; k++){			// 테스트 개수 
		prod2(inputA[k], inputB[k], r);

		cout << count << " ";
		if (r.sign == 1 && !(u.sign == 1 && v.sign == 1)){
			cout << "-";
		}

		for (int i = r.len - 1; i>=0; i--){
			cout << r.digits[i];
		}
		cout << "\n";
		count = 0;
	}
	return 0;
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
	if (u.len == 2){
		swap(str[0], str[1]);
	}else{
		for (int i=0; i<((u.len-1)/2); i++){
			swap(str[i], str[u.len-1-i]);
		}
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
}
int compare(la u, la v){		// 절대값으로 비교
	if (u.len > v.len){		// 숫자길이로 먼저 비교
		return 1;
	}else if (u.len < v.len) {
		return -1;
	}else{
		for (int i=u.len - 1; i>=0; i--){ 	// 큰자리부터 비교
			if (u.digits[i] > v.digits[i]) {
				return 1;
			}else if (u.digits[i] < v.digits[i]) {
				return -1;
			}
		}
		return 0;
	}
}
void prod2(la u, la v, la &r){

	++count;		// 횟수 추가
	cout << "Prod2 : " << count << endl;
	cout << "len : " << " u.len = " << u.len << " v.len = " << v.len << endl;
	cout << "digits : ";
	for (int i = 0; i < u.len; i++)
		cout << u.digits[i];
	cout << "  ";
	for (int i = 0; i < v.len; i++)
		cout << v.digits[i];
	cout << endl;

	la x, y, w, z, e, p, q, t1, t2, t3, t4, t5, t6, t7; 
	e.len = e.sign = p.len = p.sign = q.len = q.sign = 0;
	int n, m;
	n = (u.len > v.len) ? u.len : v.len;
	cout << "n = " << n << endl;
	if (u.len == 0 && v.len == 0){
		r.sign = r.len = 1;
		r.digits[0] = 0;
	}
	else if (n <= threshold)
		lmult(u, v, r);
	else {
		if (((u.len == 1) && (u.digits[0] == 0)) || ((v.len == 1) && (v.digits[0] == 0))){
			if (count > 30) {
			cout << "u.len = " << u.len << "  v.len = " << v.len << endl;

			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++else return" << endl;
			r.sign = r.len = 1;
			r.digits[0] = 0;
			return;
			}
		}
		m = n / 2;
		div(u, m, x); rem(u, m, y);
		div(v, m, w); rem(v, m, z);
		cout << "making e ------------- " << endl;
		ladd(x, y, t1); ladd(w, z, t2);
		//if (!(t1.len == 0 || t2.len == 0)) return;
			prod2(t1, t2, e);
		cout << "making p ------------- " << endl;
		//if (!(x.len == 0 || w.len == 0)) return;
			prod2(x, w, p);
		cout << "making q ------------- " << endl;
		//if (!(y.len == 0 || z.len == 0)) return;
			prod2(y, z, q);
		cout << "making Result ------------- " << endl;
		pow1(p, 2*m, t3); lsub(e, p, t4); lsub(t4, q, t5); 
		pow1(t5, m, t6); ladd(t3, t6, t7); ladd(t7, q, r);
	}
	cout << "OUT ------------- " << count << endl;
}
void lsum (la u, la v, la &r){
	int k = 0;
	while (k < u.len && k < v.len) {
		r.digits[k] = u.digits[k] + v.digits[k];
		k++;
	}
	for (; k < u.len; k++)
		r.digits[k] = u.digits[k];
	for (; k < v.len; k++)
		r.digits[k] = v.digits[k];
	int carry = 0, i = 0;
	for (; i < k; i++) {
		int d = r.digits[i] + carry;
		r.digits[i] = d % BASE;
		carry = d / BASE;
	}
	if (carry > 0)
		r.digits[i++] = carry;
	r.len = i;	
	if (r.len <= 0){
		r.len = 1;
		r.digits[0] = 0;
	}

	cout << "lsum : ";
	for (int i = 0; i < r.len; i++)
		cout << r.digits[i];
	cout << " || r.sign : " << r.sign << " " << r.len << endl;
}
void ldiff (la u, la v, la &r){
	int k = 0;
	while (k < u.len && k < v.len) {
		r.digits[k] = u.digits[k] - v.digits[k];
		k++;
	}
	for (; k < u.len; k++)
		r.digits[k] = u.digits[k];
	int borrow = 0, i = 0;
	for (; i < k; i++) {
		int d = r.digits[i] - borrow;
		r.digits[i] = (d >= 0) ? d: d + BASE;
		borrow = (d >= 0) ? 0: 1;
	}
	while (i > 0 && r.digits[i - 1] == 0)
		i--;
	r.len = i;
	if (r.len <= 0){
		r.len = 1;
		r.digits[0] = 0;
	}

	cout << "ldiff : ";
	for (int i = 0; i < r.len; i++)
		cout << r.digits[i];
	cout << " || r.sign : " << r.sign << " " << r.len << endl;
}
void ladd (la u, la v, la &r){
	if (u.sign == v.sign) {
		cout << "ladd : ";
		lsum(u, v, r);
		r.sign = u.sign;
	} else {
		switch (compare(u, v)) {
			case 1:
				ldiff(u, v, r);
				r.sign = u.sign;
				break;
			case -1:
				ldiff(v, u, r);
				r.sign = v.sign;
				break;
			case 0:
				r.sign = r.len = 1;
				r.digits[0] = 0;
				break;
		}
	}

}
void lsub(la u, la v, la &r){
	if (u.sign != v.sign) {
		cout << "lsub : ";
		lsum(u, v, r);
		r.sign = u.sign;
	} else {
		switch (compare(u, v)) {
			case 1:
				ldiff(u, v, r);
				r.sign = u.sign;
				break;
			case -1:
				ldiff(v, u, r);
				r.sign = v.sign;
				break;
			case 0:
				r.sign = r.len = 1;
				r.digits[0] = 0;
				break;
		}
	}

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
	if (r.len <= 0){
		r.len = 1;
		r.digits[0] = 0;
	}

	cout << "lmult : ";
	for (int i = 0; i < r.len; i++)
		cout << r.digits[i];
	cout << " || r.sign : " << r.sign << " " << r.len << endl;
}
void pow1(la u, int m, la &v){
	v.sign = u.sign;
	v.len = u.len + m;
	for (int i = 0; i < m; i++)
		v.digits[i] = 0;
	for (int i = 0; i < u.len; i++)
		v.digits[m + i] = u.digits[i];

	cout << "pow1 : ";
	for (int i = 0; i < v.len; i++)
		cout << v.digits[i];
	cout << " || v.sign : " << v.sign << " " << v.len << endl;
}
void div(la u, int m, la &v){
	v.sign = u.sign;
	v.len = u.len - m;
	for (int i = 0; i < v.len; i++)
		v.digits[i] = u.digits[m + i];

	if (v.len > 1) {
		for (int i = v.len - 1; i > 0; i--){
			if (v.digits[i] != 0) {
				break;
			}else{
				memmove(v.digits-1, v.digits-1, sizeof(int));
				v.len--;
			}
		}
	}
	if (v.len <= 0) {
		v.len = 1;
		v.digits[0] = 0;
	}
	cout << "div : ";
	for (int i = 0; i < v.len; i++)
		cout << v.digits[i];
	cout << " || v.sign : " << v.sign << " " << v.len << endl;
}
void rem(la u, int m, la &v){
	v.sign = u.sign;
	v.len = m;
	for (int i = 0; i < v.len; i++)
		v.digits[i] = u.digits[i];

	if (v.len > 1) {
		for (int i = v.len - 1; i > 0; i--){
			if (v.digits[i] != 0) {
				break;
			}else{
				memmove(v.digits-1, v.digits-1, sizeof(int));
				v.len--;
			}
		}
	}
	if (v.len <= 0) {
		v.len = 1;
		v.digits[0] = 0;
	}
	cout << "rem : ";
	for (int i = 0; i < v.len; i++)
		cout << v.digits[i];
	cout << " || v.sign : " << v.sign << " " << v.len << endl;
}
