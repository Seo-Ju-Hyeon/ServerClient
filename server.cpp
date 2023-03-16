#include<stdio.h>
#include<winsock2.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
	//윈도우는 윈소켓데이터를 사용한다고 미리 알려줘야 함
	WSADATA wsa_data;
	WSAStartup(MAKEWORD(2, 2), &wsa_data);

	//AF_INET = 소켓을 인터넷에서 사용
	//SOCK_STREAM = TCP를 사용
	//서버 소켓 생성
	SOCKET serverSckt = socket(AF_INET, SOCK_STREAM, 0);

	//서버는 IP주소와 port 번호가 필요
	SOCKADDR_IN server_info;
	server_info.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//로컬 ip주소
	server_info.sin_port = htons(9876);					//포트번호
	server_info.sin_family = AF_INET;					//프로토콜 체계
	
	bind(serverSckt, (struct sockaddr*)&server_info, sizeof(server_info));	//형 변환 필요

	printf("서버 실행중\n");

	//대기 상태
	listen(serverSckt, SOMAXCONN);

	//accept 되는 순간 알림
	SOCKET clientSckt = accept(serverSckt, NULL, NULL);

	printf("클라이언트가 접속 성공\n");

	closesocket(clientSckt);
	closesocket(serverSckt);

	WSACleanup();

	return 0;

}