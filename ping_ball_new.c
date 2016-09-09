//make a flow//
/* connect PB0 to row on right side first pin.
 connect PA0 to first pin(just after right row 4th pin)  */

#include<avr/io.h>
#include<util/delay.h>
#define ROW PORTB
#define COL PORTA

void start();
void count(int);
unsigned char dot_row[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80, 0x40,0x20,0x10,0x08,0x04,0x02};
unsigned char dot_col[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f, 0xbf,0xdf,0xef,0xf7,0xfb,0xfd};

static char ROW1=0,COL1=0;
int i,j=-1,l=-1,m=0,s;

void main()
{
char a=0,b=0,c=0xe3,d=0;
short int time=600;


DDRB=0xff; //row
DDRA=0xff; //column
DDRC=0xfd;//input switches
PORTC=0x03;

ROW1=0;//variable holding values to be display as a dot
COL1=0;//simple column variable
start();
m=0;
while(1)
{

{
l++;
j++;
if(l==14)
{l=0;
}

if(j==14)
{j=0;
}

if((dot_row[j]&0x80)==0x80) // entry loop to check exit condition
{


if((dot_col[l]&c)==c) 
{
	
m++;	// total score
j=j+2;
				// continue to shift
}
else
{

goto gameover;//label to be created at the end of this program after while loop
}

}

/*if((m/3)>d)	//increase the speed
{
d=m/3;
time=time-100;
//if(time<0)
//time=0;
}*/



for(i=0;i<800;i++)//minimum repetetion to display a column
{


ROW=dot_row[j];		//display ball
COL=dot_col[l];
_delay_us(time);








if((PINC&0x01)==0)//left shift
{
while((PINC&0x01)==0);
;
c=(c<<1)+1;
if(c==0x3f)
c=0x1f;

}


if((PINC&0x02)==0)//right shift
{
while((PINC&0x02)==0);
c=(c>>1)+0x80;
if(c==0xfc)
c=0xf8;
}



ROW=0x80;//rod display
COL=c;
_delay_us(time);

}//i loop
}//l loop
}//while loop

gameover:				//game over and display score
_delay_ms(6000);
count(m);



}//main loop

void start()
{
for(char d=0;d<5;d++)	//on-off display 5 times
{
ROW=0xff;
COL=0x00;
_delay_ms(1000);
ROW=0x00;
COL=0x00;
_delay_ms(1000);
}
}

void count(int z)	//count score and print it
{
char b;
b=z/10;
z=z%10;

ROW1=0;
print(b,z);

}
void print(char zx,char xz)		//print the score continuously until reset
{

unsigned char *ptr,*ptr1;
unsigned char a0[]={0x7c,0x44,0x7c};// no.0 codes
unsigned char a1[]={0x7c,0x00,0x00};// no.1 codes
unsigned char a2[]={0x74,0x54,0x5c};// no.2 codes
unsigned char a3[]={0x54,0x54,0x7c};// no.3 codes
unsigned char a4[]={0x1c,0x10,0x7c};// no.4 codes
unsigned char a5[]={0x5c,0x54,0x74};// no.5 codes
unsigned char a6[]={0x7c,0x54,0x74};// no.6 codes
unsigned char a7[]={0x04,0x04,0x7c};// no.7 codes
unsigned char a8[]={0x7c,0x54,0x7c};// no.8 codes
unsigned char a9[]={0x5c,0x54,0x7c};// no.9 codes

switch(zx)
{
case 0: 
	ptr=a0;
	break;
case 1:
	ptr=a1;
	break;
case 2:
	ptr=a2;
	break;
case 3:
	ptr=a3;
	break;
case 4:
	ptr=a4;
	break;
case 5:
	ptr=a5;
	break;
case 6:
	ptr=a6;
	break;
case 7:
	ptr=a7;
	break;
case 8:
	ptr=a8;
	break;
case 9:
	ptr=a9;
	break;
	
}


switch(xz)
{
case 0: 
	ptr1=a0;
	break;
case 1:
	ptr1=a1;
	break;
case 2:
	ptr1=a2;
	break;
case 3:
	ptr1=a3;
	break;
case 4:
	ptr1=a4;
	break;
case 5:
	ptr1=a5;
	break;
case 6:
	ptr1=a6;
	break;
case 7:
	ptr1=a7;
	break;
case 8:
	ptr1=a8;
	break;
case 9:
	ptr1=a9;
	break;
	
}




while(1)
{
for(i=0;i<800;i++)
{
COL1=0;
for(unsigned char d=0;d<3;d++)
{

ROW=*(ptr+d);
COL=dot_col[COL1];
_delay_us(1000);
COL1++;
}
COL1=4;

for(unsigned char d=0;d<3;d++)
{

ROW=*(ptr1+d);
COL=dot_col[COL1];
_delay_us(1000);
COL1++;
}


}

}
}
