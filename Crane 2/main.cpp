#include<windows.h>
#ifdef APPLE
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

/* GLUT callback Handlers */
float view_rotx = 0.0f, view_roty = 0.0f;
int oldMouseX, oldMouseY;

void initGL(){
    glShadeModel(GL_FLAT);
    float ambient[] = {1.0f,1.0f,1.0f,1.0f};
    float diffuse[] = {1.0f,1.0f,1.0f,1.0f};
    float specular[] = {0.2f,1.0f,0.2f,1.0f};
    float position[] = {1.0f, 1.0f, 1.0f, 0.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

    float mambient[] ={0.1745f, 0.01175f, 0.01175f, 0.55f};
    float mdiffuse[] ={0.61424f, 0.04136f, 0.04136f, 0.55f };
    float mspecular[] ={0.727811f, 0.626959f, 0.626959f, 0.55f };
    float mshine =76.8f;

    glMaterialfv(GL_FRONT,GL_AMBIENT,mambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mdiffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mspecular);
    glMaterialf (GL_FRONT,GL_SHININESS,mshine);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
}

void tiang(){
    float BODY_LENGTH=4.8f;
    float BODY_RADIUS=0.5f;
    int SLICES=4;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah

}
void tiangatas(){
    float BODY_LENGTH=4.5f;
    float BODY_RADIUS=0.3f;
    int SLICES=4;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah
}

void alas(){
    float BODY_LENGTH=0.7f;
    float BODY_RADIUS=1.2f;
    int SLICES=4;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah
}

void kaki(){
    float BODY_RADIUS=0.2f;
    float BODY_LENGTH=0.5f;
    int SLICES=30;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah
}

void otomatis(){
    float BODY_RADIUS=0.2f;
    float BODY_LENGTH=0.5f;
    int SLICES=30;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah

}
void tambang(){
    float BODY_RADIUS=0.02f;
    float BODY_LENGTH=0.8f;
    int SLICES=30;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah

}
void porosatas(){
float BODY_RADIUS=0.6f;
    int SLICES=30;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluSphere(q, BODY_RADIUS, SLICES, STACKS);
}


void tanah(){
    float BODY_LENGTH=0.0f;
    float BODY_RADIUS=10.0f;
    int SLICES=4;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah
}

void gedung(){
    float BODY_LENGTH=4.0f;
    float BODY_RADIUS=2.0f;
    int SLICES=4;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah
}

void gedung2(){
    float BODY_LENGTH=5.0f;
    float BODY_RADIUS=2.0f;
    int SLICES=4;
    int STACKS=30;
    GLUquadric *q = gluNewQuadric();
    gluCylinder(q, BODY_RADIUS, BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup atas
    glTranslatef(0.0f, 0.0f, BODY_LENGTH);
    gluDisk(q, 0.0f, BODY_RADIUS, SLICES, STACKS); //lingkaran untuk tutup bawah
}

int sudut = 0;
void display(){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(7,7,7, 0,0,0, 0,0,1);

    glTranslatef(0.0f, 0.0f, -3.0f);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glTranslatef(0.0f, 0.0f, -1.0f);
    glPushMatrix();
    glColor3f(0.0f,0.1f,0.0f);
    tanah();
    glPopMatrix();

    glTranslatef(-3.0f, 0.0f, 0.0f);
    glPushMatrix();
    glColor3f(0.1f,0.1f,0.1f);
    gedung();
    glPopMatrix();

    glTranslatef(3.0f, -3.0f, 0.0f);
    glPushMatrix();
    glColor3f(0.1f,0.1f,0.1f);
    gedung();
    glPopMatrix();

    glTranslatef(-4.0f, 0.0f, 0.0f);
    glPushMatrix();
    glColor3f(0.1f,0.1f,0.1f);
    gedung2();
    glPopMatrix();

    glTranslatef(4.0f, 4.0f, 1.0f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    alas();
    glPopMatrix();

    glTranslatef(1.0f, 0.0f, -0.5f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    kaki();
    glPopMatrix();

    glTranslatef(-2.0f, 0.0f, 0.0f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    kaki();
    glPopMatrix();

    glTranslatef(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    kaki();
    glPopMatrix();

    glTranslatef(0.0f, -2.0f, 0.0f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    kaki();
    glPopMatrix();

    glTranslatef(0.0f, 1.0f, 1.0f);
    glPushMatrix();
    glColor3f(1.0f,1.0f,0.0f);
    tiang();
    glPopMatrix();

    glTranslatef(0.0f, 0.0f, 4.0f);
    glRotatef(90, 0.1f, 2.0f, 0.0f);
    glColor3f(0.0f,0.0f,0.0f);
    glPushMatrix();
    porosatas();
    glPopMatrix();

    glRotatef(view_rotx, 1.0f, 0.0f, 0.0f);

    glTranslatef(0.0f, 0.0f, -1.0f);
    glPushMatrix();
    glColor3f(1.0f,1.0f,0.0f);
    tiangatas();
    glPopMatrix();

    glTranslatef(0.3f, 0.0f, 3.5f);
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    otomatis();
    glTranslatef(0.1f, 0.0f, -0.2f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    tambang();
    glColor3f(0.0f,0.1f,0.1f);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void timer(int value){
	glutPostRedisplay();
	glutTimerFunc(15, timer, 0);
}

void reshape(GLsizei width, GLsizei height){
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(30, 6, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 1.0f, 20.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouseControl(int button, int state, int x, int y){
	oldMouseX = x;
	oldMouseY = y;
}

void mouseMotion(int x, int y){
	int newMouseX = x;
	int newMouseY = y;
	float thetaY = 180.0f*(newMouseX - oldMouseX)/640;
	float thetaX = 180.0f*(newMouseY - oldMouseY)/480;
	oldMouseX = newMouseX;
	oldMouseY = newMouseY;
	view_rotx += thetaX;
	view_roty += thetaY;
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("3d-control");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutMouseFunc(mouseControl);
	glutMotionFunc(mouseMotion);
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
	return 0;
}
