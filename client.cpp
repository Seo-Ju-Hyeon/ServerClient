#include<stdio.h>
#include<winsock2.h>
#include<conio.h>

#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
	//윈도우는 윈소켓데이터를 사용한다고 미리 알려줘야 함
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2, 2), &wsa_data);

	//AF_INET = 소켓을 인터넷에서 사용
	//SOCK_STREAM = TCP를 사용
	//서버 소켓 생성
	SOCKET Sckt = socket(AF_INET, SOCK_STREAM, 0);

	//서버는 IP주소와 port 번호가 필요
	SOCKADDR_IN server_info;
	server_info.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");// 루프 백 ip주소로 내 주소(나중에 서버 주소가 들어감)
	server_info.sin_port = htons(9876);					//포트번호
	server_info.sin_family = AF_INET;					//프로토콜 체계

	printf("서버에 접속하려 합니다.\n");

	int state = connect(Sckt, (struct sockaddr*)&server_info, sizeof(server_info));
	
	if (state == -1) {
		printf("서버에 접속할 수 없습니다.\n");
		closesocket(Sckt);

		_getch();
		return -1;
	}

	printf("서버에 접속했습니다.\n");
	closesocket(Sckt);

	WSACleanup();

	_getch();

	return 0;

}