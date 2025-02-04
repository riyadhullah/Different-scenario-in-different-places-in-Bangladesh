#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#define PI           3.14159265358979323846
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()
#include <mmsystem.h>
#include <stdio.h>

bool riyadh = false, rakib = false, siam= false, fahad = false;
//Fahad

float _trainMoveF = 80.0f;
float _trainMove2 = -130.0f;
float _carMoveF = 70.0f;
float _carMovey = 0.0f;
float _busMove = -120.0f;
float _busMovey = 20.0f;
float _boatMove = -120.0f;
float _boatMove2 = 90.0f;
float _wheelAngleF = 0.0f;
float _cloudF = 0.0f;
bool isRainingF = false;
float r = 0.529f, g = 0.627f ,b = 0.745f;
bool isDay = true; // Start with night scene
bool isNightF = false; // Start with night scene
float timeOfDay = 0.0f; // Simulates time of day (0.0f to 1.0f)




void drawRainF(int dropCount)
{
    glColor3ub(173, 216, 230); // Light blue color for rain

    glBegin(GL_LINES);
    for (int i = 0; i < dropCount; i++)
    {
        float x = (rand() % 181) - 90; // Random x in range (-90 to 90)
        float y = (rand() % 181) - 30; // Random y in range (-30 to 150)

        glVertex2f(x, y);
        glVertex2f(x, y - 5); // Slightly downward line for rain effect
    }
    glEnd();
}

void updateF(int value) {
    _trainMoveF -= 0.7f;

    if(_trainMoveF < -150.0f)
    {
        _trainMoveF = 80.0f;
    }
    _trainMove2 += 0.7f;

    if(_trainMove2 > 130.0f)
    {
        _trainMove2 = -130.0f;
    }

    _carMoveF -= 1.0f;

    if(_carMoveF < -200.0f)
    {
        _carMoveF = 80;
    }
    _carMovey += 0.09f;

    if(_carMovey > 25.5f)
    {
        _carMovey = 0;
    }


    _busMove += 0.4f;

    if(_busMove > 150.0f)
    {
        _busMove = -100;
    }

     _busMovey -= 0.05f;

    if(_busMovey < -17.5f)
    {
        _busMovey = 13;
    }

     _boatMove += 0.2f;

    if(_boatMove > 140.0f)
    {
        _boatMove = -120;
    }

    _boatMove2 -= 0.2f;

    if(_boatMove2 < -180.0f)
    {
        _boatMove2 = 90;
    }


    _cloudF -=0.2f;
    if(_cloudF < -300.0)
    {
        _cloudF = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(20,updateF , 0);
}


void initGLF() {
	// Set "clearing" or background color
	glClearColor(0.4f, 0.698f, 0.996f, 1.0f);
}

void circle(float x, float y, float radius,float r,float g,float b, bool wheel)
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
void circle1F(float x, float y, float radius,float r,float g,float b, bool wheel)
{
    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glColor3ub(r, g, b); // Set color
    glBegin(GL_LINE_LOOP);
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


void sunF() //id: sun01
{
	circle(41.3442765028296, 137.9994808076247,6.0924722999061,255,255,0,false);
}

void cloud()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_cloudF,-5.0f,0.0f);
    circle(65.9870963742559, 135.632461771416,4,203, 203, 203,false);
    circle(70, 138,4.60,203, 203, 203,false);
    circle(75, 136,2.365,203, 203, 203,false);
    circle(77.7640621979834, 135.0747681300278, 1.609,203, 203, 203,false);
    circle(78.1089466040681, 134.9522107337552,3,203, 203, 203,false);
    circle(80.6317891115194, 134.356686135691,1.81,203, 203, 203,false);
    glPopMatrix();

}
void cloud2()
{
    cloud();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(30,-5.0f,0.0f);
    cloud();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(60,-5.0f,0.0f);
    cloud();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(90,-5.0f,0.0f);
    cloud();
    glPopMatrix();
}
void riverF()
{
    glBegin(GL_POLYGON); //square body
    glColor3ub(71, 236, 243);

	glVertex2f(-90,120);
	glVertex2f(90, 120);
	glVertex2f(90, 90);
	glVertex2f(-90,100);

	glEnd();
}
void boatF()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_boatMove2,0.0f,0.0f);

    glBegin(GL_POLYGON); //square body
    glColor3ub(166, 124, 75);

	glVertex2f(59.1064853470242, 105.6480011297107);
	glVertex2f(74.8139897169838, 105.6480011297107);
	glVertex2f(73.7630694723986, 102.7964753384399);
	glVertex2f(60.1949384574873, 102.7603800752592);

	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);
    glColor3ub(166, 124, 75);

	glVertex2f(65,105);
	glVertex2f(66,118);

	glEnd();


	glBegin(GL_POLYGON); //square body
    glColor3ub(206,206,206);

	glVertex2f(61.32, 108.39);
	glVertex2f(65.70,117.50);
	glVertex2f(64.96, 108.96);

	glEnd();

	glBegin(GL_POLYGON); //square body
    glColor3ub(206,206,206);

	glVertex2f(66.25, 117.73);
	glVertex2f(74.60, 106.11);
	glVertex2f(65.35, 106.18);

	glEnd();

	glBegin(GL_POLYGON); //square body
    glColor3ub(206,206,206);

	glVertex2f(63.17, 108.96);
	glVertex2f(64.96, 108.98);
	glVertex2f(64.96, 106.30);
	glVertex2f(60.63, 106.28);

	glEnd();
	glPopMatrix();
}
void boat1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_boatMove,0.0f,0.0f);

    glBegin(GL_POLYGON); //square body
    glColor3ub(109, 92, 21);

	glVertex2f(-43.8314065254586, 113.6114873611307);
	glVertex2f(-23.1533756367735, 113.6114873611307);
	glVertex2f(-27.4254230013975, 110.502734826885);
	glVertex2f(-41.4032621856498, 110.502734826885);

	glEnd();

	glLineWidth(5);
	glBegin(GL_LINES);
    glColor3ub(166, 124, 75);

	glVertex2f(-35, 113.5390745899354);
	glVertex2f(-35, 132);

	glEnd();

	glBegin(GL_POLYGON); // triangle 1
    glColor3ub(255, 236, 161);

	glVertex2f(-35.1825616371622, 128.7917490764724);
	glVertex2f(-35.1825616371622, 114.5390745899354);
	glVertex2f(-42.30, 113.67);

	glEnd();

	glBegin(GL_POLYGON); //triangle 2
    glColor3ub(255, 236, 161);

	glVertex2f(-34.6543038242734, 128.7791015330281);
	glVertex2f(-34.6543038242734, 114.5390745899354);
	glVertex2f(-24.6700510690181, 117.3391691510021);

	glEnd();

	glBegin(GL_POLYGON); //flag
    glColor3ub(53, 156, 1);

	glVertex2f(-34.6543038242734, 132);
	glVertex2f(-34.6543038242734, 130.4241928492143);
	glVertex2f(-31.8943491985324, 130.4241928492143);

	glEnd();
	glPopMatrix();
}
void riverside()
{
    glBegin(GL_POLYGON); //square body
    glColor3ub(210, 180, 140);

	glVertex2f(90, 90);
	glVertex2f(-90,100);
	glVertex2f(-90,95);
	glVertex2f(90, 75);

	glEnd();
}

void carF()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_carMoveF,_carMovey,0.0f);

	glBegin(GL_POLYGON);    //square body
    glColor3ub(58, 58, 77);

	glVertex2f(57.3474463977801, 70.164188377426);
	glVertex2f(85.8948230886636, 66.1376104055227);
	glVertex2f(86.9986549873777, 69.2124517658852);
	glVertex2f(85.1949573778658, 71.7051267241079);
	glVertex2f(59.4409206884449, 75.2157134694502);

    glEnd();

    glBegin(GL_POLYGON);    //body
    glColor3ub(172, 222, 204);

	glVertex2f(63.8905823163877, 74.8186681157021);
	glVertex2f(84, 72);
	glVertex2f(80, 80);
	glVertex2f(69.1470287633453, 81.4386066987553);
	glEnd();

	glBegin(GL_POLYGON);    //glass
    glColor3ub(150, 170, 163);

	glVertex2f(63.8005823163877, 74.7086681157021);
	glVertex2f(69.14702876334528, 81.43860669875534);
	glVertex2f(65.9913334473512, 74.7086681157021);
	glEnd();

	glBegin(GL_LINES);    //body
    glColor3ub(71, 189, 195);

	glVertex2f(71.49,81.127);
	glVertex2f(70.29,74);
	glVertex2f(77.31, 80.35);
	glVertex2f(76.60, 73.04);

	glEnd();

	circle(80.9569834927592, 66.6439955881468,1.5301496703489086,0,0,0,false); //front wheel
	circle(63.323363918405065, 69.28566227446528,1.5301496703489086,0,0,0,false); //front wheel

	glPopMatrix();


}

