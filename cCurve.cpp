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

void c_curve(double x, double y, double len, double alpha, int n)
{
      if(n > 0) {
            len = len/sqrt(2.0);
            c_curve(x, y, len, alpha + 45, n - 1);
            x = x + len * cos(toRad(alpha + 45));
            y = y + len * sin(toRad(alpha + 45));
            c_curve(x, y, len, alpha - 45, n - 1);
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
      c_curve(x, y, len, alpha, n);
}

int main(int argc, char **argv)
{
      scanf("%lf %lf %lf %lf", &x, &y, &len, &alpha);
      scanf("%d", &n);
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(500, 500);
      glutInitWindowPosition(100, 100);
      glutCreateWindow("cCurve");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}
