#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define PI acos(-1)

double toRad(double a)
{
      return a * PI/180;
}

void line(double x, double y, double xx, double yy)
{
      glBegin(GL_LINES);
      glVertex2i(x, y);
      glVertex2i(xx, yy);
      glEnd();
      glFlush();
}

void koch_curve(double x, double y, double len, double alpha, int n)
{
      if(n > 0) {
            len = len/3.0;
            koch_curve(x, y, len, alpha, n - 1);
            x = x + len * cos(toRad(alpha));
            y = y + len * sin(toRad(alpha));
            koch_curve(x, y, len, alpha - 60, n - 1);
            x = x + len * cos(toRad(alpha - 60));
            y = y + len * sin(toRad(alpha - 60));
            koch_curve(x, y, len, alpha + 60, n - 1);
            x = x + len * cos(toRad(alpha + 60));
            y = y + len * sin(toRad(alpha + 60));
            koch_curve(x, y, len, alpha, n - 1);
      }
      else {
            line(x, y, x + len * cos(toRad(alpha)), y + len * sin(toRad(alpha)));
      }
}

void init(void)
{
      glClear(GL_COLOR_BUFFER_BIT);
      glClearColor(.7, .7, .7, .7);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-100, 100, -100, 100);
}

double x, y, len, alpha;
int n;

void display()
{
      koch_curve(x, y, len, alpha, n);
}

int main(int argc, char **argv)
{
      scanf("%lf %lf %lf %lf", &x, &y, &len, &alpha);
      scanf("%d", &n);
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(500, 500);
      glutInitWindowPosition(100, 100);
      glutCreateWindow("kochCurve");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}
