#include <iostream>
#include <Windows.h>

using namespace std;

int nScreenWidth = 120; // Ширина консольного окна
int nScreenHeight = 40; // Высота консольного окна

float fPlayerX = 1.0f; // Координата игрока по оси X
float fPlayerY = 1.0f; // Координата игрока по оси Y
float fPlayerA = 0.0f; // Направление игрока

int nMapHeight = 16; // Высота игрового поля
int nMapWidth = 16;  // Ширина игрового поля

float fFOV = 3.14159 / 3; // Угол обзора (поле видимости)
float fDepth = 30.0f;     // Максимальная дистанция обзора

int main()
{
    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight + 1];                                                   // Массив для записи в буфер
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); // Буфер экрана
    SetConsoleActiveScreenBuffer(hConsole);                                                                            // Настройка консоли
    DWORD dwBytesWritten = 0;                                                                                          // Для дебага

    wstring map; // Строковый массив
    map += L"################";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"#..............#";
    map += L"################";

    while (1) // Игровой цикл
    {
        for (int x = 0; x < nScreenWidth; x++) // Проходим по всем X
        {
            short nShade;

            nShade = 0x2593;

            for (int y = 0; y < nScreenHeight; y++) // При заданном X проходим по всем Y
            {
                // В этом цикле рисуется вертикальная полоска
                screen[y * nScreenWidth + x] = nShade;
                Sleep(500);
            }
        }
    }
    return 0;
}
