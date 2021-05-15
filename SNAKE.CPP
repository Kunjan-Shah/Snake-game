#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>

struct food{
	int p,q,score;
}f;

  int len=1,l,j;
  char str[16];
void food();
void snake();

void menu(){
     int c;
     cout<<"\t\t\t\tMAIN MENU";
     cout<<"\nEnter level: "<<"\n1.Easy\n2.Medium\n3.Hard\n4.Exit";
     cout<<"\nEnter your choice: ";
     cin>>c;
     switch(c)
     { case 1:l=225;
              break;
       case 2:l=125;
              break;
       case 3:l=75;
              break;
       case 4:exit(0);
              break;
       default:getch();
               break;
     }
   }

void boundary()
{     char ch1=186,ch2=205;
      for(int k=0;k<80;k++)
       { gotoxy(k+1,1);
         cout<<ch2;
         gotoxy(k+1,24);
         cout<<ch2;
       }
      for(k=0;k<23;k++)
      { gotoxy(1,k+1);
        cout<<ch1;
        gotoxy(80,k+1);
        cout<<ch1;
      }
}

void food(){
	f.p=random(74)+2;
	f.q=random(19)+2;
	f.score+=100;
        if(len==16)
         {clrscr();
          cout<<"You completed the game";
          cout<<"\nYour score is: "<<f.score;
          getch();
          exit(0);}
}

void result(){
   clrscr();
   cout<<"Your score is: "<<f.score;
   getch();
   exit(0);
  }

void gameover(int x,int y)
{ if(x<2 || x>80 || y<2 || y>24)
   { clrscr();
     cout<<"\t\t\t\tGAME OVER";
     delay(2000);
     result();
   }
}

void up(int x,int y,int len)
  { boundary();
     gotoxy(x,y);
     cout<<"@";
    for(j=0;j<len-1;j++)
     { str[j]=254;
       gotoxy(x,y+1+j);
       cout<<str[j];
     }
  }

void down(int x,int y,int len)
  { boundary();
    gotoxy(x,y);
    cout<<"@";
    for(j=0;j<len-1;j++)
     { str[j]=254;
       gotoxy(x,y-1-j);
       cout<<str[j];
     }
  }

void left(int x,int y,int len)
  { boundary();
    gotoxy(x,y);
    cout<<"@";
    for(j=0;j<len-1;j++)
     { str[j]=254;
       gotoxy(x-1-j,y);
       cout<<str[j];
     }
  }

void right(int x,int y,int len)
  { boundary();
    gotoxy(x,y);
    cout<<"@";
    for(j=0;j<len-1;j++)
     { str[j]=254;
       gotoxy(x+1+j,y);
       cout<<str[j];
     }
  }

void snake(){
        int g,r=2,c=2;
while(g=getch())
{ switch(g)
  { case 100: for(int i=r;!kbhit();i++)
	      { clrscr();
                left(i,c,len);
		gotoxy(f.p,f.q);
		cout<<"*";
                gameover(i,c);
		if(i==f.p && c==f.q)
		       { len++;
                         l-=2;
                         food();}
		delay(l);
              }
	      r=i;
              break;
     case 97: for(i=r;!kbhit();i--)
	      { clrscr();
                right(i,c,len);
		gotoxy(f.p,f.q);
		cout<<"*";
                gameover(i,c);
		if(i==f.p && c==f.q)
		       { len++;
                         l-=2;
                         food(); }
		delay(l);
              }
	      r=i;
              break;
    case 115: for(i=c;!kbhit();i++)
	      { clrscr();
                down(r,i,len);
		gotoxy(f.p,f.q);
		cout<<"*";
                gameover(r,i);
		if(r==f.p && i==f.q)
			{ len++;
                          l-=2;
                          food(); }
		delay(l);
              }
	      c=i;
	      break;
    case 119: for(i=c;!kbhit();i--)
	      { clrscr();
                up(r,i,len);
		gotoxy(f.p,f.q);
		cout<<"*";
                gameover(r,i);
		if(r==f.p && i==f.q)
		      { len++;
                        l-=2;
                        food(); }
		delay(l);
              }
	      c=i;
	      break;
    case 114:result();
             break;
    default:exit(0);
            break;
  }
}
     getch();
 }


void main(){
        clrscr();
        randomize();
	f.score=-100;
        menu();
        clrscr();
	food();
	snake();
}
