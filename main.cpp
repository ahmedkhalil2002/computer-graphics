#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#endif


#include <stdlib.h>
#include <math.h>



void display();
void reshape(int w, int h);
void timer(int);

void init() {
    glClearColor(0.5, 0.9, 0.4, 0.0);
}

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("20101874 20103015");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();

}

float step=0;
void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /*roof*/
    glColor3f(0.3, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(200, 500);
    glVertex2f(600, 500);
    glVertex2f(700, 350);
    glVertex2f(300, 350);
    glEnd();

    // Top of Front Wall
    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(200, 500);
    glVertex2f(100, 350);
    glVertex2f(300, 350);
    glEnd();

    // Front Wall
    glColor3f(0.7, 0.2, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(100, 350);
    glVertex2f(300, 350);
    glVertex2f(300, 100);
    glVertex2f(100, 100);
    glEnd();
    // Front Door
    glColor3f(0.7, 0.2, 0.9);
    glBegin(GL_POLYGON);
    glVertex2f(150, 250);
    glVertex2f(250, 250);
    glVertex2f(250, 100);
    glVertex2f(150, 100);
    glEnd();


    //side Wall
    glColor3f(0.1, 0.2, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(300, 350);
    glVertex2f(700, 350);
    glVertex2f(700, 100);
    glVertex2f(300, 100);
    glEnd();

    // window one
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(330, 320);
    glVertex2f(450, 320);
    glVertex2f(450, 230);
    glVertex2f(330, 230);
    glEnd();

    // window two
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(530, 320);
    glVertex2f(650, 320);
    glVertex2f(650, 230);
    glVertex2f(530, 230);
    glEnd();

    // road
    glColor3f(0.3, 0.5, 0.7);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2f(150, 100);
    glVertex2f(250, 100);
    glVertex2f(210, 0);
    glVertex2f(40, 0);
    glEnd();





	/*man */
    int man = 20;
	int mancenterx = 750;
	int mancentery = 200;
	int mansteps = 100;
	float circleangler = 3.14 * 2.0;
	glColor3f(1.0, 1.0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= mansteps; i++) {
		float angle = circleangler * float(i) / float(mansteps);//get the current angle
		float manx = man * cosf(angle);//calculate the x component
		float many = man * sinf(angle);//calculate the y component
		glVertex2f(manx + mancenterx, many + mancentery);//output vertex
	}
	glEnd();

	/*body*/
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(750, 200);
    glVertex2f(750, 100);
    glEnd();

    /*hands*/
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(720, 140);
    glVertex2f(750, 160);
    glVertex2f(780, 140);
    glEnd();

    /*cloud*/
    glLineWidth(3);
    glColor3f(0, 0.8, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200+step, 550);
    glVertex2f(250+step, 590);
    glVertex2f(350+step, 580);
    glVertex2f(380+step, 550);
    glVertex2f(300+step, 530);
    glEnd();

    /*cloud 2*/
    glLineWidth(3);
    glColor3f(0, 0.8, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(420+step, 570);
    glVertex2f(450+step, 590);
    glVertex2f(550+step, 580);
    glVertex2f(590+step, 550);
    glVertex2f(500+step, 530);
    glEnd();

    /*sun */
    int sun = 50;
	int suncenterx = 700;
	int suncentery = 500;
	int sunsteps = 100;
	float circleangle = 3.14 * 2.0;
	glColor3f(1.0, 1.0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= sunsteps; i++) {
		float angle = circleangle * float(i) / float(sunsteps);//get the current angle
		float sunx = sun * cosf(angle);//calculate the x component
		float suny = sun * sinf(angle);//calculate the y component
		glVertex2f(sunx + suncenterx, suny + suncentery);//output vertex
	}
	glEnd();


    glFlush();


}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {

    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
	step+=0.5;


}
