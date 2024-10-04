#include "ThemeSong.h"
#include "../../../Shared/Console/Console.h"
#include <stdlib.h>

void ThemeSong::BatTheme(int numberOfNas)
{
	ConsoleColor color;
	int w = Console::GetWindowWidth();
	int h = Console::GetWindowHeight();
	int x, y;
	for (size_t i = 0; i < numberOfNas; i++)
	{
		color = (ConsoleColor)(rand() % 7 + 1);
		x = rand() % w;
		y = rand() % h;
		Console::SetCursorPosition(x, y);
		Console::Write("na ", color);
	}
	x = w / 2 - 4;
	y = h / 2;
	Console::SetCursorPosition(x, y);
	color = (ConsoleColor)(rand() % 7 + 1);
	Console::WriteLine("Batman!!!", color);
}
