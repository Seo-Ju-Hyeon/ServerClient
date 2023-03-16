#include<stdio.h>
#include<winsock2.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
	//������� �����ϵ����͸� ����Ѵٰ� �̸� �˷���� ��
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2, 2), &wsa_data);

	//AF_INET = ������ ���ͳݿ��� ���
	//SOCK_STREAM = TCP�� ���
	//���� ���� ����
	SOCKET serverSckt = socket(AF_INET, SOCK_STREAM, 0);

	//������ IP�ּҿ� port ��ȣ�� �ʿ�
	SOCKADDR_IN server_info;
	server_info.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//���� ip�ּ�
	server_info.sin_port = htons(9876);					//��Ʈ��ȣ
	server_info.sin_family = AF_INET;					//�������� ü��
	
	bind(serverSckt, (struct sockaddr*)&server_info, sizeof(server_info));	//�� ��ȯ �ʿ�

	printf("���� ������\n");

	//��� ����
	listen(serverSckt, SOMAXCONN);

	//accept �Ǵ� ���� �˸�
	SOCKET clientSckt = accept(serverSckt, NULL, NULL);

	printf("Ŭ���̾�Ʈ�� ���� ����\n");

	closesocket(clientSckt);
	closesocket(serverSckt);

	WSACleanup();

	return 0;

}