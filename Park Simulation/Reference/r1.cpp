#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14

using namespace std;


static float	tx	=  0.0,bx=0.0,by=0.0,isbaby=0,dolnay=0,glUp=1,angle=0,step=0,stepx=0,stepy=0,cloudleftx=0,cloudmiddlex=0,cloudrightx=0,cloudrightupx=0,countdolna=0;
static float	ty	=  5.0;


void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-20.0, 20.0, -10.0, 10.0, -15.0, 15.0);
}



void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 51; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslated(-4,8,0);
    glScaled(0.3,0.3,0);
    glColor3f(1,0.843,0);
    circle(2.5,3.5);
    glPopMatrix();
}



void sky()
{
    glPushMatrix();
    glColor3f(0.53f,0.807f,0.98f);
    glTranslated(0,10,1),
                 glBegin(GL_QUADS);
    glVertex2d(-150.0,0.0);
    glVertex2d(150.0,0.0);
    glVertex2d(150.0,-8);
    glVertex2d(-150.0,-8);
    glEnd();
    glPopMatrix();

}

void hillSide()
{
    glPushMatrix();
    glScaled(1,0.6,0);
    glPushMatrix(); //pahar
    glTranslated(-9.5,0.0,1);
    glColor3f(0.42, 0.56, 0.137);
    glTranslatef(0,5,0);
    halfcircle(12,5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(8.5,0.0,1);
    glColor3f(0.0,1.0,0);
    glTranslatef(0,5,0);
    halfcircle(15,7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.5,0.0,1);
    glColor3f(0.68, 1, 0.184);
    glTranslatef(0,5,0);
    halfcircle(6,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-13.4,5,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.0,0.0);
    glVertex2f(4.0,1.75);
    glVertex2f(5.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.2,5,1);
    glRotated(180,0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.0,0.0);
    glVertex2f(4.0,1.78);
    glVertex2f(5.0,0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void hillTree()
{
    glPushMatrix();//Big tree
    glTranslated(-15,6,0);
    glScaled(0.5,0.2,0);
    glPushMatrix();
    glTranslated(-1,-10,1);
    glColor3f(0.55,0.27,0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0,0.0);
    glVertex2d(0.0,10.0);
    glVertex2d(1.0,10.0);
    glVertex2d(1.0,0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5,0,0);
    glScaled(0.4,1,1);
    glPushMatrix();
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(7,6);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,1.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-0.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0,4.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0,6.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5,-3.0,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(4,3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5,-3.5,1);
    glColor3f(0.0,0.39,0);
    glTranslatef(0,5,0);
    circle(3,2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}

void field()
{

    glPushMatrix();
    glColor3f(0.4, 0.8039, 0);
    glBegin(GL_QUADS);
    glVertex2d(-150.0,0.0);
    glVertex2d(150.0,0.0);
    glVertex2d(150.0,-50);
    glVertex2d(-150.0,-50);
    glEnd();
    glPopMatrix();
}


void cloudMiddle()
{
    cloudmiddlex=cloudmiddlex-0.03;
    if(cloudmiddlex<-20)
    {
        cloudmiddlex=30;
    }
    //printf("%f\n",cloudmiddlex);
    glPushMatrix();
    //glTranslated(-3.5+cloudmiddlex,16,1);
    glScaled(0.5,0.2,1);
    glColor3f(1.0f,1.0f,1.0f);
    glPushMatrix();
    //glTranslated(0,-38,1),
                 //circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
   // glTranslated(1,-35,1),
                 //circle(2,3);
    glPopMatrix();

    glPushMatrix();
   // glTranslated(3,-35,1),
                // circle(2,3);
    glPopMatrix();

    glPushMatrix();
    //glTranslated(4.5,-37.5,1),
                 //circle(1.5,2.5);
    glPopMatrix();

    glPushMatrix();
    //glTranslated(2.5,-38.5,1),
                // circle(1.5,2.5);
    glPopMatrix();
    glPopMatrix();


}


void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    hillSide();

    field();
    // river();
    sun();
    cloudMiddle();
    hillTree();

    glutPostRedisplay();

    glFlush();
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1600, 1000);
    //glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Translating Circle");

    init();
    glutDisplayFunc(display);
    //glutKeyboardFunc(my_keyboard);
    //glutSpecialFunc(spe_key);
    //glutKeyboardFunc(normal_key);
   // PlaySound("2ndChoice.wav", NULL, SND_FILENAME| SND_ASYNC);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */
}
