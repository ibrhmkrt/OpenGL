
#include <GL\glut.h> //GL k�t�phanemiz
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);// Pencerenin arkaplan rengini beyaz yapt�k
	glMatrixMode(GL_PROJECTION);//G�r�nt�leme Modunun parametresini verdik 
	gluOrtho2D(20.0, 20.0, 20.0, 20.0); //2 boyutlu g�r�� pencersinin b�y�kl���n� belirler
}
void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//Tamponlar�n i�eri�ini temizledik parametre olarak bufferbit verdik
	glColor3f(0.0, 0.0, 1.0);//�izginin rengini MAV� yapar
	glLineWidth(3.0);//�izgi kal�nl���n� 3 yapt�k               
	glBegin(GL_LINES);//�izece�imiz �ekili �izgi olarak belirttik
	glVertex2f(-0.7, 0.7);//1.Nokta
	glVertex2f(0.7, 0.7);//2. Nokta 1-2 noktalar� �izgi olu�turur
	glColor3f(0.0, 1.0, 0.0);//karenin sa� taraf�na ye�il renk verdik
	glVertex2f(0.7, 0.7);//3.Nokta
	glVertex2f(0.7, -0.7);//4. Nokta 3-4 noktalar� �izgi olu�turur
	glColor3f(1.0, 0.0, 0.0);//karenin alt taraf�na k�rm�z� renk verdik
	glVertex2f(0.7, -0.7);//5.Nokta
	glVertex2f(-0.7, -0.7);//6. Nokta 5-6 noktalar� �izgi olu�turur
	glColor3f(0.0, 0.0, 0.0);//karenin sol taraf�na siyah renk verdik
	glVertex2f(-0.7, -0.7);//7.Nokta
	glVertex2f(-0.7, 0.7);//8. Nokta 7-8 noktalar� �izgi olu�turur
	glEnd();//yap�lacaklar� bitti
	glFlush();	//Tampon temizlenir
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);// GLUT Ba�latt�k
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// G�r�nt�leme Modu tek ve RGB renk
	glutInitWindowPosition(100, 100);// Pencerenin sol �st k��eye g�re pozisyonu
	glutInitWindowSize(300, 300);// Pencere boyutu ayarlad�k
	glutCreateWindow("soru3");	// Pencerenin ismini yazd�k ve pencere olu�turduk
	init();//init fonksiyonu �a�r�ld�
	glutDisplayFunc(lineSegment);// lineSegment'in i�inde yapt�klar�m�z ekrana �izildi
	glutMainLoop();	//main foksiyonu d�ng�ye girdi
	return 0;
}


