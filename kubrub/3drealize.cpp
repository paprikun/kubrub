#include "stdafx.h"
#include <stdlib.h>
#include "glut.h"
#include "headfile.h"
#include<stdio.h>
#include <conio.h>


#pragma comment(lib, "glut32.lib")
//float dx=30,dy=-30,dz=0;
float dx=0,dy=0,dz=0;

float lx=0,ly=0,lz=0;
int ax=0, ay=0;
int xn=0;
int k=1;


float dx1=0;
float dy1=0;
float dz1=0;

float dyD=0;
float dyU=0;
float dyu=0;
float dzF=0;
float dzB=0;
float dxR=0; 
float dxr=0; 
float dxL=0;
float dxl=0;
float dxM=0;

#include <time.h>

int glex=0;




void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}


float a=0.105;//половина длины грани малого кубика
float b=a*1.1;//половина длины грани рамки
float v=2*a+0.02;//сдвиг, второе слагаемое -0 расстояние между кубиками
//float b=0.01;
//float cc=0.01;



void set_color(int cvet)
{

	float r1;
	float g1;
	float b1;

	if (cvet==1)
	{
		r1=0.0;
		g1=0.8;
		b1=0.0;
	}
	if (cvet==2)
	{
		r1=1.0;
		g1=0.0;
		b1=0.0;
	}
	if (cvet==3)
	{
		r1=0.0;
		g1=0.0;
		b1=1.0;
	}
	if (cvet==4)
	{
		r1=1.0;
		g1=0.65;
		b1=0.0;
	}
	if (cvet==5)
	{
		r1=1.0;
		g1=1.0;
		b1=1.0;
	}
	if (cvet==6)
	{
		r1=1.0;
		g1=1.0;
		b1=0.0;
	}
	if (cvet==7)
	{
		r1=0.8;
		g1=0.8;
		b1=0.8;
	}
	glColor3f(r1,g1,b1);

}

void kub(int cvet0, int cvet1, int cvet2, int cvet3, int cvet4, int cvet5)
{
	glBegin(GL_QUADS);//1
	set_color(cvet2);
	glVertex3f(-a,a,-a);
	glVertex3f(a,a,-a);
	glVertex3f(a,-a,-a);
	glVertex3f(-a,-a,-a);
	glEnd();

	glBegin(GL_QUADS);//2
	set_color(cvet3);
	glVertex3f(-a,a,-a);
	glVertex3f(-a,-a,-a);
	glVertex3f(-a,-a,a);
	glVertex3f(-a,a,a);
	glEnd();

	glBegin(GL_QUADS);//3
	set_color(cvet5);
	glVertex3f(-a,-a,-a);
	glVertex3f(a,-a,-a);
	glVertex3f(a,-a,a);
	glVertex3f(-a,-a,a);
	glEnd();

	glBegin(GL_QUADS);//4
	set_color(cvet1);
	glVertex3f(a,a,-a);
	glVertex3f(a,-a,-a);
	glVertex3f(a,-a,a);
	glVertex3f(a,a,a);
	glEnd();

	glBegin(GL_QUADS);//5
	set_color(cvet0);
	glVertex3f(-a,a,a);
	glVertex3f(a,a,a);
	glVertex3f(a,-a,a);
	glVertex3f(-a,-a,a);
	glEnd();

	glBegin(GL_QUADS);//6
	set_color(cvet4);
	glVertex3f(-a,a,-a);
	glVertex3f(a,a,-a);
	glVertex3f(a,a,a);
	glVertex3f(-a,a,a);
	glEnd();


}




