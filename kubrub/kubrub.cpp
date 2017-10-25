

#include "stdafx.h"
#include "headfile.h"
#include <conio.h>
#include <stdio.h>



#include <stdlib.h>
#include "glut.h"
#pragma comment(lib, "glut32.lib")
int colhod = 0 ;

int error1 = 0;
int error2 = 0;
int error3 = 0;
int error4 = 0;
int error5 = 0;
int error6 = 0;
int dr = 0;//отключает печать maker
int dr2 = 0;//отключает анимацию
int t;
int YY = 0;
int kubrub[6][3][3]=
{
	6, 1, 4,
	2, 6, 2,
	2, 2, 2,

	3, 6, 5,
	3, 2, 2,
	1, 3, 3,

	4, 5, 1,
	5, 5, 5,
	2, 5, 3,

	4, 6, 1,
	4, 4, 6,
	5, 3, 6,

	6, 1, 1,
	4, 1, 1,
	2, 4, 6,

	3, 1, 5,
	6, 3, 4,
	4, 3, 5,




};


int draw()
{
	for (int g=0;g<6;g++)
	{
		for (int y=0;y<3;y++)
		{
			for (int x=0;x<3;x++)
			{
				cout<<kubrub[g][y][x]<<", ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
int rotate1(int c6,int n)
{int i=0;
while (i!=n)
{
	int c4=kubrub[c6][0][0];
	int c5=kubrub[c6][0][1];

	kubrub[c6][0][0]=kubrub[c6][2][0];
	kubrub[c6][2][0]=kubrub[c6][2][2];
	kubrub[c6][2][2]=kubrub[c6][0][2];
	kubrub[c6][0][2]=c4;

	kubrub[c6][0][1]=kubrub[c6][1][0];
	kubrub[c6][1][0]=kubrub[c6][2][1];
	kubrub[c6][2][1]=kubrub[c6][1][2];
	kubrub[c6][1][2]=c5;
	i++;
}
return 0;
}
int rotateR(int n)
{int i1=0;
//cout<<n;
while (i1!=n)
{
	int c1=kubrub[0][0][2];
	int c2=kubrub[0][1][2];
	int c3=kubrub[0][2][2];

	kubrub[0][0][2]=kubrub[5][0][2];
	kubrub[0][1][2]=kubrub[5][1][2];
	kubrub[0][2][2]=kubrub[5][2][2];

	kubrub[5][0][2]=kubrub[2][2][0];
	kubrub[5][1][2]=kubrub[2][1][0];
	kubrub[5][2][2]=kubrub[2][0][0];

	kubrub[2][0][0]=kubrub[4][2][2];
	kubrub[2][1][0]=kubrub[4][1][2];
	kubrub[2][2][0]=kubrub[4][0][2];

	kubrub[4][0][2]=c1;
	kubrub[4][1][2]=c2;
	kubrub[4][2][2]=c3;

	rotate1(1,1);


	i1++;
}
return 0;
}
int rotateU(int h)
{int i=0;

while (i!=h)
{


	int c1=kubrub[1][0][0];
	int c2=kubrub[1][0][1];
	int c3=kubrub[1][0][2];

	kubrub[1][0][0]=kubrub[2][0][0];
	kubrub[1][0][1]=kubrub[2][0][1];
	kubrub[1][0][2]=kubrub[2][0][2];

	kubrub[2][0][0]=kubrub[3][0][0];
	kubrub[2][0][1]=kubrub[3][0][1];
	kubrub[2][0][2]=kubrub[3][0][2];

	kubrub[3][0][0]=kubrub[0][0][0];
	kubrub[3][0][1]=kubrub[0][0][1];
	kubrub[3][0][2]=kubrub[0][0][2];

	kubrub[0][0][0]=c1;
	kubrub[0][0][1]=c2;
	kubrub[0][0][2]=c3;

	rotate1(4,1);
	i++;
}
return 0;

}


int rotateAllZ(int n)
{
	int bufer1ij;//временный массив

	int x3=0;
	while (x3!=n)
	{
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				bufer1ij=kubrub[4][i][j];
				kubrub[4][i][j]=kubrub[3][i][j];
				kubrub[3][i][j]=kubrub[5][i][j];
				kubrub[5][i][j]=kubrub[1][i][j];
				kubrub[1][i][j]=bufer1ij;


			}
		}
		rotate1(1,1);
		rotate1(4,1);
		rotate1(3,1);
		rotate1(5,1);
		rotate1(0,1);
		rotate1(2,3);
		x3++;
	}

	return 0;
}

int rotateAllY(int n)
{
	int bufer1ij;//временный массив
	int z=0;
	int i=0;
	int j=0;
	while (z!=n)
	{
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				bufer1ij=kubrub[0][i][j];
				kubrub[0][i][j]=kubrub[1][i][j];
				kubrub[1][i][j]=kubrub[2][i][j];
				kubrub[2][i][j]=kubrub[3][i][j];
				kubrub[3][i][j]=bufer1ij;

			}
		}

		rotate1(4,1);
		rotate1(5,3);
		z++;
	}

	return 0;
}
int rotateAllX(int n)
{
	int bufer1ij;//временный массив
	int x1=0;
	while (x1!=n)
	{
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				bufer1ij=kubrub[0][i][j];
				kubrub[0][i][j]=kubrub[5][i][j];
				kubrub[5][i][j]=kubrub[2][i][j];
				kubrub[2][i][j]=kubrub[4][i][j];
				kubrub[4][i][j]=bufer1ij;

			}
		}
		rotate1(5,2);
		rotate1(2,2);
		rotate1(1,1);
		rotate1(3,3);
		x1++;
	}

	return 0;
}


