#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef unsigned int uint;

typedef struct{
	int member;
	char str[16];
}structname;

//�񐄏��i�錾��struct���K�v�Ȃ��߁j
//struct structname1 {
//	int member;
//};

void function(structname arg1, structname *arg2);

structname A = {1, "hoge1"};
structname B;
structname tmpC;
structname *C = &tmpC;
structname D[2];

int main() {
	B.member = 2;
	sprintf(B.str, "hoge2");
	C->member = 3;
	sprintf(C->str, "hoge3");
	D[0].member = 4;
	sprintf(D[0].str, "hoge4");

	function(A, &A);

	printf("A : %d %s\n", A.member, A.str);
	printf("B : %d %s\n", B.member, B.str);
	printf("C : %d %s\n", C->member, C->str); //C->member = (*C).member
	printf("D : %d %s\n", D[0].member, D[0].str);
	return 0;
}

void function(structname arg1, structname *arg2) {
	arg1.member = 0; //�l�n��
	sprintf(arg2->str, "hoge0"); //�Q�Ɠn��

	return;
}
