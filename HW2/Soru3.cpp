
#include <GL\glut.h>

GLsizei winWidth = 500, winHeight = 500;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void displayWirePolyhedra(void)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);//Fonsiyon ile bak�� a��m�zdan Zoom out  yapt�k

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 3.0, 1.0, 0.0);//Fonksiyon ile bak�� a��m�zdan zoom yapt�k

	// Clear the window
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw a wireframe cube
	glColor3f(1.0, 0.0, 0.0);	//rengi k�rm�z� yapt�m
	glScalef(1.5, 2.0, 1.0);
	glutWireTeapot(1.0); //Fonksiyonu ile �aydakl�k �izidiriyorum



	// Draw a wireframe dodecahedron
	glColor3f(0.0, 0.0, 1.0);	// rengi mavi yapt�m
	glScalef(0.8, 0.5, 0.8);
	glTranslatef(-6.0, -5.0, 0.0);
	glutWireCone(3.0,3.0,10,8);//fonksiyonu ile sa� a�a��daki huniyi �izdirdim



	// Draw a wireframe tetrahedron
	glColor3f(0.0, 1.0, 0.0);	// Set colour to green
	glTranslatef(8.6, 8.6, 2.0);
	glutWireTetrahedron();

	// Draw a wireframe octahedron
	glColor3f(0.0, 0.0, 0.0);	// Set colour to black
	glTranslatef(-3.0, -1.0, 0.0);
	glutWireOctahedron();

	// Draw a wireframe icosahedron
	glColor3f(0.7, 0.4, 0.5);	// Set colour to purple
	glScalef(0.8, 0.8, 1.0);
	glTranslatef(4.3, -2.0, 0.5);
	glutWireIcosahedron();


	glFlush();
}

// Resize the viewport when the window is resized
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);							// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// Set display mode

	glutInitWindowPosition(100, 100);				// Set window position
	glutInitWindowSize(winWidth, winHeight);		// Set window size
	glutCreateWindow("Soru3");		// Create display window

	init();

	glutDisplayFunc(displayWirePolyhedra);	// Set the display function
	glutReshapeFunc(winReshapeFcn);			// Set up the window reshape callback function

	glutMainLoop();

	return 0;
}

