

#include <stdlib.h>
#include <GL/glut.h> //OpenGL K�t�phanemiz

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// G�r�nt� penceresini beyaz yapt�k 

	glMatrixMode(GL_PROJECTION);		// gl_projection parametresini girdik
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

// �eklimiz �izdirmemiz i�in gereken fonksiyonumuz
void drawCross() {

	
	glColor3f(0.0, 0.0, 1.0);//mavi renk yap�yoruz

	glBegin(GL_TRIANGLES);//�st ��genimiz
	glVertex2i(60, 200);
	glVertex2i(200, 340);
	glVertex2i(340, 200);
	glEnd();

	glBegin(GL_TRIANGLES);//alt ��genimiz 
	glVertex2i(60, 200);
	glVertex2i(200, 60);
	glVertex2i(340, 200);
	glEnd();

	//�izgi i�in rengi siyah yap�yoruz
	glColor3f(0.0, 0.0, 0.0);
	//�izgi kal�nl��� 5 yapt�k
	glLineWidth(5.0);

	// �st ��gen �izgileri siyah yapt�k
	glBegin(GL_LINE_LOOP);
	glVertex2i(60, 200);
	glVertex2i(200, 340);
	glVertex2i(340, 200);
	glEnd();

	//Alt ��gen �izgileri siyah yapt�k 
	glBegin(GL_LINE_LOOP);
	glVertex2i(60, 200);
	glVertex2i(200, 60);
	glVertex2i(340, 200);
	glEnd();

	//rengi k�rm�z� set'ledik
	glColor3f(1.0, 0.0, 0.0);

	// sol �stteki kare i�in 
	glBegin(GL_POLYGON);
	glVertex2i(180, 380);
	glVertex2i(220, 380);
	glVertex2i(220, 220);
	glVertex2i(180, 220);
	glEnd();

	// sa� �stteki kare
	glBegin(GL_POLYGON);
	glVertex2i(220, 220);
	glVertex2i(380, 220);
	glVertex2i(380, 180);
	glVertex2i(220, 180);
	glEnd();

	// sa� alttaki kare
	glBegin(GL_POLYGON);
	glVertex2i(220, 180);
	glVertex2i(220, 20);
	glVertex2i(180, 20);
	glVertex2i(180, 180);
	glEnd();

	// sol alttaki kare
	glBegin(GL_POLYGON);
	glVertex2i(180, 180);
	glVertex2i(20, 180);
	glVertex2i(20, 220);
	glVertex2i(180, 220);
	glEnd();

	//Ortadaki kareye farkl� renkler veriyoruz
	glBegin(GL_POLYGON);
	// mavi rengi set edip konumunu belirliyoruz
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(180, 180);
	// k�rm�z� rengi set edip konumu beliriyoruz
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(180, 220);
	//ye�il rengi set edip konumu beliriyoruz
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(220, 220);
	// siyah rengi set edip konumu beliriyoruz
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(220, 180);
	glEnd();

	// siyah renk setleriz
	glColor3f(0.0, 0.0, 0.0);
	//�izgi kal�nl�n�� 5 
	glLineWidth(5.0);

	// dikd�rtgenlerin �izgilerinin  rengini siyah  ayarl�yoruz
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

	// ye�il renk setliyoruz
	glColor3f(0.0, 1.0, 0.0);
	// k��egenlerin nokta kal�nl���
	glPointSize(10.0);

	// K��egen noktalar� �izdiriyoruz
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

void displayFunc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// penceriyi temizle
						
	//matris modunu ayarlad�k
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//ilk �eklimizi  konumland�rd�k (sol �stteki �ekil)
	glRotated(45, 0, 0, 1.0);
	glTranslatef(380, 140, 0);
	drawCross();

	//ikinici �eklimizi x ekseninde 45 derece �evirip ta��d�k (sa� �stteki �ekil)
	glRotated(-45, 0, 0, 1.0);
	glTranslatef(220, 40, 0);
	drawCross();

	//���nc� �ekili 2. �ekli d�nd�rmeden sadece translate ettim(sol altaki �ekil)
	glTranslatef(-380, -350, 0);
	drawCross();

	//d�rd�nc� �ekil 1. �ekili  rotate'ni veririz ve translate yapar�z(sa� alttaki �ekil)
	glRotated(45, 0, 0, 1.0);
	glTranslatef(380, -500, 0);
	drawCross();
	
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);							// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	// Set display mode

	glutInitWindowPosition(100,80);			// pencerinin pozisyonu
	glutInitWindowSize(800, 600);			// pencere boyutu
	glutCreateWindow("SORU1");	// Pencere ismini verip pencereyi olu�turuz

	init();							
	glutDisplayFunc(displayFunc);	// �ekillerimizi �a��r�r�z
	glutMainLoop();					// d�ng�m�z 

	return 0;
}
