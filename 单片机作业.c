#include"myself.h"


void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--);
}


uchar KeyScan()	//������ֵ���Ӻ���
{
	uchar cord_l,cord_h;//�������ߺ����ߵ�ֵ�Ĵ������
	P1= 0xf0;//1111 0000
	if( (P1 & 0xf0) != 0xf0)//�ж��Ƿ��а�������
	{
		delay(5);//�������
		if( (P1 & 0xf0) != 0xf0)//�ж��Ƿ��а�������
		{
			  t0=0;
			  delay_ms(10);
			  t0=1;
			  cord_l = P1 & 0xf0;// ��������ֵ
			  P1 = cord_l | 0x0f;
			  cord_h = P1 & 0x0f;// ��������ֵ
			  while( (P1 & 0x0f) != 0x0f );//���ּ��
			  return (cord_l + cord_h);//���ؼ�ֵ��
			  
		}	
	}
		
}

void KeyPro()
{
	switch( KeyScan() )
	{
	 	//��һ�м�ֵ��
		case 0xee: m=7*28;P2 = leddata[7];		break;	  //7
		case 0xde: m=8*28;P2 = leddata[8];		break;	  //8
		case 0xbe: m=9*28;P2 = leddata[9];		break;	  //9
		case 0x7e: n=0;		break;	  //k0
		
		//�ڶ��м�ֵ��
		case 0xed: m=4*28;P2 = leddata[4];		break;	   
		case 0xdd: m=5*28;P2 = leddata[5];		break;	   
		case 0xbd: m=6*28;P2 = leddata[6];		break;	   
		case 0x7d: n=1;		break;	  //k1

		//�����м�ֵ��
		case 0xeb: m=1*28;P2 = leddata[1];		break;
		case 0xdb: m=2*28;P2 = leddata[2];		break;
		case 0xbb: m=3*28;P2 = leddata[3];	    break;
		case 0x7b: n=2;	break;	  //k2

		//�����м�ֵ��
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
	    
	 	KeyPro();//��ȡ��ֵ�벢���Ͳ�ͬ��ֵ���������ʾ
		wave();

	}
}

/*void time() interrupt 1
{
	
   	TH0=0xfe;
	TL0=0xfe;
    wave();
	
	
	
} */

