#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define av(x, y) (x + y)/2

void triangle(double x1, double yy1, double x2, double y2, double x3, double y3)
{
      glBegin(GL_TRIANGLES);
      glVertex2i(x1, yy1);
      glVertex2i(x2, y2);
      glVertex2i(x3, y3);
      glEnd();
      glFlush();
}

void sGasket(double x1, double yy1, double x2, double y2, double x3, double y3, int n)
{
      if(n > 0) {
            double x12 = av(x1, x2);
            double yy12 = av(yy1, y2);
            double x13 = av(x1, x3);
            double yy13 = av(yy1, y3);
            double x23 = av(x2, x3);
            double y23 = av(y2, y3);

            sGasket(x1, yy1, x12, yy12, x13, yy13, n - 1);
            sGasket(x12, yy12, x2, y2, x23, y23, n - 1);
            sGasket(x13, yy13, x23, y23, x3, y3, n - 1);
      }
      else {
            triangle(x1, yy1, x2, y2, x3, y3);
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

double x1, yy1, x2, y2, x3, y3;
int n;

void display()
{
      sGasket(x1, yy1, x2, y2, x3, y3, n);
}

int main(int argc, char **argv)
{
      scanf("%lf %lf %lf %lf %lf %lf", &x1, &yy1, &x2, &y2, &x3, &y3);
      scanf("%d", &n);
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(500, 500);
      glutInitWindowPosition(100, 100);
      glutCreateWindow("gasket");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}
