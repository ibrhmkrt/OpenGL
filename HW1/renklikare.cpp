
#include <GL\glut.h> //GL kütüphanemiz
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);// Pencerenin arkaplan rengini beyaz yaptýk
	glMatrixMode(GL_PROJECTION);//Görüntüleme Modunun parametresini verdik 
	gluOrtho2D(20.0, 20.0, 20.0, 20.0); //2 boyutlu görüþ pencersinin büyüklüðünü belirler
}
void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);//Tamponlarýn içeriðini temizledik parametre olarak bufferbit verdik
	glColor3f(0.0, 0.0, 1.0);//Çizginin rengini MAVÝ yapar
	glLineWidth(3.0);//Çizgi kalýnlýðýný 3 yaptýk               
	glBegin(GL_LINES);//Çizeceðimiz þekili Çizgi olarak belirttik
	glVertex2f(-0.7, 0.7);//1.Nokta
	glVertex2f(0.7, 0.7);//2. Nokta 1-2 noktalarý çizgi oluþturur
	glColor3f(0.0, 1.0, 0.0);//karenin sað tarafýna yeþil renk verdik
	glVertex2f(0.7, 0.7);//3.Nokta
	glVertex2f(0.7, -0.7);//4. Nokta 3-4 noktalarý çizgi oluþturur
	glColor3f(1.0, 0.0, 0.0);//karenin alt tarafýna kýrmýzý renk verdik
	glVertex2f(0.7, -0.7);//5.Nokta
	glVertex2f(-0.7, -0.7);//6. Nokta 5-6 noktalarý çizgi oluþturur
	glColor3f(0.0, 0.0, 0.0);//karenin sol tarafýna siyah renk verdik
	glVertex2f(-0.7, -0.7);//7.Nokta
	glVertex2f(-0.7, 0.7);//8. Nokta 7-8 noktalarý çizgi oluþturur
	glEnd();//yapýlacaklarý bitti
	glFlush();	//Tampon temizlenir
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);// GLUT Baþlattýk
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// Görüntüleme Modu tek ve RGB renk
	glutInitWindowPosition(100, 100);// Pencerenin sol üst köþeye göre pozisyonu
	glutInitWindowSize(300, 300);// Pencere boyutu ayarladýk
	glutCreateWindow("soru3");	// Pencerenin ismini yazdýk ve pencere oluþturduk
	init();//init fonksiyonu çaðrýldý
	glutDisplayFunc(lineSegment);// lineSegment'in içinde yaptýklarýmýz ekrana çizildi
	glutMainLoop();	//main foksiyonu döngüye girdi
	return 0;
}


