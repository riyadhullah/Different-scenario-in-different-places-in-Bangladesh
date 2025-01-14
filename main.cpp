#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#define PI           3.14159265358979323846

float _move = 70.0f;
void trainUpdate(int value) {
    _move -= 1.0f;

    if(_move < -300.0f)
    {
        _move = 70.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(20, trainUpdate, 0);
}

void initGL() {
	// Set "clearing" or background color
	glClearColor(0.4f, 0.698f, 0.996f, 1.0f);
}

void circle(float x, float y, float radius,float r,float g,float b, bool wheel)
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

void sun() //id: sun01
{
	circle(0, 120,8,255,255,0,false);
}

void cloud()
{
    circle(-57.3372072570531, 112.1502599137751,8,203, 203, 203,false);
    circle(-51.2773820914892, 122.0399124341394,8,203, 203, 203,false);
    circle(-46.2165875917974, 116.1712839965521,8,203, 203, 203,false);
    circle(-60, 120,8,203, 203, 203,false);

    glPushMatrix();
    glTranslatef(100.0f, -5.0f,0.0f);

    circle(-57.3372072570531, 112.1502599137751,8,203, 203, 203,false);
    circle(-51.2773820914892, 122.0399124341394,8,203, 203, 203,false);
    circle(-46.2165875917974, 116.1712839965521,8,203, 203, 203,false);
    circle(-60, 120,8,203, 203, 203,false);
    glPopMatrix();


}

void car()
{
    glBegin(GL_POLYGON); //square body
    glColor3ub(58, 58, 77);

	glVertex2f(-77.7, -7.1);
	glVertex2f(-77.7, -22.2);
	glVertex2f(-38.4046152581465, -22.2);
	glVertex2f(-36.4675872016821, -18.2858234271046);
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

	circle(-71.0629082901365, -22.7733750896956,4,0,0,0,false); //front wheel
    circle(-71.0629082901365, -22.7733750896956,2.5,1,1,1,true);

    circle(-48.55464227402, -22.6552816248906,4,0,0,0,false); //back wheel
    circle(-48.55464227402, -22.6552816248906,2.5,1,1,1,true);
}

void truck() // id: truck01
{
    glPushMatrix();
    glTranslatef(0.0f, -10.0f,0.0f);
    glBegin(GL_POLYGON); //square body
    glColor3ub(142, 39, 3);

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

    circle(10, 16,4,0,0,0,false); //front wheel
    circle(10, 16,2.5,1,1,1,true);

    circle(-9, 16,4,0,0,0,false); //back wheel
    circle(-9, 16,2.5,1,1,1,true);

    glPopMatrix();
    //glutSwapBuffers();
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
    glTranslatef(_move, 0.0f,0.0f);

    //front bogie ______________________________________________________
    circle(25,35,1.5,0,0,0,false);
    circle(45,35,1.5,0,0,0,false);

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

    circle(25,35,1.5,0,0,0,false);
    circle(45,35,1.5,0,0,0,false);

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

void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    road();
    truck();
    car();
    sun();
    cloud();
    greenGrass();
    train();

    glutSwapBuffers();  // Swap buffers for smooth animation
	glFlush();  // Render now
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Different scenario in different places in Bangladesh");  // Create window with the given title
	glutInitWindowSize(500, 1000);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();
	gluOrtho2D(-90,90,-30,150);                      // Our own OpenGL initialization
	glutTimerFunc(20, trainUpdate, 0);
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
