#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define MX 100007

int xc, yc, r;

void plot(int x, int y)
{
      glBegin(GL_POINTS);
      glVertex2i(x, y);
      glEnd();
      glFlush();
}

void _plot(int k, int x, int y)
{
      switch(k) {
      case 1:
            plot(xc + x, yc + y);
            break;
      case 2:
            plot(xc -x, yc + y);
            break;
      case 3:

            plot(xc +x, yc - y);
            break;
      case 4:

            plot(xc -x, yc - y);
            break;
      case 5:

            plot(xc +y, yc + x);
            break;
      case 6:

            plot(xc -y, yc + x);
            break;
      case 7:

            plot(xc +y, yc - x);
            break;
      case 8:

            plot(xc -y, yc -x);
            break;
      }
}

void display()
{

      for(int k = 1; k <= 8; k ++) {

            int p = 1 - r;
            int x = 0;
            int y = r;
            _plot(k, x, y);
            while(x < y) {
                  if(p < 0) {
                        x ++;
                        p = p + 2 * x + 1;
                  }
                  else {
                        x ++;
                        y --;
                        p = p + 2 * x + 1 - 2 * y;
                  }
                  _plot(k, x, y);
            }
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

int main(int argc, char **argv)
{
      scanf("%d %d %d", &xc, &yc, &r);
      glutInit(&argc, argv);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
      glutInitWindowSize(500, 500);
      glutInitWindowPosition(100, 100);
      glutCreateWindow("midpointCircle");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}
