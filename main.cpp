#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

GLboolean angle1 = false,angle2 = false, angle3 = false, angle4 = false;
GLfloat x=2.3, y=1.38, z=2.0;
void wall(double thickness)    // function to create the walls with given thickness
{
    glPushMatrix();
        glTranslated(0.5,0.5*thickness,0.5);
        glScaled(1.0,thickness,1.0);
        //glColor3f(1.0,0.0,0.0);
        glutSolidCube(1.0);
    glPopMatrix();
}

void display(){
    GLfloat light_Intensity[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat light_Position[]={2.0f,6.0f,3.0f,0.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,light_Position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_Intensity);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,.6,100.0);//left, right, bottom, up, near, far
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x,y,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        //bed
        glPushMatrix();
            glTranslated(0.1,0.1,.1);
            glScaled(.1,1.0,.55);
            glColor3f(1,0,0);
            wall(0.05);
        glPopMatrix();
        //chair upper part
        glPushMatrix();
            glTranslated(0.55,0.2,0.39);
            glRotated(-85.0,1.0,0.0,0.0);
            glScaled(0.19,0.4,.2);
            glColor3f(0.04,0.047,0.05);
            wall(0.05);
        glPopMatrix();
        //chair 4th leg
        glPushMatrix();
            glTranslated(0.715,0.0,0.37);
            glScaled(.02,4.0,.025);
            glColor3f(0.04,0.047,0.05);
            wall(0.05);
        glPopMatrix();
        //chair 3rd leg
        glPushMatrix();
            glTranslated(0.557,0.0,0.37);
            glScaled(.02,4.0,.025);
            glColor3f(0.04,0.047,0.05);
            wall(0.05);
        glPopMatrix();
        //chair 2nd leg
        glPushMatrix();
            glTranslated(0.715,0.0,0.25);
            glScaled(.02,4.0,.025);
            glColor3f(0.04,0.047,0.05);
            wall(0.05);
        glPopMatrix();
        //chair 1st leg
        glPushMatrix();
            glTranslated(0.557,0.0,0.25);
            glScaled(.02,4.0,.025);
            glColor3f(0.04,0.047,0.05);
            wall(0.05);
        glPopMatrix();
        //chair top
        glPushMatrix();
            glTranslated(0.55,0.2,0.25);
            glScaled(0.19,0.4,.15);
            glColor3f(0.04,0.047,0.05);
            wall(0.05);
        glPopMatrix();

        //table 4th leg
        glPushMatrix();
            glTranslated(0.77,0.0,0.31);
            glScaled(.02,6.0,.02);
            glColor3f(0.87,0.1,0.35);
            wall(0.05);
        glPopMatrix();
        //table 3rd leg
        glPushMatrix();
            glTranslated(0.51,0.0,0.31);
            glScaled(.02,6.0,.02);
            glColor3f(0.87,0.1,0.35);
            wall(0.05);
        glPopMatrix();
        //table 2nd leg
        glPushMatrix();
            glTranslated(0.77,0.0,0.11);
            glScaled(.02,6.0,.02);
            glColor3f(0.87,0.1,0.35);
            wall(0.05);
        glPopMatrix();
        //table 1st leg
        glPushMatrix();
            glTranslated(0.51,0.0,0.11);
            glScaled(.02,6.0,.02);
            glColor3f(0.87,0.1,0.35);
            wall(0.05);
        glPopMatrix();
        //table top
        glPushMatrix();
            glTranslated(0.5,0.3,0.1);
            glScaled(0.3,0.5,.25);
        glColor3f(.74,.16,.87);
            wall(0.05);
        glPopMatrix();
        //base wall
        glColor3f(1,1,1);
        wall(0.1);
        //right wall
        glPushMatrix();
            glRotated(-90.0,1.0,0.0,0.0);
        glColor3f(0.98,0.94,0.9);
            wall(0.05);
        glPopMatrix();
        //left wall
        glPushMatrix();
            glRotated(90.0,0.0,0.0,1.0);
        glColor3f(0.98,0.94,0.9);
            wall(0.05);
        glPopMatrix();
    glFlush();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
	switch ( key )
	{
		case 'a':
		case 'A':
			angle1 = !angle1;
			angle2 = false;
			angle3 = false;
			break;
        case 'b':
		case 'B':
			angle2= !angle2;
			angle1 = false;
			angle3 = false;
			break;
        case 'c':
		case 'C':
			angle3= !angle3;
			angle1 = false;
			angle2 = false;
			break;
        case 'd':
		case 'D':
			angle4= !angle4;
			angle1 = false;
			angle2 = false;
			angle3 = false;
			break;
		case 27:	// Escape key
			exit(1);
	}
}

void animate()
{
	if (angle1 == true)
	{
		x += 0.001;
	}
	if (angle2 == true)
	{
		x -= 0.001;
	}
    if (angle3 == true)
	{
		y -= 0.001;
	}
	if (angle4 == true)
	{
		y += 0.001;
	}
	glutPostRedisplay();

}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("The Room");

    glutKeyboardFunc(myKeyboardFunc);
	glutDisplayFunc(display);
	glutIdleFunc(animate);


    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glViewport(0,0,640,480);
    glutMainLoop();
}