//void rotate(int N, int H)
//{
//if (dxR!=0 && H == 1)
//	{
//	glTranslatef(0,v,v*N);
//	glRotatef(dxR*k*N,1,0,0);
//	glTranslatef(0,-v,-v*N);
//	}
//else if(dxR!=0 && H == 2)
//	{
//	glTranslatef(0,0,v*N);
//	glRotatef(dxR*k*N,1,0,0);
//	glTranslatef(0,0,-v*N);
//	}
//else if(dxR!=0 && H == 3)
//	{
//	glTranslatef(0,-v,v*N);
//	glRotatef(dxR*k*N,1,0,0);
//	glTranslatef(0,v,-v*N);
//	}
//else if (dxL!=0 && H == 1)
//	{
//	glTranslatef(0,v,v*N);
//	glRotatef(dxL*k*N,1,0,0);
//	glTranslatef(0,-v,-v*N);
//	}
//else if (dxL!=0 && H == 2)
//	{
//	glTranslatef(0,0,v*N);
//	glRotatef(dxL*k*N,1,0,0);
//	glTranslatef(0,0,-v*N);
//	}
//else if (dxL!=0 && H == 3)
//	{
//	glTranslatef(0,-v,v*N);
//	glRotatef(dxL*k*N,1,0,0);
//	glTranslatef(0,v,-v*N);
//}
//
//else if(dx1!=0||dy1!=0||dz1!=0)
//	{
//	glRotatef(dx1*k,1,0,0);
//	glRotatef(dy1*k,0,1,0);
//	glRotatef(dz1*k,0,0,1);
//	}
//else if (dy2!=0)
//	{
//	glTranslatef(-v,0,-v);	
//	glRotatef(dy2*k,0,1,0);
//	glTranslatef(v,0,v);
//	}
//else if (dy3!=0)
//	{
//	glTranslatef(-v,0,-v);
//	glRotatef(dy3*k,0,1,0);
//	glTranslatef(v,0,v);
//	}
//
//}
void rotateFF(int i, int aa[28])
{
	if (i==0)
	{glRotatef(dzF*k,0,0,1);
	for (int y = 1; y<28; y++)//рисуем перед
	{
		if (y%3==0)
		{		

			aa[y] = 1;
		}
	}
	}
	else if (i==1)
	{glRotatef(-dzF*k,0,0,1);
	for (int z = 1; z<28; z++)//стираем перед
	{
		if (z%3==0)
		{		
			aa[z] = 0;
		}
	}
	for (int r = 1; r<28; r++)//рисуем середину
	{
		if ((r+1)%3==0)
		{
			aa[r] = 1;
		}
	}
	for (int g = 1; g<28; g++)//рисуем тыл
	{
		if ((g+2)%3==0)
		{
			aa[g] = 1;
		}
	}
	}
}

void rotateBB(int i, int aa[28])
{
	if (i==0)
	{glRotatef(-dzB*k,0,0,1);
	for (int y = 1; y<28; y++)//рисуем тыл
	{
		if ((y+2)%3==0)
		{		

			aa[y] = 1;
		}
	}
	}
	else if (i==1)
	{glRotatef(+dzB*k,0,0,1);
	for (int z = 1; z<28; z++)//стираем тыл
	{
		if ((z+2)%3==0)
		{		
			aa[z] = 0;
		}
	}
	for (int r = 1; r<28; r++)//рисуем середину
	{
		if ((r+1)%3==0)
		{
			aa[r] = 1;
		}
	}
	for (int g = 1; g<28; g++)//рисуем перед
	{
		if (g%3==0)
		{
			aa[g] = 1;
		}
	}
	}
}

void rotateRR(int i, int aa[28])
{
	if (i==0)


	{
		glRotatef(dxR*k,1,0,0);
		for (int y = 7; y<28; y++)//рисуем правую сторону
		{
			if (y == 10)
				y+=6;
			else if (y == 19)
				y+=6;
			aa[y] = 1;
		}
	}
	else if (i==1)
	{glRotatef(-dxR*k,1,0,0);
	for (int z = 7; z<28; z++)//стираем правую
	{
		if (z == 10)
			z+=6;
		else if (z == 19)
			z+=6;
		aa[z] = 0;
	}
	for (int r = 4; r<25; r++)//рисуем середину
	{
		if (r == 7)
			r+=6;
		else if (r == 16)
			r+=6;
		aa[r] = 1;
	}
	for (int g = 1; g<22; g++)//рисуем левую сторону
	{
		if (g == 4)
			g+=6;
		else if (g == 13)
			g+=6;
		aa[g] = 1;
	}
	}
}

