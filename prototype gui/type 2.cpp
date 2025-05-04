#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

#define ID_USERNAME     1
#define ID_PASSWORD     2
#define ID_LOGIN        3
#define ID_SIGNUP_LABEL 4
#define ID_REGISTER     5
#define ID_NEW_USERNAME 6
#define ID_NEW_PASSWORD 7
#define ID_FIRST_NAME   8
#define ID_SECOND_NAME  9
#define ID_MIDDLE_INIT  10
#define ID_LAST_NAME    11
#define ID_SCHOOL_NAME  12
#define ID_YEAR         13
#define ID_COURSE       14
#define ID_SCHOOL_YEAR  15

HFONT hFontTitle, hFontSubTitle, hFontLabel, hFontBold, hFontLink;

vector<pair<string, string>> users;
const string userFile = "users.txt";

void LoadUsers() {
    ifstream file(userFile);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string uname, pword;
        if (getline(ss, uname, ',') && getline(ss, pword)) {
            users.push_back({uname, pword});
        }
    }
}

void SaveUser(const string& uname, const string& pword) {
    ofstream file(userFile, ios::app);
    file << uname << "," << pword << "\n";
    users.push_back({uname, pword});
}

LRESULT CALLBACK SignUpProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HBRUSH hBrushBkgnd;
    switch (msg) {
        case WM_CREATE:
            hBrushBkgnd = CreateSolidBrush(RGB(255, 222, 89));

            CreateWindow("STATIC", "Sign up here:", WS_VISIBLE | WS_CHILD, 150, 10, 200, 30, hwnd, NULL, NULL, NULL);

            CreateWindow("STATIC", "Username:", WS_VISIBLE | WS_CHILD, 30, 50, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 250, 25, hwnd, (HMENU)ID_NEW_USERNAME, NULL, NULL);

            CreateWindow("STATIC", "Password:", WS_VISIBLE | WS_CHILD, 30, 85, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 85, 250, 25, hwnd, (HMENU)ID_NEW_PASSWORD, NULL, NULL);

            CreateWindow("STATIC", "First name:", WS_VISIBLE | WS_CHILD, 30, 120, 80, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 140, 100, 25, hwnd, (HMENU)ID_FIRST_NAME, NULL, NULL);

            CreateWindow("STATIC", "Second name:", WS_VISIBLE | WS_CHILD, 140, 120, 90, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 140, 140, 100, 25, hwnd, (HMENU)ID_SECOND_NAME, NULL, NULL);

            CreateWindow("STATIC", "Middle Initial:", WS_VISIBLE | WS_CHILD, 250, 120, 90, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 250, 140, 50, 25, hwnd, (HMENU)ID_MIDDLE_INIT, NULL, NULL);

            CreateWindow("STATIC", "Last name:", WS_VISIBLE | WS_CHILD, 310, 120, 80, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 310, 140, 100, 25, hwnd, (HMENU)ID_LAST_NAME, NULL, NULL);

            CreateWindow("STATIC", "School Name:", WS_VISIBLE | WS_CHILD, 30, 175, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 175, 250, 25, hwnd, (HMENU)ID_SCHOOL_NAME, NULL, NULL);

            CreateWindow("STATIC", "Year:", WS_VISIBLE | WS_CHILD, 30, 210, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 30, 230, 100, 25, hwnd, (HMENU)ID_YEAR, NULL, NULL);

            CreateWindow("STATIC", "Course:", WS_VISIBLE | WS_CHILD, 140, 210, 100, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 140, 230, 100, 25, hwnd, (HMENU)ID_COURSE, NULL, NULL);

            CreateWindow("STATIC", "School Year:", WS_VISIBLE | WS_CHILD, 250, 210, 150, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 250, 230, 150, 25, hwnd, (HMENU)ID_SCHOOL_YEAR, NULL, NULL);

            CreateWindow("BUTTON", "Register", WS_VISIBLE | WS_CHILD | BS_FLAT, 180, 270, 100, 30, hwnd, (HMENU)ID_REGISTER, NULL, NULL);
            break;

        case WM_CTLCOLORDLG:
        case WM_CTLCOLORSTATIC:
        case WM_CTLCOLOREDIT:
        case WM_CTLCOLORBTN:
            SetBkMode((HDC)wParam, TRANSPARENT);
            return (INT_PTR)hBrushBkgnd;

        case WM_COMMAND:
            if (LOWORD(wParam) == ID_REGISTER) {
                char uname[100], pword[100];
                GetWindowText(GetDlgItem(hwnd, ID_NEW_USERNAME), uname, 100);
                GetWindowText(GetDlgItem(hwnd, ID_NEW_PASSWORD), pword, 100);
                SaveUser(uname, pword);
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
            LoadUsers();

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

            HWND hTitle = CreateWindow("STATIC", "STUDMANS", WS_VISIBLE | WS_CHILD | SS_CENTER,
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

                bool found = false;
                for (const auto& user : users) {
                    if (user.first == username && user.second == password) {
                        found = true;
                        break;
                    }
                }

                if (found) {
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
                 200, 100, 500, 400, NULL, NULL, NULL, NULL);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
