#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <string>
#include <memory>

// 窗口類名
constexpr auto CLASS_NAME = L"ModernCounter";
// 窗口標題
constexpr auto WINDOW_TITLE = L"Modern C++ Counter";

// 按鈕ID
constexpr int BTN_INCREMENT = 1001;
constexpr int BTN_DECREMENT = 1002;
constexpr int BTN_RESET = 1003;

class Counter {
private:
    HWND hwnd;
    HWND displayHwnd;
    int count = 0;

public:
    Counter(HWND hwnd) : hwnd(hwnd), count(0) {
        createControls();
        updateDisplay();
    }

    void increment() {
        count++;
        updateDisplay();
    }

    void decrement() {
        count--;
        updateDisplay();
    }

    void reset() {
        count = 0;
        updateDisplay();
    }

private:
    void createControls() {
        // 使用 CreateWindowExW 替代 CreateWindowEx
        displayHwnd = CreateWindowExW(
            0, L"STATIC", L"0",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            10, 10, 280, 30,
            hwnd, nullptr, nullptr, nullptr
        );

        CreateWindowExW(
            0, L"BUTTON", L"+",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            10, 50, 90, 30,
            hwnd, (HMENU)BTN_INCREMENT, nullptr, nullptr
        );

        CreateWindowExW(
            0, L"BUTTON", L"-",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            110, 50, 90, 30,
            hwnd, (HMENU)BTN_DECREMENT, nullptr, nullptr
        );

        CreateWindowExW(
            0, L"BUTTON", L"Reset",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            210, 50, 90, 30,
            hwnd, (HMENU)BTN_RESET, nullptr, nullptr
        );
    }

    void updateDisplay() {
        // 使用 SetWindowTextW 替代 SetWindowText
        SetWindowTextW(displayHwnd, std::to_wstring(count).c_str());
    }
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    Counter* counter = reinterpret_cast<Counter*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    switch (uMsg) {
        case WM_CREATE: {
            auto counter = std::make_unique<Counter>(hwnd);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(counter.release()));
            return 0;
        }

        case WM_COMMAND: {
            if (!counter) return 0;

            switch (LOWORD(wParam)) {
                case BTN_INCREMENT:
                    counter->increment();
                    break;
                case BTN_DECREMENT:
                    counter->decrement();
                    break;
                case BTN_RESET:
                    counter->reset();
                    break;
            }
            return 0;
        }

        case WM_DESTROY: {
            delete counter;
            PostQuitMessage(0);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        320, 140,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