int maker(const char *form)
{
	const char *ca, *cb;
	ca = form;

	int rep = 0;
	int rev = 0;

	while (ca && *ca)
	{
		rep = 1;
		rev = 0;

		cb = strpbrk(ca, "RULFBDXYZrluM");
		if (cb == 0)
			break;

		ca = cb;
		rep = 1;
		if (cb > form && cb[-1] == '2' || cb[-1] == '3')
			rep = cb[-1] - '0';
		if (cb[1] == '.')
		{
			rev = 1;
			rep = 4 - rep;
			ca++;
		}
		if (dr == 0)
		{
			if (rep==1)
			{	
				cout<<*cb<<" ";
			}
			else if (rep==2)
			{	
				cout<<rep<<*cb<<" ";
			}
			else if (rep==3) 
			{	
				cout<<*cb<<".";
			}
		}



		switch(*cb)
		{
		case 'R':
			if (dr2 != 137)     Rotatecub(rep, 'R');
			rotateR(rep);	// R, 2R, 3R, R., 2R., 3R.

			break;
		case 'r':
			if (dr2 != 137)     Rotatecub(rep, 'r');
			rotateAllZ(2);
			rotateR(rep);
			rotateAllZ(2);
			rotateAllX(rep);
			break;
		case 'U':
			if (dr2 != 137)     Rotatecub(rep, 'U');
			rotateU(rep);	// U, 2U, 3U, U., 2U., 3U.
			break;
		case 'u':
			if (dr2 != 137)     Rotatecub(rep, 'u');
			rotateAllZ(3);
			rotateR(rep);
			rotateAllZ(1);
			rotateAllY(rep);

			break;
		case 'X':
			if (dr2 != 137)     Rotatecub(rep, 'X');
			rotateAllX(rep);	// X, 2X, 3X, X., 2X., 3X.
			break;
		case 'Y':
			if (dr2 != 137)     Rotatecub(rep, 'Y');
			rotateAllY(rep);	// Y, 2Y, 3Y, Y., 2Y., 3Y.
			break;
		case 'Z':
			if (dr2 != 137)     Rotatecub(rep, 'Z');
			rotateAllZ(rep);	// Z, 2Z, 3Z, Z., 2Z., 3Z.

			break;
		case 'L':
			if (dr2 != 137)     Rotatecub(rep, 'L');
			rotateAllZ(2);
			rotateR(rep);
			rotateAllZ(2);
			break;
		case 'l':
			if (dr2 != 137)     Rotatecub(rep, 'l');
			rotateR(rep);
			rotateAllX(rep^((rep&1)<<1));
			break;
		case 'F':
			if (dr2 != 137)     Rotatecub(rep, 'F');
			rotateAllY(3);
			rotateR(rep);
			rotateAllY(1);
			break;
		case 'B':
			if (dr2 != 137)     Rotatecub(rep, 'B');
			rotateAllY(1);
			rotateR(rep);
			rotateAllY(3);
			break;
		case 'D':
			if (dr2 != 137)     Rotatecub(rep, 'D');
			rotateAllZ(3);
			rotateR(rep);
			rotateAllZ(1);
			break;
		case 'M':
			if (dr2 != 137)     Rotatecub(rep, 'M');
			rotateR(rep);
			rotateAllZ(2);
			rotateR(rep^((rep&1)<<1));
			rotateAllZ(2);
			rotateAllX(rep^((rep&1)<<1));
			break;


		}
		if (dr == 0)
			colhod++;
		++ca;
	}

	//cout<<endl;
	return 0;
}




