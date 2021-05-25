/* 
 * [2019117662] [박수환] 저는 이 소스 코드를 다른 소스 코드를 복사하지 않고 직접 작성하였습니다. 
 */

#include <stdio.h>
#include <math.h>
#define MAX 256 
#define BASE 10

typedef struct la {
	int sign;
	int len;
	int digits[MAX];
} la;
int count;
int con[MAX];
int fin[MAX];
const int threshold = 1;

void create(la u, char *str);
int compare(la u, la v);
void lsum (la u, la v, la &r);
void ldiff (la u, la v, la &r);
void ladd (la &u, la &v, la &r);
void lsub (la u, la v, la &r);
void lmult(la u, la v, la &r);
void pow(la u, int m, la &v);
void div(la u, int m, la &v);
void rem(la u, int m, la &v);

int main(){

	int t;
	la u, v;
	char *str;

	scanf("%d", &t);
	for(int k=1; k<=t; k++){			// 테스트 개수 

		scanf("%s", &str);
		create(u, str);
		scanf("%s", &str);


		prod2(u, v, r);
		con[k] = count;
		fin[k] = 

	}

	for(int k=1; k<=t; k++){

		printf("%d ", con[k]);
		for(int i=0; i<n; i++){			// r배열 출력
			printf("%d", r[i]);
		}
		printf("\n");
	}
	return 0;
}

void prod2(la u, la v, la &r) {

	++count;		// 횟수 추가

	la x, y, w, z, t1, t2, t3, t4, t5, t6, t7, t8;
	int n, m;
	n = (u.len > v.len) ? u.len : v.len;
	if (u.len == 0 && v.len == 0)
		r.sign = r.len = 0;
	else if (n <= threshold)
		lmult(u, v, r);
	else {
		int m = n / 2;
		div(u, m, x); rem(u, m, y);
		div(v, m, w); rem(v, m, z);
		prod2(x, w, t1); pow(t1, 2*m, t2);
		prod2(x, z, t3); prod2(w, y, t4); ladd(t3, t4, t5); pow(t5, m, t6);
		prod2(y, z, t7);
		ladd(t2, t6, t8); ladd(t8, t7, r);

	}
}

void create(la u, char *str){
	if (str[0] == '-'){
		u.sign = 
	}
}
int compare(la u, la v){
	if (u > v) {
		return 1;
	}else if (u < v) {
		return -1;
	}else {
		return 0;
	}
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
}
void ladd (la &u, la &v, la &r){
	if (u.sign == v.sign) {
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
				r.sign = r.len = 0;
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
}
void pow(la u, int m, la &v){
	v.sign = u.sign;
	v.len = u.len + m;
	for (int i = 0; i < m; i++)
		v.digits[i] = 0;
	for (int i = 0; i < u.len; i++)
		v.digits[m + i] = u.digits[i];
}
void div(la u, int m, la &v){
	v.sign = u.sign;
	v.len = u.len - m;
	for (int i = 0; i < u.len; i++)
		v.digits[i] = u.digits[m + i];
}
void rem(la u, int m, la &v){
	v.sign = 1;
	v.len = m;
	for (int i = 0; i < m; i++)
		v.digits[i] = u.digits[i];
}

