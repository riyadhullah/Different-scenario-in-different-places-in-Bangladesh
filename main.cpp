#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#define PI           3.14159265358979323846
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
#include <mmsystem.h>
#include <stdio.h>

bool riyadh = false, rakib = false, siam= false, fahad = false;

float _move1 = 0.0f;
float _move2 = 0.0f;
float _move3 = 0.0f;

float _angle1 = 0.0f;
float _angle2 = 0.0f;

bool rainday = false;
float rain = 0.0;
float waterLevel = 0.0;

void circleSolid(float x, float y, float radius,float r,float g,float b)
{
    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r,g,b);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
//01
void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(130, 202, 255);
    glVertex2f(-90.64f,85.64f);
    glVertex2f(90.64f,85.64f);
    glVertex2f(90.64f,150.64f);
    glVertex2f(-90.64f,150.64f);
    glEnd();
}
//02
void skyR()
{
    glBegin(GL_QUADS);
    glColor3ub(99, 101, 105);
    glVertex2f(-90.64f,85.64f);
    glVertex2f(90.64f,85.64f);
    glVertex2f(90.64f,150.64f);
    glVertex2f(-90.64f,150.64f);
    glEnd();
}
//03
void ground()
{
    glBegin(GL_QUADS);
    glColor3ub(161, 161, 161);
    glVertex2f(-90.64f,60.00f);
    glVertex2f(90.64f,60.00f);
    glVertex2f(90.64f,85.64f);
    glVertex2f(-90.64f,85.64f);
    glEnd();
}
//04
void roadRakib()
{
    //Whole Road
	glBegin(GL_POLYGON);
	glColor3ub(64.0f, 64.0f, 65.0f);
	glVertex2f(-90.0f, 20.2f);
	glVertex2f(90.0f, 20.2f);
	glVertex2f(90.0f, 60.9f);
	glVertex2f(-90.0f, 60.9f);
	glEnd();

	//Border around the roadRakib
	glLineWidth(5.5);
	glBegin(GL_LINES);
	glColor3ub(255.0f, 255.0f, 255.0f);
	glVertex2f(-90.0f, 60.3f);
	glVertex2f(90.0f, 60.3f);
    glVertex2f(-90.0f, 21.1f);
	glVertex2f(90.0f, 21.1f);
    glEnd();

    //Zebra Crossing
    glLineWidth(3.5);
	glBegin(GL_LINES);
    glVertex2f(0.0f, 23.5f);
	glVertex2f(8.0f, 23.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 26.5f);
	glVertex2f(8.0f, 26.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 29.5f);
	glVertex2f(8.0f, 29.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 32.5f);
	glVertex2f(8.0f, 32.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 35.5f);
	glVertex2f(8.0f, 35.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 38.5f);
	glVertex2f(8.0f, 38.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 41.5f);
	glVertex2f(8.0f, 41.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 44.5f);
	glVertex2f(8.0f, 44.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 47.5f);
	glVertex2f(8.0f, 47.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 50.5f);
	glVertex2f(8.0f, 50.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 53.5f);
	glVertex2f(8.0f, 53.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 56.5f);
	glVertex2f(8.0f, 56.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(0.0f, 58.5f);
	glVertex2f(8.0f, 58.5f);
	glEnd();

	//Middle Line of Road
    glLineWidth(3.5);
    glColor3ub(255.0f, 255.0f, 255.0f);
	glBegin(GL_LINES);
    glVertex2f(-90.0f, 40.5f);
	glVertex2f(-80.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(-70.0f, 40.5f);
	glVertex2f(-60.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(-50.0f, 40.5f);
	glVertex2f(-40.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(-30.0f, 40.5f);
	glVertex2f(-20.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(-10.0f, 40.5f);
	glVertex2f(-0.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(10.0f, 40.5f);
	glVertex2f(20.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(30.0f, 40.5f);
	glVertex2f(40.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(50.0f, 40.5f);
	glVertex2f(60.0f, 40.5f);
	glEnd();
	glBegin(GL_LINES);
    glVertex2f(70.0f, 40.5f);
	glVertex2f(80.0f, 40.5f);
	glEnd();
}
//05
void river()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(-1.0f, 95.0f, 0.0f);
glScalef(120.0f, 120.0f,1.0f);

glBegin(GL_QUADS);
glColor3ub (30,144,255);
//river with sky blue color
glVertex2f(-1.0f, -0.70f);
glVertex2f(-1.0f, -1.50f);
glVertex2f(1.0f, -1.50f);
glVertex2f(1.0f, -0.70f);
glEnd();
//between river and roadRakib
glBegin(GL_QUADS);
glColor3ub (240,230,140);
glVertex2f(-1.0f, -0.70f);
glVertex2f(-1.0f, -0.65f);
glVertex2f(1.0f, -0.65f);
glVertex2f(1.0f, -0.70f);
glEnd();
glPopMatrix();
}
//06
void railing()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(50.0f, 30.0f, 0.0f);
glScalef(80.0f, 78.0f,1.0f);

//Vertical Bar
for(float j=-90.0f; j<=90.0f; j+=0.05f)
{
glLineWidth(6.0);
glBegin(GL_LINES);
glColor3f(0.5f,0.0f,0.0f);
glVertex2f(j,-0.04);
glVertex2f(j,-0.18);
glEnd();
}
//Horizontal Bar
glBegin(GL_LINES);
glColor3ub(60.0f,25.0f,10.0f);
glVertex2f(-90.0,-0.08);
glVertex2f(90.0,-0.08);
glEnd();
glBegin(GL_LINES);
glColor3ub(60.0f,25.0f,10.0f);
glVertex2f(-90.0,-0.16);
glVertex2f(90.0,-0.16);
glEnd();
glPopMatrix();
}
//07
void houseRakib()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

    //Whole House
    glBegin(GL_QUADS);
    glColor3ub(248, 167, 5);
    glVertex2f(-88.0f,85.0f);
    glVertex2f(-75.0f,85.0f);
    glVertex2f(-75.0f,125.0f);
    glVertex2f(-88.0f,125.0f);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(25, 248, 5);
    glVertex2f(-84.0f,85.0f);
    glVertex2f(-80.0f,85.0f);
    glVertex2f(-80.0f,95.0f);
    glVertex2f(-84.0f,95.0f);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glColor3ub(91, 133, 87);
    glVertex2f(-86.0f,99.0f);
    glVertex2f(-84.0f,99.0f);
    glVertex2f(-84.0f,105.0f);
    glVertex2f(-86.0f,105.0f);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(91, 133, 87);
    glVertex2f(-86.0f+6,99.0f);
    glVertex2f(-84.0f+6,99.0f);
    glVertex2f(-84.0f+6,105.0f);
    glVertex2f(-86.0f+6,105.0f);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glColor3ub(91, 133, 87);
    glVertex2f(-86.0f,99.0f+8);
    glVertex2f(-84.0f,99.0f+8);
    glVertex2f(-84.0f,105.0f+8);
    glVertex2f(-86.0f,105.0f+8);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glColor3ub(91, 133, 87);
    glVertex2f(-86.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,105.0f+8);
    glVertex2f(-86.0f+6,105.0f+8);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f,99.0f+16);
    glVertex2f(-84.0f,99.0f+16);
    glVertex2f(-84.0f,105.0f+16);
    glVertex2f(-86.0f,105.0f+16);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,105.0f+16);
    glVertex2f(-86.0f+6,105.0f+16);
    glEnd();

    //Below houseRakib stand
    glBegin(GL_QUADS);
    glColor3ub(89, 67, 21);
    glVertex2f(-89.5f,83.0f);
    glVertex2f(-73.5f,83.0f);
    glVertex2f(-73.5f,86.9f);
    glVertex2f(-89.5f,86.9f);
    glEnd();

    glPopMatrix();
}
//08
void house1()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(20.0f, 0.0f, 0.0f);

    //Whole House
    glBegin(GL_QUADS);
    glColor3ub(5, 74, 248);
    glVertex2f(-88.0f,85.0f);
    glVertex2f(-75.0f,85.0f);
    glVertex2f(-75.0f,125.0f);
    glVertex2f(-88.0f,125.0f);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-84.0f,85.0f);
    glVertex2f(-80.0f,85.0f);
    glVertex2f(-80.0f,95.0f);
    glVertex2f(-84.0f,95.0f);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f,99.0f);
    glVertex2f(-84.0f,99.0f);
    glVertex2f(-84.0f,105.0f);
    glVertex2f(-86.0f,105.0f);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f+6,99.0f);
    glVertex2f(-84.0f+6,99.0f);
    glVertex2f(-84.0f+6,105.0f);
    glVertex2f(-86.0f+6,105.0f);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f,99.0f+8);
    glVertex2f(-84.0f,99.0f+8);
    glVertex2f(-84.0f,105.0f+8);
    glVertex2f(-86.0f,105.0f+8);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,105.0f+8);
    glVertex2f(-86.0f+6,105.0f+8);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f,99.0f+16);
    glVertex2f(-84.0f,99.0f+16);
    glVertex2f(-84.0f,105.0f+16);
    glVertex2f(-86.0f,105.0f+16);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,105.0f+16);
    glVertex2f(-86.0f+6,105.0f+16);
    glEnd();

    //Below houseRakib stand
    glBegin(GL_QUADS);
    glColor3ub(89, 67, 21);
    glVertex2f(-89.5f,83.0f);
    glVertex2f(-73.5f,83.0f);
    glVertex2f(-73.5f,86.9f);
    glVertex2f(-89.5f,86.9f);
    glEnd();

    glPopMatrix();
}
//09
void house2()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(130.0f, 0.0f, 0.0f);

    //Whole House
    glBegin(GL_QUADS);
    glColor3ub(92, 92, 61);
    glVertex2f(-88.0f,85.0f);
    glVertex2f(-75.0f,85.0f);
    glVertex2f(-75.0f,125.0f);
    glVertex2f(-88.0f,125.0f);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-84.0f,85.0f);
    glVertex2f(-80.0f,85.0f);
    glVertex2f(-80.0f,95.0f);
    glVertex2f(-84.0f,95.0f);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f,99.0f);
    glVertex2f(-84.0f,99.0f);
    glVertex2f(-84.0f,105.0f);
    glVertex2f(-86.0f,105.0f);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+6,99.0f);
    glVertex2f(-84.0f+6,99.0f);
    glVertex2f(-84.0f+6,105.0f);
    glVertex2f(-86.0f+6,105.0f);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f,99.0f+8);
    glVertex2f(-84.0f,99.0f+8);
    glVertex2f(-84.0f,105.0f+8);
    glVertex2f(-86.0f,105.0f+8);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,105.0f+8);
    glVertex2f(-86.0f+6,105.0f+8);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f,99.0f+16);
    glVertex2f(-84.0f,99.0f+16);
    glVertex2f(-84.0f,105.0f+16);
    glVertex2f(-86.0f,105.0f+16);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,105.0f+16);
    glVertex2f(-86.0f+6,105.0f+16);
    glEnd();

    //Below houseRakib stand
    glBegin(GL_QUADS);
    glColor3ub(89, 67, 21);
    glVertex2f(-89.5f,83.0f);
    glVertex2f(-73.5f,83.0f);
    glVertex2f(-73.5f,86.9f);
    glVertex2f(-89.5f,86.9f);
    glEnd();

    glPopMatrix();
}
//10
void house3()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(110.0f, 0.0f, 0.0f);

    //Whole House
    glBegin(GL_QUADS);
    glColor3ub(5, 115, 130);
    glVertex2f(-88.0f,85.0f);
    glVertex2f(-75.0f,85.0f);
    glVertex2f(-75.0f,125.0f);
    glVertex2f(-88.0f,125.0f);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-84.0f,85.0f);
    glVertex2f(-80.0f,85.0f);
    glVertex2f(-80.0f,95.0f);
    glVertex2f(-84.0f,95.0f);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f,99.0f);
    glVertex2f(-84.0f,99.0f);
    glVertex2f(-84.0f,105.0f);
    glVertex2f(-86.0f,105.0f);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+6,99.0f);
    glVertex2f(-84.0f+6,99.0f);
    glVertex2f(-84.0f+6,105.0f);
    glVertex2f(-86.0f+6,105.0f);
    glEnd();

    //window 3
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f,99.0f+8);
    glVertex2f(-84.0f,99.0f+8);
    glVertex2f(-84.0f,105.0f+8);
    glVertex2f(-86.0f,105.0f+8);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glColor3ub(200, 92, 221);
    glVertex2f(-86.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,99.0f+8);
    glVertex2f(-84.0f+6,105.0f+8);
    glVertex2f(-86.0f+6,105.0f+8);
    glEnd();

    //window 5
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f,99.0f+16);
    glVertex2f(-84.0f,99.0f+16);
    glVertex2f(-84.0f,105.0f+16);
    glVertex2f(-86.0f,105.0f+16);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,99.0f+16);
    glVertex2f(-84.0f+6,105.0f+16);
    glVertex2f(-86.0f+6,105.0f+16);
    glEnd();

    //Below houseRakib stand
    glBegin(GL_QUADS);
    glColor3ub(89, 67, 21);
    glVertex2f(-89.5f,83.0f);
    glVertex2f(-73.5f,83.0f);
    glVertex2f(-73.5f,86.9f);
    glVertex2f(-89.5f,86.9f);
    glEnd();

    glPopMatrix();
}
//11
void school()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(60.0f, 0.0f, 0.0f);
glScalef(1.2f, 1.0f,1.0f);

    //Whole School
    glBegin(GL_QUADS);
    glColor3ub(222, 49, 99);
    glVertex2f(-88.0f,85.0f);
    glVertex2f(-73.0f,85.0f);
    glVertex2f(-73.0f,115.0f);
    glVertex2f(-88.0f,115.0f);
    glEnd();

    //door
    glBegin(GL_QUADS);
    glColor3ub(50, 43, 65);
    glVertex2f(-84.0f,85.0f);
    glVertex2f(-77.0f,85.0f);
    glVertex2f(-77.0f,93.0f);
    glVertex2f(-84.0f,93.0f);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glColor3ub(44, 35, 211);
    glVertex2f(-86.0f,96.0f);
    glVertex2f(-84.0f,96.0f);
    glVertex2f(-84.0f,100.0f);
    glVertex2f(-86.0f,100.0f);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(44, 35, 211);
    glVertex2f(-86.0f+3,96.0f);
    glVertex2f(-84.0f+3,96.0f);
    glVertex2f(-84.0f+3,100.0f);
    glVertex2f(-86.0f+3,100.0f);
    glEnd();

    //window3
    glBegin(GL_QUADS);
    glColor3ub(44, 35, 211);
    glVertex2f(-86.0f+6,96.0f);
    glVertex2f(-84.0f+6,96.0f);
    glVertex2f(-84.0f+6,100.0f);
    glVertex2f(-86.0f+6,100.0f);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glColor3ub(44, 35, 211);
    glVertex2f(-86.0f+9,96.0f);
    glVertex2f(-84.0f+9,96.0f);
    glVertex2f(-84.0f+9,100.0f);
    glVertex2f(-86.0f+9,100.0f);
    glEnd();


    //window 5
    glBegin(GL_QUADS);
    glColor3ub(218, 247, 166);
    glVertex2f(-86.0f,94.0f+8);
    glVertex2f(-84.0f,94.0f+8);
    glVertex2f(-84.0f,98.0f+8);
    glVertex2f(-86.0f,98.0f+8);
    glEnd();

    //window 6
    glBegin(GL_QUADS);
    glColor3ub(218, 247, 166);
    glVertex2f(-86.0f+3,94.0f+8);
    glVertex2f(-84.0f+3,94.0f+8);
    glVertex2f(-84.0f+3,98.0f+8);
    glVertex2f(-86.0f+3,98.0f+8);
    glEnd();

    //window7
    glBegin(GL_QUADS);
    glColor3ub(218, 247, 166);
    glVertex2f(-86.0f+6,94.0f+8);
    glVertex2f(-84.0f+6,94.0f+8);
    glVertex2f(-84.0f+6,98.0f+8);
    glVertex2f(-86.0f+6,98.0f+8);
    glEnd();

    //window8
    glBegin(GL_QUADS);
    glColor3ub(218, 247, 166);
    glVertex2f(-86.0f+9,94.0f+8);
    glVertex2f(-84.0f+9,94.0f+8);
    glVertex2f(-84.0f+9,98.0f+8);
    glVertex2f(-86.0f+9,98.0f+8);
    glEnd();

    //window 9
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f,92.0f+16);
    glVertex2f(-84.0f,92.0f+16);
    glVertex2f(-84.0f,96.0f+16);
    glVertex2f(-86.0f,96.0f+16);
    glEnd();

    //window 10
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+3,92.0f+16);
    glVertex2f(-84.0f+3,92.0f+16);
    glVertex2f(-84.0f+3,96.0f+16);
    glVertex2f(-86.0f+3,96.0f+16);
    glEnd();

    //window 11
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+6,92.0f+16);
    glVertex2f(-84.0f+6,92.0f+16);
    glVertex2f(-84.0f+6,96.0f+16);
    glVertex2f(-86.0f+6,96.0f+16);
    glEnd();

    //window 12
    glBegin(GL_QUADS);
    glColor3ub(179, 248, 5);
    glVertex2f(-86.0f+9,92.0f+16);
    glVertex2f(-84.0f+9,92.0f+16);
    glVertex2f(-84.0f+9,96.0f+16);
    glVertex2f(-86.0f+9,96.0f+16);
    glEnd();

    //Below school stand
    glBegin(GL_QUADS);
    glColor3ub(83, 52, 35);
    glVertex2f(-89.5f,83.0f);
    glVertex2f(-68.5f,83.0f);
    glVertex2f(-68.5f,86.9f);
    glVertex2f(-89.5f,86.9f);
    glEnd();

    //Upward school Roof
    glLineWidth(5);
	glBegin(GL_LINES);
	glColor3ub(92, 92, 61);
    glVertex2f(-89.0f, 115.2f);
	glVertex2f(-71.0f, 115.2f);
	glEnd();

    glPopMatrix();
}
//12
void flag()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(60.0f, 0.0f, 0.0f);
glScalef(1.2f, 1.0f,1.0f);

    //Flag Stand
    glLineWidth(8);
	glBegin(GL_LINES);
	glColor3ub(92, 92, 61);
    glVertex2f(-71.0f, 85.2f);
	glVertex2f(-71.0f, 110.2f);
	glEnd();

	//Flag Rectangle
    glLineWidth(26);
	glBegin(GL_LINES);
	glColor3ub(0, 159, 94);
    glVertex2f(-71.0f, 107.0f);
	glVertex2f(-66.0f, 107.0f);
	glEnd();

	//Flag Circle
    circleSolid(-68.5f,107.0f, 1.5,249,0,0);

    glPopMatrix();
}
//13
void tree()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(7.0f, 60.0f, 0.0f);
glScalef(150.0f, 180.0f,1.0f);

    //Tree stand
    glBegin(GL_QUADS);
    glColor3ub(92, 92, 61);
    glVertex2f(-0.05f,-0.01f);
    glVertex2f(-0.03f,-0.01f);
    glVertex2f(-0.03f,0.24f);
    glVertex2f(-0.05f,0.24f);
    glEnd();

    //Tree shield
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(92, 92, 61);
    glVertex2f(-0.04f, 0.23f);
    glVertex2f(-0.09f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.04f, 0.23f);
    glVertex2f(0.01f, 0.27f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.04f, 0.24f);
    glVertex2f(-0.04f, 0.32f);
    glEnd();

    //Tree Leaves
    circleSolid(-0.10f, 0.28f, 0.03,0, 255, 0);
    circleSolid(-0.11f, 0.31f, 0.03,0, 255, 0);
    circleSolid(-0.09f, 0.33f, 0.03,0, 255, 0);
    circleSolid(-0.04f, 0.33f, 0.03,0, 255, 0);
    circleSolid(0.0f, 0.33f, 0.03,0, 255, 0);
    circleSolid(0.02f, 0.31f, 0.03,0, 255, 0);
    circleSolid(0.03f, 0.28f, 0.03,0, 255, 0);
    glEnd();

    glPopMatrix();
}
//14
void lambpost()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(50.0f, 0.0f, 0.0f);

    //Lamp Stand
	glColor3ub(0, 1, 0);
    glLineWidth(15);
	glBegin(GL_LINES);
    glVertex2f(-2.0f, 20.0f);
	glVertex2f(-2.0f, 70.0f);
	glEnd();

	//Hanging lamp bar
    glColor3ub(55, 59, 58);
    glLineWidth(11);
	glBegin(GL_LINES);
    glVertex2f(2.0f, 62.5f);
	glVertex2f(-10.0f, 67.5f);
	glEnd();

	//Lamp
    circleSolid(-8.5f,64.0f, 2.03,244, 233, 6 );

    glPopMatrix();
}
//15
void lambpost1()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(-70.0f, 0.0f, 0.0f);

    //Lamp Stand
	glColor3ub(0, 1, 0);
    glLineWidth(15);
	glBegin(GL_LINES);
    glVertex2f(-2.0f, 20.0f);
	glVertex2f(-2.0f, 70.0f);
	glEnd();

	//Hanging lamp bar
    glColor3ub(55, 59, 58);
    glLineWidth(11);
	glBegin(GL_LINES);
    glVertex2f(2.0f, 62.5f);
	glVertex2f(-10.0f, 67.5f);
	glEnd();

	//Lamp
    circleSolid(-8.5f,64.0f, 2.03,244, 233, 6 );

    glPopMatrix();
}
//16
void traflight()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(0.0f, 40.0f, 0.0f);

    //Vertical Stand of traffic light
	glColor3ub(83, 52, 35);
    glLineWidth(15);
	glBegin(GL_LINES);
    glVertex2f(-2.0f, 27.5f);
	glVertex2f(-2.0f, 65.5f);
	glEnd();

    //Upper Horizontal Stand of traffic light
    glColor3ub(55, 59, 58);
    glLineWidth(25);
	glBegin(GL_LINES);
    glVertex2f(2.0f, 65.5f);
	glVertex2f(-10.0f, 65.5f);
	glEnd();

	//Traffic rgb light
	glPointSize(15.0);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-8.0f, 65.5f);
	glEnd();

	glBegin(GL_POINTS);
    glColor3ub(252, 240, 0 );
	glVertex2f(-5.0f, 65.5f);
	glEnd();

	glBegin(GL_POINTS);
    glColor3ub(0, 251, 71 );
	glVertex2f(-2.0f, 65.5f);
	glEnd();

	glPopMatrix();
}
//17
void sun()
{
glPushMatrix();
glTranslatef( 0.0f,0.0f,0.0f);
glRotatef(_angle1, 0.0f, 0.0f,1.0f);
glTranslatef( 0.0f,0.0f,0.0f);

    circleSolid(90.0f,120.0f,8.0,253, 208, 23);

    glPopMatrix();
}
//18
void carRakib()
{
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glTranslatef(_move1, 83.0f, 0.0f);
glScalef(90.0f, 90.0f,1.0f);

    glBegin(GL_POLYGON);
    glColor3ub(25,25,112);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.38f, -0.26f);
    glVertex2f(-0.35f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.62f, -0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.50f, -0.19f);
	glVertex2f(-0.50f, -0.25f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(204,0,0);
	glVertex2f(-0.62f, -0.29f);
    glVertex2f(-0.62f, -0.26f);
	glEnd();

    // Front wheel
    glPushMatrix();
    glTranslatef(-0.55f, -0.31f, 0.0f); // Translate to wheel position
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f); // Apply rotation
    circleSolid(0.0f, 0.0f, 0.03f, 0.0f, 0.0f, 0.0f); // Draw wheel
    glPopMatrix();

    // Rear wheel
    glPushMatrix();
    glTranslatef(-0.42f, -0.31f, 0.0f); // Translate to wheel position
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f); // Apply rotation
    circleSolid(0.0f, 0.0f, 0.03f, 0.0f, 0.0f, 0.0f); // Draw wheel
    glPopMatrix();

    glPopMatrix();
}
//19
void car2()
{
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glTranslatef(_move1-30, 58.0f, 0.0f);
glScalef(90.0f, 90.0f,1.0f);

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.38f, -0.26f);
    glVertex2f(-0.35f, -0.31f);
    glVertex2f(-0.61f, -0.31f);
    glVertex2f(-0.62f, -0.30f);
    glVertex2f(-0.62f, -0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.50f, -0.19f);
	glVertex2f(-0.50f, -0.25f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-0.58f, -0.25f);
    glVertex2f(-0.55f, -0.19f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.55f, -0.19f);
    glVertex2f(-0.45f, -0.19f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.45f, -0.19f);
    glVertex2f(-0.42f, -0.25f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.42f, -0.25f);
    glVertex2f(-0.58f, -0.25f);
	glEnd();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3ub(204,0,0);
	glVertex2f(-0.62f, -0.29f);
    glVertex2f(-0.62f, -0.26f);
	glEnd();

    // Front wheel
    glPushMatrix();
    glTranslatef(-0.55f, -0.31f, 0.0f); // Translate to wheel position
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f); // Apply rotation
    circleSolid(0.0f, 0.0f, 0.03f, 0.0f, 0.0f, 0.0f); // Draw wheel
    glPopMatrix();

    // Rear wheel
    glPushMatrix();
    glTranslatef(-0.42f, -0.31f, 0.0f); // Translate to wheel position
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f); // Apply rotation
    circleSolid(0.0f, 0.0f, 0.03f, 0.0f, 0.0f, 0.0f); // Draw wheel
    glPopMatrix();

    glPopMatrix();
}
//20
void clouds()
{
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glTranslatef(_move1, 90.0f, 0.0f);
glScalef(120.0f, 120.0f,1.0f);

    circleSolid(0.23f,0.43f,0.04,255, 255, 255);
    circleSolid(0.21f,0.42f,0.04,255, 255, 255);
    circleSolid(0.21f,0.40f,0.04,255, 255, 255);
    circleSolid(0.23f,0.41f,0.04,255, 255, 255);
    circleSolid(0.19f,0.43f,0.04,255, 255, 255);
    circleSolid(0.19f,0.40f,0.04,255, 255, 255);
    circleSolid(0.17f,0.42f,0.04,255, 255, 255);
    circleSolid(0.18f,0.41f,0.04,255, 255, 255);
    circleSolid(0.16f,0.41f,0.04,255, 255, 255);

    circleSolid(-0.43f,0.38f,0.04,255, 255, 255);
    circleSolid(-0.41f,0.37f,0.04,255, 255, 255);
    circleSolid(-0.41f,0.36f,0.04,255, 255, 255);
    circleSolid(-0.43f,0.37f,0.04,255, 255, 255);
    circleSolid(-0.39f,0.38f,0.04,255, 255, 255);
    circleSolid(-0.39f,0.36f,0.04,255, 255, 255);
    circleSolid(-0.37f,0.37f,0.04,255, 255, 255);
    circleSolid(-0.38f,0.36f,0.04,255, 255, 255);
    circleSolid(-0.36f,0.37f,0.04,255, 255, 255);

    circleSolid(0.43f,0.38f,0.04,255, 255, 255);
    circleSolid(0.41f,0.37f,0.04,255, 255, 255);
    circleSolid(0.41f,0.36f,0.04,255, 255, 255);
    circleSolid(0.43f,0.37f,0.04,255, 255, 255);
    circleSolid(0.39f,0.38f,0.04,255, 255, 255);
    circleSolid(0.39f,0.36f,0.04,255, 255, 255);
    circleSolid(0.37f,0.37f,0.04,255, 255, 255);
    circleSolid(0.38f,0.36f,0.04,255, 255, 255);
    circleSolid(0.36f,0.37f,0.04,255, 255, 255);

    circleSolid(-0.13f,0.43f,0.04,255, 255, 255);
    circleSolid(-0.11f,0.42f,0.04,255, 255, 255);
    circleSolid(-0.11f,0.40f,0.04,255, 255, 255);
    circleSolid(-0.13f,0.41f,0.04,255, 255, 255);
    circleSolid(-0.09f,0.43f,0.04,255, 255, 255);
    circleSolid(-0.09f,0.40f,0.04,255, 255, 255);
    circleSolid(-0.07f,0.42f,0.04,255, 255, 255);
    circleSolid(-0.04f,0.41f,0.04,255, 255, 255);
    circleSolid(-0.06f,0.41f,0.04,255, 255, 255);
    glPopMatrix();
}
//21
void cloudsR()
{
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glTranslatef(_move1, 90.0f, 0.0f);
glScalef(120.0f, 120.0f,1.0f);

    circleSolid(0.23f,0.43f,0.04,210, 211, 214);
    circleSolid(0.21f,0.42f,0.04,210, 211, 214);
    circleSolid(0.21f,0.40f,0.04,210, 211, 214);
    circleSolid(0.23f,0.41f,0.04,210, 211, 214);
    circleSolid(0.19f,0.43f,0.04,210, 211, 214);
    circleSolid(0.19f,0.40f,0.04,210, 211, 214);
    circleSolid(0.17f,0.42f,0.04,210, 211, 214);
    circleSolid(0.18f,0.41f,0.04,210, 211, 214);
    circleSolid(0.16f,0.41f,0.04,210, 211, 214);

    circleSolid(-0.43f,0.38f,0.04,210, 211, 214);
    circleSolid(-0.41f,0.37f,0.04,210, 211, 214);
    circleSolid(-0.41f,0.36f,0.04,210, 211, 214);
    circleSolid(-0.43f,0.37f,0.04,210, 211, 214);
    circleSolid(-0.39f,0.38f,0.04,210, 211, 214);
    circleSolid(-0.39f,0.36f,0.04,210, 211, 214);
    circleSolid(-0.37f,0.37f,0.04,210, 211, 214);
    circleSolid(-0.38f,0.36f,0.04,210, 211, 214);
    circleSolid(-0.36f,0.37f,0.04,210, 211, 214);

    circleSolid(0.43f,0.38f,0.04,210, 211, 214);
    circleSolid(0.41f,0.37f,0.04,210, 211, 214);
    circleSolid(0.41f,0.36f,0.04,210, 211, 214);
    circleSolid(0.43f,0.37f,0.04,210, 211, 214);
    circleSolid(0.39f,0.38f,0.04,210, 211, 214);
    circleSolid(0.39f,0.36f,0.04,210, 211, 214);
    circleSolid(0.37f,0.37f,0.04,210, 211, 214);
    circleSolid(0.38f,0.36f,0.04,210, 211, 214);
    circleSolid(0.36f,0.37f,0.04,210, 211, 214);

    circleSolid(-0.13f,0.43f,0.04,210, 211, 214);
    circleSolid(-0.11f,0.42f,0.04,210, 211, 214);
    circleSolid(-0.11f,0.40f,0.04,210, 211, 214);
    circleSolid(-0.13f,0.41f,0.04,210, 211, 214);
    circleSolid(-0.09f,0.43f,0.04,210, 211, 214);
    circleSolid(-0.09f,0.40f,0.04,210, 211, 214);
    circleSolid(-0.07f,0.42f,0.04,210, 211, 214);
    circleSolid(-0.04f,0.41f,0.04,210, 211, 214);
    circleSolid(-0.06f,0.41f,0.04,210, 211, 214);
    glPopMatrix();
}
//22
void windmill()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
    glLineWidth(10);
	glBegin(GL_LINES);
	glColor3ub(23, 163, 37);
    glVertex2f(70.5f, 85.2f);
	glVertex2f(72.0f, 130.2f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(23, 163, 37);
    glVertex2f(73.5f, 85.2f);
	glVertex2f(72.0f, 130.2f);
	glEnd();
glPopMatrix();
}
//23
void winwheel()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();