int centr(void)//функция поиска центра, проверка кубика
{	
	int green = 0;
	int red = 0;
	int blue = 0;
	int orange = 0;
	int white = 0;
	int yellow = 0;


	for (int n=0;n<6;n++)
	{
		for (int y=0;y<3;y++)
		{
			for (int x=0;x<3;x++)
			{
				if (kubrub[n][y][x] == 1)
					green++;
				else if (kubrub[n][y][x] == 2)
					red++;
				else if (kubrub[n][y][x] == 3)
					blue++;
				else if (kubrub[n][y][x] == 4)
					orange++;
				else if (kubrub[n][y][x] == 5)
					white++;
				else if (kubrub[n][y][x] == 6)
					yellow++;
			}
		}		
	}

	cout<<endl<<endl<<"green = "<<green<<"; red = "<<red<<"; blue = "<<blue<<"; orange = "<<orange<<"; white = "<<white<<"; yellow = "<<yellow<<";"<<endl<<endl; 

	if (green != 9 || red != 9 || blue != 9 || orange != 9 || white != 9 || yellow != 9)
	{
		cout<<"ERROR, colors are incorrect"<<endl;
		sleep(3000);
		exit(1);
	}


	if (kubrub[0][1][1]==5)
		maker("X");
	else if (kubrub[1][1][1]==5)
		maker("Z.");
	else if (kubrub[2][1][1]==5)
		maker("X.");
	else if (kubrub[3][1][1]==5)
		maker("Z");
	else if (kubrub[5][1][1]==5)
		maker("2Z");
	return 0;
}
int krest10(int a)
{	
	if (kubrub[0][0][1]==kubrub[3][1][1])
	{
		maker("U");
		if (a==2)
			maker("Y.");
	}
	else if (kubrub[0][0][1]==kubrub[1][1][1])
	{
		maker("U.");
		if (a==2)
			maker("Y");
	}
	else if (kubrub[0][0][1]==kubrub[2][1][1])
	{
		maker("2U");
		if (a==2)
			maker("2Y");
	}	
	return 0;
}


int krest33()
{
	if(kubrub[1][1][1]==kubrub[5][0][1])
		maker("F.RF");
	else if(kubrub[3][1][1]==kubrub[5][0][1])
		maker("FL.F.");
	else if (kubrub[2][1][1]==kubrub[5][0][1])
		maker("DR.BR");
	else if (kubrub[0][1][1]==kubrub[5][0][1])
		maker("DRF.R.");
	return 0;
}
int krest2()
{
	if(kubrub[1][1][1]==kubrub[4][2][1])
		maker("FRF.");
	else if(kubrub[3][1][1]==kubrub[4][2][1])
		maker("F.L.F");
	else if (kubrub[2][1][1]==kubrub[4][2][1])
	{
		maker("2FDR.BR");}
	else if (kubrub[0][1][1]==kubrub[4][2][1])
		maker("2FDRF.R.");
	return 0;
}
int krest4()
{
	if (kubrub[0][2][1]==kubrub[3][1][1])//слева
	{
		maker("D.2L");
	}
	else if (kubrub[0][2][1]==kubrub[1][1][1])//справа
	{
		maker("D2R");
	}	
	else if (kubrub[0][2][1]==kubrub[2][1][1])//cзади
	{
		maker("2D2B");
	}
	else if (kubrub[0][2][1]==kubrub[0][1][1])//спереди
	{
		maker("2F");
	}
	return 0;
}
int krest2par()
{
	if ((kubrub[0][1][1]==kubrub[0][1][2])&&(kubrub[1][1][0]==5))
		maker("F.");
	if ((kubrub[0][1][1]==kubrub[0][1][0])&&(kubrub[3][1][2]==5))
		maker("F");
	return 0;
}