void truckF() // id: truck01
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_busMove,_busMovey,0.0f);

    glLineWidth(3);

    glBegin(GL_POLYGON); //square body
    glColor3ub(212, 219, 220);

	glVertex2f(-45.3760675669359, 81.835971207436);
	glVertex2f(-23.1353690294218, 78.1587125025615);
	glVertex2f(-22.727334092289684, 73.47991798506325);
	glVertex2f(-22.780205940355, 68.786159336639);
	glVertex2f(-23.187930578938, 66.1320847058118);
	glVertex2f(-46.8138209529003, 69.8841697845785);

    glEnd();

    glBegin(GL_LINES); //square body
     glColor3ub(71, 189, 195);

	glVertex2f(-45.3760675669359, 81.835971207436);
	glVertex2f(-23.1353690294218, 78.1587125025615);
	glVertex2f(-22.727334092289684, 73.47991798506325);
	glVertex2f(-22.780205940355, 68.786159336639);
	glVertex2f(-23.187930578938, 66.1320847058118);
	glVertex2f(-46.8138209529003, 69.8841697845785);

    glEnd();


    glBegin(GL_LINES); //glass body
    glColor3ub(106, 111, 111);

	glVertex2f(-44.946, 80.859);
	glVertex2f(-26.2852436215777, 77.5757170289802);
	glVertex2f(-26.0454741640386, 71.7240373115625);
	glVertex2f(-45.7607870579103, 74.8634549357566);

    glEnd();

    glBegin(GL_LINES); //glass
    glColor3ub(106, 111, 111);

	glVertex2f(-37.84, 79.60);
	glVertex2f(-38.75, 73.747);
	glVertex2f(-41.37, 80.23);
	glVertex2f(-42.269,74.307);

    glEnd();

    glBegin(GL_LINES); //glass
    glColor3ub(106, 111, 111);

	glVertex2f(-44.946, 80.859);
	glVertex2f(-45.7607870579103, 74.8634549357566);
	glVertex2f(-41.37, 80.23);
	glVertex2f(-42.269,74.307);

    glEnd();

    glBegin(GL_LINES); //glass
    glColor3ub(106, 111, 111);

	glVertex2f(-34.01, 78.93);
	glVertex2f(-35.12, 73.169);
	glVertex2f(-41.37, 80.23);
	glVertex2f(-42.269,74.307);

    glEnd();

    glBegin(GL_LINES); //glass
    glColor3ub(106, 111, 111);

	glVertex2f(-34.01, 78.93);
	glVertex2f(-35.12, 73.169);
	glVertex2f(-30.25, 78.27);
	glVertex2f(-31.61,72.61);

    glEnd();

    glBegin(GL_LINES); //glass
    glColor3ub(106, 111, 111);

	glVertex2f(-26.2852436215777, 77.5757170289802);
	glVertex2f(-28, 72.03);
	glVertex2f(-26.2852436215777, 77.5757170289802);
	glVertex2f(-26.0454741640386, 71.7240373115625);

	glVertex2f(-26.0454741640386, 71.7240373115625);
	glVertex2f(-22.780205940355, 68.786159336639);

	glVertex2f(-24.50, 70.33);
	glVertex2f(-23.1353690294218, 78.1587125025615);

	glVertex2f(-22.727334092289684, 73.47991798506325);
	glVertex2f(-23.1353690294218, 78.1587125025615);

	glVertex2f(-22.727334092289684, 73.47991798506325);
	glVertex2f(-22.780205940355, 68.786159336639);

	glVertex2f(-23.74, 74.67);
	glVertex2f(-22.727334092289684, 73.47991798506325);

	glVertex2f(-26.285243621577653, 77.57571702898021);
	glVertex2f(-23.1353690294218, 78.1587125025615);


    glEnd();


    circle(-28.45, 66.96,1.5301496703489086,0,0,0,false); //front wheel
	circle(-38.79, 68.61,1.5301496703489086,0,0,0,false); //front wheel
	circle(-41.99, 69.09,1.5301496703489086,0,0,0,false); //front wheel



    glPopMatrix();
}

void roadF() // id: road01
{

    glBegin(GL_POLYGON);
    glColor3ub(132,132,132);

	glVertex2f(-90,95);
	glVertex2f(90, 75);
	glVertex2f(90, 47.5);
	glVertex2f(-90,73.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(132,132,132);

    glVertex2f(35,63);
	glVertex2f(30,35.5);
	glVertex2f(15,35.5);
	glVertex2f(20,64);
	glEnd();


	//roadF mid line
	glLineWidth(5);
	glBegin(GL_LINES);
    glColor3ub(232, 235, 44);

    glVertex2f(90,61.42);
	glVertex2f(74.98,63.48);

	glVertex2f(69.94,64.17);
	glVertex2f(54.95,66.24);

	glVertex2f(50.05,66.91);
	glVertex2f(34.86,69);

	glVertex2f(29.95,69.67);
	glVertex2f(15.04,71.72);

	glVertex2f(10.19,72.39);
	glVertex2f(-5.03,74.41);

	glVertex2f(-9.95,75);
	glVertex2f(-24.98,76.84);

	glVertex2f(-30.14,77.47);
	glVertex2f(-45.08,79.30);

	glVertex2f(-50.01,79.90);
	glVertex2f(-65.17,81.74);

	glVertex2f(-69.93,82.32);
	glVertex2f(-85.13,84.18);

	glVertex2f(26.05,53.69);
	glVertex2f(22.85,38.62);

	glEnd();

	//roadF side line
	glBegin(GL_LINES);
    glColor3ub(255, 255, 255);

    glVertex2f(-90,93);
	glVertex2f(90, 73);

	glVertex2f(90, 49.5);
	glVertex2f(32.96,57.58);

	glVertex2f(29,37.5);
	glVertex2f(32.96,57.58);

	glVertex2f(20.5,59.74);
	glVertex2f(16.5,37.57);

	glVertex2f(20.5,59.74);
	glVertex2f(-90,75.5);

	glEnd();


}

void greenGrassF()
{
    glBegin(GL_POLYGON);
    glColor3ub(134, 218, 64);

	glVertex2f(90, 47.67);
	glVertex2f(90, 25);
	glVertex2f(-90,25);
	glVertex2f(-90, 73.53);

    glEnd();




}
void soil()
{
    glBegin(GL_POLYGON); //background color
    glColor3ub(189, 126, 58);
	glVertex2f(-90, 25);
	glVertex2f(90, 25);
	glVertex2f(90, -30);
	glVertex2f(-90, -30);
    glEnd();
}

void RailLine1()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0, 15.0f,0.0f);

    glBegin(GL_POLYGON); //background color
    glColor3ub(101, 67, 33);
	glVertex2f(90, 5);
	glVertex2f(90, -5);
	glVertex2f(-90, -5);
	glVertex2f(-90, 5);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,0,00);
	glVertex2f(90, 5);
	glVertex2f(-90, 5);
	glVertex2f(-90, -5);
	glVertex2f(90, -5);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);

    for(int i = 90; i>-90; i-=5)
    {
        glVertex2f(i, 5);
        glVertex2f(i-5, -5);
    }
    glEnd();
    glPopMatrix();
}
void RailLine2()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0, 10.0f,0.0f);

    glBegin(GL_POLYGON); //background color
    glColor3ub(101, 67, 33);
	glVertex2f(90, -10);
	glVertex2f(90, -20);
	glVertex2f(-90, -20);
	glVertex2f(-90, -10);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0,0,00);
	glVertex2f(90, -10);
	glVertex2f(-90, -10);
	glVertex2f(-90, -20);
	glVertex2f(90, -20);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);

    for(int i = 90; i>-90; i-=5)
    {
        glVertex2f(i, -10);
        glVertex2f(i-5, -20);
    }
    glEnd();
    glPopMatrix();
}