void rotateMM(int i, int aa[28])
{
	if (i==0)


	{
		glRotatef(dxM*k,1,0,0);
		for (int r = 4; r<25; r++)//рисуем середину
		{
			if (r == 7)
				r+=6;
			else if (r == 16)
				r+=6;
			aa[r] = 1;
		}
	}
	else if (i==1)
	{glRotatef(-dxM*k,1,0,0);
	for (int r = 4; r<25; r++)//стираем середину
	{
		if (r == 7)
			r+=6;
		else if (r == 16)
			r+=6;
		aa[r] = 0;
	}
	for (int g = 1; g<22; g++)//рисуем левую сторону
	{
		if (g == 4)
			g+=6;
		else if (g == 13)
			g+=6;
		aa[g] = 1;
	}
	for (int y = 7; y<28; y++)//рисуем правую сторону
	{
		if (y == 10)
			y+=6;
		else if (y == 19)
			y+=6;
		aa[y] = 1;
	}
	}
}

void rotaterr(int i, int aa[28])
{
	if (i==0)
	{
		glRotatef(dxr*k,1,0,0);
		for (int y = 4; y<28; y++)//рисуем правую сторону
		{
			if (y == 10)
				y+=3;
			else if (y == 19)
				y+=3;
			aa[y] = 1;
		}

	}
	else if (i==1)
	{glRotatef(-dxr*k,1,0,0);
	for (int y = 4; y<28; y++)//рисуем правую сторону
	{
		if (y == 10)
			y+=3;
		else if (y == 19)
			y+=3;
		aa[y] = 0;
	}

	for (int g = 1; g<22; g++)//рисуем левую сторону
	{
		if (g == 4)
			g+=6;
		else if (g == 13)
			g+=6;
		aa[g] = 1;
	}
	}
}

void rotateLL(int i, int aa[28])
{
	if (i==0)
	{glRotatef(dxL*k,1,0,0);
	for (int g = 1; g<22; g++)//рисуем левую
	{
		if (g == 4)
			g+=6;
		else if (g == 13)
			g+=6;
		aa[g] = 1;
	}
	}
	else if (i==1)
	{glRotatef(-dxL*k,1,0,0);
	for (int g = 1; g<22; g++)//стираем левую
	{
		if (g == 4)
			g+=6;
		else if (g == 13)
			g+=6;
		aa[g] = 0;
	}
	for (int r = 4; r<25; r++)//рисуем середину
	{
		if (r == 7)
			r+=6;
		else if (r == 16)
			r+=6;
		aa[r] = 1;
	}
	for (int y = 7; y<28; y++)//рисуем правую сторону
	{
		if (y == 10)
			y+=6;
		else if (y == 19)
			y+=6;
		aa[y] = 1;
	}
	}
}
void rotatell(int i, int aa[28])
{
	if (i==0)
	{glRotatef(dxl*k,1,0,0);
	for (int g = 1; g<25; g++)//рисуем всю левую
	{
		if (g == 7)
			g+=3;
		else if (g == 16)
			g+=3;
		aa[g] = 1;
	}
	}
	else if (i==1)
	{glRotatef(-dxl*k,1,0,0);
	for (int g = 1; g<25; g++)//рисуем всю левую
	{
		if (g == 7)
			g+=3;
		else if (g == 16)
			g+=3;
		aa[g] = 0;
	}
	for (int y = 7; y<28; y++)//рисуем правую сторону
	{
		if (y == 10)
			y+=6;
		else if (y == 19)
			y+=6;
		aa[y] = 1;
	}
	}
}
void rotateUU(int i, int aa[28],int p)//p предел
{
	if (i==0)
	{
		if (dyU!=0)
			glRotatef(dyU*k,0,1,0);
		else if (dyu!=0)
			glRotatef(dyu*k,0,1,0);

		for (int g = p-9; g<28; g++)//рисуем верх, p = 28 верхний слой, p = 19 верхний слой и срдений пояс
		{
			aa[g]=1;
		}
	}
	else if (i==1)
	{

		if (dyU!=0)
			glRotatef(-dyU*k,0,1,0);
		else if (dyu!=0)
			glRotatef(-dyu*k,0,1,0);

		for (int g = p-9; g<28; g++)//стираем верх
		{
			aa[g]=0;
		}
		for (int r = 1; r<(p-9); r++)//рисуем оставшуюся часть
		{
			aa[r] = 1;
		}
	}
}
void rotateDD(int i, int aa[28])
{
	if (i==0)
	{glRotatef(dyD*k,0,1,0);
	for (int g = 1; g<10; g++)//рисуем низ
	{
		aa[g]=1;
	}
	}
	else if (i==1)
	{glRotatef(-dyD*k,0,1,0);
	for (int g = 1; g<10; g++)//стираем низ
	{
		aa[g]=0;
	}
	for (int r = 10; r<28; r++)//рисуем средний пояс и верх
	{
		aa[r] = 1;
	}
	}
}