int skan0()//вызывается ровно 1 раз
{
	int b=0;
	for (int i=0;i<4;i++)
	{
		if (kubrub[4][2][1]==5&&kubrub[0][0][1]!=kubrub[0][1][1]&&b<1)//верхний ближний к нам белый. и не совп. по цвету  с центром нижней гранью
		{
			krest10(1);
			b=1;
			continue;
		}
		maker("Y");
	}
	return 0;
}

int skan1()//собираем крест
{
	centr();
	skan0();
	for (int k=0;k<4;k++)
	{
		if (kubrub[4][0][1]!=5||kubrub[4][1][0]!=5||kubrub[4][1][2]!=5||kubrub[4][2][1]!=5)
		{



			for (int i=0;i<4;)
			{	
				//проверка остальных белых на шапке
				if (kubrub[4][2][1]==5&&kubrub[0][0][1]!=kubrub[0][1][1])
				{
					maker("2F");
					krest4();
					continue;
				}
				//проверка пар
				if ((kubrub[0][1][1]==kubrub[0][1][2])&&(kubrub[1][1][0]==5))
				{
					maker("F.");
					continue;
				}
				else if ((kubrub[0][1][1]==kubrub[0][1][0])&&(kubrub[3][1][2]==5))
				{
					maker("F");
					continue;
				}
				//низ
				else if (kubrub[5][0][1]==5)
				{
					krest4();
					continue;
				}

				//средний пояс
				else if (kubrub[0][1][0]==5)
				{
					maker("F.DFD.");
					krest33();
					continue;
				}
				else if (kubrub[0][1][2]==5)
				{
					maker("FDF.D.");
					krest33();
					continue;
				}

				//верхний пояс
				else if (kubrub[0][0][1]==5)
				{
					krest2();//функция установки белого с верхнего пояса на место
					continue;
				}

				//нижний пояс
				else if (kubrub[0][2][1]==5)
				{
					krest33();
					continue;
				}



				maker("Y");
				i++;
			}

		}//закрыли условие проверки
	}//закрыли цикл проверки (4 раза проверяется)

	int a9=kubrub[4][0][1];
	int b9=kubrub[4][1][0];
	int c9=kubrub[4][1][2];
	int d9=kubrub[4][2][1];

	if (a9!=5||b9!=5||c9!=5||d9!=5)
	{
		cout<<"error 1"<<endl;
		error1++;
	}
	return 0;
}


int angle3a()
{
	for (int y=0;y<4;y++)
	{
		if (kubrub[3][2][2] == kubrub[y][1][1])
		{
			if (y==0)
			{			
				maker("2DFD.F.");
				return 0;
			}
			else if (y==1)
			{			
				maker("R2DR.");
				return 0;
			}	
			else if (y==2)
			{			
				maker("BD.B.");
				return 0;
			}		
			else if (y==3)
			{		
				maker("DLD.L.");
				return 0;
			}
		}
	}

	cout<<"ERROR in 3a"<<endl;
	return 0;
}
int angle3b()
{
	for (int y=0;y<4;y++)
	{
		if (kubrub[1][2][0] == kubrub[y][1][1])
		{
			if (y==0)
			{
				maker("DF.2DF");
				return 0;
			}
			else if (y==1)
			{	
				maker("D.R.DR");
				return 0;
			}
			else if (y==2)
			{
				maker("B.DB");
				return 0;		
			}
			else if (y==3)
			{
				maker("L.2DL");
				return 0;
			}
		}
	}
	cout<<"ERROR in 3b"<<endl;
	return 0;
}
int angle4b()
{
	for (int ii=0;ii<4;ii++)
	{
		if (kubrub[0][2][2] == kubrub[ii][1][1])
		{
			if (ii==0)
			{				
				maker("D.F.DFYY");
				angle3a();
				return 0;
			}
			else if (ii==1)
			{
				maker("R.2DR");
				angle3a();
				return 0;
			}
			else if (ii==2)
			{
				maker("DRD.R.Y.");
				angle3b();
				return 0;
			}
			else if (ii==3)
			{
				maker("2DL.DLY");
				angle3a();
				return 0;
			}


		}
	}
	cout<<"ERROR in 4b"<<endl;
	return 0;
}



