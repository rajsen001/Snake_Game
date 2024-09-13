#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int c=0, i, j, m, n, key, size=100, p=0, dir=RIGHT, speed=300, step=10, d[10], a[10], b[10];
int px=0, py=0, l=615, ch, score=0;
char scostr[10];

void start(void);
void gameover(void);
void eat(void);
void bonus(void);
void death(void);
void turn(int, int);
void make(int, int, int, int);
void snake(int, int);
void game(void);
void cont();


void main()
{
int gd=DETECT, gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");

start();


getch();
cleardevice();
closegraph();
}

void cont()
{
  cleardevice();
  setcolor(15);
  rectangle(1,31,638,478);
  rectangle(4,34,635,475);
  rectangle(5,35,634,474);
  setcolor(RED);
  settextstyle(0,0,5);
  outtextxy(85,110,"Sorry we are");
  outtextxy(65,210,"not available");
  outtextxy(135,310,"right now");
  getch();
  start();
}

void start()
{
cleardevice();
 setcolor(15);
 rectangle(1,31,638,478);
 rectangle(4,34,635,475);
 rectangle(5,35,634,474);
 rectangle(95,70,550,164);
 rectangle(94,69,551,165);
 setfillstyle(SOLID_FILL,WHITE);
 floodfill(100,100,WHITE);
 setcolor(RED);
 settextstyle(4,0,6);
 outtextxy(130,80,"SNAKE  GAME");

 setcolor(WHITE);
 settextstyle(8,0,1);
 outtextxy(175,195,"1. START GAME");
 outtextxy(175,215,"2. CONTINUE (CURRENTLY NOT WORKING)");
 outtextxy(175,235,"3. EXIT");

 setcolor(CYAN);
 settextstyle(7,0,3);
 outtextxy(190,315,"CHOOSE AN OPTION");
 outtextxy(200,345,"& PRESS ENTER");

 setcolor(BROWN);
 settextstyle(0,0,3);
 outtextxy(80,410,"DESIGNED BY:- RAJ SEN");

 scanf("%d",&ch);
 switch(ch)
 {
      case 1:   game();
		break;
      case 2:   cont();
		break;
      case 3:   exit(0);
		break;
      default:  setcolor(RED);
		settextstyle(0,0,2);
		outtextxy(220,280,"WRONG CHOICE");
		delay(1000);
		start();
 }
}

void make(int x1, int y1, int s, int dirop)
{
switch(dirop)
{
 case RIGHT:  line(x1,y1,x1-s,y1);
	      break;
 case LEFT:   line(x1,y1,x1+s,y1);
	      break;
 case UP:     line(x1,y1,x1,y1+s);
	      break;
 case DOWN:   line(x1,y1,x1,y1-s);
	      break;
}
}

void snake(int x, int y)
{
int s=size;
if(p==0)
make(x,y,s,dir);
else
{
if((s<=abs(x-a[0])) || (s<=abs(y-b[0])))
 make(x,y,s,dir);

else
{
line(x,y,a[0],b[0]);
s=s-abs(x-a[0])-abs(y-b[0]);
i=0;
while((s>abs(a[i]-a[i+1])) && (s>abs(b[i]-b[i+1])) && (i<p))
{ line(a[i],b[i],a[i+1],b[i+1]);
  s=s-abs(a[i]-a[i+1])-abs(b[i]-b[i+1]);
  i++;
}
make(a[i],b[i],s,d[i]);
}
}
}


void death()
{
l-=25;
if(l>=565)     game();
gameover();
}

void turn(int x, int y)
{
 for(i=9;i>0;i--)
 { a[i]=a[i-1];
   b[i]=b[i-1];
 }
 a[i]=x;    b[i]=y;
 d[i]=dir;
 p++;
}

void eat()
{
 if(((m>=px-5)&&(m<=px+5))||((m>=px-5)&&(m<=px+5)))
{px=0;    py=200;
 setfillstyle(SOLID_FILL,WHITE);
 pieslice(px,py,0,360,5);
 size+=20;
 score+=50;
}
}

void bonus()
{
 srand(time(0));
px=20+(rand()%605);
py=70+(rand()%345);
}


void gameover()
{
 cleardevice();
 setcolor(15);
 rectangle(1,31,638,478);
 rectangle(4,34,635,475);
 rectangle(5,35,634,474);
  setcolor(RED);
  settextstyle(0,0,7);
  outtextxy(100,110,"Game Over");
  setcolor(BROWN);
  settextstyle(7,0,5);
  outtextxy(100,220,"Your Score: ");
  sprintf(scostr,"%d",score);
  outtextxy(400,220,scostr);

 setcolor(15);
 settextstyle(3,0,4);
 outtextxy(230,310,"1. Play Again");
 outtextxy(230,345,"2. Main Menu");

 scanf("%d",&ch);
 switch(ch)
 {
     case 1:    game();
		break;
     case 2:    start();
		break;
     default:   setcolor(4);
		settextstyle(0,0,3);
		outtextxy(185,400,"WRONG CHOICE");
		delay(1000);
		gameover();
 }
}


void game()
{
m=200;  n=200;  size=100;  dir=RIGHT;  speed=300; step=10;  p=0;
while(1)
{
while(!kbhit())
{
cleardevice();
setcolor(WHITE);
for(i=0,j=50;i<=10;i++,j++)
rectangle(i,j,639-i,479-j);
outtextxy(100,0,"Press 'Esc' to exit");
settextstyle(0,0,1);
sprintf(scostr,"%d",score);
outtextxy(5,30,"Score: ");
outtextxy(55,30,scostr);
outtextxy(500,30,"Lifes: ");
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL,LIGHTGREEN);
for(i=565;i<=l;i+=25)
sector(i,35,0,360,10,5);
eat();

 if((c%30==0))            bonus();
 if((m<11)||(m>629)||(n<61)||(n>419))   death();

setcolor(WHITE);
snake(m,n);
setcolor(RED);
setfillstyle(SOLID_FILL,RED);
pieslice(px,py,0,360,5);
switch(dir)
{
   case LEFT:   m-=step;
		break;
   case RIGHT:  m+=step;
		break;
   case UP:     n-=step;
		break;
   case DOWN:   n+=step;
		break;
}
delay(speed);
score+=step;
c++;
}

key=getch();
if(key==27)
{
 cleardevice();
 closegraph();
 exit(0);
}
if((key==UP)||(key==DOWN)||(key==LEFT)||(key==RIGHT))
{
 switch(dir)
 {
   case UP:
   case DOWN:   switch(key)
	      {
	       case LEFT:
	       case RIGHT:  turn(m,n);
			    dir=key;
	       }
	       break;

   case RIGHT:
   case LEFT:   switch(key)
	      {
	       case UP:
	       case DOWN:   turn(m,n);
			    dir=key;
	      }
	       break;
 }
}
}
}