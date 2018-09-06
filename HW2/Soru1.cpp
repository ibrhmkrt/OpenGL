

#include <stdlib.h>
#include <GL/glut.h> //OpenGL Kütüphanemiz

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Görüntü penceresini beyaz yaptýk 

	glMatrixMode(GL_PROJECTION);		// gl_projection parametresini girdik
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

// Þeklimiz çizdirmemiz için gereken fonksiyonumuz
void drawCross() {

	
	glColor3f(0.0, 0.0, 1.0);//mavi renk yapýyoruz

	glBegin(GL_TRIANGLES);//üst üçgenimiz
	glVertex2i(60, 200);
	glVertex2i(200, 340);
	glVertex2i(340, 200);
	glEnd();

	glBegin(GL_TRIANGLES);//alt üçgenimiz 
	glVertex2i(60, 200);
	glVertex2i(200, 60);
	glVertex2i(340, 200);
	glEnd();

	//çizgi için rengi siyah yapýyoruz
	glColor3f(0.0, 0.0, 0.0);
	//çizgi kalýnlýðý 5 yaptýk
	glLineWidth(5.0);

	// üst üçgen çizgileri siyah yaptýk
	glBegin(GL_LINE_LOOP);
	glVertex2i(60, 200);
	glVertex2i(200, 340);
	glVertex2i(340, 200);
	glEnd();

	//Alt üçgen çizgileri siyah yaptýk 
	glBegin(GL_LINE_LOOP);
	glVertex2i(60, 200);
	glVertex2i(200, 60);
	glVertex2i(340, 200);
	glEnd();

	//rengi kýrmýzý set'ledik
	glColor3f(1.0, 0.0, 0.0);

	// sol üstteki kare için 
	glBegin(GL_POLYGON);
	glVertex2i(180, 380);
	glVertex2i(220, 380);
	glVertex2i(220, 220);
	glVertex2i(180, 220);
	glEnd();

	// sað üstteki kare
	glBegin(GL_POLYGON);
	glVertex2i(220, 220);
	glVertex2i(380, 220);
	glVertex2i(380, 180);
	glVertex2i(220, 180);
	glEnd();

	// sað alttaki kare
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

	//Ortadaki kareye farklý renkler veriyoruz
	glBegin(GL_POLYGON);
	// mavi rengi set edip konumunu belirliyoruz
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(180, 180);
	// kýrmýzý rengi set edip konumu beliriyoruz
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(180, 220);
	//yeþil rengi set edip konumu beliriyoruz
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(220, 220);
	// siyah rengi set edip konumu beliriyoruz
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(220, 180);
	glEnd();

	// siyah renk setleriz
	glColor3f(0.0, 0.0, 0.0);
	//çizgi kalýnlýnðý 5 
	glLineWidth(5.0);

	// dikdörtgenlerin çizgilerinin  rengini siyah  ayarlýyoruz
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

	// yeþil renk setliyoruz
	glColor3f(0.0, 1.0, 0.0);
	// köþegenlerin nokta kalýnlýðý
	glPointSize(10.0);

	// Köþegen noktalarý çizdiriyoruz
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
						
	//matris modunu ayarladýk
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//ilk þeklimizi  konumlandýrdýk (sol üstteki þekil)
	glRotated(45, 0, 0, 1.0);
	glTranslatef(380, 140, 0);
	drawCross();

	//ikinici þeklimizi x ekseninde 45 derece çevirip taþýdýk (sað üstteki þekil)
	glRotated(-45, 0, 0, 1.0);
	glTranslatef(220, 40, 0);
	drawCross();

	//üçüncü þekili 2. þekli döndürmeden sadece translate ettim(sol altaki þekil)
	glTranslatef(-380, -350, 0);
	drawCross();

	//dördüncü þekil 1. þekili  rotate'ni veririz ve translate yaparýz(sað alttaki þekil)
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
	glutCreateWindow("SORU1");	// Pencere ismini verip pencereyi oluþturuz

	init();							
	glutDisplayFunc(displayFunc);	// þekillerimizi çaðýrýrýz
	glutMainLoop();					// döngümüz 

	return 0;
}
