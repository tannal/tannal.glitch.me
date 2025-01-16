#include <windows.h>
#include <string>

// 窗口常量
constexpr const wchar_t* CLASS_NAME = L"ModernCounter";
constexpr const wchar_t* WINDOW_TITLE = L"Modern C++ Counter";

// 按钮 ID
constexpr int BTN_INCREMENT = 1001;
constexpr int BTN_DECREMENT = 1002;
constexpr int BTN_RESET = 1003;

// 布局常量
constexpr int MARGIN = 10;
constexpr int BUTTON_HEIGHT = 30;
constexpr int DISPLAY_HEIGHT = 30;
constexpr int MIN_WINDOW_WIDTH = 320;
constexpr int MIN_WINDOW_HEIGHT = 140;

// 全局变量
static HWND g_displayHwnd = nullptr;
static int g_count = 0;
static HINSTANCE g_hInstance = nullptr;

// 更新显示
void updateDisplay() {
    wchar_t buffer[32];
    swprintf(buffer, 32, L"%d", g_count);
    SetWindowTextW(g_displayHwnd, buffer);
}

// 布局函数
void layoutControls(HWND hwnd) {
    if (!g_displayHwnd) return;

    RECT clientRect;
    GetClientRect(hwnd, &clientRect);
    int width = clientRect.right - clientRect.left;
    int height = clientRect.bottom - clientRect.top;

    // 计算控件尺寸
    int usableWidth = width - (MARGIN * 2);
    int buttonWidth = (usableWidth - MARGIN * 2) / 3;

    // 计算垂直位置
    int displayY = MARGIN;
    int buttonsY = height - MARGIN - BUTTON_HEIGHT;

    // 调整显示标签
    SetWindowPos(g_displayHwnd, nullptr,
        MARGIN, displayY,
        usableWidth, DISPLAY_HEIGHT,
        SWP_NOZORDER);

    // 获取按钮句柄并调整位置
    HWND btnIncrement = GetDlgItem(hwnd, BTN_INCREMENT);
    HWND btnDecrement = GetDlgItem(hwnd, BTN_DECREMENT);
    HWND btnReset = GetDlgItem(hwnd, BTN_RESET);

    if (btnIncrement) {
        SetWindowPos(btnIncrement, nullptr,
            MARGIN, buttonsY,
            buttonWidth, BUTTON_HEIGHT,
            SWP_NOZORDER);
    }

    if (btnDecrement) {
        SetWindowPos(btnDecrement, nullptr,
            MARGIN * 2 + buttonWidth, buttonsY,
            buttonWidth, BUTTON_HEIGHT,
            SWP_NOZORDER);
    }

    if (btnReset) {
        SetWindowPos(btnReset, nullptr,
            MARGIN * 3 + buttonWidth * 2, buttonsY,
            buttonWidth, BUTTON_HEIGHT,
            SWP_NOZORDER);
    }

    InvalidateRect(hwnd, nullptr, TRUE);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // 创建显示标签
            g_displayHwnd = CreateWindowExW(
                0, L"STATIC", L"0",
                WS_CHILD | WS_VISIBLE | SS_CENTER,
                10, 10, 280, 30,
                hwnd, nullptr, nullptr, nullptr
            );

            // 创建按钮
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

            layoutControls(hwnd);
            return 0;
        }

        case WM_SIZE: {
            layoutControls(hwnd);
            return 0;
        }

        case WM_GETMINMAXINFO: {
            MINMAXINFO* mmi = (MINMAXINFO*)lParam;
            mmi->ptMinTrackSize.x = MIN_WINDOW_WIDTH;
            mmi->ptMinTrackSize.y = MIN_WINDOW_HEIGHT;
            return 0;
        }

        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case BTN_INCREMENT:
                    g_count++;
                    updateDisplay();
                    break;
                case BTN_DECREMENT:
                    g_count--;
                    updateDisplay();
                    break;
                case BTN_RESET:
                    g_count = 0;
                    updateDisplay();
                    break;
            }
            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

extern "C" {

__declspec(dllexport) void initialize() {
    g_hInstance = GetModuleHandle(nullptr);
    if (!g_hInstance) {
        MessageBoxW(nullptr, L"GetModuleHandle failed", L"Error", MB_OK | MB_ICONERROR);
        return;
    }

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = g_hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    if (!RegisterClassW(&wc)) {
        MessageBoxW(nullptr, L"RegisterClass failed", L"Error", MB_OK | MB_ICONERROR);
        return;
    }
}

__declspec(dllexport) HWND create_window() {
    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        WINDOW_TITLE,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT,
        nullptr,
        nullptr,
        g_hInstance,
        nullptr
    );

    if (!hwnd) {
        DWORD error = GetLastError();
        wchar_t msg[256];
        swprintf(msg, 256, L"CreateWindowEx failed with error: %lu", error);
        MessageBoxW(nullptr, msg, L"Error", MB_OK | MB_ICONERROR);
        return nullptr;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
    return hwnd;
}

__declspec(dllexport) BOOL process_messages() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return TRUE;
}

} // extern "C"
