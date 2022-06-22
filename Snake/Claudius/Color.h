#pragma once

struct Color
{
	unsigned char r, g, b, a;

	Color();
	Color(const Color& rhs);
	Color(char r, char g, char b, char a);

	void SetColor(char r, char g, char b, char a);
};