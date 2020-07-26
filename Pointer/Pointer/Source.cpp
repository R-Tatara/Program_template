#include <iostream>
using namespace std;

#define SIZE 2

//�ϐ�
void function1(int arg) { //�l�n��
    arg = 1;
}

void function2(int *arg) { //�|�C���^�n��
    *arg = 1;
}

void function3(int &arg) { //�Q�Ɠn��
    arg = 2;
}

//�z��
void function4(int argarray[]) { //�A�h���X�n���i�l�n���̂Ƃ���const��t����j
//void function4(int argarray[SIZE]) { //����
//void function4(int *argarray) { //����
    argarray[0] = 1;
    //*(argarray) = 1; //����
    argarray[1] = 2;
    //*(argarray + 1) = 2; //����
}

//�������z��
void function5(int argarray[SIZE][SIZE]) { //�A�h���X�n��
//void function5(int argarray[][SIZE]) { //����
//void function5(int (*argarray)[SIZE]) { //����
    argarray[1][1] = 1;
    //(*(argarray + 1))[1] = 1; //����
}

void function6(int argarray[SIZE][SIZE][SIZE]) { //�A�h���X�n��
//void function6(int argarray[][SIZE][SIZE]) { //����
//void function6(int (*argarray)[SIZE][SIZE]) { //����
    argarray[1][1][1] = 1;
    //(*(argarray + 1))[1][1] = 1; //����
}

//�\����
typedef struct {
    int val;
}structname;

void function7(structname argstruct) { //�l�n��
    argstruct.val = 1;
}

void function8(structname *argstruct) { //�A�h���X�n��
    argstruct->val = 1;
}

void function9(structname argstruct[]) { //�A�h���X�n���i�l�n���̂Ƃ���const��t����j
//void function9(structname argstruct[SIZE]) { //����
//void function9(structname *argstruct) { //����
    argstruct[0].val = 3;
    argstruct[1].val = 3;
}

int main() {
    //�ϐ�
    int val = 0;
    function1(val);
    cout << val << endl; //0
    function2(&val);
    cout << val << endl; //1
    function3(val);
    cout << val << endl; //2

    //�z��
    int array[SIZE] = {};
    function4(array);
    cout << array[0] << ", " << array[1] << endl; //1, 2

    //�������z��
    int array2[SIZE][SIZE] = {};
    function5(array2);
    cout << array2[0][0] << ", " << array2[0][1] << ", " << array2[1][0] << ", " << array2[1][1] << endl; //0, 0, 0, 1

    int array3[SIZE][SIZE][SIZE] = {};
    function6(array3);
    cout << array3[1][1][1] << endl; //1

    //�\����
    structname hoge;
    structname *phoge = &hoge;
    hoge.val = 0;
    function7(hoge);
    cout << hoge.val << endl; //0
    function8(&hoge);
    //function8(phoge); //����
    cout << hoge.val << endl; //1

    //�\���̔z��
    structname huga[SIZE] = {2, 2};
    function9(huga);
    cout << huga[0].val << "," << huga[1].val << endl; //3, 3

    return 0;
}


