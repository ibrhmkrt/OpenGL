
#include <GL\glut.h>
 double yatayDonme;//y ekseni dönme için
 double zoom = 0;//zoomlamak için gerekli deðiþkne
void display(void)
{

	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(0.0, 0.0, -4.5);
	// Red color used to draw.
	glColor3f(1.0, 1.0, 1.0);
	// changing in transformation matrix.
	// rotation about X axis

	glRotatef(yatayDonme, 0.0, 1.0, 0.0);

	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a Teapot.
	glutSolidTeapot(1.5);
	// Flush buffers to screen

	glFlush();
	// sawp buffers called because we are using double buffering 
	// glutSwapBuffers();
}
void idleFunc(void)
{
	yatayDonme += 0.01;
	display();
}

void reshapeFunc(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLdouble)x / (GLdouble)y, 1, 50);

	
}

void mouseFunc(int btn, int state) {//Mouse sebepli fonksiyon

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {//mouse sað týk yapýnca Cisim y ekseninde dönüyor
		glutIdleFunc(idleFunc);
		display();
	}
	else if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {//sol týk yapýnca dönmeyi kesiyoruz
		glutIdleFunc(0);
	}
}
// The callback function for when keys are pressed
void tusFunc(unsigned char key) {//tus sebepli foksiyon

	switch (key) {
	case'a'://a tuþuna her bastýðýmýzda 20 birim zoom yapar
		zoom += 20;
		glViewport(0, 0, (500 + zoom), (500 + zoom));
		glutPostRedisplay();
		break;
	case'z'://z tuþuna her bastýðýmýzda 20 birim zoom out yapar
		zoom-= 20;
		glViewport(0, 0, (500 + zoom), (500 + zoom));
		glutPostRedisplay();
		break;
	}
}



int main(int argc, char **argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	//double buffering used to avoid flickering problem in animation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// window size
	glutInitWindowPosition(200,80);	//pencere pozisyonu
	glutInitWindowSize(500, 500);//pencere boyutu
	// create the window 
	glutCreateWindow("Soru4");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	yatayDonme = 10;
	glClearColor(0.0, 0.0, 0.0, 0.0);//arka plan rengi siyah
	//Assign  the function used in events
	glutDisplayFunc(display);
	glutMouseFunc(mouseFunc);
	glutKeyboardFunc(tusFunc);
	glutReshapeFunc(reshapeFunc);
	
	//Let start glut loop
	glutMainLoop();
	return 0;
} 

