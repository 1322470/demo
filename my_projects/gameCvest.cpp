
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <locale>
#include <codecvt>
#include <string>
#ifdef _WIN32
#include <windows.h> // ��� ������� Sleep() �� Windows
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h> // ��� ������� usleep() �� Unix-�������� ��������
#define SLEEP(ms) usleep((ms) * 1000)
#endif

void gotoxy(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

void setcolor(int color) {
    std::cout << "\033[" << color << "m";
}

void round1() {
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale());
    std::wcout << L"\n \n \n \n \n";
    std::wcout << L"    ������ ������� ����! ����� ������� � ����)) ����� Enter!" << std::endl;
    std::cin.get();
    std::wcout << L"    ���� �� ��������))) �������" << std::endl << std::endl;
    std::wcout << L"    ������ �1" << std::endl;
    std::wstring str = L"���� ������ ������� ��� �� 4 ����, �� ������ ���������� ����� �� ��������� ���� �����.\n"
    L"������� ����:\n"
        L"� ������ � ������ �������� 4 ������� � ���������� �� 2 ������ (������ ������ �� 2 �������). ������ � ��������� ������!!\n"
        L"���������: ������ - ���������.\n"
        L"�.�. ��� ����� ������ ��������� ����� ������� ���, ������� � ��� �������.\n"
        L"���������� ����� ����������� 2 �����.\n"
        L"����� ������ �����, �� ������ ������ ����� ������� � ��������� ��������� �����������, ��� �� ��������� ���������.\n\n";
    for (auto el : str) {
        std::wcout << el;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));  // ����� �� 0.05 �������
    }
    int code{ 1647 };
    int codeArr[4]{ 1, 6, 4, 7 };
    int numb, codeAnima;
    for (int i = 0; i < 4; i++) {
        std::wcout << L"������� ����� �����:  ";
        std::cin >> numb;
        std::wcout << L"�������������:  ";
        std::cin >> codeAnima;
        if (codeAnima == 1111) {
            int number = numb;
            if (numb <= 0 and numb >= 5) std::wcout << "eror:(\n";
            else {
                std::wcout << "number: " << codeArr[numb - 1] << L"  ���-�� �������: " << 3 - i << "\n";
            }
        }
        else {
            std::wcout << L"������������!!!\n";
        }
    }
    do {
        std::wcout << L"������� ��� �������: ";
        std::cin >> numb;
    } while (numb != 1647);
    std::cout << "\n------------------------------------------------------------------------------------------------------\n------------------------------------------------------------------------------------------------------\n";
    str = L"�� ����� ������ � 2 �������� \n ������� ����:\n"
        L"1. � ������ ������� ���� �� 3 �������� : 1 ������� � 2 ��������������(��� ����, ��������� ��������).\n"
        L"2. ����� ��������, ���������� ������ ���� ����������� � � ����� ���������.\n"
        L"3. �� ������ ���� ������� ���������� � ���� ��������, � �������� �������� ����� �� ��������� ��������������� �������.\n"
        L"4. ���������� ������ ������� ����, ��� ��������� � ��������, � ����� �������� 3 ���������.\n"
        L"5. ��� ������ ������ �� ������� ��������, �� �������� ��������� ����� � ������� ��������� ����� �������.\n";
    for (auto el : str) {
        std::wcout << el;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));  // ����� �� 0.05 �������
    }
}

void round2() {
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale());
    std::wcout << L"������ ����������!? (enter)";
    std::cin.get();
    std::wcout << L"�������������� ����:";
    SLEEP(400);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    const int width = 250; // ������ �������
    const int height = 20; // ������ �������
    std::vector<int> drops(width, 0);

    std::system("clear"); // ������� ������ �� ������ (��� Unix-�������� ������)
#ifdef _WIN32
    std::system("cls"); // ������� ������ �� ������ (��� Windows)
