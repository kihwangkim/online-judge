


#include <stdio.h>


#define LEN 40

#define PUSH(x) (stack[++sp] = x)
#define POP() stack[sp--]
#define TOP() (sp == -1 ? empty : stack[sp])

struct node {
	char oper;
	int num;
	int flag;
	// 0 -> oper
	// 1 -> num
	
	inline bool operator==(struct node a) {
		if (oper == a.oper && num == a.num && flag == a.flag)
			return true;
		else
			return false;
	}
};

struct node empty = {0, 0, -1};

struct node stack[LEN];
int sp = -1;

int main() {

	char str[LEN];
	int dummy;

	dummy = scanf("%s", str);

	for (int i = 0; i < LEN; i++) {
		char c = str[i];
		if (c == '\0' || c == '\n') break;

		if (c == '(' || c == '[') {
			struct node n;
			n.oper = c;
			n.flag = 0;
			PUSH(n);
		}
		else if (c == ')') {
			struct node n = POP();
			if (n == empty) goto error;
			struct node k;
			if (n.flag == 0 && n.oper == '(') {
				k.flag = 1;
				k.num = 2;
			}
			else if (n.flag == 1) {
				k.flag = 1;
				k.num = n.num * 2;
				struct node l = POP();
				if (l == empty) goto error;
				if (l.flag == 0 && l.oper == '(') {
				}
				else goto error;
			}
			else goto error;
			
			if (TOP().flag == 1) {
				struct node l = POP();
				if (l == empty) goto error;
				k.num = l.num + k.num;
			}

			PUSH(k);
		}
		else if (c == ']') {
			struct node n = POP();
			if (n == empty) goto error;
			struct node k;
			if (n.flag == 0 && n.oper == '[') {
				k.flag = 1;
				k.num = 3;
			}
			else if (n.flag == 1) {
				k.flag = 1;
				k.num = n.num * 3;
				struct node l = POP();
				if (l == empty) goto error;
				if (l.flag == 0 && l.oper == '[') {
				}
				else goto error;
			}
			else goto error;
			
			if (TOP().flag == 1) {
				struct node l = POP();
				if (l == empty) goto error;
				k.num = l.num + k.num;
			}

			PUSH(k);
		}
	}

	if (sp == 0 && TOP().flag == 1)
		printf("%d\n", TOP().num);
	else
		goto error;

	return 0;

error:
	printf("0\n");
	return 0;
}