int skan2()//угловые белые кубики
{
	for (int h=0;h<4;h++)
	{
		if (kubrub[4][0][0]!=5||kubrub[4][0][2]!=5||kubrub[4][2][0]!=5||kubrub[4][2][2]!=5)
		{

			for (int i=0;i<4;i++)
			{		
				if (kubrub[0][2][0] == 5)//3a
				{	cout<<endl<<"   "<<"3a"<<endl;
				angle3a();
				continue;
				}
				if (kubrub[0][2][2] == 5)//3b
				{cout<<endl<<"   "<<"3b"<<endl;
				angle3b();
				continue;
				}
				if (kubrub[5][0][2]==5)//4b
				{cout<<endl<<"   "<<"4b"<<endl;
				angle4b();
				continue;
				}		
				if(kubrub[4][2][0]== 5 && kubrub[0][0][0] != kubrub[0][1][1])//1a
				{	cout<<endl<<"   "<<"1a"<<endl;
				maker("LDL.Y");
				angle3a();;
				continue;		
				}

				if (kubrub[0][0][0]==5)//2a
				{cout<<endl<<"   "<<"2a"<<endl;
				maker("F.D.FY.");
				angle3a();
				continue;
				}
				if (kubrub[0][0][2]==5)//2b
				{cout<<endl<<"   "<<"2b"<<endl;
				maker("FDF.Y");
				angle3b();
				continue;
				}
				maker("Y");
			}//закрали цикл
		}//закрыли условие проверки
	}//закрыли цикл проверки (4 раза проверяется)

	return 0;
}
int bok1()
{
	for (int t=0;t<4;t++)//если боковой кубик есть на верхнем поясе
	{
		if (kubrub[0][0][1]!=6 && kubrub[4][2][1]!=6)
		{	
			krest10(2);

			cout<<endl<<"bok 1";


			if (kubrub[4][2][1]==kubrub[3][1][1])
			{
				cout<<"a"<<endl;
				maker("U.L.ULUFU.F.");
				return 0;
			}	
			else if (kubrub[4][2][1]==kubrub[1][1][1])	
			{	
				cout<<"b"<<endl;	
				maker("URU.R.U.F.UF");
				return 0;
			}
		}

		maker("Y");	

	}
	return 0;
}
int bok2()
{
	for (int rr=0;rr<4;rr++)//выбивание нужного кубика из среднего пояса
	{
		if ((kubrub[0][1][0]!=6&&kubrub[3][1][2]!=6)&&(kubrub[0][1][0]!=kubrub[0][1][1]))
		{	cout<<endl<<"bok 2a"<<endl;
		maker("U.L.ULUFU.F.");
		bok1();
		return 0;

		}
		else if ((kubrub[0][1][2]!=6&&kubrub[1][1][0]!=6)&&(kubrub[0][1][2]!=kubrub[0][1][1]))
		{	cout<<endl<<"bok 2b"<<endl;
		maker("URU.R.U.F.UF");
		bok1();
		return 0;	
		}
		maker("Y");
	}
	return 0;
}
int skan3()//средний пояс
{
	int b = 0;
	int kh = 0;
	for (int i = 0; i<5; i++)
	{
		if (kubrub[0][1][0]!=kubrub[0][1][1] || kubrub[0][1][2]!=kubrub[0][1][1])
		{	

			bok1();
			bok2();

			i = 0;
			continue;
		}
		maker("Y");

	}	

	if (kubrub[0][1][0]!=kubrub[0][1][1] || kubrub[0][1][2]!=kubrub[0][1][1])
	{
		cout<<"error3 "<<endl;
		error3++;
	}
	return 0;
}
int skan4()//собираем крест
{

	for (int o=0;o<4;o++)
	{	
		int a=kubrub[4][0][1];
		int b=kubrub[4][1][0];
		int c=kubrub[4][1][2];
		int d=kubrub[4][2][1];

		if (a==6&&b==6&&c==6&&d==6)//если крест уже готов
		{
			return 0;
		}
		else if (a==6&&b==6)//если галка
		{	
			maker("FURU.R.F.");
			if (kubrub[4][0][1]!=6 || kubrub[4][1][0]!=6 || kubrub[4][1][2]!=6 || kubrub[4][2][1]!=6)
			{
				cout << "error 4"<<endl;
				error4++;
			}

			return 0;
		}

		else if (b==6&&c==6)//если минус
		{
			maker("FRUR.U.F.");
			if (kubrub[4][0][1]!=6 || kubrub[4][1][0]!=6 || kubrub[4][1][2]!=6 || kubrub[4][2][1]!=6)
			{
				cout << "error 4"<<endl;
				error4++;
			}
			return 0;
		}
		else if (o!=3)//барьер
		{		
			maker("Y");
			continue;
		}
		{
			cout<<"bli n"<<endl;
			maker("FURU.R.F.");//если ни галка и не минус
			o=0;
			continue;
		}	
	}


	cout << "error 4"<<endl;
	error4++;
	return 0;
}
int skan5()//собираем весь слой
{
	for (int i=0;i<4;i++)
	{


		if (kubrub[4][2][0] == 6 && kubrub[0][0][2] == 6  &&  kubrub[4][0][2]!=6  &&  kubrub[4][2][2]!=6  &&  kubrub[4][0][0]!=6)//RFISH
		{cout<<"rfish"<<endl;
		maker("RUR.UR2UR.");
		return 0;
		}
		else if (kubrub[4][2][2] == 6 && kubrub[0][0][0] == 6 && kubrub[4][0][0]!=6  &&  kubrub[4][2][0]!=6  &&  kubrub[4][0][2]!=6)//LFISH
		{cout<<"lfish"<<endl;
		maker("L.U.LU.L.2UL");
		return 0;
		}
		else if (kubrub[4][0][0] == 6 && kubrub[4][2][2] == 6 && kubrub[0][0][0] == 6 && kubrub[4][0][2] != 6 && kubrub[4][2][0] != 6)//EIGHT
		{cout<<"eight"<<endl;
		maker("RUR.UR2UR. Y. L.U.LU.L.2UL");
		return 0;
		}
		else if (kubrub[3][0][2] == 6 && kubrub[1][0][2] == 6 && kubrub[4][0][0] != 6 && kubrub[4][0][2] != 6 && kubrub[4][2][0] != 6 && kubrub[4][2][2] != 6)//CROSS1
		{cout<<"cross"<<endl;
		maker("RUR.UR2UR.RUR.UR2UR.");
		return 0;
		}
		else if (kubrub[3][0][2] == 6 && kubrub[0][0][2] == 6 && kubrub[4][0][0] != 6 && kubrub[4][0][2] != 6 && kubrub[4][2][0] != 6 && kubrub[4][2][2] != 6)//CROSS2
		{cout<<"cross with yey"<<endl;
		maker("RUR.UR2UR.Y.RUR.UR2UR.");
		return 0;
		}
		else if (kubrub[4][0][0] == 6 && kubrub[4][0][2] == 6 && kubrub[0][0][0] == 6 && kubrub[0][0][2] == 6 && kubrub[4][2][0] != 6 && kubrub[4][2][2] != 6)//ROBYEYS
		{cout<<"robyeys"<<endl;
		maker("RUR.UR2UR.2YL.U.LU.L.2UL");
		return 0;
		}
		else if (kubrub[4][0][2] == 6 && kubrub[4][2][2] == 6 && kubrub[0][0][0] == 6 && kubrub[4][0][0] != 6 &&  kubrub[4][2][0] != 6)//ROBEARS
		{cout<<"robears"<<endl;
		maker("RUR.UR2UR.L.U.LU.L.2UL");
		return 0;
		}
		maker("Y");
		cout<<endl<<endl;
	}		
	return 0;
}
int sovp(int EE[12])
{int nn=0;
for (int i=0; i<12; i++)
{
	if (EE[i]==9)
		nn++;
}
return nn;
}

