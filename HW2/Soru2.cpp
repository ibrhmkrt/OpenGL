// SampleTransformationCode.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <GL/glut.h>
// The angle to rotate the drawing by
float angle = 0;//döndürme için kullandýðýmýz
bool durum = true;//ekran dönme durumu için bool deðiþken tanýmladým 
double zoom=0;//zoom için oluþturduðum deðiþken
// A set of possible background colours
int   backgroundIndex = 0;
float backgroundRed[] = { 1.0, 1.0, 0.0, 0.0, 0.0 };
float backgroundGreen[] = { 1.0, 0.0, 1.0, 0.0, 0.0 };
float backgroundBlue[] = { 1.0, 0.0, 0.0, 1.0, 0.0 };

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window colour to white

			// Set projection parameters
	glMatrixMode(GL_PROJECTION); 
	
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

// A function to draw the cross shape
void drawCross() {

	//Set colour to blue
	glColor3f(0.0, 0.0, 1.0);

	// Draw top triangle
	glBegin(GL_TRIANGLES);
	glVertex2i(60, 200);
	glVertex2i(200, 340);
	glVertex2i(340, 200);
	glEnd();

	// Draw bottom triangle
	glBegin(GL_TRIANGLES);
	glVertex2i(60, 200);
	glVertex2i(200, 60);
	glVertex2i(340, 200);
	glEnd();

	//Set colour to black
	glColor3f(0.0, 0.0, 0.0);
	// Set line width
	glLineWidth(5.0);

	// Draw top triangle outline
	glBegin(GL_LINE_LOOP);
	glVertex2i(60, 200);
	glVertex2i(200, 340);
	glVertex2i(340, 200);
	glEnd();

	// Draw bottom triangle outline
	glBegin(GL_LINE_LOOP);
	glVertex2i(60, 200);
	glVertex2i(200, 60);
	glVertex2i(340, 200);
	glEnd();

	//Set colour to red
	glColor3f(1.0, 0.0, 0.0);

	// Draw the top arm
	glBegin(GL_POLYGON);
	glVertex2i(180, 380);
	glVertex2i(220, 380);
	glVertex2i(220, 220);
	glVertex2i(180, 220);
	glEnd();

	// Draw the right arm
	glBegin(GL_POLYGON);
	glVertex2i(220, 220);
	glVertex2i(380, 220);
	glVertex2i(380, 180);
	glVertex2i(220, 180);
	glEnd();

	// Draw the bottom arm
	glBegin(GL_POLYGON);
	glVertex2i(220, 180);
	glVertex2i(220, 20);
	glVertex2i(180, 20);
	glVertex2i(180, 180);
	glEnd();

	// Draw the left arm
	glBegin(GL_POLYGON);
	glVertex2i(180, 180);
	glVertex2i(20, 180);
	glVertex2i(20, 220);
	glVertex2i(180, 220);
	glEnd();

	// Draw the middle rectangle
	glBegin(GL_POLYGON);
	// Set the colour to blue
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(180, 180);
	// Set the colour to red
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(180, 220);
	// Set the colour to green
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(220, 220);
	// Set the colour to black
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(220, 180);
	glEnd();

	// Set colour to black
	glColor3f(0.0, 0.0, 0.0);
	// Set line width
	glLineWidth(5.0);

	// Draw the outline around the shape
	glBegin(GL_LINE_LOOP);
	glVertex2i(180, 380);
	glVertex2i(220, 380);
	glVertex2i(220, 220);
	glVertex2i(380, 220);
	glVertex2i(380, 180);
	glVertex2i(220, 180);
	glVertex2i(220, 20);
	glVertex2i(180, 20);
	glVertex2i(180, 180);
	glVertex2i(20, 180);
	glVertex2i(20, 220);
	glVertex2i(180, 220);
	glEnd();

	// Set colour to green
	glColor3f(0.0, 1.0, 0.0);
	// Change point size
	glPointSize(10.0);

	// Draw the corner points
	glBegin(GL_POINTS);
	glVertex2i(180, 380);
	glVertex2i(220, 380);
	glVertex2i(220, 220);
	glVertex2i(380, 220);
	glVertex2i(380, 180);
	glVertex2i(220, 180);
	glVertex2i(220, 20);
	glVertex2i(180, 20);
	glVertex2i(180, 180);
	glVertex2i(20, 180);
	glVertex2i(20, 220);
	glVertex2i(180, 220);
	glEnd();
}