#endif
    int ind = 0;
    while (ind < 22) {
        // �������� �� ������� �������
        for (int i = 0; i < width; ++i) {
            // ���������� ��������� ������ � ������ �������
            char ch = '!' + std::rand() % 94;
            int color = 32 + std::rand() % 8; // ������� ���� � ��� �������

            // ������ ������ � ��������� �������
            gotoxy(i + 1, drops[i]);
            setcolor(color);
            std::cout << ch;
            drops[i] = (drops[i] + 1) % height;

            // ������� ����� �� ���� ������
            setcolor(30);
            if (drops[i] == 0) {
                for (int j = 0; j < height; ++j) {
                    gotoxy(i + 1, j);
                    std::cout << " ";
                }
            }
        }
        ind++;

        SLEEP(1); // �������� ��� �������� ������� ��������
        std::cout.flush(); // �������������� ���������� ������ ������
    }
    std::wstring str = L"\n\n\n���� ������ ������������ �������� ���:\n"
        L"���... �� ������ ��������\n"
        L"��� ��� ������� ������ ������� �� ������, ������������ � ��������� ��������\n\n"
        L"������ �2 �����\n"
        L"�� ������ ����� ����� � �������� � �������, ������ ������� �������� ������� ��� ���� � �����, ��������� ������� � ������ �������.\n"
        L"���� ������ �������� �����, �� �� �������� � ��� ��� ������ ��������� ������ �����.\n"
        L" - ������� ���������, ���� ��������� �������\n"
        L"���� ������� ��������� �������, ��� ����� ����� ������ �� ��������� ������� (� ��� ����� ���� �������), ����� ���� ��� ����� ����� � ������� .. ������ �������\n";
    int color = 32 + std::rand() % 8;
    for (auto el : str) {
        setcolor(color);
        std::wcout << el;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));  // ����� �� 0.05 �������
    }
    char code;
    std::wcout << L"\n �����:";
    std::cin >> code;
    int color1 = 32 + std::rand() % 8;
    if (code == 'b') {
        str = L"\n\n\n������� ������� (� ��� ���� .. �)\n"
            L"�������\n";
        for (auto el : str) {
            setcolor(color1);
            std::wcout << el;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));  // ����� �� 0.05 �������
        }
        SLEEP(500);
        system("CLS");
        int number;
        ;       std::wcout << L"�����:  ";
        std::cin >> number;
        if (number == 123) {

        }
        else {

        }
    }
    else {
        color = 32 + std::rand() % 8;
        std::wcout << L"������ ��� �������";
        str = L"\n�����������������������������������������������������������������������������\n";
        for (auto el : str) {
            int color = 32 + std::rand() % 8;
            setcolor(color);
            std::wcout << el;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));  // ����� �� 0.05 �������
        }
    }
}
void ClearScreen() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void SetCursorPosition1(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawLongKey() {
    const char* key[] = {
        "    ____",
        "   /    \\",
        "  | ||  | | ?   ?????????????? ? ???  ?????? ?????? ???",
        "  | ||  | | ????  ?? ? ? ?? ? ? ??????????????? ? ? ? ?",
        "  | ||  | |",
        "   \\____/",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||",
        "     ||-",
        "     |--|",
        "     |--|",
        "     ||-" };

    int startX = 10;
    int startY = 5;
    int color = 32 + std::rand() % 8;
    setcolor(color);
    for (int i = 0; i < 20; ++i) { 
        SetCursorPosition1(startX, startY + i);
        std::wcout << key[i];
    }
}

void SetCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void PrintRaund3() {
    const char* raund3[] = {
        "  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  ",
        " /  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\",
        "/    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\",
        "\\    /    /    /    /    /    /    /    /    /    /    /    /    /",
        " \\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /",
        "  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/",
        "  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  ",
        " /  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\",
        "/    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\",
        "\\    /    /    /    /    /    /    /    /    /    /    /    /    /",
        " \\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /",
        "  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/",
        "  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  ",
        " /  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\",
        "/    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\    \\",
        "\\    /    /    /    /    /    /    /    /    /    /    /    /    /",
        " \\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /\\  /",
        "  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/  \\/\n\n"
    };

    int startX = 10;
    int startY = 5;

    int color = 32 + std::rand() % 8;
    setcolor(color);
    for (int i = 0; i < 18; ++i) {
        SetCursorPosition(startX, startY + i);
        std::cout << raund3[i];
    }
}

void round3() {
    // ��������� ������ ��� ������ ������� ��������
    SetConsoleOutputCP(CP_UTF8);
    std::wcout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wcout << L"����� ������� � ���������� ������ ������� ������ enter";
    std::wcin.get();
    PrintRaund3();
    std::wstring str = L"������ �������� �������, ��� � ��� ���������!\n ���������, ������� � ����, � ���� �� ����� ������������ ��������� ��������� ������\n ����� ����, ������ �����������. ���� ������:\n ���� ������� ���������� �������� ���� ����� �� ������ � �������, ������� ����� �� ��� ������� �����,\n ������ ������ �� ����, ������ �������� ������ � ������� ���� �� ����� ����� (����� ������� �������� ���������)\n �.�. �� ������� ������ ����� ����������, �������� ���� �� ��������������� ������� � ������������, ��� ������� �������\n ������ �����, �� � �������� ����";
    for (auto el : str) {
        std::wcout << el;
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
    }
    std::wcout << L"\n������� enter, ����� ������ ��� �� ����..";
    std::cin.get();
    ClearScreen();
    DrawLongKey();
    std::wstring str1 = L"    ������ � ������ ������ �������� ���������� ? � ���������, ������ � ������ �� �������� � ������ ������, �����";
    for (auto el : str1) {
        std::wcout << el;
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
    }
    std::wcout << L"\nKey: ";
    std::wcin >> str1;
    if (str1 == L"?    ?") {
        std::wcout << L"\n����������, �� ����� ���������� ����!";
    }
}

void printStars(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the screen
}

void round4() {
    SetConsoleOutputCP(CP_UTF8);
    std::wcout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wcout << L"round 4! �� ������!? ���� ��, �� ������ ��� enter";
    std::wcin.get();
    
    int starCount = 1;
    while (starCount <= 500) {
        clearScreen();
        printStars(starCount);
        std::this_thread::sleep_for(std::chrono::milliseconds(5)); // Pause for 500 milliseconds
        starCount++;
    }

    clearScreen();
    std::cout << "round4" << std::endl;
    std::wstring str = L"�� � ������� ���� ��������!? ...... � �� ���� 500)) \n ��� �� ����� ������ ��������� �������..\n"
        L"�� ������ ������� � �� �������. ������:\n"
        L"������ �4 ������ (������� �� �������)\n"
        L"������ ������� ������� �� 4 ��������, ������� ����������� �� ��������(�.�.������ 8 �������).\n"
        L"��� ���������� �� ���� � ������ ��� ���� �� ����.������� ����� ��������� ���.\n"
        L"���� ���� : ������ ���� ����������. ��� �� ��� ������� ?!\n"
        L" - ����� � ���� �����, �� ������ ��� ������ 2-�� ������ �� ����� � � �����-�� ������ �������� ��� �������.\n"
        L"���� ���-�� �������� ���� �� �����, �� ��� �� ������ ��� � ��������, ����� �� ����� ��� �������, ���� ������� ��������.\n"
        L"�� ������ ���������� ���� ������� �������� + 1 ����, � ���� ������ ��� � �������)\n"
        L"\n���� ������� ��������� ��� ���������� ����������� �������������� � ��������, ����� �������� ����� ������!";
    int color = 32 + std::rand() % 8;
    setcolor(color);
    for (auto el : str) {
        std::wcout << el;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    
}

int main() {
    //round1();
    //round2();
    //round3();
    round4();
    return 0;
}