glTranslatef(72.0f, 130.0f, 0.0f);
glRotatef(_angle2, 0.0f, 0.0f,1.0f);
glTranslatef(-72.0f, -130.0f, 0.0f);

    glLineWidth(25);

	glBegin(GL_LINES);
	glColor3ub(0,0,255);
    glVertex2f(72.0f, 130.0f);
	glVertex2f(72.0f, 115.0f);
    glEnd();
	glBegin(GL_LINES);
	glColor3ub(0,0,255);
    glVertex2f(72.0f, 130.0f);
	glVertex2f(72.0f, 145.0f);
    glEnd();
	glBegin(GL_LINES);
	glColor3ub(0,0,255);
    glVertex2f(72.0f, 130.0f);
	glVertex2f(57.0f, 130.0f);
    glEnd();
	glBegin(GL_LINES);
	glColor3ub(0,0,255);
    glVertex2f(72.0f, 130.0f);
	glVertex2f(87.0f, 130.0f);
	glEnd();

    circleSolid(72.0f,130.0f, 2.4, 255, 0, 0);

    glPopMatrix();
}
//24
void skyN()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-90.64f,85.64f);
    glVertex2f(90.64f,85.64f);
    glVertex2f(90.64f,150.64f);
    glVertex2f(-90.64f,150.64f);
    glEnd();
}
//25
void starRakib()
{
    //Night Moon
   circleSolid(30,140.0,8.0,255.0f, 255.0f, 255.0f);
   circleSolid(29.0f,142.0,6.7,0.0f, 0.0f, 0.0f);
   glEnd();

    //Night Stars
   circleSolid(40,130.0,0.9,255.0f, 255.0f, 255.0f);
   circleSolid(20,130.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-20,130.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-40,130.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-70,150.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-16,140.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-6,133.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(0,110.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(10,116.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(88,130.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(80,150.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(70,140.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(65,129.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(16,120.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(22,117.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(54,100.0,1.0,255.0f, 255.0f, 255.0f);
   circleSolid(-80,150.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(67,144.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(45,147.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-16,130.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-22,122.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-77,130.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-35,138.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-76,144.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-87,137.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-84,136.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-55,122.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-66,139.0,0.6,255.0f, 255.0f, 255.0f);
   circleSolid(-70,133.0,0.6,255.0f, 255.0f, 255.0f);
   glEnd();
}
//26
void boat()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(_move3, 85.0f, 0.0f);
glScalef(105.0f, 105.0f,1.0f);

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(-0.03f, -0.92f);
glVertex2f(0.03f,-0.92f);
glVertex2f(0.13f, -0.85f);
glVertex2f(-0.13f,-0.85f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f);
glVertex2f(0.10f, -0.85f);
glVertex2f(-0.10f,-0.85f);
glVertex2f(-0.10f, -0.83f);
glVertex2f(0.10f, -0.83f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f);
glVertex2f(0.07f, -0.83f);
glVertex2f(-0.07f,-0.83f);
glVertex2f(-0.07f, -0.81f);
glVertex2f(0.07f, -0.81f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.05f, -0.81f);
glVertex2f(-0.04f,-0.81f);
glVertex2f(-0.04f, -0.79f);
glVertex2f(-0.05f, -0.79f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(-0.01f, -0.81f);
glVertex2f(0.0f,-0.81f);
glVertex2f(0.0f, -0.79f);
glVertex2f(-0.01f, -0.79f);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(0.03f, -0.81f);
glVertex2f(0.04f,-0.81f);
glVertex2f(0.04f, -0.79f);
glVertex2f(0.03f, -0.79f);
glEnd();
glPopMatrix();
}
//27
void drawWaterLevel()
{
    // Set water color (blue)
    glColor3ub(30,144,255);
    glBegin(GL_POLYGON);
    // Draw a rectangle representing the water level
    glVertex2f(-90, -30);
    glVertex2f(90, -30);
    glVertex2f(90, -20+ waterLevel);
    glVertex2f(80, -30+ waterLevel);
    glVertex2f(50, -20+ waterLevel);
    glVertex2f(-50, -30+ waterLevel);
    glVertex2f(-70, -20+ waterLevel);
    glVertex2f(-90, -30+ waterLevel);
    glEnd();
}
//28
void Rain(int value)
{
if(rainday)
{
rain -= 100.09f;
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(-90.0f, -30.0f, 0.0f);
glBegin(GL_POINTS);
for(int i=1;i<=1200;i++)
{
int x = rand() % 1200;  // Random x-coordinate (screen width)
int y = rand() % 1000;  // Random y-coordinate (screen height)
glLineWidth(3);
glBegin(GL_LINES);
glColor3f(1.0, 1.0, 1.0);
glVertex2f(x,y);
glVertex2f(x+5,y+9);
glEnd();
}
// Increase water level
waterLevel += 0.2f; // Increment water level
if (waterLevel > 105) // Limit the water level to prevent overflow
waterLevel = 105;
glPopMatrix();
glFlush();
glutPostRedisplay();
glutTimerFunc(10, Rain, 0);
}
}
//29
void bench()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(-80.0f, 82.0f, 0.0f);
glScalef(4.0f, 3.0f,1.0f);

    glBegin(GL_POLYGON);
    glColor3ub(252, 123, 3);
    glVertex2f(3, -3);
    glVertex2f(3.5964184138402, -2.0014137599239);
    glVertex2f(7.4142044638252, -1.9862034569359);
    glVertex2f(8, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(3.4138947779843, -4.2221179961701);
    glVertex2f(3.3986844749963, -2.9900834541431);
    glVertex2f(3.794152352684, -2.9900834541431);
    glVertex2f(3.809362655672, -4.2221179961701);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(7.2012602219933, -4.2069076931821);
    glVertex2f(7.2012602219933, -2.9900834541431);
    glVertex2f(7.596728099681, -2.9900834541431);
    glVertex2f(7.611938402669, -4.2069076931821);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(4, -2);
    glVertex2f(4,0);
    glVertex2f(4.39,0);
    glVertex2f(4.3873541692155, -1.9862034569359);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(6.5928481024738, -2.0014137599239);
    glVertex2f(6.54,0);
    glVertex2f(7,0);
    glVertex2f(7,-2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(177, 252, 3);
    glVertex2f(3.6116287168282, -1.5907355792482);
    glVertex2f(3.6116287168282, -1.1952677015605);
    glVertex2f(7.4142044638252, -1.2104780045485);
    glVertex2f(7.4142044638252, -1.5603149732722);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(177, 252, 3);
    glVertex2f(3.5812081108522, -0.8150101268608);
    glVertex2f(3.6116287168282, -0.4043319461851);
    glVertex2f(7.4142044638252, -0.3891216431972);
    glVertex2f(7.4142044638252, -0.7997998238728);
    glEnd();

glPopMatrix();
}
//30
void bench1()
{
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glTranslatef(40.0f, 82.0f, 0.0f);
glScalef(4.0f, 3.0f,1.0f);

    glBegin(GL_POLYGON);
    glColor3ub(252, 123, 3);
    glVertex2f(3, -3);
    glVertex2f(3.5964184138402, -2.0014137599239);
    glVertex2f(7.4142044638252, -1.9862034569359);
    glVertex2f(8, -3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(3.4138947779843, -4.2221179961701);
    glVertex2f(3.3986844749963, -2.9900834541431);
    glVertex2f(3.794152352684, -2.9900834541431);
    glVertex2f(3.809362655672, -4.2221179961701);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(7.2012602219933, -4.2069076931821);
    glVertex2f(7.2012602219933, -2.9900834541431);
    glVertex2f(7.596728099681, -2.9900834541431);
    glVertex2f(7.611938402669, -4.2069076931821);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(4, -2);
    glVertex2f(4,0);
    glVertex2f(4.39,0);
    glVertex2f(4.3873541692155, -1.9862034569359);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 65, 3);
    glVertex2f(6.5928481024738, -2.0014137599239);
    glVertex2f(6.54,0);
    glVertex2f(7,0);
    glVertex2f(7,-2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(177, 252, 3);
    glVertex2f(3.6116287168282, -1.5907355792482);
    glVertex2f(3.6116287168282, -1.1952677015605);
    glVertex2f(7.4142044638252, -1.2104780045485);
    glVertex2f(7.4142044638252, -1.5603149732722);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(177, 252, 3);
    glVertex2f(3.5812081108522, -0.8150101268608);
    glVertex2f(3.6116287168282, -0.4043319461851);
    glVertex2f(7.4142044638252, -0.3891216431972);
    glVertex2f(7.4142044638252, -0.7997998238728);
    glEnd();

glPopMatrix();
}
//31
void displayRakib() //hello
{
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
sky();
houseRakib();
house1();
house2();
house3();
school();
flag();
tree();
river();
ground();
bench();
bench1();
roadRakib();
carRakib();
car2();
clouds();
sun();
windmill();
winwheel();
traflight();
lambpost();
lambpost1();
railing();
boat();

glFlush();
glutSwapBuffers();
}

void displayR()
{
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
skyR();
houseRakib();
house1();
house2();
house3();
school();
flag();
tree();
river();
ground();
roadRakib();
carRakib();
car2();
cloudsR();
windmill();
winwheel();
drawWaterLevel();
bench();
bench1();
traflight();
lambpost();
lambpost1();
railing();
boat();

glFlush();
glutSwapBuffers();
}
//32
void displayN()
{
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

skyN();
starRakib();
houseRakib();
house1();
house2();
house3();
school();
flag();
tree();
river();
ground();
bench();
bench1();
roadRakib();
carRakib();
car2();
windmill();
winwheel();
traflight();
lambpost();
lambpost1();
railing();
boat();

glFlush();
glutSwapBuffers();
}

void displayNR()
{
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
skyN();
starRakib();
houseRakib();
house1();
house2();
house3();
school();
flag();
tree();
river();
ground();
roadRakib();
carRakib();
car2();
windmill();
winwheel();
drawWaterLevel();
bench();
bench1();
traflight();
lambpost();
lambpost1();
railing();
boat();

glFlush();
glutSwapBuffers();
}

void init()
{
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
gluOrtho2D(-90,90,-30,150);
}

void handleKeypress(unsigned char key, int x, int y)
{
switch (key)
{

case 'n':
    rainday = false;
    waterLevel = 0.0;
glutPostRedisplay();
glutDisplayFunc(displayN);
break;

case 'r':
        rainday = true;
        Rain(rain);
glutPostRedisplay();
glutDisplayFunc(displayR);
break;

case 't':
        rainday = true;
        Rain(rain);
glutPostRedisplay();
glutDisplayFunc(displayNR);
break;

case 's':
        rainday = false;
        Rain(rain);
        _angle1=0.0;
glutPostRedisplay();
break;

case 'd':
        rainday = false;
        Rain(rain);
        waterLevel = 0.0;
        _angle1=0.0;
glutPostRedisplay();
glutDisplayFunc(displayRakib);
break;

}
}

//33
void updatesun(int value)
{
    _angle1+=0.05f;
    if(_angle1 > 20.0)
    {
        _angle1=20;
    }
	glutPostRedisplay(); //Notify GLUT that the displayRakib has changed

	glutTimerFunc(30, updatesun, 0); //Notify GLUT to call update again in 30 milliseconds
}
//34
void updatecloud(int value)
{
 _move1 += 0.1;
if(_move1>150.0f)
{
_move1=-90.0f;
}
glutPostRedisplay(); //Notify GLUT that the displayRakib has changed

 glutTimerFunc(20, updatecloud, 0); //Notify GLUT to call update again in 20 milliseconds
}
//35
void updatecar(int value)
{
 _move1 += 0.3f;
if(_move1>150.0f)
{
_move1=-90.0f;
}
glutPostRedisplay(); //Notify GLUT that the displayRakib has changed

glutTimerFunc(20, updatecar, 0); //Notify GLUT to call update again in 20 milliseconds
}
//36
void updatecar2(int value)
{
 _move1 += 0.1f;
if(_move1>150.0f)
{
_move1=-90.0f;
}
glutPostRedisplay(); //Notify GLUT that the displayRakib has changed

glutTimerFunc(20, updatecar2, 0); //Notify GLUT to call update again in 20 milliseconds
}
//37
void updatewinwheell(int value)
{
    _angle2+=0.5f;
   if(_angle2 > 360.0)
   {
        _angle2=-360;
    }
	glutPostRedisplay(); //Notify GLUT that the displayRakib has changed

	glutTimerFunc(20,updatewinwheell, 0); //Notify GLUT to call update again in 20 milliseconds
}
//38
void updateboat(int value)
{
 _move3 += 0.5;
if(_move3>90.0f)
{
_move3=-90.0f;
}
glutPostRedisplay(); //Notify GLUT that the displayRakib has changed

 glutTimerFunc(20, updateboat, 0); //Notify GLUT to call update again in 20 milliseconds
}


//--------------------------- rakib end



//--------------------------- riyadh start
float _trainMove = 0.0f;
float _carMove = -90.0f;
float _newTruckMove = -109.0f;
float _oldTruckMove = -109.0f;
float _newCarMove = -54.0f;
float _oldCarMove = -54.0f;
float _wheelAngle = 0.0f;
float _sun = 0.0f;
float _cloud = 0.0f;
float _allObj = 0.0f;
bool isRaining = false;
bool isNight = false;
bool starCheck = false;
float rr = 0.4f, gg = 0.698f ,bb = 0.996f;
//float r = 0.529f, g = 0.627f ,b = 0.745f; //when rain


void update(int value) {
    _trainMove -= 0.6f;

    if(_trainMove < -180.0f)
    {
        _trainMove = 0.0f;
    }

    _sun -= 0.01f;

    if(_sun < -180.0f)
    {
        _sun = 0.0f;
    }


    if(_oldCarMove<=127)
    {
        _oldCarMove += 1.0f;
    }
    if(_oldCarMove>=127 && _oldCarMove <= 168)
    {
        _oldCarMove += 1.0f;
        _newCarMove += 1.0f;
    }
    if(_oldCarMove>=168)
    {
        _oldCarMove = _newCarMove;
        _newCarMove = -54;
    }


    if(_oldTruckMove<=71)
    {
        _oldTruckMove += 0.5f;
    }
    if(_oldTruckMove>=71 && _oldTruckMove <= 75.5)
    {
        _oldTruckMove += 0.5f;
        _newTruckMove += 0.5f;
    }
    if(_oldTruckMove>=75.5)
    {
        _oldTruckMove = _newTruckMove;
        _newTruckMove = -109;
    }


    _wheelAngle -=8.0f;
    if(_wheelAngle < 360.0)
    {
        _wheelAngle+=360;
    }

    _cloud -=0.2f;
    if(_cloud < -181.0)
    {
        _cloud = 0;
    }


    _allObj -= 0.4f;

    if(_allObj < -180.0f)
    {
        _allObj = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(20,update , 0);
}

void sceenUpdateRain(int value)
{
    if(!isRaining)
    {
        rr = 0.529f; gg = 0.627f; bb = 0.745f;
        isRaining = true;
        glutPostRedisplay();
    }

    glutTimerFunc(2000,sceenUpdateRain , 0);
}

void sceenUpdateNight(int value)
{
    if(!isNight && isRaining)
    {
        rr = 0.25f; gg = 0.25f; bb = 0.35f;
        isNight = true;
        glutPostRedisplay();
    }

    glutTimerFunc(2000,sceenUpdateNight , 0);
}

void circle1(float x, float y, float radius,float r,float g,float b, bool wheel)
{
    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glColor3f(r, g, b); // Set color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    if(wheel)
    {
        // Draw spokes
        int spokeCount=6;
        glColor3f(0.0f, 0.0f, 0.0f); // Set color for spokes
        for (int i = 0; i < spokeCount; i++)
        {
            float angle = i * twicePi / spokeCount;
            float spokeX = x + radius * cos(angle);
            float spokeY = y + radius * sin(angle);

            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex2f(x, y); // Center
            glVertex2f(spokeX, spokeY); // Edge
            glEnd();
        }
    }
}

void circle2(float x, float y, float radius,float r,float g,float b)
{
    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glColor3ub(r, g, b); // Set color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void sun(float r,float g,float b) //id: sun01
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_sun, 0.0f,0.0f);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(50.0f, 0.0f,0.0f);

	circle2(0, 120,8,r, g, b);

    glPopMatrix();
    glPopMatrix();
}

void moon(float x, float y, float radius) {
    circle2(x, y, radius, 200, 200, 200);
    circle2(x+5, y+1, radius, 64, 64, 89);
}

void star() {
    circle2(-80, 120, 0.5, 255, 255, 0);
    circle2(-75, 110, 0.5, 255, 255, 0);
    circle2(-68, 125, 0.5, 255, 255, 0);
    circle2(-65, 120, 0.5, 255, 255, 0);
    circle2(-55, 125, 0.5, 255, 255, 0);
    circle2(-50, 105, 0.5, 255, 255, 0);
    circle2(-43, 135, 0.5, 255, 255, 0);
    circle2(-37, 120, 0.5, 255, 255, 0);
    circle2(-35, 140, 0.5, 255, 255, 0);
    circle2(-28, 130, 0.5, 255, 255, 0);
    circle2(-20, 134, 0.5, 255, 255, 0);
    circle2(-11, 144, 0.5, 255, 255, 0);
    circle2(-5, 110, 0.5, 255, 255, 0);
    circle2(1, 137, 0.5, 255, 255, 0);
    circle2(9, 117, 0.5, 255, 255, 0);
    circle2(15, 145, 0.5, 255, 255, 0);

    circle2(20, 120, 0.5, 255, 255, 0);
    circle2(22, 110, 0.5, 255, 255, 0);
    circle2(25, 125, 0.5, 255, 255, 0);
    circle2(33, 120, 0.5, 255, 255, 0);
    circle2(40, 125, 0.5, 255, 255, 0);
    circle2(45, 105, 0.5, 255, 255, 0);
    circle2(43, 135, 0.5, 255, 255, 0);
    circle2(50, 120, 0.5, 255, 255, 0);
    circle2(55, 140, 0.5, 255, 255, 0);
    circle2(60, 130, 0.5, 255, 255, 0);
    circle2(68, 134, 0.5, 255, 255, 0);
    circle2(75, 144, 0.5, 255, 255, 0);
    circle2(80, 110, 0.5, 255, 255, 0);
    circle2(88, 137, 0.5, 255, 255, 0);
    circle2(83, 117, 0.5, 255, 255, 0);
    circle2(-86, 145, 0.5, 255, 255, 0);
}


void sunnyCloud()
{
    circle2(-57.3372072570531, 112.1502599137751,7,255, 255, 255);
    circle2(-51.2773820914892, 122.0399124341394,7,255, 255, 255);
    circle2(-46.2165875917974, 116.1712839965521,7,255, 255, 255);
    circle2(-60, 120,8,255, 255, 255);

    glPushMatrix();
    glTranslatef(100.0f, -5.0f,0.0f);

    circle2(-57.3372072570531, 112.1502599137751,6,255, 255, 255);
    circle2(-51.2773820914892, 122.0399124341394,6,255, 255, 255);
    circle2(-47.2165875917974, 116.1712839965521,6,255, 255, 255);
    circle2(-60, 120,8,255, 255, 255);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(65.0f, -10.0f,0.0f);

    circle2(-57.3372072570531, 112.1502599137751,6,255, 255, 255);
    circle2(-51.2773820914892, 122.0399124341394,6,255, 255, 255);
    circle2(-47.2165875917974, 116.1712839965521,6,255, 255, 255);
    circle2(-60, 120,8,255, 255, 255);
    glPopMatrix();
}

void sunnyCloud1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_cloud, 0.0f,0.0f);

    sunnyCloud();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(181, 0.0f,0.0f);

    sunnyCloud();

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-181, 0.0f,0.0f);

    sunnyCloud();

    glPopMatrix();

    glPopMatrix();
}

void rainyCloud()
{
    circle2(-57.3372072570531, 112.1502599137751,7,203, 203, 203);
    circle2(-51.2773820914892, 122.0399124341394,7,203, 203, 203);
    circle2(-46.2165875917974, 116.1712839965521,7,203, 203, 203);
    circle2(-60, 120,8,203, 203, 203);

    glPushMatrix();
    glTranslatef(65.0f, -10.0f,0.0f);

    circle2(-57.3372072570531, 112.1502599137751,6,203, 203, 203);
    circle2(-51.2773820914892, 122.0399124341394,6,203, 203, 203);
    circle2(-47.2165875917974, 116.1712839965521,6,203, 203, 203);
    circle2(-60, 120,8,203, 203, 203);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.0f, -5.0f,0.0f);

    circle2(-57.3372072570531, 112.1502599137751,6,203, 203, 203);
    circle2(-51.2773820914892, 122.0399124341394,6,203, 203, 203);
    circle2(-47.2165875917974, 116.1712839965521,6,203, 203, 203);
    circle2(-60, 120,8,203, 203, 203);
    glPopMatrix();

    circle2(-87.9571609085263, 142.0867286249647,8,203, 203, 203);
    circle2(-80, 143,8,203, 203, 203);
    circle2(-71.1116097709093, 144.64163355458 ,8,203, 203, 203);
    circle2(-60, 140,8,203, 203, 203);
    circle2(-38.1283037619618, 144.8813653929808 ,8,203, 203, 203);
    circle2(-30.6256633393257, 143.9224380393776,8,203, 203, 203);
    circle2(-10.3826901235339, 147.5184156153897,8,203, 203, 203);
    circle2(-1.6060164215822, 144.8813653929808,8,203, 203, 203);
    circle2(12.8330274106609, 144.64163355458,8,203, 203, 203);
    circle2(15.5370192950205, 144.64163355458,8,203, 203, 203);
    circle2(46.0994519261229, 145.1210972313816,8,203, 203, 203);
    circle2(58.1319884529922, 153.271979737009,8,203, 203, 203);
    circle2(69.0320509538031, 154.2309070906123,8,203, 203, 203);
    circle2(80.6399097209005, 147.2786837769889,8,203, 203, 203);

}

void rainyCloud1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_cloud, 0.0f,0.0f);

    rainyCloud();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(181, 0.0f,0.0f);

    rainyCloud();

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-181, 0.0f,0.0f);

    rainyCloud();

    glPopMatrix();

    glPopMatrix();
}

void car()
{

    glBegin(GL_POLYGON); // body
    glColor3ub(58, 58, 77);

	glVertex2f(-78, -7.1);
	glVertex2f(-78, -22.2);
	glVertex2f(-38.4046152581465, -22.2);
	glVertex2f(-37, -18.2858234271046);
	glVertex2f(-39.6055726531544, -13.3);
	glVertex2f(-49.0582695687007, -13.3);
	glVertex2f(-52.312476703561, -7.1);

	glEnd();

	glBegin(GL_POLYGON); //front window
    glColor3ub(0,0,0);

	glVertex2f(-61.65, -8.7202527778976);
	glVertex2f(-53.6296557819568, -8.7202527778976);
	glVertex2f(-51.0340381862945, -14.2);
	glVertex2f(-61.65, -14.2);

	glEnd();

	glBegin(GL_POLYGON); //back window
    glColor3ub(0,0,0);

	glVertex2f(-75.3, -14.3296923561362);
	glVertex2f(-65.755451415424, -14.3296923561362);
	glVertex2f(-65.755451415424, -8.5431125806901);
	glVertex2f(-75.3, -8.6612060454951);

	glEnd();

	glLineWidth(3);
	glBegin(GL_LINES); //handle
    glColor3ub(0,0,0);


	glVertex2f(-70.4817998731972, -16.25);
	glVertex2f(-66.2590787101048, -16.25);

	glVertex2f(-55.411721593904, -16.25);
	glVertex2f(-51.2664815530702, -16.25);

	glEnd();

	// Front wheel
    glPushMatrix();
    glTranslatef(-71.0629082901365, -22.7733750896956, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle1(0,0,4,0,0,0,false);
    circle1(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();


    // Back wheel
    glPushMatrix();
    glTranslatef(-48.55464227402, -22.6552816248906, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle1(0,0,4,0,0,0,false);
    circle1(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();


}

void carMove()
{
    if(_oldCarMove<=127)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(_oldCarMove, 0.0f,0.0f);

        car();

        glPopMatrix();
    }
    if(_oldCarMove>=127 && _oldCarMove <=168)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(_oldCarMove, 0.0f,0.0f);

        car();

        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(_newCarMove, 0.0f,0.0f);

        car();

        glPopMatrix();
    }
}

void truck() // id: truck01
{

    glPushMatrix();
    glTranslatef(0.0f, -10.0f,0.0f);
    glBegin(GL_POLYGON); //square body
    glColor3ub(65, 90, 173);

	glVertex2f(-14.55, 36.7333955619761);
	glVertex2f(-14.5, 16);
	glVertex2f(8, 16);
	glVertex2f(7.944204387028, 36.7770734797732);

    glEnd();

    glBegin(GL_POLYGON); //front body
    glColor3ub(101, 111, 118);

    glVertex2f(8, 30.8369194973632);
    glVertex2f(12.0708241758237, 30.9242324949699);
    glVertex2f(15.4541585552863, 25);
    glVertex2f(19,25);
    glVertex2f(19, 16.0358079507589);
	glVertex2f(8, 16);

    glEnd();

    glBegin(GL_POLYGON); //Window
    glColor3ub(0,0,0);

    glVertex2f(7.963909925574, 29.4391592510257);
    glVertex2f(12.0421670939571, 29.4828612076677);
    glVertex2f(14.2487623976882, 25);
    glVertex2f(7.9758740837369, 25);

    glEnd();

    // front wheel
    glPushMatrix();
    glTranslatef(10, 16, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle1(0,0,4,0,0,0,false);
    circle1(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();

    // Back wheel
    glPushMatrix();
    glTranslatef(-9, 16, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle1(0,0,4,0,0,0,false);
    circle1(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();

    glPopMatrix();
}

void truckMove()
{
    if(_oldTruckMove<71)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(_oldTruckMove, 0.0f,0.0f);

        truck();

        glPopMatrix();
    }
    if(_oldTruckMove>=71 && _oldTruckMove <75.5)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(_oldTruckMove, 0.0f,0.0f);

        truck();

        glPopMatrix();

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(_newTruckMove, 0.0f,0.0f);

        truck();

        glPopMatrix();
    }
}

void road() // id: road01
{
    glPushMatrix();
    glTranslatef(0.0f, -10.0f,0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(132,132,132);

	glVertex2f(-90, -20);
	glVertex2f(90, -20);
	glVertex2f(90, 40);
	glVertex2f(-90,40);

    glEnd();

    bool check =true;
    glLineWidth(10);
    glBegin(GL_LINES);
    for(int i = -90; i<90; i+=10)
    {
        if(check)
        {
            glColor3ub(0,0,0);
            check = !check;
        }
        else if(!check)
        {
            glColor3ub(145, 132, 8);
            check = !check;
        }

        glVertex2f(i,-20);
        glVertex2f(i+10,-20);

        glVertex2f(i,40);
        glVertex2f(i+10,40);

        if(!check)
        {
            glColor3ub(255,255,255);
            glVertex2f(i+5,10);
            glVertex2f(i+15,10);
        }
    }
    glEnd();

    glPopMatrix();
    //glutSwapBuffers();
}

void greenGrass()
{
    glBegin(GL_POLYGON);
    glColor3ub(134, 218, 64);

	glVertex2f(-90, 35);
	glVertex2f(90, 35);
	glVertex2f(90, 30);
	glVertex2f(-90, 30);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(134, 218, 64);

	glVertex2f(-90, 38);
	glVertex2f(90, 38);
	glVertex2f(90, 60);
	glVertex2f(-90, 60);

    glEnd();
}

void railTrack()
{
    glBegin(GL_POLYGON); //background color
    glColor3ub(180, 180, 180);

	glVertex2f(-90, 33);
	glVertex2f(90, 33);
	glVertex2f(90, 38);
	glVertex2f(-90, 38);

    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,0,00);

	glVertex2f(-90, 33);
	glVertex2f(90, 33);

	glVertex2f(-90, 38);
	glVertex2f(90, 38);

    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);

    for(int i = -90; i<90; i+=5)
    {
        glVertex2f(i, 33);
        glVertex2f(i+3, 38);
    }
    glEnd();
}

void train()
{
    railTrack();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_trainMove, 0.0f,0.0f);

    //front bogie ______________________________________________________
    circle1(25,35,1.5,0,0,0,false);
    circle1(45,35,1.5,0,0,0,false);

    glBegin(GL_POLYGON);    //body
    glColor3ub(43, 50, 54);

	glVertex2f(20,35);
	glVertex2f(20, 46);
	glVertex2f(22, 50);
	glVertex2f(50, 50);
	glVertex2f(50, 35);

    glEnd();

    glBegin(GL_POLYGON);    //up blue line
    glColor3ub(65, 90, 173);

	glVertex2f(24, 48);
	glVertex2f(24, 49);
	glVertex2f(49, 49);
	glVertex2f(49, 48);

    glEnd();

    glBegin(GL_POLYGON);    //low blue line
    glColor3ub(65, 90, 173);

	glVertex2f(22, 39);
	glVertex2f(22, 37);
	glVertex2f(49, 37);
	glVertex2f(49, 39);

    glEnd();

    glBegin(GL_POLYGON);    //front door
    glColor3ub(0,0,0);

	glVertex2f(21, 46);
	glVertex2f(23, 46);
	glVertex2f(23, 38);
	glVertex2f(21, 38);

    glEnd();

    glBegin(GL_POLYGON);    //back door
    glColor3ub(0,0,0);

	glVertex2f(46.5, 38);
	glVertex2f(49, 38);
	glVertex2f(49, 48);
	glVertex2f(46.5, 48);

    glEnd();

    for(int i =24; i<45; i+=6)  //window
    {
        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);

        glVertex2f(i, 41);
        glVertex2f(i, 45);
        glVertex2f(i+4, 45);
        glVertex2f(i+4, 41);

        glEnd();
    }

    glBegin(GL_POLYGON);    //tail
    glColor3ub(0,0,0);

	glVertex2f(50, 41);
	glVertex2f(53, 41);
	glVertex2f(53, 39);
	glVertex2f(50, 39);

    glEnd();

    //front bogie ends ______________________________________________________


    //back bogie ______________________________________________________
    glPushMatrix();
    glTranslatef(33.0f, 0.0f,0.0f);

    circle1(25,35,1.5,0,0,0,false);
    circle1(45,35,1.5,0,0,0,false);

    glBegin(GL_POLYGON);    //body
    glColor3ub(43, 50, 54);

	glVertex2f(20,35);
	glVertex2f(20, 50);
	glVertex2f(50, 50);
	glVertex2f(50, 35);

    glEnd();

    glBegin(GL_POLYGON);    //up blue line
    glColor3ub(65, 90, 173);

	glVertex2f(21, 48);
	glVertex2f(21, 49);
	glVertex2f(49, 49);
	glVertex2f(49, 48);

    glEnd();

    glBegin(GL_POLYGON);    //low blue line
    glColor3ub(65, 90, 173);

	glVertex2f(21, 39);
	glVertex2f(21, 37);
	glVertex2f(49, 37);
	glVertex2f(49, 39);

    glEnd();

    glBegin(GL_POLYGON);    //front door
    glColor3ub(0,0,0);

	glVertex2f(20.5, 48);
	glVertex2f(23, 48);
	glVertex2f(23, 38);
	glVertex2f(20.5, 38);

    glEnd();

    glBegin(GL_POLYGON);    //back door
    glColor3ub(0,0,0);

	glVertex2f(46.5, 38);
	glVertex2f(49, 38);
	glVertex2f(49, 48);
	glVertex2f(46.5, 48);

    glEnd();

    for(int i =24; i<45; i+=6)  //window
    {
        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);

        glVertex2f(i, 41);
        glVertex2f(i, 45);
        glVertex2f(i+4, 45);
        glVertex2f(i+4, 41);

        glEnd();
    }

    glPopMatrix();
    //glutSwapBuffers();
    //back bogie ends ______________________________________________________

    glPopMatrix();
}

void building1()
{
    glBegin(GL_POLYGON);    //left
    glColor3ub(0, 196, 241);

	glVertex2f(51.4, 46);
	glVertex2f(51.4, 66.2);
	glVertex2f(60.7, 66.2);
	glVertex2f(60.7, 46);

    glEnd();

    glBegin(GL_POLYGON);    //right
    glColor3ub(0, 196, 241);

	glVertex2f(82.7, 63.5);
    glVertex2f(82.7, 46);
    glVertex2f(88, 46);
    glVertex2f(88, 63.5);

    glEnd();



    glBegin(GL_POLYGON);    //right top
    glColor3ub(5, 101, 123);

	glVertex2f(82.7, 64.5);
    glVertex2f(82.7, 63.5);
    glVertex2f(88.6, 63.5);
    glVertex2f(88.6, 64.5);

    glEnd();

    glBegin(GL_POLYGON);    //mid-right top
    glColor3ub(5, 101, 123);

	glVertex2f(83.2, 69);
    glVertex2f(83.2, 67.7);
    glVertex2f(76, 67.7);
    glVertex2f(76, 69);

    glEnd();

    glBegin(GL_POLYGON);    //mid-right
    glColor3ub(0, 196, 241);

	glVertex2f(76, 67.7);
    glVertex2f(76, 46);
    glVertex2f(82.7, 46);
    glVertex2f(82.7, 67.7);

    glEnd();

    glBegin(GL_POLYGON);    //mid
    glColor3ub(199, 199, 199);

	glVertex2f(60.7, 46);
    glVertex2f(76, 46);
    glVertex2f(76, 71);
    glVertex2f(60.7, 71);

    glEnd();

    glBegin(GL_POLYGON);    //mid top
    glColor3ub(5, 101, 123);

	glVertex2f(59.8, 74.5);
    glVertex2f(59.8, 71);
    glVertex2f(76.9, 71);
    glVertex2f(76.9, 74.5);

    glEnd();

    glBegin(GL_POLYGON);    //left top
    glColor3ub(5, 101, 123);

	glVertex2f(50.6, 68);
    glVertex2f(50.6, 66.2);
    glVertex2f(60.7, 66.2);
    glVertex2f(60.7, 68);

    glEnd();

    glBegin(GL_POLYGON);    //bottom
    glColor3ub(5, 101, 123);

	glVertex2f(50.6, 45.3);
	glVertex2f(50.6, 46);
    glVertex2f(88.8, 46);
    glVertex2f(88.8, 45.3);

    glEnd();

    glBegin(GL_POLYGON);    //door
    glColor3ub(142, 206, 255);

	glVertex2f(64.5, 57.3);
	glVertex2f(64.5, 46);
    glVertex2f(72.6, 46);
    glVertex2f(72.6, 57.3);

    glEnd();

    glBegin(GL_POLYGON);    //window left bottom
    glColor3ub(142, 206, 255);

	glVertex2f(54, 57.2);
	glVertex2f(54, 53.3);
    glVertex2f(57.6, 53.3);
    glVertex2f(57.6, 57.2);

    glEnd();

    glBegin(GL_LINES);    //window left bottom lines
    glColor3ub(5, 101, 123); //--------------------------------

	glVertex2f(54, 57.2);
	glVertex2f(54, 53.3);

    glVertex2f(57.6, 53.3);
    glVertex2f(57.6, 57.2);

	glVertex2f(54, 53.3);
    glVertex2f(57.6, 53.3);

    glVertex2f(54, 57.2);
    glVertex2f(57.6, 57.2);

    glEnd();

    glBegin(GL_POLYGON);    //window left top
    glColor3ub(142, 206, 255);

	glVertex2f(54, 60);
	glVertex2f(57.6, 60);
    glVertex2f(57.6, 64.3);
    glVertex2f(54, 64.3);

    glEnd();

    glBegin(GL_LINES);    //window left top lines
    glColor3ub(5, 101, 123);

	glVertex2f(54, 60);
	glVertex2f(57.6, 60);

    glVertex2f(57.6, 64.3);
    glVertex2f(54, 64.3);

	glVertex2f(57.6, 60);
    glVertex2f(57.6, 64.3);

    glVertex2f(54, 60);
    glVertex2f(54, 64.3);

    glEnd();

    glBegin(GL_POLYGON);    //window right bottom-left
    glColor3ub(142, 206, 255);

	glVertex2f(77.9, 53.5);
	glVertex2f(80.8, 53.5);
    glVertex2f(80.8, 56.8);
    glVertex2f(77.9, 56.8);
    glEnd();

    glBegin(GL_LINES);    //window right bottom-left lines
    glColor3ub(5, 101, 123);

	glVertex2f(77.9, 53.5);
	glVertex2f(80.8, 53.5);

    glVertex2f(80.8, 56.8);
    glVertex2f(77.9, 56.8);

    glVertex2f(77.9, 53.5);
    glVertex2f(77.9, 56.8);

	glVertex2f(80.8, 53.5);
    glVertex2f(80.8, 56.8);
    glEnd();

    glBegin(GL_POLYGON);    //window right top-left
    glColor3ub(142, 206, 255);

	glVertex2f(78, 64.7);
	glVertex2f(80.9, 64.7);
    glVertex2f(80.9, 61.4);
    glVertex2f(77.9, 61.4);
    glEnd();

    glBegin(GL_LINES);    //window right top-left lines
    glColor3ub(5, 101, 123);

	glVertex2f(78, 64.7);
	glVertex2f(80.9, 64.7);

    glVertex2f(80.9, 61.4);
    glVertex2f(77.9, 61.4);

    glVertex2f(78, 64.7);
    glVertex2f(77.9, 61.4); //problem

	glVertex2f(80.9, 64.7);
    glVertex2f(80.9, 61.4);

    glEnd();

    glBegin(GL_POLYGON);    //window right top-right
    glColor3ub(142, 206, 255);

	glVertex2f(84.2, 61.6);
	glVertex2f(86.6, 61.6);
    glVertex2f(86.6, 59);
    glVertex2f(84.2, 59);
    glEnd();

    glBegin(GL_LINES);    //window right top-right lines
    glColor3ub(5, 101, 123);

	glVertex2f(84.2, 61.6);
	glVertex2f(86.6, 61.6);

    glVertex2f(86.6, 59);
    glVertex2f(84.2, 59);

	glVertex2f(84.2, 61.6);
    glVertex2f(84.2, 59);

	glVertex2f(86.6, 61.6);
    glVertex2f(86.6, 59);
    glEnd();

    glBegin(GL_POLYGON);    //window right bottom-right
    glColor3ub(142, 206, 255);

	glVertex2f(86.6, 54);
	glVertex2f(84.25, 54);
    glVertex2f(84.25, 56.6);
    glVertex2f(86.6, 56.6);
    glEnd();

    glBegin(GL_LINES);    //window right bottom-right lines
    glColor3ub(5, 101, 123);

	glVertex2f(86.6, 54);
	glVertex2f(84.25, 54);

    glVertex2f(84.25, 56.6);
    glVertex2f(86.6, 56.6);

	glVertex2f(86.6, 54);
    glVertex2f(86.6, 56.6);

	glVertex2f(84.25, 54);
    glVertex2f(84.25, 56.6);

    glEnd();

    //lines------------------
    glLineWidth(2);
    glBegin(GL_LINES);    //right and mid-right line
    glColor3ub(5, 101, 123);

	glVertex2f(82.7, 67.7);
    glVertex2f(82.7, 46);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);    //right line
    glColor3ub(5, 101, 123);

	glVertex2f(88, 63.5);
    glVertex2f(88, 46);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);    //right-mid and mid line
    glColor3ub(5, 101, 123);

	glVertex2f(76, 71);
    glVertex2f(76, 46);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);    //left and mid line
    glColor3ub(5, 101, 123);

	glVertex2f(60.7, 71);
    glVertex2f(60.7, 46);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);    //left and mid line
    glColor3ub(5, 101, 123);

	glVertex2f(51.4, 66.2);
    glVertex2f(51.4, 46);

    glEnd();

    //door---------------------
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);    //left and mid line
    glColor3ub(5, 101, 123);

	glVertex2f(64.5, 46);
	glVertex2f(64.5, 57.3);

	glVertex2f(64.5, 57.3);
	glVertex2f(72.6, 57.3);

	glVertex2f(72.6, 57.3);
	glVertex2f(72.6, 46);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);    //left door handle
    glColor3ub(5, 101, 123);

	glVertex2f(67, 52.3);
    glVertex2f(67, 50.2);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);    //right door handle
    glColor3ub(5, 101, 123);

	glVertex2f(70, 50.2);
    glVertex2f(70, 52.3);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);    //door mid line
    glColor3ub(5, 101, 123);

	glVertex2f(68.65, 57.3);
    glVertex2f(68.65, 46);

    glEnd();


}