void trainF()
{

    RailLine1();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_trainMoveF, 15.0f,0.0f);

    //front bogie
    circle(13.2108469913231, -2.9585530679294,1.975073974115803,171, 211, 203,false);
    circle(18.8557798440809, -3.0000900318868,1.975073974115803,171, 211, 203,false);

    glBegin(GL_POLYGON);    // small body
    glColor3ub(163, 53, 26);

	glVertex2f(9.8555799115322, 5.5595027635054);
	glVertex2f(21.6943282944828, 5.5782047032778);
	glVertex2f(21.6628626239126, -2.5192969469466);
	glVertex2f(9.8555799115322, -2.5192969469466);

    glEnd();

    glBegin(GL_POLYGON);    //front triangle
    glColor3ub(43, 50, 54);

	glVertex2f(9.8739638196177, 0.479955162458);
	glVertex2f(9.8555799115322, -3.0546173219564);
	glVertex2f(6.4189950970071, -2.9850878592429);

    glEnd();

    glBegin(GL_POLYGON);    //front square
    glColor3ub(43, 50, 54);

	glVertex2f(9.85,5.25);
	glVertex2f(9.8545334992042, 2.034192943937);
	glVertex2f(9, 2);
	glVertex2f(9.0018206855504, 5.2300227963586);

    glEnd();

    glBegin(GL_POLYGON);    //upper square
    glColor3ub(210, 210, 210);

	glVertex2f(10.6030685068033, 5.642906326978);
	glVertex2f(10.6030685068033, 8.4830501157819);
	glVertex2f(13.1769175724675, 8.4830501157819);
	glVertex2f(13.1769175724675, 5.642906326978);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(43, 50, 54);
    glVertex2f(10.20, 8.4830501157819);
	glVertex2f(13.50, 8.4830501157819);

    glEnd();

    //big body
    circle(25.7890866850853, -2.4159080600636,2.5413681732969944,171, 211, 203,false);
    glBegin(GL_POLYGON);
    glColor3ub(234, 126, 36);

	glVertex2f(21.7158505452341, 9.2674870765784);
	glVertex2f(29.8376823710073, 9.2674870765784);
	glVertex2f(29.7707990634168, -2.4939319675032);
	glVertex2f(21.6628626239126, -2.5192969469466);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(43, 50, 54);
    glVertex2f(30.20, 9.2674870765784);
	glVertex2f(21.20, 9.2674870765784);

    glEnd();


    glBegin(GL_POLYGON);    //window
    glColor3ub(218, 242, 254);

	glVertex2f(22.930441415454, 7.0887398915528);
	glVertex2f(28.6522492062419, 7.0887398915528);
	glVertex2f(28.6522492062419, 2.8373787915167);
	glVertex2f(22.930441415454, 2.8373787915167);

    glEnd();

    glBegin(GL_POLYGON);    //front+2nd bogie conection
    glColor3ub(43, 50, 54);

	glVertex2f(29.7828514130356, -0.94077622923);
	glVertex2f(32.4343683291683, -0.94077622923);
	glVertex2f(32.4343683291683, -2.0766662467731);
	glVertex2f(29.7848987032144, -2.0608552948169);

    glEnd();

    //front bogie ends ______________________________________________________


    //2nd bogie ______________________________________________________

    circle(35.7840422962199, -2.974658601745,1.975073974115803,218, 242, 254,false);
    circle(41.2337250987842, -3.1325298708979,1.975073974115803,218, 242, 254,false);

    glBegin(GL_POLYGON);    //body
    glColor3ub(198, 186, 162);

	glVertex2f(32.5041976171983, 9.2906020993907);
	glVertex2f(44.3768022152707, 9.2906020993907);
	glVertex2f(44.3768022152707, -2.6816658905334);
	glVertex2f(32.5041976171983, -2.6816658905334);

    glEnd();

   glBegin(GL_POLYGON);    //window
    glColor3ub(65, 90, 173);

	glVertex2f(33.9660893995078, 5.9304208969889);
	glVertex2f(37.6548681559591, 5.9304208969889);
	glVertex2f(37.6548681559591, 2.82253401911661);
	glVertex2f(33.9660893995078,2.82253401911661);

    glEnd();

    glBegin(GL_POLYGON);    //window
    glColor3ub(65, 90, 173);

	glVertex2f(39.2281801327741, 5.6850614066306);
	glVertex2f(42.8531759712463, 5.7055080308271);
	glVertex2f(42.8531759712463, 2.761194146527);
	glVertex2f(39.2388106191039, 2.761194146527);

    glEnd();

    glBegin(GL_POLYGON);    //2nd+3rd bogie conection
    glColor3ub(43, 50, 54);

	glVertex2f(44.35,-0.96);
	glVertex2f(46.192950837295, -0.9467457539215);
	glVertex2f(46.1835673138878, -2.1379284027958);
	glVertex2f(44.35, -2.1379284027958);

    glEnd();

    //3rd bogie
    circle(49.6802084703547, -3.2453487864431,1.975073974115803,218, 242, 254,false);
    circle(55.0570208017944, -3.0573172605344,1.975073974115803,218, 242, 254,false);

    glBegin(GL_POLYGON);    //front door
    glColor3ub(198, 186, 162);

	glVertex2f(46.2038159956747, 9.245010345498);
	glVertex2f(58.004481227312, 9.2148476392065);
	glVertex2f(57.9786489906327, -2.8807579821364);
	glVertex2f(46.2038159956747, -2.7871457572957);

    glEnd();

    glBegin(GL_POLYGON);    //window
    glColor3ub(65, 90, 173);

	glVertex2f(47.7664014799497, 5.6905193964011);
	glVertex2f(51.4353726510343, 5.6905193964011);
	glVertex2f(51.3970210360055, 2.7399072212178);
	glVertex2f(47.7791853516259, 2.7399072212178);

    glEnd();

    glBegin(GL_POLYGON);    //window
    glColor3ub(65, 90, 173);

	glVertex2f(52.9548044924705, 5.6793795592854);
	glVertex2f(56.6325441271752, 5.6793795592854);
	glVertex2f(56.624041762624, 2.9326578383411);
	glVertex2f(52.9478637520825, 2.9326578383411);

    glEnd();


    glPopMatrix();


}
void train2()
{
    RailLine2();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_trainMove2, 10.0f,0.0f);

    circle(39.9092391019118, -18.5523465298623,1.8609805669220414,218, 242, 254,false);
    circle(34.11, -18.45,1.8609805669220414,218, 242, 254,false);
    circle(28.7257620119521, -18.3645595760918,1.8609805669220414,218, 242, 254,false);

    glBegin(GL_POLYGON);    //front 1st side
    glColor3ub(65, 90, 173);

	glVertex2f(41.8194516792835, -9.4119067085818);
	glVertex2f(46.1648636317916, -13.2533084827519);
	glVertex2f(46.1273020561945, -16.4981573397939);
	glVertex2f(41.8095001244956, -17.8637322833475);

    glEnd();

    glBegin(GL_POLYGON);    //front 2nd side
    glColor3ub(198, 186, 162);

	glVertex2f(33.6566800581487, -9.3424344575347);
	glVertex2f(41.8194516792835, -9.4119067085818);
	glVertex2f(41.8095001244956, -17.8637322833475);
	glVertex2f(33.6566800581487, -17.8637322833475);

    glEnd();

    glBegin(GL_POLYGON);    //front 2nd side upper side
    glColor3ub(182, 206, 238);

	glVertex2f(38.8416607708161, -7.2904841850127);
	glVertex2f(40.965389600499, -7.2904841850127);
	glVertex2f(40.965389600499, -9.4502473164773);
	glVertex2f(38.83, -9.38);

    glEnd();

    glBegin(GL_POLYGON);    //front 3rd side
    glColor3ub(182, 206, 238);

	glVertex2f(28.0033205365724, -6.5);
	glVertex2f(33.677295322864, -6.5);
	glVertex2f(33.6857446623663, -14.8344535851048);
	glVertex2f(28, -14.80);

    glEnd();

    glBegin(GL_POLYGON);    //front 4th side
    glColor3ub(226, 234, 244);

	glVertex2f(33.7439415660148, -17.8637322833475);
	glVertex2f(27.9992728079924, -17.8637322833475);
	glVertex2f(28, -14.80);
	glVertex2f(33.6857446623663, -14.8344535851048);


    glEnd();

    glBegin(GL_POLYGON);    //front 4th side
    glColor3ub(99, 138, 186);

	glVertex2f(26.2502061310082, -8.3626343499667);
	glVertex2f(28.0022406951815, -8.3553976069758);
	glVertex2f(27.9992728079924, -17.8637322833475);
	glVertex2f(26.2354949834548, -17.8637322833475);


    glEnd();

    glBegin(GL_POLYGON);    //window
    glColor3ub(99, 138, 186);

	glVertex2f(29.1994436705317, -8.2764630058987);
	glVertex2f(31.9896313387857, -8.2714512021294);
	glVertex2f(31.9984488328741, -11.7142345729447);
	glVertex2f(29.1944857127664, -11.6633560009622);

    glEnd();

    glBegin(GL_POLYGON);    //connenction
    glColor3ub(234, 126, 36);

	glVertex2f(24.5, -10);
	glVertex2f(26.273601809078, -10.0062390892487);
	glVertex2f(26.2227927082471, -15.9675232724308);
	glVertex2f(24.488882320485, -15.9394963298075);

    glEnd();


    circle(21.5751092170411, -18.1615417611293,1.8609805669220414,218, 242, 254,false);
    circle(15.905, -18.067,1.8609805669220414,218, 242, 254,false);
    circle(10.6386866611028, -17.9806554698757,1.8609805669220414,218, 242, 254,false);
     //2nd bogie
    glBegin(GL_POLYGON);    //body
    glColor3ub(198, 186, 162);

	glVertex2f(24.509494476754, -6.5);
	glVertex2f(24.5018505242513, -17.5358469354152);
	glVertex2f(7.4795698033313, -17.5358469354152);
	glVertex2f(7.4795698033313, -6.5);

    glEnd();

    glBegin(GL_POLYGON);    //window
    glColor3ub(99, 138, 186);

	glVertex2f(20.0201309987697, -9.7064452484376);
	glVertex2f(23.50357531789, -9.7064452484376);
	glVertex2f(23.50357531789, -13.1782838296345);
	glVertex2f(20.0201309987697, -13.1782838296345);

    glEnd();

    glBegin(GL_POLYGON);    //window
    glColor3ub(99, 138, 186);

	glVertex2f(14.7053209564264, -9.6588605711237);
	glVertex2f(18.1473380605663, -9.6588605711237);
	glVertex2f(18.1473380605663, -13.0425993443166);
	glVertex2f(14.674725248834, -13.0425993443166);

    glEnd();

    glBegin(GL_POLYGON);    //window
    glColor3ub(99, 138, 186);

	glVertex2f(9.7598040951793, -9.6150810752482);
	glVertex2f(13.2367269919934, -9.6150810752482);
	glVertex2f(13.2367269919934, -13.0720231597357);
	glVertex2f(9.7182206188726, -13.0720231597357);

    glEnd();

    glPopMatrix();  // Restore state


}
void renderStrokeString(float x, float y, const char* text, float scale) {
    glPushMatrix();  // Save current state
    glTranslatef(x, y, 0);  // Move to position
    glScalef(scale, scale, 1.0f);  // Scale text
    while (*text) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *text);  // Render each character
        text++;
    }
    glPopMatrix();  // Restore state
}

