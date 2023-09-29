
	#include <WinSock2.h>
	#include <ws2tcpip.h>
	#include <iostream>

	#pragma comment(lib, "ws2_32.lib")
	using namespace std;

	class Protocol {
	public:
		void connection() {
			cout << " ok";
		} 
	};

/*// Winsock Initialization
		WSADATA wsaData;
		int wsaStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	
		// Checking Winsock with error handling 
		if (wsaStartupResult != 0) {
			cerr << "WSAStartup failed with error: " << wsaStartupResult << endl;
		}

		// Creating socket 
		SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

		if (sockfd == INVALID_SOCKET) {
			cerr << "Socket creation failed with error: " << WSAGetLastError() << std::endl;
			WSACleanup();
		}

		// Socket binding 
		sockaddr_in serverAddr;
		memset(&serverAddr, 0, sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_addr.s_addr = inet_addr("192.168.0.100");
		serverAddr.sin_port = htons(12345);

		if (bind(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
			std::cerr << "Socket bind failed with error: " << WSAGetLastError() << std::endl;
			closesocket(sockfd);
			WSACleanup();
		}

		std::cout << "Server listening on port 12345...\n";

		// Cleanup
		closesocket(sockfd);
		WSACleanup();

		return 0;*/