void building2()
{
//rgb(153, 208, 246)

    glBegin(GL_POLYGON);    //main body
        glColor3ub(255, 252, 226);

        glVertex2f(-83, 47.5);
        glVertex2f(-60, 47.5);
        glVertex2f(-60, 94);
        glVertex2f(-83, 94);

    glEnd();

    glBegin(GL_POLYGON);    //upper low
        glColor3ub(250, 240, 190);

        glVertex2f(-84.5, 94);
        glVertex2f(-58.5, 94);
        glVertex2f(-58.5, 97.5);
        glVertex2f(-84.5, 97.5);

    glEnd();

    glBegin(GL_POLYGON);    //upper low dark
        glColor3ub(216, 211, 161);

        glVertex2f(-84.5, 96);
        glVertex2f(-58.5, 96);
        glVertex2f(-58.5, 97.5);
        glVertex2f(-84.5, 97.5);

    glEnd();

    glBegin(GL_POLYGON);    //up
        glColor3ub(250, 240, 190);

        glVertex2f(-85.5, 97.5);
        glVertex2f(-57.5, 97.5);
        glVertex2f(-60, 100);
        glVertex2f(-83, 100);

    glEnd();

    glBegin(GL_POLYGON);    //down
        glColor3ub(216, 211, 161);

        glVertex2f(-84, 47.5);
        glVertex2f(-59, 47.5);
        glVertex2f(-59, 45.5);
        glVertex2f(-84, 45.5);

    glEnd();

    glBegin(GL_POLYGON);    //door
        glColor3ub(137, 201, 236);

        glVertex2f(-74.7, 47.5);
        glVertex2f(-68.3, 47.5);
        glVertex2f(-68.3, 58);
        glVertex2f(-74.7, 58);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);    //door lines
        glColor3ub(216, 211, 161);

        glVertex2f(-74.7, 47.5);
        glVertex2f(-74.7, 58.3);

        glVertex2f(-68.3, 47.5);
        glVertex2f(-68.3, 58.3);

        glVertex2f(-68.3, 58);
        glVertex2f(-74.7, 58);

        glVertex2f(-68.3, 58);
        glVertex2f(-74.7, 58);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);    //door lines
        glColor3ub(216, 211, 161);

        glVertex2f(-71.5, 47.5);
        glVertex2f(-71.5, 57.5);

    glEnd();


    for(int i = 51; i<90; i+=7) //windows
    {
        glBegin(GL_POLYGON);    //left
        glColor3ub(153, 208, 246);

        glVertex2f(-81, i);
        glVertex2f(-77, i);
        glVertex2f(-77, i+5);
        glVertex2f(-81, i+5);

        glEnd();

        glLineWidth(1.5);
        glBegin(GL_LINES);    //left lines
        glColor3ub(220, 210, 160);

        glVertex2f(-81, i);
        glVertex2f(-77, i);
        glVertex2f(-77, i+5);
        glVertex2f(-81, i+5);

        glVertex2f(-81, i);
        glVertex2f(-81, i+5);

        glVertex2f(-77, i);
        glVertex2f(-77, i+5);

        glEnd();

        glBegin(GL_POLYGON);    //right
        glColor3ub(153, 208, 246);

        glVertex2f(-81+15, i);
        glVertex2f(-77+15, i);
        glVertex2f(-77+15, i+5);
        glVertex2f(-81+15, i+5);

        glEnd();

        glBegin(GL_LINES);    //right lines
        glColor3ub(220, 210, 160);

        glVertex2f(-81+15, i);
        glVertex2f(-77+15, i);

        glVertex2f(-77+15, i+5);
        glVertex2f(-81+15, i+5);

        glVertex2f(-81+15, i);
        glVertex2f(-81+15, i+5);

        glVertex2f(-77+15, i);
        glVertex2f(-77+15, i+5);

        glEnd();
    }

    for(int i = 60; i<90; i+=17) //mid windows
    {
        glBegin(GL_POLYGON);    //left
        glColor3ub(153, 208, 246);

        glVertex2f(-75, i);
        glVertex2f(-72, i);
        glVertex2f(-72, i+13.5);
        glVertex2f(-75, i+13.5);

        glEnd();

        glBegin(GL_LINES);    //left lines
        glColor3ub(220, 210, 160);

        glVertex2f(-75, i);
        glVertex2f(-72, i);

        glVertex2f(-72, i+13.5);
        glVertex2f(-75, i+13.5);

        glVertex2f(-75, i);
        glVertex2f(-75, i+13.5);

        glVertex2f(-72, i);
        glVertex2f(-72, i+13.5);
        glEnd();

        glBegin(GL_POLYGON);    //right
        glColor3ub(153, 208, 246);

        glVertex2f(-75+4, i);
        glVertex2f(-72+4, i);
        glVertex2f(-72+4, i+13.5);
        glVertex2f(-75+4, i+13.5);

        glEnd();

        glBegin(GL_LINES);    //right lines
        glColor3ub(220, 210, 160);

        glVertex2f(-75+4, i);
        glVertex2f(-72+4, i);

        glVertex2f(-72+4, i+13.5);
        glVertex2f(-75+4, i+13.5);

        glVertex2f(-75+4, i);
        glVertex2f(-75+4, i+13.5);

        glVertex2f(-72+4, i);
        glVertex2f(-72+4, i+13.5);
        glEnd();
    }
}