void station()
{
    glLineWidth(3);
    circle(0, 30,38.67699670534033,133, 169, 214,false); //station

    circle1F(0, 30,38.67699670534033,215, 166, 174,false); //station
    circle1F(0.6246942371318, 25.1022510192819,40.3016338201744,215, 166, 174,false); //station

    glBegin(GL_POLYGON);    //body
    glColor3ub(206, 206, 206);

	glVertex2f(-39.91, 30.84);
	glVertex2f(41.9904514744527, 30.84);
	glVertex2f(42, 15);
	glVertex2f(-40, 15);

    glEnd();

    glBegin(GL_POLYGON);    //chad
    glColor3ub(255, 236, 161);

	glVertex2f(-35.8239253672268, 36.6933053367241);
	glVertex2f(-40, 34.5);
	glVertex2f(37.4020116150383, 34.5);
	glVertex2f(42.1760746327732, 36.6933053367241);

    glEnd();

    glBegin(GL_POLYGON);    //Filer 1
    glColor3ub(255, 236, 161);

	glVertex2f(-30.92, 30.62);
	glVertex2f(-29.10, 30.62);
	glVertex2f(-29.52, 36.69);

    glEnd();


    glBegin(GL_LINES);    //Filer 2
    glColor3ub(255, 236, 161);

	glVertex2f(-23.93, 30.49);
	glVertex2f(-22.97, 36.69);

    glEnd();

    glBegin(GL_POLYGON);    //Filer 3
    glColor3ub(255, 236, 161);

	glVertex2f(-16.50, 30.62);
	glVertex2f(-14.79770677538, 30.62);
	glVertex2f(-15.34, 36.69);

    glEnd();

    glBegin(GL_LINES);    //Filer 4
    glColor3ub(255, 236, 161);

	glVertex2f(-12.9398145541614, 30.49);
	glVertex2f(-12.52, 36.69);

    glEnd();

    glBegin(GL_POLYGON);    //Filler 5
    glColor3ub(255, 236, 161);

	glVertex2f(-2.93, 29.97);
	glVertex2f(-1.74, 29.94);
	glVertex2f(-2.33, 36.69);

    glEnd();

    glBegin(GL_LINES);    //Filer 6
    glColor3ub(255, 236, 161);

	glVertex2f(7.32, 30.49);
	glVertex2f(8.17, 36.69);

    glEnd();

    glBegin(GL_LINES);    //Filer 7
    glColor3ub(255, 236, 161);

	glVertex2f(12.00, 30.49);
	glVertex2f(12.17, 36.69);

    glEnd();

    glBegin(GL_POLYGON);    //Filler 8
    glColor3ub(255, 236, 161);

	glVertex2f(17.56, 29.97);
	glVertex2f(19.34, 29.94);
	glVertex2f(18.19, 36.69);

    glEnd();

    glBegin(GL_POLYGON);    //Filler 9
    glColor3ub(255, 236, 161);

	glVertex2f(31.60, 29.97);
	glVertex2f(33.72, 29.94);
	glVertex2f(32.17, 36.69);

    glEnd();

    glBegin(GL_POLYGON);    //Filler 10
    glColor3ub(255, 236, 161);

	glVertex2f(37.50, 29.97);
	glVertex2f(39.77, 29.94);
	glVertex2f(38.55, 36.69);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(206, 206, 206);

	glVertex2f(-25, 48.4244399776265);
	glVertex2f(27, 48.4244399776265);
	glVertex2f(23,  42.2089561402893);
	glVertex2f(-23, 42.2089561402893);

    glEnd();
    glColor3ub(0, 0, 0);
    renderStrokeString(-20,50, "Cox's Bazar Railway Station", 0.025);

    glBegin(GL_LINES);    //upper Filer1
    glColor3ub(255, 236, 161);

	glVertex2f(-31.28, 52.74);
	glVertex2f(-24.92, 30.52);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer1
    glColor3ub(255, 236, 161);

	glVertex2f(-18.93, 30.37);
	glVertex2f(-13.62,30.24);
	glVertex2f(-24.58, 56.54);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer2
    glColor3ub(255, 236, 161);

	glVertex2f(-14.79770677538, 30.37);
	glVertex2f(-9.58,30.24);
	glVertex2f(-20.44, 59.54);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer3
    glColor3ub(255, 236, 161);

    glVertex2f(-9.58,30.24);
	glVertex2f(-5.19, 30.37);
	glVertex2f(-15.87, 61.87);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer4
    glColor3ub(255, 236, 161);

    glVertex2f(-5.19, 30.37);
    glVertex2f(-0.38,30.24);
	glVertex2f(-11.06, 63.37);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer5
    glColor3ub(255, 236, 161);

    glVertex2f(-0.38,30.24);
    glVertex2f(4.53, 30.37);
	glVertex2f(-6.05, 64.84);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer6
    glColor3ub(255, 236, 161);

    glVertex2f(4.53, 30.37);
    glVertex2f(9.25,30.24);
	glVertex2f(-0.99, 65.37);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer7
    glColor3ub(255, 236, 161);

    glVertex2f(-9.67, 30.37);
    glVertex2f(-5.19,30.24);
	glVertex2f(4, 65);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer8
    glColor3ub(255, 236, 161);

    glVertex2f(-5.19,30.24);
    glVertex2f(-0.387229272230,30.24);
	glVertex2f(9.14, 64.49);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer9
    glColor3ub(255, 236, 161);

    glVertex2f(-0.387229272230,30.24);
    glVertex2f(4.54,30.24);
	glVertex2f(14.07, 63.09);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer10
    glColor3ub(255, 236, 161);

    glVertex2f(4.54,30.24);
    glVertex2f(12.00,30.24);
	glVertex2f(20, 60);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer11
    glColor3ub(255, 236, 161);

    glVertex2f(12.00,30.24);
    glVertex2f(20, 30);
	glVertex2f(22.86, 59);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer12
    glColor3ub(255, 236, 161);

    glVertex2f(20, 30);
    glVertex2f(27.00,30.24);
    glVertex2f(28.19, 54);

    glEnd();

    glBegin(GL_LINE_LOOP);    //upper Filer12
    glColor3ub(255, 236, 161);

    glVertex2f(27.9461251947667, 30);
    glVertex2f(35,47);

    glEnd();
}
void treeF()
{
    circle(-65.7954282605812, 56.7815272720049, 8.1366725272952,74, 220, 17,false);
    circle(-73.9324466954792, 49.5158902246772,8.714854849904457,74, 220, 17,false);
    circle(-77.3753837369157, 56.4691244903631,9.508340875769855,74, 220, 17,false);
    circle(-73.8463732694433, 66.4023162984859,9.445541799998235,74, 220, 17,false);
    circle(-63.6897089972057, 69.7133802345268,10.05379450028941,74, 220, 17,false);
    circle(-53.791265003075864, 66.56786949528794,8.95022560940642,74, 220, 17,false);
    circle(-50.5204748137112, 56.3035712935611,9.663012149309731,74, 220, 17,false);
    circle(-54.5659258373991, 51.3369753894997,9.947377896348796,74, 220, 17,false);

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-68.25, 25);
	glVertex2f(-66.6376884574976, 26.9509972491381);
	glVertex2f(-61.8548440231304, 26.4830997349317);
	glVertex2f(-60.47, 25);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-66.6376884574976, 26.9509972491381);
	glVertex2f(-65.2838972204838, 55.263130669625);
	glVertex2f(-61.5475929368635, 55.3849007422013);
	glVertex2f(-61.8548440231304, 26.4830997349317);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-70.5808199027389, 51.6994370201554);
	glVertex2f(-64.5598634947626, 46.8096243234625);
	glVertex2f(-65.6519055961873, 51.0008923491993);
	glVertex2f(-68.6351958343633, 53.7451749850984);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-61.5876450726873, 40.6161506403614);
	glVertex2f(-56.7780639647111, 46.0124064406164);
	glVertex2f(-58.2921913505555, 48.5820520597855);
	glVertex2f(-61.6202055064997, 46.1671656454976);

    glEnd();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(120,0.0f,0.0f);
     circle(-65.7954282605812, 56.7815272720049, 8.1366725272952,74, 220, 17,false);
    circle(-73.9324466954792, 49.5158902246772,8.714854849904457,74, 220, 17,false);
    circle(-77.3753837369157, 56.4691244903631,9.508340875769855,74, 220, 17,false);
    circle(-73.8463732694433, 66.4023162984859,9.445541799998235,74, 220, 17,false);
    circle(-63.6897089972057, 69.7133802345268,10.05379450028941,74, 220, 17,false);
    circle(-53.791265003075864, 66.56786949528794,8.95022560940642,74, 220, 17,false);
    circle(-50.5204748137112, 56.3035712935611,9.663012149309731,74, 220, 17,false);
    circle(-54.5659258373991, 51.3369753894997,9.947377896348796,74, 220, 17,false);

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-68.25, 25);
	glVertex2f(-66.6376884574976, 26.9509972491381);
	glVertex2f(-61.8548440231304, 26.4830997349317);
	glVertex2f(-60.47, 25);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-66.6376884574976, 26.9509972491381);
	glVertex2f(-65.2838972204838, 55.263130669625);
	glVertex2f(-61.5475929368635, 55.3849007422013);
	glVertex2f(-61.8548440231304, 26.4830997349317);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-70.5808199027389, 51.6994370201554);
	glVertex2f(-64.5598634947626, 46.8096243234625);
	glVertex2f(-65.6519055961873, 51.0008923491993);
	glVertex2f(-68.6351958343633, 53.7451749850984);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-61.5876450726873, 40.6161506403614);
	glVertex2f(-56.7780639647111, 46.0124064406164);
	glVertex2f(-58.2921913505555, 48.5820520597855);
	glVertex2f(-61.6202055064997, 46.1671656454976);

    glEnd();
    glPopMatrix();

     glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(-20,0.0f,0.0f);
     circle(-65.7954282605812, 56.7815272720049, 8.1366725272952,74, 220, 17,false);
    circle(-73.9324466954792, 49.5158902246772,8.714854849904457,74, 220, 17,false);
    circle(-77.3753837369157, 56.4691244903631,9.508340875769855,74, 220, 17,false);
    circle(-73.8463732694433, 66.4023162984859,9.445541799998235,74, 220, 17,false);
    circle(-63.6897089972057, 69.7133802345268,10.05379450028941,74, 220, 17,false);
    circle(-53.791265003075864, 66.56786949528794,8.95022560940642,74, 220, 17,false);
    circle(-50.5204748137112, 56.3035712935611,9.663012149309731,74, 220, 17,false);
    circle(-54.5659258373991, 51.3369753894997,9.947377896348796,74, 220, 17,false);

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-68.25, 25);
	glVertex2f(-66.6376884574976, 26.9509972491381);
	glVertex2f(-61.8548440231304, 26.4830997349317);
	glVertex2f(-60.47, 25);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-66.6376884574976, 26.9509972491381);
	glVertex2f(-65.2838972204838, 55.263130669625);
	glVertex2f(-61.5475929368635, 55.3849007422013);
	glVertex2f(-61.8548440231304, 26.4830997349317);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-70.5808199027389, 51.6994370201554);
	glVertex2f(-64.5598634947626, 46.8096243234625);
	glVertex2f(-65.6519055961873, 51.0008923491993);
	glVertex2f(-68.6351958343633, 53.7451749850984);

    glEnd();

    glBegin(GL_POLYGON);    //
    glColor3ub(154, 124, 79);

	glVertex2f(-61.5876450726873, 40.6161506403614);
	glVertex2f(-56.7780639647111, 46.0124064406164);
	glVertex2f(-58.2921913505555, 48.5820520597855);
	glVertex2f(-61.6202055064997, 46.1671656454976);

    glEnd();
    glPopMatrix();



}
void drawMoon() {
    glColor3f(1.0f, 1.0f, 0.8f); // Light yellowish color
    float cx = 60.0f, cy = 130.0f, radius = 10.0f; // Moon position and size

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center
    for (int i = 0; i <= 100; i++) {
        float angle = i * 2.0f * 3.1415926f / 100;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawStars() {
    glColor3f(1.0f, 1.0f, 1.0f); // White color for stars
    glPointSize(2.0f);           // Small size for stars

    glBegin(GL_POINTS);
    // Positions of stars in (x, y) coordinates
    float stars[20][2] = {
        {-80.0f, 140.0f}, {-60.0f, 130.0f}, {-30.0f, 145.0f},
        {0.0f, 135.0f},   {20.0f, 140.0f},  {40.0f, 145.0f},
        {70.0f, 120.0f},  {-50.0f, 125.0f}, {30.0f, 130.0f},
        {80.0f, 140.0f},  {-70.0f, 115.0f}, {10.0f, 120.0f},
        {-40.0f, 110.0f}, {0.0f, 100.0f},   {50.0f, 110.0f},
        {-90.0f, 95.0f},  {70.0f, 105.0f},  {-60.0f, 90.0f},
        {20.0f, 85.0f},   {80.0f, 95.0f}
    };

    for (int i = 0; i < 20; i++) {
        glVertex2f(stars[i][0], stars[i][1]);
    }
    glEnd();
}


void renderNightScene() {
    // Clear the screen and set the background to dark blue (night sky)
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawMoon();
    drawStars();

    greenGrassF();
    riverF();
    boatF();
    boat1();
    riverside();
    roadF();
    carF();
    truckF();
    station();
    soil();
    treeF();

    trainF();
    train2();

    glFlush(); // Render the day scene
}

// Function to render the day scene
void renderDayScene() {
    // Clear the screen and set the background to light blue (day sky)
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    greenGrassF();
	sunF();
	cloud2();
    riverF();
    boatF();
    boat1();
    riverside();
    roadF();
    carF();
    truckF();
    station();
    soil();
    treeF();

    trainF();
    train2();

    glFlush(); // Render the day scene
}
void handleKeypressF(unsigned char key, int x, int y) {
	switch (key) {
	    case 'o':
	        r = 0.4f; g = 0.698f;b = 0.996f;
            isRainingF = false;
            glutPostRedisplay();
            break;

        case 'r':
            r = 0.529f; g = 0.627f ;b = 0.745f;
            isRainingF = true;
            glutPostRedisplay();
            break;
        case 'd':
            isDay = true;
            isNightF=false;
            break;

        case 'n':
            isDay = false;
            isNightF=true;
            isRainingF = false;
            break;


        glutPostRedisplay();
	}
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

            r = 0.529f; g = 0.627f; b = 0.745f;
            isRainingF = true;
            isDay=true;
            isNightF=false;
            glutPostRedisplay();

    }
    if (button == GLUT_RIGHT_BUTTON)
        {
            r = 0.4f; g = 0.698f;b = 0.996f;
            isRainingF = false;
            isDay=false;
            isNightF=true;
            glutPostRedisplay();
        }
    glutPostRedisplay();

}



void displayFahad() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (isDay) {
        renderDayScene(); // Render the day scene
    }
    else if (isNightF) {
        renderNightScene(); // Render the night scene
    }

    if (isRainingF) {
        drawRainF(250); // Render rain if raining
    }

    glFlush();
    glutSwapBuffers();
}





