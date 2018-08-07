#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

double x1 = 10, y1 = 20, x2 = 30, y2 = 40;

void display(void)
{
      double dx = x1 - x2, dy = y1 - y2;
      double s, xi, yi, x, y;
      if(abs(dx) > abs(dy)) s = abs(dx);
      else s = abs(dy);

      xi = dx/s;
      yi = dy/s;
      for(int k = 0, x = x1, y = y1; k <= s; k ++) {

            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            x += xi;
            y += yi;
      }

      glFlush();
}

void init(void)
{
      //glClear(GL_COLOR_BUFFER_BIT);
      //glClearColor(.7, .7, .7, .7);
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
      glutCreateWindow("DDA Line Algo");
      init();
      glutDisplayFunc(display);
      glutMainLoop();
      return 0;
}