void ramka()
{

	glTranslatef(-v,v,v);

	glTranslatef(lx,ly,lz);

	glBegin(GL_LINE_LOOP);
	glColor3f(0,0.7,1);
	glVertex3f(-b,b,b);
	glVertex3f(b,b,b);
	glVertex3f(b,-b,b);
	glVertex3f(-b,-b,b);
	glVertex3f(-b,-b,-b);
	glVertex3f(b,-b,-b);
	glVertex3f(b,b,-b);
	glVertex3f(-b,b,-b);
	glEnd();


	glBegin(GL_LINES);

	glColor3f(0,0.7,1);
	glVertex3f(-b,-b,b);
	glVertex3f(-b,b,b);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0,0.7,1);
	glVertex3f(-b,-b,-b);
	glVertex3f(-b,b,-b);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0,0.7,1);
	glVertex3f(b,b,-b);
	glVertex3f(b,b,b);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0,0.7,1);
	glVertex3f(b,-b,-b);
	glVertex3f(b,-b,b);
	glEnd();
}
void kubrub2()
{
	float r=0.8;
	float g=0.8;
	float b=0.8;

	int aa [28]= 
	{9, /*правая*/
	0,0,0, 
	0,0,0, //перед низ
	0,0,0,	

	0,0,0, 
	/*тыл*/	0,0,0, //перед 
	0,0,0,	

	0,0,0, 
	0,0,0, //перед верх
	0,0,0,};
	/*левая*/

	for (int i = 0; i<2; i++)
	{
		if (dzF==0 && dzB==0 && dxR==0 && dxr==0 && dxL==0 && dxl==0 && dyU==0 && dyD==0 && dyu==0 && dxM==0)
		{

			if (dx1!=0)
				glRotatef(dx1*k,1, 0, 0);
			else if (dy1!=0)
				glRotatef(dy1*k,0, 1, 0);
			else if (dz1!=0)
				glRotatef(dz1*k,0, 0, 1);

			i=2;
			for (int r = 0; r<28; r++)
			{
				aa[r]=1;
			}	


		}



		else if (dzF!=0)
			rotateFF(i, aa);
		else	if (dzB!=0)
			rotateBB(i, aa);
		else if (dxR!=0)
			rotateRR(i, aa);
		else if (dxr!=0)
			rotaterr(i, aa);
		else if (dxL!=0)
			rotateLL(i, aa);
		else	if (dxl!=0)
			rotatell(i, aa);
		else	if (dyU!=0)
			rotateUU(i, aa, 28);
		else	if (dyu!=0)
			rotateUU(i, aa, 19);
		else	if (dyD!=0)
			rotateDD(i, aa);
		else if (dxM!=0)
			rotateMM(i, aa);




		glTranslatef(-v,-v,-v);


		if (aa[1] == 1)   kub(7,7,kubrub[2][2][2],kubrub[3][2][0],7,kubrub[5][2][0]);//1
		glTranslatef(0,0,v);
		if (aa[2] == 1)   kub(7,7,7,kubrub[3][2][1],7,kubrub[5][1][0]);//2
		glTranslatef(0,0,v);
		if (aa[3] == 1)   kub(kubrub[0][2][0],7,7,kubrub[3][2][2],7,kubrub[5][0][0]);//3
		glTranslatef(v,0,-2*v);
		if (aa[4] == 1)   kub(7,7,kubrub[2][2][1],7,7,kubrub[5][2][1]);//4
		glTranslatef(0,0,v);
		if (aa[5] == 1)   kub(7,7,7,7,7,kubrub[5][1][1]);//5
		glTranslatef(0,0,v);
		if (aa[6] == 1)   kub(kubrub[0][2][1],7,7,7,7,kubrub[5][0][1]);//6
		glTranslatef(v,0,-2*v);
		if (aa[7] == 1)   kub(7,kubrub[1][2][2],kubrub[2][2][0],7,7,kubrub[5][2][2]);//7
		glTranslatef(0,0,v);
		if (aa[8] == 1)   kub(7,kubrub[1][2][1],7,7,7,kubrub[5][1][2]);//8
		glTranslatef(0,0,v);
		if (aa[9] == 1)   kub(kubrub[0][2][2],kubrub[1][2][0],7,7,7,kubrub[5][0][2]);//9



		glTranslatef(-2*v,v,-2*v);


		if (aa[10] == 1)   kub(7,7,kubrub[2][1][2],kubrub[3][1][0],7,7);//10
		glTranslatef(0,0,v);
		if (aa[11] == 1)   kub(7,7,7,kubrub[3][1][1],7,7);//11
		glTranslatef(0,0,v);
		if (aa[12] == 1)   kub(kubrub[0][1][0],7,7,kubrub[3][1][2],7,7);//12
		glTranslatef(v,0,-2*v);
		if (aa[13] == 1)   kub(7,7,kubrub[2][1][1],7,7,7);//13
		glTranslatef(0,0,2*v);
		if (aa[15] == 1)   kub(kubrub[0][1][1],7,7,7,7,7);//15
		glTranslatef(v,0,-2*v);
		if (aa[16] == 1)   kub(7,kubrub[1][1][2],kubrub[2][1][0],7,7,7);//16
		glTranslatef(0,0,v);
		if (aa[17] == 1)   kub(7,kubrub[1][1][1],7,7,7,7);//17
		glTranslatef(0,0,v);
		if (aa[18] == 1)   kub(kubrub[0][1][2],kubrub[1][1][0],7,7,7,7);//18


		glTranslatef(-2*v,v,-2*v);

		if (aa[19] == 1)   kub(7,7,kubrub[2][0][2],kubrub[3][0][0],kubrub[4][0][0],7);//19
		glTranslatef(0,0,v);
		if (aa[20] == 1)   kub(7,7,7,kubrub[3][0][1],kubrub[4][1][0],7);//20
		glTranslatef(0,0,v);
		if (aa[21] == 1)   kub(kubrub[0][0][0],7,7,kubrub[3][0][2],kubrub[4][2][0],7);//21
		glTranslatef(v,0,-2*v);
		if (aa[22] == 1)   kub(7,7,kubrub[2][0][1],7,kubrub[4][0][1],7);//22
		glTranslatef(0,0,v);
		if (aa[23] == 1)   kub(7,7,7,7,kubrub[4][1][1],7);//23
		glTranslatef(0,0,v);
		if (aa[24] == 1)   kub(kubrub[0][0][1],7,7,7,kubrub[4][2][1],7);//24
		glTranslatef(v,0,-2*v);
		if (aa[25] == 1)   kub(7,kubrub[1][0][2],kubrub[2][0][0],7,kubrub[4][0][2],7);//25
		glTranslatef(0,0,v);
		if (aa[26] == 1)   kub(7,kubrub[1][0][1],7,7,kubrub[4][1][2],7);//26
		glTranslatef(0,0,v);
		if (aa[27] == 1)   kub(kubrub[0][0][2],kubrub[1][0][0],7,7,kubrub[4][2][2],7);//27


		glTranslatef(-v,-v,-v);
	}



}

