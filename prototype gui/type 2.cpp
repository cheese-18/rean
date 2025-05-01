#include <windows.h>
#include <iostream>
#define ID_USERNAME     1
#define ID_PASSWORD     2
#define ID_LOGIN        3
#define ID_SIGNUP_LABEL 4
#define ID_REGISTER     5
#define ID_NEW_USERNAME 6
#define ID_NEW_PASSWORD 7

using namespace std;

string registeredUsername = "";
string registeredPassword = "";

HFONT hFontTitle, hFontSubTitle, hFontLabel, hFontBold, hFontLink;

LRESULT CALLBACK SignUpProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            CreateWindow("STATIC", "Sign Up", WS_VISIBLE | WS_CHILD, 100, 20, 200, 30, hwnd, NULL, NULL, NULL);

            CreateWindow("STATIC", "New Username:", WS_VISIBLE | WS_CHILD, 30, 70, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 70, 200, 25, hwnd, (HMENU)ID_NEW_USERNAME, NULL, NULL);

            CreateWindow("STATIC", "New Password:", WS_VISIBLE | WS_CHILD, 30, 110, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 110, 200, 25, hwnd, (HMENU)ID_NEW_PASSWORD, NULL, NULL);

            CreateWindow("BUTTON", "Register", WS_VISIBLE | WS_CHILD, 150, 160, 100, 30, hwnd, (HMENU)ID_REGISTER, NULL, NULL);
            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_REGISTER) {
                char uname[100], pword[100];
                GetWindowText(GetDlgItem(hwnd, ID_NEW_USERNAME), uname, 100);
                GetWindowText(GetDlgItem(hwnd, ID_NEW_PASSWORD), pword, 100);

                registeredUsername = uname;
                registeredPassword = pword;

                MessageBox(hwnd, "Registration Successful!", "Success", MB_OK);
                DestroyWindow(hwnd);
            }
            break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_CREATE: {
            // Fonts
            hFontTitle = CreateFont(36, 0, 0, 0, FW_NORMAL, TRUE, FALSE, FALSE, DEFAULT_CHARSET,
                                    OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                    VARIABLE_PITCH, "Segoe Script");

            hFontSubTitle = CreateFont(24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                    OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                    VARIABLE_PITCH, "Segoe UI");

            hFontLabel = CreateFont(16, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                    OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                    VARIABLE_PITCH, "Segoe UI");

            hFontBold = CreateFont(18, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                    OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                    VARIABLE_PITCH, "Segoe UI");

            LOGFONT lf = {0};
            lf.lfHeight = 16;
            lf.lfWeight = FW_BOLD;
            lf.lfUnderline = TRUE;
            strcpy(lf.lfFaceName, "Segoe UI");
            hFontLink = CreateFontIndirect(&lf);

            HWND hTitle = CreateWindow("STATIC", "SUTDMANS", WS_VISIBLE | WS_CHILD | SS_CENTER,
                         100, 10, 300, 40, hwnd, NULL, NULL, NULL);
            SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, TRUE);

            HWND hSub = CreateWindow("STATIC", "Student Management System", WS_VISIBLE | WS_CHILD | SS_CENTER,
                         60, 60, 350, 30, hwnd, NULL, NULL, NULL);
            SendMessage(hSub, WM_SETFONT, (WPARAM)hFontSubTitle, TRUE);

            CreateWindow("STATIC", "Manage your academic experience with us!", WS_VISIBLE | WS_CHILD | SS_CENTER,
                         60, 95, 350, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("STATIC", "Schedule, assignment and to do list organize.", WS_VISIBLE | WS_CHILD | SS_CENTER,
                         60, 115, 350, 20, hwnd, NULL, NULL, NULL);

            HWND hLoginLabel = CreateWindow("STATIC", "Login To Your Account", WS_VISIBLE | WS_CHILD,
                         40, 160, 300, 20, hwnd, NULL, NULL, NULL);
            SendMessage(hLoginLabel, WM_SETFONT, (WPARAM)hFontBold, TRUE);

            HWND hLink = CreateWindow("STATIC", "Don't have an account? Sign up here", WS_VISIBLE | WS_CHILD | SS_NOTIFY,
                         40, 185, 400, 20, hwnd, (HMENU)ID_SIGNUP_LABEL, NULL, NULL);
            SendMessage(hLink, WM_SETFONT, (WPARAM)hFontLink, TRUE);

            CreateWindow("STATIC", "Username:", WS_VISIBLE | WS_CHILD, 40, 215, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                         150, 215, 230, 25, hwnd, (HMENU)ID_USERNAME, NULL, NULL);

            CreateWindow("STATIC", "Password:", WS_VISIBLE | WS_CHILD, 40, 250, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD,
                         150, 250, 230, 25, hwnd, (HMENU)ID_PASSWORD, NULL, NULL);

            CreateWindow("BUTTON", "Login", WS_VISIBLE | WS_CHILD,
                         150, 290, 100, 35, hwnd, (HMENU)ID_LOGIN, NULL, NULL);
            break;
        }

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_LOGIN) {
                char username[100], password[100];
                GetWindowText(GetDlgItem(hwnd, ID_USERNAME), username, 100);
                GetWindowText(GetDlgItem(hwnd, ID_PASSWORD), password, 100);

                if (username == registeredUsername && password == registeredPassword) {
                    MessageBox(hwnd, "Login successful!", "Success", MB_OK);
                } else {
                    MessageBox(hwnd, "Invalid username or password.", "Error", MB_OK);
                }
            } else if (LOWORD(wParam) == ID_SIGNUP_LABEL) {
                WNDCLASS signupClass = {0};
                signupClass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
                signupClass.hInstance = GetModuleHandle(NULL);
                signupClass.lpszClassName = "SignUpWindow";
                signupClass.lpfnWndProc = SignUpProc;
                signupClass.hCursor = LoadCursor(NULL, IDC_ARROW);
                RegisterClass(&signupClass);

                CreateWindow("SignUpWindow", "Sign Up", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                             300, 150, 450, 300, hwnd, NULL, NULL, NULL);
            }
            break;

        case WM_SETCURSOR:
            if ((HWND)wParam == GetDlgItem(hwnd, ID_SIGNUP_LABEL)) {
                SetCursor(LoadCursor(NULL, IDC_HAND));
                return TRUE;
            }
            break;

        case WM_CTLCOLORSTATIC: {
            HDC hdcStatic = (HDC)wParam;
            SetBkMode(hdcStatic, TRANSPARENT);
            return (INT_PTR)CreateSolidBrush(RGB(255, 230, 90));
        }

        case WM_ERASEBKGND: {
            HDC hdc = (HDC)wParam;
            RECT rc;
            GetClientRect(hwnd, &rc);
            HBRUSH brush = CreateSolidBrush(RGB(255, 230, 90));
            FillRect(hdc, &rc, brush);
            DeleteObject(brush);
            return 1;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.hInstance = hInst;
    wc.lpszClassName = "LoginWindowClass";
    wc.lpfnWndProc = WindowProcedure;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    RegisterClass(&wc);

    CreateWindow("LoginWindowClass", "Student Management System", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                 500, 500, 500, 400, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