//

//-----------siam

float _angle1s = 0.0f;
float boatMove = 0.0f;
float carMoveS = 0.0f;
float busMove = 0.0f;
float cloudMove = 0.0f;
bool checkRain = false;
float sr = 77, sg = 189, sb = 243;

void initGL() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque

}

    //Sun------------------------------------------------
void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3ub(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}

    void tree1S(){

        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92); // tree
        glVertex2f(-79.740268814286, 70.6482600525719);
        glVertex2f(-81.3583540962604, 33.4172191102996);
        glVertex2f(-78.6923846370553, 32.8797378378444);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92); // tree
        glVertex2f(-80, 52);
        glVertex2f(-80, 50);
        glVertex2f(-73.1684057513682, 57.6408792584301);
        glEnd();

        circle(6,-83.4324, 61.15904,53, 159, 100);
        circle(8,-83.4324,72.4418,53, 159, 100);
        circle(6,-73.4842,79.6217,55, 159, 100);
        circle(10,-74.71077, 67.8261,61, 183, 115);
        circle(6,-74.2547, 58.2214,53, 159, 100);

    }

    void tree2Land(){

        glBegin(GL_POLYGON);
        glColor3ub(108, 85, 53); // tree
        glVertex2f(-4.8024657107914, 71.7170959435397);
        glVertex2f(-3.7650254682906, 71.4167687366551);
        glVertex2f(-3.5256161815597, 44.3873201170422);
        glVertex2f(-4.283745589541, 44.1620747118788);
        glVertex2f(-6.9172477435814, 42.735520479177);
        glVertex2f(-5.3716845737664, 44.5115188059784);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(108, 85, 53); // tree
        glVertex2f(-9, 72);
        glVertex2f(-4.4095198661747, 64.9975900482019);
        glVertex2f(-4.7984192886126, 63.9365048806387);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(108, 85, 53); // tree
        glVertex2f(-3.8561378437857, 60.2697294228166);
        glVertex2f(-3.7539459239697, 59.1880862131942);
        glVertex2f(1.0934069613217, 70.8152638979447);
        glEnd();

        circle(8,1.332, 75.5986,53, 159, 100);
        circle(8,-2.3224, 82.2868,53, 159, 100);
        circle(6,-6.6277, 90.1996,61, 183, 115);
        circle(10,-10.2822, 83.79402,53, 159, 100);
        circle(7,-9.9816, 72.20743,61, 183, 115);

    }

    void tree3Hill(){

        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92); // tree
        glVertex2f(-60.9144762789324, 127.3624672826828);
        glVertex2f(-61.2223255283318, 118.9474822940086);
        glVertex2f(-60.6063713443486, 118.6661604137039);
        glEnd();
        circle(2,-61.7844196236397, 126.1688565359602,78, 235, 148);
        circle(1.5,-60.9688477379766, 128.6583875219816,53, 159, 100);
        circle(2,-59.1927134091993, 126.1347533717681,61, 183, 115);

        //T2Right

        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92); // tree
        glVertex2f(-47.8653261083235, 129.6132761193597);
        glVertex2f(-47.1584971407488, 124.6683173115089);
        glVertex2f(-46.6147825503068, 124.702420475701);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92);
        glVertex2f(-46.8275471389502, 128.7871314492998);
        glVertex2f(-47.4517584081925, 127.7220610404933);
        glVertex2f(-47.4200188521294, 127.4732128141367);
        glEnd();
        circle(1,-46.9150434055825, 129.2758045241291,78, 235, 148);
        circle(1,-47.7216435613076, 130.5406049374159,53, 159, 100);
        circle(1,-48.158551978992, 129.0860844621361,61, 183, 115);

        //L3
        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92);
        glVertex2f(5.0800809296203, 113.0683965271573);
        glVertex2f(6.5567035942146, 112.9449064803187);
        glVertex2f(8.5583476506646, 126.0965964686317);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92);
        glVertex2f(5.3160643359058, 123.1762103632934);
        glVertex2f(7.2187015557982, 119.9317016021564);
        glVertex2f(7.2662674862956, 120.6477311218556);
        glEnd();
        circle(1,4.6980746523351, 123.4270224145127,61, 183, 115);
        circle(1,5.8464642481989, 123.170644729937,53, 159, 100);
        circle(1,6.8002115396789, 124.4525331528153,61, 183, 115);
        circle(1,6.5861050048569, 126.3570530953773,61, 183, 115);
        circle(1,7.8318157529125, 127.3825638336799,53, 159, 100);
        circle(1,9.5446680314889, 127.5290653677232,61, 183, 115);
        circle(1,8.2211003616798, 125.844297726226,61, 183, 115);
        circle(1,9.7198461054342, 126.02742464378,61, 183, 115);
        circle(1,9.1164549618448, 124.708910837391,53, 159, 100);
        circle(1,8.5519922791321, 123.4270224145127,61, 183, 115);

        //L4
        glBegin(GL_POLYGON);
        glColor3ub(185, 145, 92);
        glVertex2f(26.1690785174442, 126.0943926129752);
        glVertex2f(26.5805354845035, 126.3121444838046);
        glVertex2f(25.0405247755586, 134.0371572811135);
        glEnd();
        circle(1,24.8701209153873, 133.1529203453606,61, 183, 115);
        circle(1,24.2237603674143, 131.6934306605838,53, 159, 100);
        circle(1,24, 134,61, 183, 115);
        circle(1,24.9930603069356, 134.837058852829,53, 159, 100);
        circle(1,26.188696433252, 134.3691617493413,61, 183, 115);
        circle(1,26.8867658250628, 133.2015700015199,53, 159, 100);
        circle(1,26, 132,53, 159, 100);

    }

    void carS(){

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(carMoveS,0.0f,0.0f);

        glBegin(GL_POLYGON);
        glColor3ub(241, 32, 2); // tree
        glVertex2f(-40.0143539606602, -23.3297699298479);
        glVertex2f(-40, -20);
        glVertex2f(-30.6010889318529, -18.1699779112968);
        glVertex2f(-26, -15);
        glVertex2f(-18, -15);
        glVertex2f(-12.2656857453063, -17.9389424477796);
        glVertex2f(-10.2602510217778, -18.2469897324692);
        glVertex2f(-10.1374693040107, -22.8676990028134);
        glVertex2f(-13.5753574014882, -23.5608053933651);
        glEnd();

        //Glass
        glBegin(GL_POLYGON);
        glColor3ub(137, 143, 147); // tree
        glVertex2f(-29.9895010620378, -18.4911742752463);
        glVertex2f(-25.6216411393084, -16.0361784592204);
        glVertex2f(-22, -16);
        glVertex2f(-21.5941339378307, -18.420014976231);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(137, 143, 147); // tree
        glVertex2f(-20.6660762731939, -18.3916814689936);
        glVertex2f(-21.1403303094952, -15.9650191602052);
        glVertex2f(-19, -16);
        glVertex2f(-13.1987668136236, -18.5623335742615);
        glEnd();

        circle(2,-34.527537345393, -22.831891515176,0,0,0);
        circle(1.5,-34.527537345393, -22.831891515176,255, 255, 255);

        circle(2,-16.7157449332239, -22.831891515176,0, 0, 0);
        circle(1.5,-16.7157449332239, -22.831891515176,255,255,255);

        glPopMatrix();

    }

    void daySun(){
        circle(7,53.3597186480976, 127.3933295498741,255, 232, 71);
    }
    void Bus(){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(busMove,0.0f,0.0f);

        glBegin(GL_POLYGON);
        glColor3ub(10, 45, 106); // tree
        glVertex2f(20.3929515563966, -8.2402864813311);
        glVertex2f(19.8149928764729, -6.7099354090625);
        glVertex2f(20.6884234164422, 6.4381738255554);

        glVertex2f(20.6456237264382, 9.7657834978754);
        glVertex2f(26.6246102345536, 9.7657834978754);
        glVertex2f(26.6246102345536, 10.7932939983959);

        glVertex2f(31.6246102345536, 10.7932939983959);
        glVertex2f(31.6246102345536,9.7657834978754);

        glVertex2f(39.6246102345536, 9.7657834978754);
        glVertex2f(39.6246102345536, 10.7932939983959);
        glVertex2f(45, 10.7932939983959);
        glVertex2f(45, 9.7657834978754);

        glVertex2f(56.7680900804872, 9.7657834978754);
        glVertex2f(59.7453378748964, -6.6638516365638);
        glVertex2f(59.7453378748964, -8.7584088797657);
        glEnd();

        //Glass
        glBegin(GL_POLYGON);
        glColor3ub(125, 125, 125); // tree
        glVertex2f(54.5901074292911, 5.1061288145897);
        glVertex2f(54.5901074292911, -4.9858376374708);
        glVertex2f(58.8620965714115, -5.0259128805213);
        glVertex2f(57.1661385971192, 5.1061288145897);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(9, 9, 9);
        glVertex2f(47.7615687675478, 5.1763250427607);
        glVertex2f(47.7615687675478, -8.2104051581456);
        glVertex2f(50.0726202173038, -8.2104051581456);
        glVertex2f(50.0726202173038, 5.1763250427607);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(9, 9, 9);
        glVertex2f(22.1414511410185, 5.9161997680722);
        glVertex2f(22.1414511410185, -1.5515798000134);
        glVertex2f(47.4352880081045, -1.5515798000134);
        glVertex2f(47.4352880081045, 5.9161997680722);
        glEnd();

        //wheel
        circle(3,53.5752952915942, -8.7871591224307,0,0,0);
        circle(2,53.5752952915942, -8.7871591224307,255,255,255);

        circle(3,27.0004868827031, -8.4337733604157,0,0,0);
        circle(2,27.0004868827031, -8.4337733604157,255,255,255);

        glPopMatrix();
    }

    //Sky------------------------------------------------
    void skys(){
    glBegin(GL_POLYGON);
    glColor3ub(sr, sg, sb); // tree
    glVertex2f(-90,-30);
    glVertex2f(90,-30);
    glVertex2f(90,150);
    glVertex2f(-90,150);
glEnd();

}

    //Hill------------------------------------------------
    void hill(){
    glBegin(GL_POLYGON);
    glColor3ub(0, 135, 0);
    glVertex2f(-90, 100);
    glVertex2f(-50.3527195617966, 127.4079952633437);
    glVertex2f(2.2148918114321, 100.2978938345805);
    glEnd();

//Hill L3------------------------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 115, 0);
    glVertex2f(84.1814265822812, 99.5651883905598);
    glVertex2f(90, 100);
    glVertex2f(90, 120);
    glVertex2f(79.8981397296477, 136.2004605915912);
    glVertex2f(65.2960254593064, 107.6249482747868);
    glEnd();

//Hill L2------------------------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 115, 0);
    glVertex2f(-20.7591013072382, 103.228715610663);
    glVertex2f(-8.4933253201515, 100.6642465565908);
    glVertex2f(84.1814265822812, 99.5651883905598);
    glVertex2f(32.0032049229283, 129.9724643174159);
    glEnd();
}

    void riverS()
        {
    glBegin(GL_POLYGON);
    glColor3ub(128, 219, 227);
    glVertex2f(-90, 100);
    glVertex2f(-90,60);
    glVertex2f(90,60);
    glVertex2f(90,100);
    glEnd();
}
    void land()
        {
    glBegin(GL_POLYGON);
glColor3ub(0, 115, 0);
glVertex2f(-90,60);
glVertex2f(90,60);
glVertex2f(90,0);
glVertex2f(-90,0);

glEnd();
}

    void boatS()
        {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(boatMove, 0.0f, 0.0f);
    //Body base
    glBegin(GL_POLYGON);
    glColor3ub(243, 153, 127);
    glVertex2f(10, 80);
    glVertex2f(12.54, 74.91);
    glVertex2f(54.998, 74.91);
    glVertex2f(60, 80);
    glEnd();

    //Body---
    glBegin(GL_POLYGON);
    glColor3ub(243, 153, 126);
    glVertex2f(54.998,75.15);
    glVertex2f(12.54, 75.15);
    glVertex2f(15, 70);
    glVertex2f(50, 70);
    glEnd();

//Lines next two--
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(10, 80);
    glVertex2f(10, 79.2429638869627);
    glVertex2f(60, 79.2429638869627);
    glVertex2f(60, 80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(12.54, 74.91);
    glVertex2f(54.998, 74.91);
    glVertex2f(54.998,75.15);
    glVertex2f(12.54, 75.15);
    glEnd();

//piller
    glBegin(GL_POLYGON);
    glColor3ub(243, 153, 126);
    glVertex2f(33.4275221289085, 108.8742429709251);
    glVertex2f(34.709436831992, 108.8742429709251);
    glVertex2f(28.7601278561337, 79.9184096132819);
    glVertex2f(27.4897092038403, 79.819947826384);
    glEnd();

//tent clkwise 1
    glBegin(GL_POLYGON);
    glColor3ub(239, 239, 239);
    glVertex2f(33.4275221289085, 108.8742429709251);
    glVertex2f(30.95,96.8);
    glVertex2f(23.5945113674044, 96.5195275701763);
    glEnd();

    //tent clkwise 2
    glBegin(GL_POLYGON);
    glColor3ub(239, 239, 239);
    glVertex2f(34.709436831992, 108.8742429709251);
    glVertex2f(50, 80);
    glVertex2f(28.7601278561337, 79.9184096132819);
    glEnd();

    //tent clkwise 3
    glBegin(GL_POLYGON);
    glColor3ub(239, 239, 239);
    glVertex2f(25.340647472717, 96.0630051078589);
    glVertex2f(30.95,96.0630051078589);
    glVertex2f(27.4897092038403, 81.1137119373814);
    glVertex2f(15, 81.1137119373814);
    glEnd();
    glPopMatrix();


}

    void Road()
        {
    //road
    glBegin(GL_POLYGON);
    glColor3ub(57, 53, 59);
    glVertex2f(90,0);
    glVertex2f(-90,0);
    glVertex2f(-90,-30);
    glVertex2f(90,-30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(57, 53, 59);
    glVertex2f(90,0);
    glVertex2f(-90,0);
    glVertex2f(-90,-30);
    glVertex2f(90,-30);
    glEnd();

    //Road Border------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(90,0);
    glVertex2f(-90,0);
    glVertex2f(-90,3.50);
    glVertex2f(90,3.50);
    glEnd();

    //Road Middle Line L1------------------------------
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-80, -17);
    glVertex2f(-70, -17);
    glVertex2f(-70, -15);
    glVertex2f(-80, -15);
    glEnd();

    //L2
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-64, -17);
    glVertex2f(-54, -17);
    glVertex2f(-54, -15);
    glVertex2f(-64, -15);
    glEnd();

    //L3
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-48, -17);
    glVertex2f(-38, -17);
    glVertex2f(-38, -15);
    glVertex2f(-48, -15);
    glEnd();

    //L4
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-32, -17);
    glVertex2f(-22, -17);
    glVertex2f(-22, -15);
    glVertex2f(-32, -15);
    glEnd();

    //L5
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-16, -17);
    glVertex2f(-6, -17);
    glVertex2f(-6, -15);
    glVertex2f(-16, -15);
    glEnd();

    //L6
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(0, -17);
    glVertex2f(10, -17);
    glVertex2f(10, -15);
    glVertex2f(0, -15);
    glEnd();

    //L7
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(16, -17);
    glVertex2f(26, -17);
    glVertex2f(26, -15);
    glVertex2f(16, -15);
    glEnd();

    //L6
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(32, -17);
    glVertex2f(42, -17);
    glVertex2f(42, -15);
    glVertex2f(32, -15);
    glEnd();

    //L6
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(48, -17);
    glVertex2f(58, -17);
    glVertex2f(58, -15);
    glVertex2f(48, -15);
    glEnd();

    //L6
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(64, -17);
    glVertex2f(74, -17);
    glVertex2f(74, -15);
    glVertex2f(64, -15);
    glEnd();

    //L6
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(80, -17);
    glVertex2f(90, -17);
    glVertex2f(90, -15);
    glVertex2f(80, -15);
    glEnd();
}
    void windmillS(float x, float y, float radius,float r,float g,float b)
        {
    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glColor3f(r, g, b); // Set color

    // Draw spokes
    int spokeCount=4;
    glColor3ub(1.0f, 1.0f, 0.0f); // Set color for spokes
    for (int i = 0; i < spokeCount; i++)
    {
        float angle = i * twicePi / spokeCount;
        float spokeX = x + radius * cos(angle);
        float spokeY = y + radius * sin(angle);

        glLineWidth(10);
        glBegin(GL_LINES);
        glVertex2f(x, y); // Center
        glVertex2f(spokeX, spokeY); // Edge
        glEnd();
    }
}
    //Windmill----------------------
    void windmillS()
        {
    //Piller
    glLineWidth(10);

	glBegin(GL_LINES);
	glColor3ub(123, 123, 123);
    glVertex2f(-80.2908413789232, 102.6411729917741);
	glVertex2f(-79.4164521570391, 133.8925712927076);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 123, 123);
    glVertex2f(-79.4164521570391, 133.8925712927076);
	glVertex2f(-78.9904081226272, 102.6271677162774);
	glEnd();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(-79.4164521570391, 133.8925712927076, 0.0f);
    glRotatef(_angle1s, 0.0f, 0.0f, 1.0f);
    windmillS(0, 0,7,0,0,0);
    glPopMatrix();

   /*End of  windmillS */
}

    void colud(){
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glTranslatef(boatMove, 0.0f, 0.0f);

        circle(3,-41.0012565480993, 143.4058599540206,185, 185, 185);
        circle(3,-37.3954892696925, 147.2717577066678,185, 185, 185);
        circle(3,-33.5855957591752, 144.5941843259681,185, 185, 185);
        circle(3,-37.0741729495284, 141.9166109452683,185, 185, 185);

        //ClwdL3
        circle(3,18.0537246744996, 142.5100634432633,185, 185, 185);
        circle(3,13.0882057494921, 142.1081924802553,185, 185, 185);
        circle(3,16.1849809930451, 138.6922892946874,185, 185, 185);
        circle(3,20.1894317390189, 138.4913538131834,185, 185, 185);
        circle(3,20.6165731519228, 146.1269021103353,185, 185, 185);
        circle(3,23.179421629346, 142.1081924802553,185, 185, 185);
        circle(3,25.4753067237043, 146.1269021103353,185, 185, 185);
        circle(3,27.0236943454808, 140.9025795912314,185, 185, 185);

        circle(3,-11.0273971265672, 142.0633821567416,185, 185, 185);
        circle(3,-7.1286248209597, 144.7662029718514,185, 185, 185);
        circle(3,-3.127253244152, 142.0633821567416,185, 185, 185);
        circle(3,-7.0260255497595, 138.9744440823305,185, 185, 185);

        circle(3,-87.7178826181751, 143.346319,185, 185, 185);
        circle(3,-85.1886194860824, 146.519156330105,185, 185, 185);
        circle(3,-81.8162686432922, 144.5802006693694,185, 185, 185);
        circle(3,-77.8818593267036, 147.4004998122576,185, 185, 185);
        circle(3,-76.3830367299079, 143.1700510979254,185, 185, 185);
        circle(3,-76.3830367299079, 143.1700510979254,185, 185, 185);
        circle(3,-81.3478865817935, 140.3497519550372,185, 185, 185);

        circle(4,65.3158317018991, 139.4894141746252,185, 185, 185);
        circle(4,67.0092111393465, 142.9481357761582,185, 185, 185);
        circle(4,71.422192139855, 144.2160243210495,185, 185, 185);
        circle(4,71.510465362697, 138.9778683011318,185, 185, 185);
        circle(4,67.5718679172653, 135.8016543211106,185, 185, 185);

        glPopMatrix();
    }

    void houseS(){
        //chal
            glBegin(GL_POLYGON);
            glColor3ub(9, 64, 95);
            glVertex2f(9.0866388239613, 53.4322004995267);
            glVertex2f(19.6871819814495, 74.4940307011483);
            glVertex2f(61.1675682498818, 74.4940307011483);
            glVertex2f(71.76811140737, 53.4322004995267);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(136, 167, 187);
            glVertex2f(23.5040893741498, 71.8798548958683);
            glVertex2f(23.5040893741498, 71.3124897222293);
            glVertex2f(57.5238070106389, 71.3124897222293);
            glVertex2f(57.5238070106389, 71.8798548958683);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(204, 224, 241);
            glVertex2f(57.5339161314138, 71.8798548958683);
            glVertex2f(54.7200568053145, 73.6948642055033);
            glVertex2f(26.316659311883, 73.6948642055033);
            glVertex2f(23.5175448838545, 71.8798548958683);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(204, 224, 241);
            glVertex2f(26.4432590096488, 71.2087029634368);
            glVertex2f(26.4432590096488, 62.2191386056149);
            glVertex2f(54.6385452971178, 62.2191386056149);
            glVertex2f(54.6385452971178, 71.2087029634368);
            glEnd();

            //windowL1
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(30.9202966883511, 70.1621685537816);
            glVertex2f(30.9048203342121, 67.1394759625277);
            glVertex2f(33.3646048348497, 67.1394759625277);
            glVertex2f(33.3390762066715, 70.1621685537816);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(33.68729213129, 70.1621685537816);
            glVertex2f(33.68729213129, 67.1394759625277);
            glVertex2f(35.8655524050444, 67.1394759625277);
            glVertex2f(35.8655524050444, 70.1621685537816);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(33.68729213129, 66.8121685537816);
            glVertex2f(33.68729213129, 64.1394759625277);
            glVertex2f(35.8655524050444, 64.1394759625277);
            glVertex2f(35.8655524050444, 66.8121685537816);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(30.9048203342121, 66.8121685537816);
            glVertex2f(30.9048203342121, 64.1394759625277);
            glVertex2f(33.3390762066715, 64.1394759625277);
            glVertex2f(33.3390762066715, 66.8121685537816);
            glEnd();

            //window L2
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(45.1985223681482, 70.1965251672193);
            glVertex2f(45.1985223681482, 67.1262943608837);
            glVertex2f(47.6033073551318, 67.1262943608837);
            glVertex2f(47.6033073551318, 70.1965251672193);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(47.7452084796337, 70.1965251672193);
            glVertex2f(47.7452084796337, 67.1262943608837);
            glVertex2f(50, 67.1262943608837);
            glVertex2f(50, 70.1965251672193);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(47.7452084796337, 66.8121685537816);
            glVertex2f(47.7452084796337, 64.1394759625277);
            glVertex2f(50, 64.1394759625277);
            glVertex2f(50, 66.8121685537816);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(107, 172, 225);
            glVertex2f(45.1985223681482, 66.8121685537816);
            glVertex2f(45.1985223681482, 64.1394759625277);
            glVertex2f(47.6033073551318, 64.1394759625277);
            glVertex2f(47.6033073551318, 66.8121685537816);
            glEnd();

            //Wall-----------------------------------
            glBegin(GL_POLYGON);
            glColor3ub(214, 227, 227);
            glVertex2f(14.5, 53);
            glVertex2f(14.8, 37);
            glVertex2f(67, 37);
            glVertex2f(67, 53);
            glEnd();

            //Window below
            glBegin(GL_POLYGON);
            glColor3ub(98, 157, 211);
            glVertex2f(25, 49);
            glVertex2f(25, 44);
            glVertex2f(30, 44);
            glVertex2f(30, 49);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(98, 157, 211);
            glVertex2f(25, 43.7);
            glVertex2f(25, 40);
            glVertex2f(30, 40);
            glVertex2f(30, 43.7);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(98, 157, 211);
            glVertex2f(30.4, 49);
            glVertex2f(30.4, 40);
            glVertex2f(36, 40);
            glVertex2f(36, 49);
            glEnd();

            //Pillers -----------------------------------------

            //Right Piller
            glBegin(GL_POLYGON);
            glColor3ub(44, 21, 12);
            glVertex2f(65.7863967493533, 53.2825081477186);
            glVertex2f(65.3572427932369, 40.2302570539799);
            glVertex2f(67.6932792059489, 40.2302570539799);
            glVertex2f(67.1977951475349, 53.2825081477186);
            glEnd();

            //Mid Piller
            glBegin(GL_POLYGON);
            glColor3ub(44, 21, 12);
            glVertex2f(42.4159887596245, 53.5168131910917);
            glVertex2f(42, 40);
            glVertex2f(44.290497863092, 40);
            glVertex2f(43.5893311085559, 53.5168131910917);
            glEnd();

            //Right Piller
            glBegin(GL_POLYGON);
            glColor3ub(44, 21, 12);
            glVertex2f(14.298932661684, 53.6);
            glVertex2f(13.8272543974964, 40.5473161408876);
            glVertex2f(16.1317203012982, 40.5473161408876);
            glVertex2f(15.6, 53.6);
            glEnd();

            //LowerBase
            glBegin(GL_POLYGON);
            glColor3ub(228, 217, 116);
            glVertex2f(69.67, 34.8);
            glVertex2f(69.67, 30.5);
            glVertex2f(11.6, 30.5);
            glVertex2f(11.6, 34.8);
            glEnd();

            //Door
            glBegin(GL_POLYGON);
            glColor3ub(176, 158, 76);
            glVertex2f(51, 49);
            glVertex2f(51, 37);
            glVertex2f(58, 37);
            glVertex2f(58, 49);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(96, 157, 212);
            glVertex2f(52, 48);
            glVertex2f(52, 39);
            glVertex2f(54.5,39);
            glVertex2f(54.5, 48);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(51.583, 46.05);
            glVertex2f(51.583, 42.843);
            glVertex2f(51.9, 42.843);
            glVertex2f(51.9, 46.05);
            glEnd();



            //UperBase
            glBegin(GL_POLYGON);
            glColor3ub(100, 95, 50);
            glVertex2f(64.4, 37.2);
            glVertex2f(64.4, 35);
            glVertex2f(17.2, 35);
            glVertex2f(17.2, 37.2);
            glEnd();
            //PillarBase
            glBegin(GL_POLYGON);
            glColor3ub(70, 158, 162);
            glVertex2f(12.4, 40.5);
            glVertex2f(12.4, 34.5);
            glVertex2f(17.4, 34.5);
            glVertex2f(17.4, 40.5);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(70, 158, 162);
            glVertex2f(40.5, 40.5);
            glVertex2f(40.5, 34.5);
            glVertex2f(45.5, 34.5);
            glVertex2f(45.5, 40.5);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(70, 158, 162);
            glVertex2f(64, 40.5);
            glVertex2f(64, 34.5);
            glVertex2f(69, 34.5);
            glVertex2f(69, 40.5);
            glEnd();

            //RainWaterDrainage
            glBegin(GL_POLYGON);
            glColor3ub(142, 175, 197);
            glVertex2f(9.0866388239613, 53.4322004995267);
            glVertex2f(9.0866388239613, 52.0842264559586);
            glVertex2f(71.76811140737, 52.0842264559586);
            glVertex2f(71.76811140737, 53.4322004995267);
            glEnd();


        }

    void house2S(){

        glBegin(GL_POLYGON);
        glColor3ub(169, 148, 103);
        glVertex2f(-72.8938277469536, 38.2359837375161);
        glVertex2f(-73.4858548189886, 34.6154727417259);
        glVertex2f(-56.3856285285619, 29.5318570888954);
        glVertex2f(-56.5144120873188, 35.2653080486626);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(116, 102, 71);
        glVertex2f(-56.3856285285619, 29.5318570888954);
        glVertex2f(-56.5144120873188, 35.2653080486626);
        glVertex2f(-10.8175748133734, 37.1524247260164);
        glVertex2f(-10.2046610761561, 33.5643637032323);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(51,17,23);
        glVertex2f(-76.7777175779859, 50.1485541691719);
        glVertex2f(-67.0612694372829, 67.0939695975101);
        glVertex2f(-64.907438258232, 61.4734149984758);
        glVertex2f(-71.8010002376258, 50.891774144099);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(190, 138, 97);
        glVertex2f(-71.8010002376258, 50.891774144099);
        glVertex2f(-71.6639465022139, 37.883664612108);
        glVertex2f(-55.5279244897817, 34.8382226856733);
        glVertex2f(-55.8439065431379, 47.3243182644489);
        glVertex2f(-63.7434578770428, 64.567021682758);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(126, 92, 64);
        glVertex2f(-55.8439065431379, 47.3243182644489);
        glVertex2f(-55.5279244897817, 34.8382226856733);
        glVertex2f(-12.9971734264105, 36.7833961431907);
        glVertex2f(-13.8330280809896, 47.9233303334392);
        glEnd();
        //door
        glBegin(GL_POLYGON);
        glColor3ub(77, 59, 45);
        glVertex2f(-39.4990376535563, 48.3023029946222);
        glVertex2f(-38.8744368006429, 36.4927730465341);
        glVertex2f(-34.2534102208426, 37.0134483019832);
        glVertex2f(-34.9970920359319, 48.9136749048316);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(-66, 50);
        glVertex2f(-65.8931153822892, 43.0953457005145);
        glVertex2f(-62.89553138287, 42.8784040413551);
        glVertex2f(-62.9723925110602, 50.0374787936167);
        glEnd();


//chal--------------------------
        glBegin(GL_POLYGON);
        glColor3ub(140, 76, 77);
        glVertex2f(-67.0612694372829, 67.0939695975101);
        glVertex2f(-58.1347764299703, 47.027030274478);
        glVertex2f(-7.8936299463351, 47.9188942443906);
        glVertex2f(-26.5365710943507, 63.52651371786);
        glEnd();



    }

    void Plant(){

        circle(4,68.6910110999845, 42.2477356446413,89, 188, 73);
        circle(4,71.7487508290957, 37.2305295130389,69, 155, 66);
        circle(4,70.794736033613, 32.0292057252309,89, 188, 73);
        circle(4,77,37,89, 152, 73);
        circle(4,74.9532620652042, 32.3974410376421,89, 188, 73);
        circle(4,74.6132911151374, 41.6225237629045,89, 188, 73);

        glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(66, 30.5);
        glVertex2f(66, 28);
        glVertex2f(80, 28);
        glVertex2f(80, 30.5);
        glEnd();
    }


