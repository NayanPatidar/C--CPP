#include <iostream>
#include <Windows.h>

class KeyBoard {
public:
    static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
            if (nCode == HC_ACTION) {
                KBDLLHOOKSTRUCT* pKeyboard = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
                DWORD key = pKeyboard->vkCode;

                if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
                    std::cout << "Key pressed: " << key << std::endl;
                }
                else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
                    std::cout << "Key released: " << key << std::endl;
                }
            }
            return CallNextHookEx(NULL, nCode, wParam, lParam);
    }
};
