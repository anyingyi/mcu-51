#include<reg52.h>

#define uchar unsigned char 
#define uint unsigned int 

uchar m,n;
uchar code leddata[]={ 
 
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
                0x77,  //"A"
                0x7C,  //"B"
                0x39,  //"C"
                0x5E,  //"D"
                0x79,  //"E"
                0x71,  //"F"
                0x76,  //"H"
                0x38,  //"L"
                0x37,  //"n"
                0x3E,  //"u"
                0x73,  //"P"
                0x5C,  //"o"
                0x40,  //"-"
                0x00,  //Ï¨Ãð
                0x00  //×Ô¶¨Òå
 
                         };

delay_ms(uchar a)
{
   uchar i,j;
   for(i=0;i<a;i++)
   {
     for(j=0;j<114;j++);
   }
}



/*Èý½Ç²¨*/
void sanjiao()
{
   uchar i;
   for(i=0;i<m;i++)
   {
	  P0=i;
	  delay_ms(1);
   }
   for(i=m;i>0;i--)
   {
	  P0=i;
	  delay_ms(1);
   }
}

/*¾â³Ý²¨*/
void serrate()
{
   uchar i;
   for(i=0;i<m;i++)
   {
	  P0=i;
	  delay_ms(1);
   }

}

/*·½²¨*/
void fangbo()
{
   P0=m;
   delay_ms(80);
   P0=0;
   delay_ms(80);
}

/*ÌÝÐÎ²¨*/
void tixing()
{
	uchar i;
   for(i=0;i<m;i++)
   {
	  P0=i;
	  delay_ms(1);
   }
   P0=m;
   delay_ms(80);
   for(i=m;i>0;i--)
   {
	  P0=i;
	  delay_ms(1);
   }
   P0=0;
   delay_ms(80);
}






