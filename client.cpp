#include<stdio.h>
#include<winsock2.h>
#include<conio.h>

#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
	//������� �����ϵ����͸� ����Ѵٰ� �̸� �˷���� ��
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2, 2), &wsa_data);

	//AF_INET = ������ ���ͳݿ��� ���
	//SOCK_STREAM = TCP�� ���
	//���� ���� ����
	SOCKET Sckt = socket(AF_INET, SOCK_STREAM, 0);

	//������ IP�ּҿ� port ��ȣ�� �ʿ�
	SOCKADDR_IN server_info;
	server_info.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");// ���� �� ip�ּҷ� �� �ּ�(���߿� ���� �ּҰ� ��)
	server_info.sin_port = htons(9876);					//��Ʈ��ȣ
	server_info.sin_family = AF_INET;					//�������� ü��

	printf("������ �����Ϸ� �մϴ�.\n");

	int state = connect(Sckt, (struct sockaddr*)&server_info, sizeof(server_info));
	
	if (state == -1) {
		printf("������ ������ �� �����ϴ�.\n");
		closesocket(Sckt);

		_getch();
		return -1;
	}

	printf("������ �����߽��ϴ�.\n");
	closesocket(Sckt);

	WSACleanup();

	_getch();

	return 0;

}