void translatedBuilding2()
{
    glMatrixMode(GL_MODELVIEW);     //translated tree2
    glPushMatrix();
    glTranslatef(65.0f, 5.0f,0.0f);

    building2();

    glPopMatrix();
}

void house()
{
    glBegin(GL_POLYGON);    //body1
        glColor3ub(254, 183, 201);

        glVertex2f(-33.4, 45.5);
        glVertex2f(-9.5, 45.5);
        glVertex2f(-9.5, 54.9);
        glVertex2f(-33.4, 54.9);

    glEnd();

    glBegin(GL_POLYGON);    //body2
        glColor3ub(166, 23, 31);

        glVertex2f(-35.6, 54.9);
        glVertex2f(-7., 54.9);
        glVertex2f(-9.5, 58.1);
        glVertex2f(-33.4, 58.1);

    glEnd();

    glBegin(GL_POLYGON);    //body3
        glColor3ub(254, 183, 201);

        glVertex2f(-33.4, 58.1);
        glVertex2f(-9.5, 58.1);
        glVertex2f(-9.5, 64);
        glVertex2f(-7.2, 60.4);
        glVertex2f(-15, 72.5);
        glVertex2f(-22.65, 64);
        glVertex2f(-33.4, 64);

    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);    //body3 line
        glColor3ub(61, 0, 0);

        glVertex2f(-22.67, 64);
        glVertex2f(-15, 72.5);

        glVertex2f(-15, 72.5);
        glVertex2f(-7.2, 60.4);

        glVertex2f(-34.4, 45.5);
        glVertex2f(-8.5, 45.5);

    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);    //body4
        glColor3ub(61, 0, 0);

        glVertex2f(-7.2, 60.35);
        glVertex2f(-10, 60.35);

    glEnd();

    glBegin(GL_POLYGON);    //body4
        glColor3ub(166, 23, 31);

        glVertex2f(-35.1098755004563, 64);
        glVertex2f(-22.67, 64);
        glVertex2f(-16.7472980786729, 70.785164271849);
        glVertex2f(-21.324937775888, 74.8607631959023);

    glEnd();

    glBegin(GL_POLYGON);    //door back
        glColor3ub(254, 171, 119);

        glVertex2f(-25, 45.5);
        glVertex2f(-19.5, 45.5);
        glVertex2f(-19.5, 55);
        glVertex2f(-25, 55);

    glEnd();

    glBegin(GL_POLYGON);    //door
        glColor3ub(109, 12, 5);

        glVertex2f(-23.5, 45.5);
        glVertex2f(-21, 45.5);
        glVertex2f(-21, 53);
        glVertex2f(-23.5, 53);

    glEnd();

    glBegin(GL_POLYGON);    //door up
        glColor3ub(0, 202, 252);

        glVertex2f(-26, 55);
        glVertex2f(-18.5, 55);
        glVertex2f(-22.25, 59);

    glEnd();

    glLineWidth(1.2);
    glBegin(GL_LINES);    //door line
        glColor3ub(61, 0, 0);

        glVertex2f(-18.5, 55);
        glVertex2f(-26, 55);

        glVertex2f(-26, 55);
        glVertex2f(-22.25, 59);

        glVertex2f(-18.5, 55);
        glVertex2f(-22.25, 59);

        glVertex2f(-25, 45.5);
        glVertex2f(-19.5, 45.5);

        glVertex2f(-19.5, 55);
        glVertex2f(-25, 55);

        glVertex2f(-25, 45.5);
        glVertex2f(-25, 55);

        glVertex2f(-19.5, 45.5);
        glVertex2f(-19.5, 55);

    glEnd();

    glBegin(GL_POLYGON);    //window left bottom
        glColor3ub(0, 202, 252);

        glVertex2f(-31, 47.5);
        glVertex2f(-26.5, 47.5);
        glVertex2f(-26.5, 52.8);
        glVertex2f(-31, 52.8);

    glEnd();

    glBegin(GL_LINES);    //window left bottom lines
        glColor3ub(109, 12, 5);

        glVertex2f(-31, 47.5);
        glVertex2f(-26.5, 47.5);

        glVertex2f(-26.5, 52.8);
        glVertex2f(-31, 52.8);

        glVertex2f(-31, 47.5);
        glVertex2f(-31, 52.8);

        glVertex2f(-26.5, 47.5);
        glVertex2f(-26.5, 52.8);

        glVertex2f(-28.75, 47.5);
        glVertex2f(-28.75, 52.8);

        glVertex2f(-26.5, 50.15);
        glVertex2f(-31, 50.15);

    glEnd();

    glBegin(GL_POLYGON);    //window left top
        glColor3ub(0, 202, 252);

        glVertex2f(-31, 58.9);
        glVertex2f(-26.5, 58.9);
        glVertex2f(-26.5, 63);
        glVertex2f(-31, 63);

    glEnd();

    glBegin(GL_LINES);    //window left top lines
        glColor3ub(109, 12, 5);

        glVertex2f(-31, 58.9);
        glVertex2f(-26.5, 58.9);

        glVertex2f(-26.5, 63);
        glVertex2f(-31, 63);

        glVertex2f(-26.5, 58.9);
        glVertex2f(-26.5, 63);

        glVertex2f(-28.75, 58.9);
        glVertex2f(-28.75, 63);

        glVertex2f(-26.5, 60.95);
        glVertex2f(-31, 60.95);

        glVertex2f(-31, 58.9);
        glVertex2f(-31, 63);

    glEnd();

    glBegin(GL_POLYGON);    //window right top
        glColor3ub(0, 202, 252);

        glVertex2f(-17.8, 58.9);
        glVertex2f(-12, 58.9);
        glVertex2f(-12, 63.0);
        glVertex2f(-17.8, 63.0);

    glEnd();

    glBegin(GL_LINES);    //window right top lines
        glColor3ub(109, 12, 5);

        glVertex2f(-17.8, 58.9);
        glVertex2f(-12, 58.9);

        glVertex2f(-12, 63.0);
        glVertex2f(-17.8, 63.0);

        glVertex2f(-12, 58.9);
        glVertex2f(-12, 63.0);

        glVertex2f(-17.8, 58.9);
        glVertex2f(-17.8, 63.0);

        glVertex2f(-14.9, 58.9);
        glVertex2f(-14.9, 63.0);

        glVertex2f(-12, 60.95);
        glVertex2f(-17.8, 60.95);


    glEnd();


    glBegin(GL_POLYGON);    //window right bottom
        glColor3ub(0, 202, 252);

        glVertex2f(-17.8, 47.5);
        glVertex2f(-12, 47.5);
        glVertex2f(-12, 52.8);
        glVertex2f(-17.8, 52.8);

    glEnd();

    glBegin(GL_LINES);    //window right bottom lines
        glColor3ub(109, 12, 5);

        glVertex2f(-17.8, 47.5);
        glVertex2f(-12, 47.5);

        glVertex2f(-12, 52.8);
        glVertex2f(-17.8, 52.8);

        glVertex2f(-12, 47.5);
        glVertex2f(-12, 52.8);

        glVertex2f(-17.8, 47.5);
        glVertex2f(-17.8, 52.8);

        glVertex2f(-14.9, 47.5);
        glVertex2f(-14.9, 52.8);

        glVertex2f(-12, 50.15);
        glVertex2f(-17.8, 50.15);

    glEnd();

}