// The main display function
void displayFunc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

									// Reset the model view matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the world coordinate reference frame centre to the 
	// middle of the window, rotate, and move the referrence frame back
	glTranslatef(200, 200, 0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glTranslatef(-200, -200, 0);

	// Draw the cross shape
	drawCross();

	// We're using double buffering so now we've got to swap the buffers before flushing
	glutSwapBuffers();

	// Process all OpenGL routines
	glFlush();
}

// The idle callback function which simply incrementes the rotation angle every time it is called
void idleFunc() {
	// Increment the rotation angle
	angle += 0.2;
	if (angle > 360.0) {
		angle -= 360.0;
	}
	// Redraw the window
	glutPostRedisplay();
}

// The callback function handling mouse button presses - turn on and off animation when the left button is pressed
void mouseFunc(int btn, int state, int x, int y) {

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//mouse sað týk yapýnca ekran arka planý deðiþmektedir
		backgroundIndex++;
		if (backgroundIndex > 4) {
			backgroundIndex = 0;
		}

		// Change the background colour
		glClearColor(backgroundRed[backgroundIndex], backgroundGreen[backgroundIndex], backgroundBlue[backgroundIndex], 0.0);
		// Redraw the scene
		glutPostRedisplay();
	}
	else if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {//Mouse Sol týk Ve basýldýðýnda girilecek
		
		if (durum==true)//eðer basýlmýþ ise
		{
			glutIdleFunc(idleFunc);//döndürme
		}
		else
		{
			glutIdleFunc(0);//durdurma
		}
		durum=!durum;
		/*her  fonksiyona girildiðinde tersini alýyorum ki ç
		alýþýyosa durdurmak için ve duruyorsa çalýþtýrmak için*/
		
	}
}

// The callback function for when keys are pressed
void keyboardFunc(unsigned char key, int x, int y) {//tuþlar için geçerli fonksiyon

	switch (key) {
	case 'b'://b tuþuna basýldýðýnda ekran arka plan rengi deðiþecektir

		// Increment the background colour index - make sure it doesn't go over 3
		backgroundIndex++;
		if (backgroundIndex > 4) {
			backgroundIndex = 0;
		}

		// Change the background colour
		glClearColor(backgroundRed[backgroundIndex], backgroundGreen[backgroundIndex], backgroundBlue[backgroundIndex], 0.0);
		// Redraw the scene
		glutPostRedisplay();
		break;
	case'a'://zoom in yapmak için a tuþuna basarýz
		zoom+=20;//20 þer arttýr
		glViewport(0, 0, (400+zoom),(400+zoom));
		glutPostRedisplay();
		break;
	case'z'://zoom out yapmak için a tuþuna basarýz
		zoom-=20;//20 þer azalt 
		glViewport(0, 0, (400 + zoom), (400+zoom));
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);									// Initalise GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);			// Set display mode

	glutInitWindowPosition(50, 100);						// Set window position
	glutInitWindowSize(400, 400);							// Set window size
	glutCreateWindow("Soru3");	// Create display window

	init();							// Execute initialisation procedure
	glutDisplayFunc(displayFunc);	// Send graphics to display window

			// Set the idle behaviour to rotate the window

	glutMouseFunc(mouseFunc);		// Set the callback to handle mouse button presses

	glutKeyboardFunc(keyboardFunc);	// Set the callback function for key presses

	glutMainLoop();					// Display everything and wait

	return 0;
}
