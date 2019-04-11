#include <GL/glut.h>  
#include <math.h>  
//int ww = 600, wh = 400;  
int first = 0;  
int xi, yi, xf, yf; 
 
void putPixel (int x, int y)  
{  
 
   glBegin (GL_POINTS);  
   glVertex2i (x, y);  
   glEnd ();  
   glFlush (); 
  } 

  void display()  
  {  
   glClearColor(0.4, 0.7, 0.5, 1.0);  
   glClear(GL_COLOR_BUFFER_BIT);  
   glFlush();  
  }

  void bresenhamAlg (int x0, int y0, int x1, int y1)  
  {  
  int dx = abs (x1 - x0);  
  int dy = abs (y1 - y0);  
  int x, y;  
  if (dx >= dy)  
  {  
   int d = 2*dy-dx;  
   int ds = 2*dy;  
   int dt = 2*(dy-dx);  
      
     if (x0 < x1)   
       {  
            x = x0;  
            y = y0;  
       }  
        else  
        {   
             x = x1;  
             y = y1;  
             x1 = x0;  
             y1 = y0;  
        }  
       putPixel (x, y);  
    while (x < x1)  
    {  
        if (d < 0)  
        d += ds;  
        else {  
               if (y < y1)
               {  
                 y++;  
                 d += dt;  
               }   
             else 
               {  
                y--;  
                d += dt;  
               }  
             }  
          x++;  
        putPixel (x, y);  
       } 
 }
       else {   
             int d = 2*dx-dy;  
             int ds = 2*dx;  
             int dt = 2*(dx-dy);  
             if (y0 < y1) {  
             x = x0;  
             y = y0;  
             }  
             else {   
             x = x1;  
             y = y1;  
             y1 = y0;  
             x1 = x0;  
             }  
            putPixel (x, y);   
        while (y < y1)  
        {  
              if (d < 0)  
                 d += ds;  
              else {  
                      if (x > x1){  
                      x--;  
                      d += dt;  
                 } else {  
                      x++;  
                      d += dt;  
                   }  
              }  
              y++;  
              putPixel (x, y);  
        }  
       }  
  }  
      
 void mouse(int btn, int state, int x, int y)  
 {  
        if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)  
        {  
           switch(first)  
          {  
           case 0:  
            xi = x;  
            yi = (480-y);  
            first = 1;  
            break;  
            case 1:  
           xf = x;  
           yf = (480-y);  
         
 glColor3f(1.0,0.0,0.0);
	bresenhamAlg(xi,yi,xi,yf);
	bresenhamAlg(xi,yf,xf,yf);
	bresenhamAlg(xf,yf,xf,yi);
	bresenhamAlg(xf,yi,xi,yi);
 glColor3f(0.0,1.0,0.0);
	bresenhamAlg(xi,(yi+yf)/2,(xi+xf)/2,yf);
	bresenhamAlg((xi+xf)/2,yf,xf,(yi+yf)/2);
	bresenhamAlg(xf,(yi+yf)/2,(xi+xf)/2,yi);
	bresenhamAlg((xi+xf)/2,yi,xi,(yi+yf)/2);	
 glColor3f(0.0,0.0,1.0);
	bresenhamAlg((xi+(xi+xf)/2)/2,(yf+(yi+yf)/2)/2,(xf+(xi+xf)/2)/2,(yf+(yi+yf)/2)/2);
	bresenhamAlg((xf+(xi+xf)/2)/2,(yf+(yi+yf)/2)/2,(xf+(xi+xf)/2)/2,(yi+(yi+yf)/2)/2);
	bresenhamAlg((xf+(xi+xf)/2)/2,(yi+(yi+yf)/2)/2,(xi+(xi+xf)/2)/2, (yi+(yi+yf)/2)/2);
	bresenhamAlg((xi+(xi+xf)/2)/2, (yi+(yi+yf)/2)/2,(xi+(xi+xf)/2)/2,(yf+(yi+yf)/2)/2);  
         first = 0;  
         break;   
        }  
        }  
       } 

 
  int main(int argc, char** argv)  
  {  
     glutInit(&argc,argv);  
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
     glutInitWindowSize(640,480);  
     glutCreateWindow("Bresenham Line Algorithm With Mouse");  
     glutDisplayFunc(display);                                       //require...
      gluOrtho2D(0.0,640.,0.0,480.0);     
     glutMouseFunc(mouse);  
     glutMainLoop();  
     return 0;  
  }  