void translatedHouse()
{
    glMatrixMode(GL_MODELVIEW);     //translated tree2
    glPushMatrix();
    glTranslatef(50.0f, 5.0f,0.0f);

    house();

    glPopMatrix();
}

void tree1()
{
    glBegin(GL_POLYGON);    //body
        glColor3ub(165, 114, 8);

        glVertex2f(-50, 48);
        glVertex2f(-48, 48);
        glVertex2f(-49, 80);

    glEnd();

    glBegin(GL_POLYGON);    //body
        glColor3ub(165, 114, 8);

        glVertex2f(-48.706698403882, 61.6964027899669);
        glVertex2f(-48.5222185204125, 58.6266315356091);
        glVertex2f(-45.8653714229234, 78.1600430405144);

    glEnd();

    circle2(-51.6941634386321, 77,6,84, 115, 26);
    circle2(-49, 80,6,86, 139, 23);
    circle2(-45, 77.1600430405144,6,109, 181, 45);




}

void translatedTree1()
{
    glMatrixMode(GL_MODELVIEW);     //translated tree1
    glPushMatrix();
    glTranslatef(135.0f, 5.0f,0.0f);

    tree1();

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);     //translated tree1
    glPushMatrix();
    glTranslatef(115.0f, 5.0f,0.0f);

    tree1();

    glPopMatrix();
}