void drawRain1() {
    glColor3ub(233,233,233); // Blue color for rain
    glLineWidth(1);
    glBegin(GL_LINES);

    for (int i = 0; i < 400; i++) { // Generate 1000 raindrops
        float x = (rand() % 181) - 90;  // Random X in range [-90, 90]
        float y = (rand() % 181) - 30;  // Random Y in range [-30, 150]
        glVertex2f(x, y);
        glVertex2f(x, y+5);

    }

    glEnd();
    glFlush();
}

void handleKeypressRS(unsigned char key, int x, int y) {

    switch (key)
    {
        case 'r':
            sr = 77; sg = 189; sb = 243;
            checkRain = true;
            glutPostRedisplay();
        break;
        case 'd':
            sr = 77; sg = 189; sb = 243;
            checkRain = false;
            glutPostRedisplay();
        break;
        case 'n':
            sr = 38, sg = 94, sb = 121;
            checkRain = false;
            glutPostRedisplay();
        break;


    }

}


void displaySiam() {

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color

    skys();
    riverS();
    hill();
    windmillS();
    boatS();
    land();
    Road();
    tree1S();
    tree2Land();
    tree3Hill();
    Bus();
    carS();
    Plant();
    tree1S();
    houseS();
    house2S();

    daySun();

    if(checkRain)
    {
        colud();
        drawRain1();
    }


    //Windmill center-------------------------------------------
    circle(1.5,-79.4164521570391, 133.8925712927076,105, 105, 108);



glFlush();
glutSwapBuffers();
}