void renderScene(void) {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glViewport(0, 0, 720, 720);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(45, 1, 1, 100);
	glTranslatef(0,0,-2);
	glRotatef(dx,1,0,0);
	glRotatef(dy,0,1,0);
	glRotatef(dz,0,0,1);

	glColor3f(0.8,0.8,0.8);


	kubrub2();
	if (glex == 0)
		ramka();

	sleep(t/18);//именно здесь должна быть эта функция и нигде иначе
	glutSwapBuffers();


}

void Rotatecub(int repp, unsigned char n)
{	


	if (repp==3)
	{
		k=-1;	
		repp=1;
	}
	switch (n)
	{
	case 'U':
		for (int i =0;i<18*repp-1;i++)
		{
			dyU-=5;
			renderScene();
		}
		dyU+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;
	case 'u':
		for (int i =0;i<18*repp-1;i++)
		{
			dyu-=5;
			renderScene();
		}
		dyu+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;

	case 'D':
		for (int i =0;i<18*repp-1;i++)
		{
			dyD+=5;
			renderScene();
		}
		dyD-=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;


	case 'X':
		for (int i =0;i<18*repp-1;i++)
		{
			dx1-=5;
			renderScene();
		}
		dx1+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;

	case 'Y':
		for (int i =0;i<18*repp-1;i++)
		{
			dy1-=5;
			renderScene();
		}
		dy1+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;

	case 'Z':
		for (int i =0;i<18*repp-1;i++)
		{
			dz1-=5;
			renderScene();
		}

		dz1+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;

	case 'R':
		for (int i =0;i<18*repp-1;i++)
		{
			dxR-=5;
			renderScene();
		}

		dxR+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;

	case 'r':
		for (int i =0;i<18*repp-1;i++)
		{
			dxr-=5;
			renderScene();
		}

		dxr+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;


	case 'L':
		for (int i =0;i<18*repp-1;i++)
		{
			dxL+=5;
			renderScene();
		}

		dxL-=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;
	case 'l':
		for (int i =0;i<18*repp-1;i++)
		{
			dxl+=5;
			renderScene();
		}

		dxl-=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;

	case 'F':
		for (int i =0;i<18*repp-1;i++)
		{
			dzF-=5;
			renderScene();
		}

		dzF+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;	
	case 'B':
		for (int i =0;i<18*repp-1;i++)
		{
			dzB-=5;
			renderScene();
		}

		dzB+=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;

	case 'M':
		for (int i =0;i<18*repp-1;i++)
		{
			dxM+=5;
			renderScene();
		}

		dxM-=repp*90-5;
		//sleep(t/18);
		glutPostRedisplay();
		break;
	}
	k=1;
}

