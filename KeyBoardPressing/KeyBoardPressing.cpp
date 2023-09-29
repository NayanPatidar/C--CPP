#include <iostream>
#include <WS2tcpip.h>
#include <string>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment (lib, "ws2_32.lib")
using namespace std;

SOCKET sendSock;
sockaddr_in clientAddr;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pKeyboard = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
        DWORD key = pKeyboard->vkCode;

        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            std::cout << "Key pressed: " << key << std::endl;


            string key_string = to_string(key);
            const char* message = key_string.c_str();

            // Send the UDP packet to the client
            int sendResult = sendto(sendSock, message, strlen(message), 0, (sockaddr*)&clientAddr, sizeof(clientAddr));

            if (sendResult == SOCKET_ERROR) {
                cerr << "Send to failed with error: " << WSAGetLastError() << std::endl;
            }
            else {
                std::cout << "Sent " << sendResult << " bytes to the client." << std::endl;
            }
        }
        else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
            std::cout << "Key released: " << key << std::endl;

            
                string key_string = to_string(key) + "'";
                const char* message = key_string.c_str();


                // Send the UDP packet to the client
                int sendResult = sendto(sendSock, message, strlen(message), 0, (sockaddr*)&clientAddr, sizeof(clientAddr));

                if (sendResult == SOCKET_ERROR) {
                    cerr << "Sendto failed with error: " << WSAGetLastError() << std::endl;
                }
                else {
                    std::cout << "Sent " << sendResult << " bytes to the client." << std::endl;
              
            }

        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

    int main()
    {
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
        sendSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sendSock == INVALID_SOCKET) {
            cerr << "Socket creation for sending failed with error: " << WSAGetLastError() << std::endl;
            closesocket(sockfd);
            WSACleanup();
            return 1;
        }

        // Client address to send to
        memset(&clientAddr, 0, sizeof(clientAddr));
        clientAddr.sin_family = AF_INET;
        inet_pton(AF_INET, "10.200.233.107", &clientAddr.sin_addr);  // Change to the appropriate client IP address
        clientAddr.sin_port = htons(12345);  // Change to the appropriate client port



        HHOOK hook = SetWindowsHookExA(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0);

        if (hook == NULL) {
            std::cerr << "Failed to set up hook." << std::endl;
            return 1;
        }

        // Message loop to keep the application running
        MSG msg;
        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // Unhook and exit
        UnhookWindowsHookEx(hook);

        return 0;
    }
