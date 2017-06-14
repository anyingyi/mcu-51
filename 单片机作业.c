#include"myself.h"


void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--);
}


uchar KeyScan()	//带返回值的子函数
{
	uchar cord_l,cord_h;//声明列线和行线的值的储存变量
	P1= 0xf0;//1111 0000
	if( (P1 & 0xf0) != 0xf0)//判断是否有按键按下
	{
		delay(5);//软件消抖
		if( (P1 & 0xf0) != 0xf0)//判断是否有按键按下
		{
			  t0=0;
			  delay_ms(10);
			  t0=1;
			  cord_l = P1 & 0xf0;// 储存列线值
			  P1 = cord_l | 0x0f;
			  cord_h = P1 & 0x0f;// 储存行线值
			  while( (P1 & 0x0f) != 0x0f );//松手检测
			  return (cord_l + cord_h);//返回键值码
			  
		}	
	}
		
}

void KeyPro()
{
	switch( KeyScan() )
	{
	 	//第一行键值码
		case 0xee: m=7*28;P2 = leddata[7];		break;	  //7
		case 0xde: m=8*28;P2 = leddata[8];		break;	  //8
		case 0xbe: m=9*28;P2 = leddata[9];		break;	  //9
		case 0x7e: n=0;		break;	  //k0
		
		//第二行键值码
		case 0xed: m=4*28;P2 = leddata[4];		break;	   
		case 0xdd: m=5*28;P2 = leddata[5];		break;	   
		case 0xbd: m=6*28;P2 = leddata[6];		break;	   
		case 0x7d: n=1;		break;	  //k1

		//第三行键值码
		case 0xeb: m=1*28;P2 = leddata[1];		break;
		case 0xdb: m=2*28;P2 = leddata[2];		break;
		case 0xbb: m=3*28;P2 = leddata[3];	    break;
		case 0x7b: n=2;	break;	  //k2

		//第四行键值码
		case 0xe7: P2 = leddata[14];	break;	  //set
		case 0xd7: P2 = leddata[0];m=0*28;	    break;
		case 0xb7: P2 = leddata[15];	break;	  //ok
		case 0x77: n=3;	break;	  //k3
	}	
}

void wave()
{
   while(n==0)
   {
	 sanjiao();
	 KeyPro();
   }
   while(n==1)
   {
	 serrate();
	 KeyPro();
   }
   while(n==2)
   {
	 fangbo();
	 KeyPro();
   }
   while(n==3)
   {
	 tixing();
	 KeyPro();
   }
}

void main()
{
    //t0_init();
	P3=0xf0;
	P2 = leddata[22];
	while(1)
	{
	    
	 	KeyPro();//提取键值码并且送不同数值给数码管显示
		wave();

	}
}

/*void time() interrupt 1
{
	
   	TH0=0xfe;
	TL0=0xfe;
    wave();
	
	
	
} */

