#include <glut.h>
#include<iostream>
int Y = 0;
int T = 0; 
int speed=0;
//Инициализация
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

//Изменение размеров окна
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

//Отображение 
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glRotatef(T, 0, 1, 0);
	glRotatef(Y, 0, 0, 1);
	Y = 0;
	glScalef(4, 1,1);
	glutWireSphere(0.5, 20,16);
	glScalef(0.25, 1, 1);
	glTranslatef(-2, 0.0, 0.0);
	glutWireSphere(1, 20, 16);
	glTranslatef(4, 0.0, 0.0);
	glutWireSphere(1, 20, 16);
	glTranslatef(-2, 0, 0);
	glutSwapBuffers();
}

void timer(int =0)
{
	display();
	glutTimerFunc(1000/speed, timer, 0);
}
//Реакция на клавиатуру 
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case'W':
		Y += 5;
		glutPostRedisplay();
		break;
	case's':
	case'S':
		Y -= 5;
		glutPostRedisplay();
		break;
	case 'd':
	case 'D':
		T = 0;
		glutPostRedisplay();
		break;
	default:
		T = 1;
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1500, 800);
	glutInitWindowPosition(00, 00);
	glutCreateWindow("Planetary System");
	init();
	std::cin >> speed;
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	timer();
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