int skan6()//финальный шаг. Собираем последний пояс
{
	for (int rotate=0; rotate<4; rotate++)
	{
		for (int povorot=0;povorot<4;povorot++)
		{

			int E[12];

			int F = kubrub[0][1][1];//объявляем и присваим переменным цвета 4х граней всего кубикарубика
			int R = kubrub[1][1][1];
			int B = kubrub[2][1][1];
			int L = kubrub[3][1][1];

			int i=0; int r=0;

			for (int e=0; e<12; e++)//создаем массив цветов граней 8ми кубиков, получаем 12 цветов для 12 граней
			{
				E[e]=kubrub[r][0][i];
				if (i<2)
					i++;
				else 
				{
					i=0;
					r++;
				}
			}
			int u = 0;//если кубик стоит на своем месте, в массив E[ii] ставим 9, если не на своем то в массив E[ii] ставим цвет соответствующей грани кубика
			int St = kubrub[u][1][1];
			for (int ii=0;ii<12;ii++)
			{	
				if (E[ii]==St)
				{			
					E[ii]=9;
				}
				if ((ii+1)%3==0)
				{
					St=kubrub[(ii+1)/3][1][1];
				}
			}


			int rr = sovp(E);


			if (rr==9 && E[4]==F && E[1]==L && E[10]==R)//1 малый треугольник по часовой
			{
				cout<<endl<<"1 малый треугольник по часовой"<<endl;
				maker("(2R U) (R U R. U.) (R. U.) (R. U R.)");
				return 0;
			}
			else if (rr==9 && E[4]==L && E[1]==R && E[10]==F)//2 малый треугольник против часовой
			{
				cout<<endl<<"2 малый треугольник против часовой"<<endl;
				maker("(R U. R U) (R U) (R U.) (R. U. 2R)");
				return 0;
			}
			else if (rr==8 && E[1]==R && E[4]==F && E[10]==B && E[7]==L)//3 середины по диогонали
			{
				cout<<endl<<"3 середины по диогонали"<<endl;
				maker("R B. R. B F R. B. F R. B R 2F U");
				return 0;
			}
			else if (rr==8 && E[1]==B && E[7]==F && E[4]==L && E[10]==R)//4 крест сторон
			{
				cout<<endl<<"4 крест сторон"<<endl;
				maker("(2M. U) (2M. 2U) (2M. U) 2M.");
				return 0;
			}
			else if (rr==6 && E[2]==B && E[8]==R && E[6]==R)//5 большой треугольник по часовой
			{
				cout<<endl<<"5 большой треугольник по часовой"<<endl;
				maker("(l. U R.) 2D (R U. R.) 2D 2R");
				return 0;
			}
			else if (rr==6 && E[6]==L && E[8]==L && E[0]==B)//6 большой треугольник против часовой (тругольник отзеркаливается)
			{
				cout<<endl<<"6 большой треугольник против часовой (тругольник отзеркаливается)"<<endl;
				maker("(r U. L) 2D (L. U L) 2D 2L");
				return 0;
			}
			else if (rr==4 && E[0]==L && E[8]==L && E[6]==R && E[2]==R)//7 шпалы, формула Леонида
			{
				cout<<endl<<"7 терминатор (шпалы), формула Леонида"<<endl;
				maker("(L l U R. D) (R U.) (R. r. F) (r Z. R. u. F.)");
				return 0;
			}
			else if (rr==6 && E[1]==R && E[4]==F && E[6]==R && E[2]==R)//8 лямбда правая
			{
				cout<<endl<<"8 лямбда правая"<<endl;
				maker("(R 2U R. U. R 2U) (L. U R. U. L)");
				return 0;
			}
			else if (rr==6 && E[1]==L && E[10]==F && E[0]==L && E[8]==L)//9 лямбда левая
			{
				cout<<endl<<"9 лямбда левая"<<endl;
				maker("	(L. 2U L U L. 2U) (R U. L U R.)");
				return 0;
			}
			else if (rr==6 && E[10]==R && E[4]==L && E[6]==R && E[2]==R)//10 буква Т
			{
				cout<<endl<<"10 буква Т"<<endl;
				maker("(R U R. U.) (R. F) (2R U.) (R. U. R U) (R. F.)");
				return 0;
			}
			else if (rr==6 && E[9]==B && E[5]==B && E[1]==R && E[4]==F)//11 семёрка правая
			{
				cout<<endl<<"11 семёрка правая"<<endl;
				maker("(R. 2U) (R 2U) (R. F R U R. U.) (R. F. 2R U.)");
				return 0;
			}
			else if (rr==6 && E[9]==B && E[5]==B && E[1]==L && E[10]==F)//12 семерка левая
			{
				cout<<endl<<"12 семерка левая"<<endl;
				maker("(L 2U) (L. 2U) (L F. L. U. L U) (L F 2L U)");
				return 0;
			}
			else if (rr==6 && E[9]==B && E[5]==B &&  E[4]==L && E[10]==R)//13 паралельный перенос сверху
			{
				cout<<endl<<"13 паралельный перенос сверху"<<endl;
				maker("(R. U R U. 2R) (F. U. F U) (R F R. F. 2R U.)");
				return 0;
			}
			else if (rr==3 && E[0]==R && E[2]==B && E[9]==F && E[10]==R && E[4]==F && E[1]==L)//восьмерка 14
			{
				cout<<endl<<"восьмерка 14"<<endl;
				maker("(2R u. R U.) (R U R. u 2R) Y (R U. R.)");
				return 0;
			}
			else if (rr==3 && E[0]==L && E[9]==B && E[6]==F && E[10]==R && E[4]==B && E[7]==L)//восьмерка 15
			{
				cout<<endl<<"восьмерка 15"<<endl;
				maker("(2R u) (R. U R. U. R u.) 2R Y. (R. U R)");
				return 0;
			}
			else if (rr==3 && E[0]==R && E[3]==L && E[9]==F && E[1]==L && E[10]==B && E[7]==F)//восьмерка 16
			{
				cout<<endl<<"восьмерка 16"<<endl;
				maker("(R. U. R) Y (2R u R. U) (R U. R u. 2R)");
				return 0;
			}
			else if (rr==3 && E[0]==L && E[9]==B && E[6]==F && E[1]==B && E[7]==L && E[10]==F)//восьмерка 17
			{
				cout<<endl<<"восьмерка 17"<<endl;
				maker("(R U R.) Y. (2R u. R U.) (R. U R. u 2R)");
				return 0;
			}
			else if (rr==6 && E[0]==B && E[6]==F && E[1]==R && E[4]==F)//летающая тарелка
			{
				cout<<endl<<"18 летающая тарелка"<<endl;
				maker("L. U R U. L U L. U R. U. L 2U R 2U R.");
				return 0;
			}
			else if (rr==6 && E[0]==B && E[6]==F && E[10]==R && E[4]==L)//буква X правая
			{
				cout<<endl<<"19 буква X правая"<<endl;
				maker("L U. R 2U L. U L R. U. R 2U L. U R. U.");
				return 0;
			}
			else if (rr==6 && E[2]==B && E[8]==F && E[10]==R && E[4]==L)//буква Х левая
			{
				cout<<endl<<"20 буква Х левая"<<endl;
				maker("Z U. R D. 2R U R. D U. R D. 2R U R. D R");
				return 0;
			}
			else if (rr==6 && E[2]==B && E[8]==F && E[10]==B && E[7]==L)//копье
			{
				cout<<endl<<"21 копье"<<endl;
				maker("(F R U.) (R. U. R U) (R. F.) (R U R. U.) (R. F R F.)");
				return 0;
			}

			else if (rr==12)
			{
				return 0;
			}

			maker("Y");

		}
		maker("U");
	}
	cout << "error6 "<<endl;
	error6++;
	return 0;


}
void options()
{
	setlocale(LC_ALL, "Russian");
	cout<<endl<<"назначте цвета\n"<<" W вращение кубика вверх \n S -//- вниз \n A -//- влево \n D -//- вправо \n a движение рамки влево \n";
	cout<<" d -//- вправо \n s -//- вниз \n w -//- вверх \n k и l выбор цвета \n 1 размешать \n 2 собрать \n 7 показать текущее расположение чисел в массиве \n";
	cout<<" p повернуть куб в исходной положение\n 9 вызов справки";

	cout<<"\n\nвведите время в миллисекундах одного оборота ";
	cin>>t;

}



void main(int argc, char **argv) {

	//char form[700];



	options();
	glutInit(&argc, argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(620,620);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glDepthFunc(GL_LESS);

	glutCreateWindow("3D Example");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(renderScene);


	glutKeyboardFunc(kir);
	glutMouseFunc(mse);
	glutMotionFunc(msa);
	glutMainLoop();	

	getch();




}