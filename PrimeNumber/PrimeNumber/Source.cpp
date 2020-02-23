#include <math.h> 
#include <iostream> 

bool IsPrime(int num) {
	double sqrtNum = sqrt(num);

	 //��O����
	if (num < 2) {
		return false;
	}
	else if (num == 2) {
		return true;
	}
	//�����̏���
	else if (num % 2 == 0) {
		return false;
	}

	//��̏���
	for (int i = 3; i <= (int)sqrtNum; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	for (int i = 0; i < 1000; i++) {
		std::cout << i << "\t" << IsPrime(i) << std::endl;
	}
	return 0;
}