void kir(unsigned char key,int,int)
{

	if (key=='p')
	{
		dx=0,dy=0,dz=0;
	}
	else if (key=='7')
	{
		cout<<endl<<endl;
		cout<<"save      "<<endl<<endl;
		draw();
		cout<<endl<<endl;
	}
	else if (key=='9')
	{
		options();
	}
	else if (key=='1')
	{
		int rtt;
		rtt = t;
		glex=1;
		t = 180;
		for (int t=0;t<21;t++)
		{
			int ar = rand()%10;
			if (ar==1)
				maker("F");
			else if (ar==2)
				maker("R");
			else if (ar==3)
				maker("L");
			else if (ar==4)
				maker("U");
			else if (ar==5)
				maker("D");
			else if (ar==6)
				maker("B");
			else if (ar==7)
				maker("X");
			else if (ar==8)
				maker("Y");
			else if (ar==9)
				maker("Z");
		}
		cout<<endl<<endl;
		draw();
		cout<<endl<<endl;
		t = rtt;
		glex=0;
	}
	else if (key=='2')
	{	int w;
	glex=1;
	colhod=0;
	skan1();
	setlocale(LC_ALL, "Russian");
	cout<<endl<<endl<<"крест собран"<<endl<<endl;

	skan2();
	if (error2+error1<1)
		cout<<endl<<endl<<"первый слой собран"<<endl<<endl;
	maker("2Z");
	skan3();
	if (error3<1)
		cout<<endl<<endl<<"средний слой собран"<<endl<<endl;
	skan4();
	if (error4<1)
		cout<<endl<<"верхний крест собран"<<endl<<endl;
	cout<<endl;
	skan5();	
	for (int d=0;d<3;d++)
	{	for (int dd=0;dd<3;dd++)
	{
		if (kubrub[4][d][dd]!=6)
		{
			dd=5;
			d=5;
			error5++;
			cout << "error5" << endl;
		}
	}
	}
	if (error5<1)
		cout<<endl<<"собрана верхняя грань"<<endl<<endl;
	skan6();
	if (error1+error2+error3+error4+error5+error6<1)
		cout<<endl<<"кубик собран"<<endl<<endl;
	draw();
	glex=0;


	if (error1 !=0 || error2 !=0 || error3 !=0 || error4 !=0 || error5 !=0 || error6 !=0 )
	{
		cout<<endl<<"ошибок при сборке белого креста   "<<error1<<endl<<"ошибок при сборке угловых кубиков   "<<error2<<endl<<"ошибок при сборке среднего слоя   "<<error3;
		cout<<endl<<"ошибок при сборке желтого креста   "<<error4<<endl<<"ошибок при сборке желтой шапки   "<<error5<<endl<<"ошибок при сборке последнего слоя   "<<error6<<endl;
	}

	cout<<"число ходов = "<<colhod<<endl<<"число ошибок = "<<error1+error2+error3+error4+error5+error6<<endl<<endl<<endl;
	}

	else if (key=='3')//режим самоотладки
	{
		setlocale(LC_ALL, "Russian");
		cout<<"введите колличство переборок\n";
		int yu;

		cin>>yu;

		int _error=0;
		dr = 137;
		dr2 = 137;
		t = 1;
		glex=1;
		for (int i = 0;i<yu;i++)
		{
			for (int t=0;t<21;t++)
			{
				int ar = rand()%10;
				if (ar==1)
					maker("F");
				else if (ar==2)
					maker("R");
				else if (ar==3)
					maker("L");
				else if (ar==4)
					maker("U");
				else if (ar==5)
					maker("D");
				else if (ar==6)
					maker("B");
				else if (ar==7)
					maker("X");
				else if (ar==8)
					maker("Y");
				else if (ar==9)
					maker("Z");
			}
			cout<<endl;


			skan1();
			skan2();
			maker("2Z");
			skan3();
			skan4();
			skan5();
			skan6();


		}
		glex=0;
		t = 180;
		dr = 0;
		dr2 = 0;
		for (int n=0; n<6; n++)
		{			k = kubrub[n][0][0];
		if (kubrub[n][0][1] != k || kubrub[n][0][2] != k || kubrub[n][1][0] != k || kubrub[n][1][1] != k || kubrub[n][1][2] != k || kubrub[n][2][0] != k || kubrub[n][2][1] != k || kubrub[n][2][2] != k)
			_error++;
		}



		setlocale(LC_ALL, "Russian");
		cout<<endl<<"число сборок = "<<yu<<" число ошибок = "<<_error<<endl;
		if (error1 !=0 || error2 !=0 || error3 !=0 || error4 !=0 || error5 !=0 || error6 !=0 )
		{
			cout<<endl<<"ошибок при сборке белого креста   "<<error1<<endl<<"ошибок при сборке угловых кубиков   "<<error2<<endl<<"ошибок при сборке среднего слоя   "<<error3;
			cout<<endl<<"ошибок при сборке желтого креста   "<<error4<<endl<<"ошибок при сборке желтой шапки   "<<error5<<"ошибок при сборке последнего слоя   "<<error6<<endl;
		}


	}

	//для рамки
	else if (key=='w') // вверх
	{

		if (ay!=0)
		{
			ly+=v;
			ay++;
		}


	}
	else if (key=='s')// вниз
	{
		if(ay!=-2)
		{
			ly-=v;
			ay--;
		}
	}
	else if (key=='d')// >
	{
		if (ax!=2)
		{
			lx+=v;
			ax++;
		}
	}
	else if (key=='a')// <
	{
		if (ax!=0)
		{
			lx-=v;
			ax--;
		}
	}
	else if (key=='k')// < по цвету
	{
		if(kubrub[0][-ay][ax]>1)
			kubrub[0][-ay][ax]--;
		else
			kubrub[0][-ay][ax] = 6;
	}
	else if (key=='l')// > по цвету
	{

		if(kubrub[0][-ay][ax]<6)
			kubrub[0][-ay][ax]++;
		else
			kubrub[0][-ay][ax] = 1;
	}
	else if (key=='W')//весь куб вверх
	{
		dr = 1;
		maker("X");
		dr = 0;
	}	
	else if (key=='S')//весь куб вниз
	{
		dr = 1;
		maker("X.");
		dr = 0;
	}
	else if (key=='D')//весь куб >
	{
		dr = 1;
		maker("Y.");
		dr = 0;
	}
	else if (key=='A')//весь куб <
	{
		dr = 1;
		maker("Y");
		dr = 0;
	}
	else if (key=='6')//
	{
		maker("BD");
	}
	glutPostRedisplay();
}


void msa(int x, int y)
{

	static int mx = -2040, my = 260;
	float ay = (mx - x), ax = (my - y);
	mx = x;
	my = y;

	float delim = 0.3f;
	ax *= delim;
	ay *= delim;

	dx -= ax;
	dy -= ay;
	glutPostRedisplay();
}


void mse(int button, int state, int x, int y)
{
	msa(x, y);
}