void carUpdate(int value) {
    carMoveS -= 0.5;
    if(carMoveS < -100)
    {
        carMoveS = 135;
    }

    busMove += 0.5;
    if(busMove > 70)
    {
        busMove = -180;
    }


    glutPostRedisplay();
    glutTimerFunc(20, carUpdate, 0);
}

void boatUpdate(int value) {
    boatMove += 0.2;
    if(boatMove > 90)
    {
    boatMove = -160;
    }

    cloudMove+=0.1;
    if(cloudMove)

    glutPostRedisplay();
    glutTimerFunc(20, boatUpdate, 0);
}



void updatewinwheellS(int value)
{

    _angle1s+=0.7f;
   if(_angle1s > 360.0)
   {
        _angle1s-=360;
    }
	glutPostRedisplay(); //Notify GLUT that the displaySiam has changed

	glutTimerFunc(30,updatewinwheellS, 0); //Notify GLUT to call update again in 25 milliseconds
}


//siam


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
            glutDisplayFunc(displaySiam);
        break;

        case '4':
            rakib = false;
            riyadh = false;
            siam = false;
            fahad = true;
            glutPostRedisplay();
            glutDisplayFunc(displayFahad);
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

    if(siam)
    {
        switch (key)
        {
            case 'r':
                sr = 77; sg = 189; sb = 243;
                checkRain = true;
                glutPostRedisplay();
            break;
            case 'd':
                sr = 77; sg = 189; sb = 243;
                checkRain = false;
                glutPostRedisplay();
            break;
            case 'n':
                sr = 38, sg = 94, sb = 121;
                checkRain = false;
                glutPostRedisplay();
            break;
        }

    }

    if(fahad)
    {
        switch (key)
        {
            case 'o':
                r = 0.4f; g = 0.698f;b = 0.996f;
                isRainingF = false;
                glutPostRedisplay();
                break;

            case 'r':
                r = 0.529f; g = 0.627f ;b = 0.745f;
                isRainingF = true;
                glutPostRedisplay();
                break;
            case 'd':
                isDay = true;
                isNightF=false;
                break;

            case 'n':
                isDay = false;
                isNightF=true;
                isRainingF = false;
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

    glutTimerFunc(20, updateF, 0);

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
