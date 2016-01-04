#include"Header.h"
#include<iostream>
using namespace std;
void reshape(int w, int h) 
{
	const int width = 800;
	const int height = 800;
	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, min(w, h), min(w, h));
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); 
}
void timer(int)
{
	Circle::display();
	glutTimerFunc(60, timer, 0);
}
int main()
{

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(800, 800);
	glutCreateWindow("lab2");
	glutReshapeFunc(reshape);
	glutDisplayFunc(Circle::display);
	glutMouseFunc(Circle::mouse);
	glutSpecialFunc(Circle::key);
	glutTimerFunc(60, timer, 0);
	glutMainLoop();
	return 0;
}