void tree2Leaf(int x, int y, float leafRadius, int leafCount, float radius, float r,float g,float b)
{
    //int x = 32, y =80;
    // Draw Leaves in a Circular Shape - Smaller
    //float leafRadius = 4; // Smaller cluster radius
    //int leafCount = 10;    // Fewer leaves

    for (int i = 0; i < leafCount; i++)
    {
        float angle = i * (2 * PI / leafCount); // Spread evenly
        float leafX = x + leafRadius * cos(angle);
        float leafY = y + leafRadius * sin(angle);
        circle2(leafX, leafY, radius,r ,g ,b); // Smaller leaves
    }

}

void tree2()
{
    glBegin(GL_POLYGON);    //body
        glColor3ub(165, 114, 8);

        glVertex2f(31, 52);
        glVertex2f(33, 52);
        glVertex2f(32, 80);

    glEnd();

    tree2Leaf(32, 80, 7,8, 5, 70, 115, 26);
    tree2Leaf(32, 80, 5,6, 5, 86, 139, 23);

    glBegin(GL_POLYGON);    //body right
        glColor3ub(165, 114, 8);

        glVertex2f(37.7960578152048, 83.1262131855341);
        glVertex2f(32.0209133487875, 57.4458869798775);
        glVertex2f(32.6963688419357, 55.3296908337544);

    glEnd();

    tree2Leaf(37.7960578152048, 83.1262131855341, 4,8, 4, 97, 160, 45);

    glBegin(GL_POLYGON);    //body left
        glColor3ub(165, 114, 8);

        glVertex2f(31.6216215837314, 61.3623430535477);
        glVertex2f(31.723012903515, 63.9951851056522);
        glVertex2f(25, 75.8429743401225);

    glEnd();

    tree2Leaf(25, 75.8429743401225, 3, 6, 4, 109, 181, 45);




}

