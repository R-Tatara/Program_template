#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma warning(disable:4996)

//Client of TCP/IP communication
int main() {
	struct sockaddr_in dstAddr;
	int dstSocket; //�|�[�g�ԍ�
	char destination[32] = "127.0.0.1"; //IP �A�h���X
	char request[1024] = "\0";
	char response[1024];

	int i;
	int res1;
	float res2;

	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(9876);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(destination);
	//dstAddr.sin_addr.s_addr = inet_pton(destination);
	dstSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (connect(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))) {
		printf("%s�@�ɐڑ��ł��܂���ł���\n", destination);
		return(-1);
	}

	puts("�ڑ��J�n");

	while (1) {		
		send(dstSocket, request, 1024, 0); //�p�P�b�g�̑��M		
		recv(dstSocket, response, 1024, 0); //�p�P�b�g�̎�M
		i = sscanf_s(response, "%d,%f", &res1, &res2);
		//printf("Response : %s\n\n", response);
		printf("Response : %d,%f\n", res1, res2);
	}

	closesocket(dstSocket);
	WSACleanup();
	return(0);
}