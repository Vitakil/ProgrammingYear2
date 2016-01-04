#include <windows.h>
#include <glut.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <list>
#include <time.h>
#include <stdlib.h>
using namespace std;
class Circle
{
public:
	static	_declspec(dllexport) int dis(int, int);
	static	_declspec(dllexport)void reshape(int, int);
public:
	static	_declspec(dllexport) void display();
	static	_declspec(dllexport) void mouse(int, int, int, int);
	static	_declspec(dllexport) void key(int, int, int);
	
	friend void timer();
	 Circle(int _x0 =  801, int _y0 =  801, int _r = 0) { x0 = _x0; y0 = _y0; r = _r; }
	 static	_declspec(dllexport) void drawCircle();
	 static	_declspec(dllexport) void drawPixel(int &, int &);//draw Pixel and Pixel which symmetric him
	int x0, y0, r; // (x0, y0) - center cirle
};

Circle _circle;

