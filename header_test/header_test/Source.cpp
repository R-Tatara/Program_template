#include <iostream>
#include "Header.h"

//Header.h���C���N���[�h����΁C���ʂ̕ϐ��Ƃ��Ďg�p�\
int val_h;
//Header.h���C���N���[�h����΁C���ʂ̃I�u�W�F�N�g�Ƃ��Ďg�p�\?
MyClass myclass;

int main() {
	int macro = MACRO;
	myclass.val_c = 200;
	int ret1, ret2;
	ret1 = Func_p();
	ret2 = Func_h();

	std::cout << macro << std::endl;
	std::cout << myclass.val_c << std::endl;
	std::cout << ret1<< std::endl;
	std::cout << ret2 << std::endl;

	getchar();
	return 0;
}

//Header.h���C���N���[�h����΁C���ʂ̊֐��Ƃ��Ďg�p�\
int Func_p() {
	return 300;
}