void translatedTree2()
{
    glMatrixMode(GL_MODELVIEW);     //translated tree2
    glPushMatrix();
    glTranslatef(-20.0f, -10.0f,0.0f);

    tree2();

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);     //translated tree2
    glPushMatrix();
    glTranslatef(18.0f, -5.0f,0.0f);

    tree2();

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);     //translated tree2
    glPushMatrix();
    glTranslatef(-120.0f, -5.0f,0.0f);

    tree2();

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);     //translated tree2
    glPushMatrix();
    glTranslatef(-60.0f, -5.0f,0.0f);

    tree2();

    glPopMatrix();
}


void drawRain(int dropCount)
{
    glColor3ub(173, 216, 230); // Light blue color for rain

    glBegin(GL_LINES);
    for (int i = 0; i < dropCount; i++)
    {
        float x = (rand() % 181) - 90; // Random x in range (-90 to 90)
        float y = (rand() % 181) - 30; // Random y in range (-30 to 150)

        glLineWidth(1.5);
        glVertex2f(x, y);
        glVertex2f(x, y - 5); // Slightly downward line for rain effect
    }
    glEnd();
}

void allObj()
{
    road();
    truckMove();
    carMove();
    if(!isRaining && !isNight)
    {
        sunnyCloud1();
    }

    if(isRaining && !isNight)
    {
        rainyCloud1();
    }

    greenGrass();
    tree1();
    tree2();
    translatedHouse();
    translatedBuilding2();
    translatedTree1();
    translatedTree2();
    building1();
    building2();
    house();
    train();

    if(isRaining)
    {
        drawRain(300);
    }

    glBegin(GL_POLYGON);    //body1
        glColor3ub(254, 183, 201);

        glVertex2f(150,-90);
        glVertex2f(150, 90);

    glEnd();
}

