#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define MX 100007

double x1 = 0, yy1 = 0, x2 = 50, y2 = 40;

void display()
{
      double dx = abs(x2 - x1);
      double dy = abs(y2 - yy1);

      double x = x1, y = yy1;
      glBegin(GL_POINTS);
      glVertex2i(x, y);
      glEnd();

      double p = 2 * dy - dx;

	  while(x < x2) {
			x += 1.0;
            if(p < 0) {
                  p = p + 2 * dy;
            }
            else {
                  p = p + 2 * dy - 2 * dx;
                  y += 1.0;
            }
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
      }
      glFlush();
}

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv)
{
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(500, 500);
      glutInitWindowPosition(100, 100);
      glutCreateWindow("Bresenham");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}
