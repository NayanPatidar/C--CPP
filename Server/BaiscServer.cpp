#include <iostream>
#include <WS2tcpip.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment (lib, "ws2_32.lib")
using namespace std;

int main() {
    WSADATA wsaData;
    int wsaStartupResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

    // Checking Winsock with error handling 
    if (wsaStartupResult != 0) {
        cerr << "WSAStartup failed with error: " << wsaStartupResult << endl;
        return 1;
    }

    // Creating socket for receiving
    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (sockfd == INVALID_SOCKET) {
        cerr << "Socket creation failed with error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Socket binding 
    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Bind to any available network interface
    serverAddr.sin_port = htons(12345);

    if (bind(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Socket bind failed with error: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 12345...\n";

    // Create a socket for sending
    SOCKET sendSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sendSock == INVALID_SOCKET) {
        cerr << "Socket creation for sending failed with error: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // Client address to send to
    sockaddr_in clientAddr;
    memset(&clientAddr, 0, sizeof(clientAddr));
    clientAddr.sin_family = AF_INET;
    inet_pton(AF_INET, "10.200.233.107", &clientAddr.sin_addr);  // Change to the appropriate client IP address
    clientAddr.sin_port = htons(12345);  // Change to the appropriate client port

    const char* message = "Hello, client! This is a UDP message.";

    // Send the UDP packet to the client
    int sendResult = sendto(sendSock, message, strlen(message), 0, (sockaddr*)&clientAddr, sizeof(clientAddr));
    if (sendResult == SOCKET_ERROR) {
        cerr << "Sendto failed with error: " << WSAGetLastError() << std::endl;
    }
    else {
        std::cout << "Sent " << sendResult << " bytes to the client." << std::endl;
    }

    // Cleanup
    closesocket(sendSock);
    closesocket(sockfd);
    WSACleanup();

    return 0;
}
