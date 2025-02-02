#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#define PI           3.14159265358979323846

float _trainMove = 70.0f;
float _carMove = 0.0f;
float _truckMove = -120.0f;
float _wheelAngle=0.0f;


void update(int value) {
    _trainMove -= 1.0f;

    if(_trainMove < -300.0f)
    {
        _trainMove = 70.0f;
    }

    _carMove += 1.0f;

    if(_carMove > 200.0f)
    {
        _carMove = -60;
    }

    _truckMove += 0.4f;

    if(_truckMove > 150.0f)
    {
        _truckMove = -100;
    }


    _wheelAngle -=8.0f;
    if(_wheelAngle < 360.0)
    {
        _wheelAngle+=360;
    }

    glutPostRedisplay();
    glutTimerFunc(20,update , 0);
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
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_carMove, 0.0f,0.0f);

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

	// Front wheel
    glPushMatrix();
    glTranslatef(-71.0629082901365, -22.7733750896956, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle(0,0,4,0,0,0,false);
    circle(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();


    // Back wheel
    glPushMatrix();
    glTranslatef(-48.55464227402, -22.6552816248906, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle(0,0,4,0,0,0,false);
    circle(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();

{
    /*glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-71.0629082901365, -22.7733750896956, 0.0f);
    glRotatef(_angle1, 0.0f, 0.0f,1.0f);

	circle(-71.0629082901365, -22.7733750896956,4,0,0,0,false); //front wheel
    circle(-71.0629082901365, -22.7733750896956,2.5,1,1,1,true);

    circle(-48.55464227402, -22.6552816248906,4,0,0,0,false); //back wheel
    circle(-48.55464227402, -22.6552816248906,2.5,1,1,1,true);*/
}

    glPopMatrix();
}

void truck() // id: truck01
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_truckMove, 0.0f,0.0f);

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

    // front wheel
    glPushMatrix();
    glTranslatef(10, 16, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle(0,0,4,0,0,0,false);
    circle(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();

    // Back wheel
    glPushMatrix();
    glTranslatef(-9, 16, 0.0f); // Translate to wheel position
    glRotatef(_wheelAngle, 0.0f, 0.0f, 1.0f); // Apply rotation
    circle(0,0,4,0,0,0,false);
    circle(0,0,2.5,1,1,1,true); // Draw wheel
    glPopMatrix();

    {
        /*
        circle(10, 16,4,0,0,0,false); //front wheel
        circle(10, 16,2.5,1,1,1,true);

        circle(-9, 16,4,0,0,0,false); //back wheel
        circle(-9, 16,2.5,1,1,1,true);
        */
    }

    glPopMatrix();

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
    glTranslatef(_trainMove, 0.0f,0.0f);

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

    glBegin(GL_POLYGON);    //window left bottom ////////here
    glColor3ub(142, 206, 255);

	glVertex2f(54, 57.2);
	glVertex2f(54, 53.3);
    glVertex2f(57.6, 53.3);
    glVertex2f(57.6, 57.2);

    glEnd();
    glBegin(GL_POLYGON);    //window left top
    glColor3ub(142, 206, 255);

	glVertex2f(54, 60);
	glVertex2f(57.6, 60);
    glVertex2f(57.6, 64.3);
    glVertex2f(54, 64.3);

    glEnd();

    glBegin(GL_POLYGON);    //window right bottom-left
    glColor3ub(142, 206, 255);

	glVertex2f(77.9, 53.5);
	glVertex2f(80.8, 53.5);
    glVertex2f(80.8, 56.8);
    glVertex2f(77.9, 56.8);
    glEnd();

    glBegin(GL_POLYGON);    //window right top-left
    glColor3ub(142, 206, 255);

	glVertex2f(78, 64.7);
	glVertex2f(80.9, 64.7);
    glVertex2f(80.9, 61.4);
    glVertex2f(77.9, 61.4);
    glEnd();

    glBegin(GL_POLYGON);    //window right top-right
    glColor3ub(142, 206, 255);

	glVertex2f(84.2, 61.6);
	glVertex2f(86.6, 61.6);
    glVertex2f(86.6, 59);
    glVertex2f(84.2, 59);
    glEnd();

    glBegin(GL_POLYGON);    //window right bottom-right
    glColor3ub(142, 206, 255);

	glVertex2f(86.6, 54);
	glVertex2f(84.25, 54);
    glVertex2f(84.25, 56.6);
    glVertex2f(86.6, 56.6);
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

        glBegin(GL_POLYGON);    //left
        glColor3ub(153, 208, 246);

        glVertex2f(-81+15, i);
        glVertex2f(-77+15, i);
        glVertex2f(-77+15, i+5);
        glVertex2f(-81+15, i+5);

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

        glBegin(GL_POLYGON);    //right
        glColor3ub(153, 208, 246);

        glVertex2f(-75+4, i);
        glVertex2f(-72+4, i);
        glVertex2f(-72+4, i+13.5);
        glVertex2f(-75+4, i+13.5);

        glEnd();
    }
}

void house()
{
    glBegin(GL_POLYGON);    //main body
        glColor3ub(255, 252, 226);

        glVertex2f(-33.4, 45.5);
        glVertex2f(-9.5, 45.5);
        glVertex2f(-9.3606522036213, 54.8639601449528);
        glVertex2f(-33.2892233481548, 54.9996781100857);

    glEnd();

    glBegin(GL_POLYGON);    //main body
        glColor3ub(255, 252, 226);

        glVertex2f(-77.3474987511428, 72.8194392565979);
        glVertex2f(-7.2799068867053, 54.9044302030647);
        glVertex2f(-9.4646894694671, 58.1877206098482);
        glVertex2f(-33.2892233481548, 58.0996265982258);

    glEnd();

    glBegin(GL_POLYGON);    //main body
        glColor3ub(255, 252, 226);

        glVertex2f(-33.2892233481548, 58.0996265982258);
        glVertex2f(-9.4646894694671, 58.1877206098482);
        glVertex2f(-9.4126708365442, 64.0019253769255);
        glVertex2f(-7.3839441525511, 64.0019253769255);
        glVertex2f(-15.0827018251402, 72.4589504926743);
        glVertex2f(-22.6254035989605, 64.1781134001702);
        glVertex2f(-33.3412419810777, 64.0019253769255);

    glEnd();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color


    road();
    truck();
    car();
    sun();
    cloud();
    greenGrass();
    building1();
    building2();
    //house();
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
	glutTimerFunc(20, update, 0);
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