void allObj1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_allObj, 0.0f,0.0f);

    allObj();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(180, 0.0f,0.0f);

    allObj();

    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-180, 0.0f,0.0f);

    allObj();

    glPopMatrix();

    glPopMatrix();



}

void displayRiyadh()
{
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glClearColor(rr,gg,bb, 1.0f);

    if(!isRaining && !isNight)
    {
        sun(255, 255, 0);
    }

    if(isRaining && !isNight)
    {
        sun(240, 230, 140);
    }
    if(isNight)
    {
        moon(50,120,10);
        star();
    }

    allObj1();

    glutSwapBuffers();  // Swap buffers for smooth animation
	glFlush();  // Render now
}

//------------------------------------- riyadh end

void handleMouseR(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    if(!isRaining)
        {
            rr = 0.529f; gg = 0.627f; bb = 0.745f;
            isRaining = true;
            glutPostRedisplay();
        }
        else if(isRaining)
        {
            rr = 0.4f; gg = 0.698f;bb = 0.996f;
            isRaining = false;
            glutPostRedisplay();
        }
    }
    if (button == GLUT_RIGHT_BUTTON)
        {
            //speed -= 0.1f;
        }
    glutPostRedisplay();

}


void handleKeypressR(unsigned char key, int x, int y) {

    switch (key)
    {
        case '1':
            rakib = true;
            riyadh = false;
            siam = false;
            fahad = false;
            glutPostRedisplay();
            glutDisplayFunc(displayRakib);
        break;

        case '2':
            rakib = false;
            riyadh = true;
            siam = false;
            fahad = false;
            glutPostRedisplay();
            glutDisplayFunc(displayRiyadh);
        break;

        case '3':
            rakib = false;
            riyadh = false;
            siam = true;
            fahad = false;
            glutPostRedisplay();
            glutDisplayFunc(displayRakib);
        break;

        case '4':
            rakib = false;
            riyadh = false;
            siam = false;
            fahad = true;
            glutPostRedisplay();
            glutDisplayFunc(displayRakib);
        break;
    }


    if(riyadh)
    {
        switch (key) {
            case 'd':
                rr = 0.4f; gg = 0.698f;bb = 0.996f;
                isRaining = false;
                isNight = false;
                glutPostRedisplay();
                break;

            case 'r':
                rr = 0.529f; gg = 0.627f ;bb = 0.745f;
                isRaining = true;
                isNight = false;
                glutPostRedisplay();
                break;

            case 'n':
                rr = 0.25f; gg = 0.25f; bb = 0.35f;
                isNight = true;
                isRaining = false;
                glutPostRedisplay();
                break;
            case 'b':
                rr = 0.25f; gg = 0.25f; bb = 0.35f;
                isNight = true;
                isRaining = true;
                glutPostRedisplay();
                break;

            glutPostRedisplay();
        }
    }


	if(rakib)
    {
        switch (key)
        {
            case 'n':
                rainday = false;
                waterLevel = 0.0;
            glutPostRedisplay();
            glutDisplayFunc(displayN);
            break;

            case 'r':
            rainday = true;
            Rain(rain);
            glutPostRedisplay();
            glutDisplayFunc(displayR);
            break;

            case 't':
                    rainday = true;
                    Rain(rain);
            glutPostRedisplay();
            glutDisplayFunc(displayNR);
            break;

            case 's':
                    rainday = false;
                    Rain(rain);
                    _angle1=0.0;
            glutPostRedisplay();
            break;

            case 'd':
                    rainday = false;
                    Rain(rain);
                    waterLevel = 0.0;
                    _angle1=0.0;
            glutPostRedisplay();
            glutDisplayFunc(displayRakib);
            break;

        }
    }
}

void display()
{
    displayRakib();
    rakib = true;
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Different scenario in different places in Bangladesh");  // Create window with the given title
	glutInitWindowSize(500, 1000);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	gluOrtho2D(-90,90,-30,150);                      // Our own OpenGL initialization
	glutTimerFunc(20, update, 0);

	//glutTimerFunc(2000, sceenUpdate, 0);
	//glutTimerFunc(4000, sceenUpdate, 0);

    glutKeyboardFunc(handleKeypressR);
    glutMouseFunc(handleMouseR);

    //rakib

glutTimerFunc(20, updatecloud,0);
glutTimerFunc(30, updatesun, 0);
glutTimerFunc(20, updatecar, 0);
glutTimerFunc(20, updatecar2, 0);
glutTimerFunc(20,updatewinwheell,0);
glutTimerFunc(20, updateboat, 0);
//rakib----end

	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
