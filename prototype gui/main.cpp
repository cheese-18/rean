/*#include <windows.h>
#include <string>

#define ID_USERNAME 1
#define ID_PASSWORD 2
#define ID_LOGIN    3

using namespace std;

HFONT hFontTitle, hFontSubTitle, hFontLabel, hFontBold, hFontLink;

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

            hFontLink = CreateFont(16, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                    OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                    VARIABLE_PITCH, "Segoe UI");

            HWND hTitle = CreateWindow("STATIC", "SUTDMANS",
                         WS_VISIBLE | WS_CHILD | SS_CENTER,
                         100, 10, 300, 40, hwnd, NULL, NULL, NULL);
            SendMessage(hTitle, WM_SETFONT, (WPARAM)hFontTitle, TRUE);

            HWND hSub = CreateWindow("STATIC", "Student Management System",
                         WS_VISIBLE | WS_CHILD | SS_CENTER,
                         60, 60, 350, 30, hwnd, NULL, NULL, NULL);
            SendMessage(hSub, WM_SETFONT, (WPARAM)hFontSubTitle, TRUE);

            HWND hDesc1 = CreateWindow("STATIC", "Manage your academic experience with us!",
                         WS_VISIBLE | WS_CHILD | SS_CENTER,
                         60, 95, 350, 20, hwnd, NULL, NULL, NULL);
            HWND hDesc2 = CreateWindow("STATIC", "Schedule, assignment and to do list organize.",
                         WS_VISIBLE | WS_CHILD | SS_CENTER,
                         60, 115, 350, 20, hwnd, NULL, NULL, NULL);

            HWND hLoginLabel = CreateWindow("STATIC", "Login To Your Account",
                         WS_VISIBLE | WS_CHILD,
                         40, 160, 300, 20, hwnd, NULL, NULL, NULL);
            SendMessage(hLoginLabel, WM_SETFONT, (WPARAM)hFontBold, TRUE);

            HWND hLink = CreateWindow("STATIC", "Don't have an account? Sign up here",
            WS_VISIBLE | WS_CHILD | SS_NOTIFY,
                         40, 185, 400, 20, hwnd, (HMENU)ID_SIGNUP_LABEL, NULL, NULL);
            SendMessage(hLink, WM_SETFONT, (WPARAM)hFontLink, TRUE);
            LOGFONT lf = {0};
            lf.lfHeight = 16;
            lf.lfWeight = FW_BOLD;
            lf.lfUnderline = TRUE;
            strcpy(lf.lfFaceName, "Segoe UI");
            hFontLink = CreateFontIndirect(&lf)

            CreateWindow("STATIC", "Username:",
                         WS_VISIBLE | WS_CHILD,
                         40, 215, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("EDIT", "",
                         WS_VISIBLE | WS_CHILD | WS_BORDER,
                         150, 215, 230, 25, hwnd, (HMENU)ID_USERNAME, NULL, NULL);

            CreateWindow("STATIC", "Password:",
                         WS_VISIBLE | WS_CHILD,
                         40, 250, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("EDIT", "",
                         WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD,
                         150, 250, 230, 25, hwnd, (HMENU)ID_PASSWORD, NULL, NULL);

            CreateWindow("BUTTON", "Login",
                         WS_VISIBLE | WS_CHILD,
                         150, 290, 100, 35, hwnd, (HMENU)ID_LOGIN, NULL, NULL);
        }
        break;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_LOGIN) {
                char username[100], password[100];
                GetWindowText(GetDlgItem(hwnd, ID_USERNAME), username, 100);
                GetWindowText(GetDlgItem(hwnd, ID_PASSWORD), password, 100);

                string msg = "Username: " + string(username) + "\nPassword: " + string(password);
                MessageBox(hwnd, msg.c_str(), "Login Info", MB_OK);
            }
            break;

        case WM_CTLCOLORSTATIC: {
            HDC hdcStatic = (HDC)wParam;
            SetBkMode(hdcStatic, TRANSPARENT);
            return (INT_PTR)CreateSolidBrush(RGB(255, 230, 90)); // Light yellow background
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

    CreateWindow("LoginWindowClass", "Student Management System",
                 WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                 200, 100, 500, 400, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
*/
