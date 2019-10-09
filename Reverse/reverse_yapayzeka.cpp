// Bu kod 6 nisan 2013 tarihinde yazilmistir. 9. sinifta kodlama basladiktan 3 ay sonra...  :D
#include <library.h>
int tah[8][8], tahp[8][8],enb,enx,eny,bay,yet,yedtah[8][8];
FILE *dosya;

int puan(int q,int w)
{	
	if(tah[q-1][w]==2)
	{
		int i=q-1,j=w,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			i--;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
	if(tah[q][w-1]==2)
	{
		int i=q,j=w-1,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			j--;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
	if(tah[q+1][w]==2)
	{
		int i=q+1,j=w,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			i++;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
	if(tah[q][w+1]==2)
	{
		int i=q,j=w+1,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			j++;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
	if(tah[q-1][w-1]==2)
	{
		int i=q-1,j=w-1,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			i--;j--;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
	
	if(tah[q+1][w+1]==2)
	{
		int i=q+1,j=w+1,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			i++;j++;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
	
	if(tah[q+1][w-1]==2)
	{
		int i=q+1,j=w-1,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			i++;j--;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
	
	if(tah[q-1][w+1]==2)
	{
		int i=q-1,j=w+1,kalan;
		kalan=tahp[q][w];
		while(tah[i][j]==2)
		{
			tahp[q][w]++;
			i--;j++;
		}
		if(tah[i][j]==0)
		tahp[q][w]=kalan;
	}
}
void oyna(int q,int w,int oy)
{
	if(oy==1)
	yet=2;
	if(oy==2)
	yet=1;
	
	tah[q][w]=oy;
	if(tah[q-1][w]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q-1,j=w;
		while(tah[i][j]==yet)
		{
			tah[i][j]=oy;
			i--;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
	if(tah[q][w-1]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q,j=w-1;
		while(tah[i][j]==yet)
		{
			tah[i][j]=oy;
			j--;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
	if(tah[q+1][w]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q+1,j=w,kalan;
		while(tah[i][j]==yet)
		{
			tah[i][j]=oy;
			i++;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
	if(tah[q][w+1]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q,j=w+1,kalan;
		while(tah[i][j]==yet)
		{
			tah[i][j]=oy;
			j++;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
	if(tah[q-1][w-1]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q-1,j=w-1,kalan;
		while(tah[i][j]==yet)
		{
			
			tah[i][j]=oy;
			i--;j--;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
	
	if(tah[q+1][w+1]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q+1,j=w+1,kalan;
		while(tah[i][j]==yet)
		{
			tah[i][j]=oy;
			i++;j++;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
	
	if(tah[q+1][w-1]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q+1,j=w-1,kalan;
		while(tah[i][j]==yet)
		{
			tah[i][j]=oy;
			tahp[q][w]++;
			i++;j--;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
	
	if(tah[q-1][w+1]==yet)
	{
		for(int i=0;i<8;i++)	
			for(int j=0;j<8;j++)
				yedtah[i][j]=tah[i][j];
		int i=q-1,j=w+1,kalan;
		while(tah[i][j]==yet)
		{
			tah[i][j]=oy;
			tahp[q][w]++;
			i--;j++;
		}
		if(tah[i][j]==0)
		{
			for(int i=0;i<8;i++)	
				for(int j=0;j<8;j++)
					tah[i][j]=yedtah[i][j];
		}
	}
}
int bx,by,tkl=0;
int main()
{
	enb=0;
	bx=0;
	by=0;
	bay=0;
	if(tkl)
	for(int f=0;f<8;f++,printf("\n"))	
		for(int g=0;g<8;g++)	
		{
			printf("%d ",tah[f][g]);
		}
	printf("\n");
	printf("\n");	
	dosya=fopen ("reversetahta.txt","r");
	if(!tkl)
	for(int i=0;i<8;i++)	
		for(int j=0;j<8;j++)
			fscanf(dosya,"%d",&tah[i][j]);
	tkl=1;
	for(int f=0;f<8;f++,printf("\n"))	
		for(int g=0;g<8;g++)	
		{
			printf("%d ",tah[f][g]);
		}
	scanf("%d %d",&bx,&by);
	oyna(bx-1,by-1,2);
		printf("\n");
	printf("\n");	
	for(int f=0;f<8;f++,printf("\n"))	
		for(int g=0;g<8;g++)	
		{
			printf("%d ",tah[f][g]);
		}
	
	for(int f=0;f<8;f++)	
		for(int g=0;g<8;g++)
		{
			if(tah[f][g]!=1 && tah[f][g]!=2)
				puan(f,g);
		}
	
		
	if(enb<tahp[0][0])
	{
		enb=tahp[0][0];	
		enx=0;
		eny=0;
	}
	if(enb<tahp[7][7])
	{
		enb=tahp[7][7];	
		enx=7;
		eny=7;
	}
	if(enb<tahp[0][7])
	{
		enb=tahp[0][7];	
		enx=0;
		eny=7;
	}
	if(enb<tahp[7][0])
	{
		enb=tahp[7][0];	
		enx=7;
		eny=0;
	}
	if(enb>0)
	{
	//	printf("%d %d",enx+1,eny+1);
		bay=1;
	}
	if(!bay)
	{
		for(int f=0;f<8;f++)	
		{
			if(f==3 || f==4)
				break;
			if(enb<tahp[f][2])
			{
				enb=tahp[f][2];	
				enx=f;
				eny=2;
			}
			if(enb<tahp[2][f])
			{
				enb=tahp[2][f];	
				enx=2;
				eny=f;
			}
			if(enb<tahp[f][5])
			{
				enb=tahp[f][5];	
				enx=f;
				eny=5;
			}
			if(enb<tahp[5][f])
			{
				enb=tahp[5][f];	
				enx=5;
				eny=f;
			}
		}
		if(enb>0 && bay==0)
		{
		//	printf("%d %d",enx+1,eny+1);
			bay=1;
		}
	}
	if(!bay)
	{
		for(int f=0;f<8;f++)	
		{
			if(enb<tahp[f][3])
			{
				enb=tahp[f][3];	
				enx=f;
				eny=3;
			}
			if(enb<tahp[3][f])
			{
				enb=tahp[3][f];	
				enx=3;
				eny=f;
			}
			if(enb<tahp[f][4])
			{
				enb=tahp[f][4];	
				enx=f;
				eny=4;
			}
			if(enb<tahp[4][f])
			{
				enb=tahp[4][f];	
				enx=4;
				eny=f;
			}
		}
		if(enb>0 && bay==0)
		{
		//	printf("%d %d",enx+1,eny+1);
			bay=1;
		}
	}
	if(!bay)
	{
		for(int f=0;f<8;f++)	
			for(int g=0;g<8;g++)	
			{
				if((f==0 && g==1) || (f==1 && g==0) || (f==1 && g==1) || (f==7 && g==6) || (f==6 && g==7) || (f==6 && g==6) || (f==6 && g==1) || (f==6 && g==0) || (f==7 && g==1) || (f==1 && g==6) || (f==1 && g==7) || (f==0 && g==6))							
					break;
				if(enb<tahp[f][g])
				{
					enb=tahp[f][g];	
					enx=f;
					eny=g;
				}
			}
	}
	if(enb>0 && bay==0)
	{
	//	printf("%d %d",enx+1,eny+1);
		bay=1;
	}
	if(!bay)
	{
		for(int f=0;f<8;f++)	
			for(int g=0;g<8;g++)	
			{
				if(enb<tahp[f][g])
				{
					enb=tahp[f][g];	
					enx=f;
					eny=g;
				}
			}
	}
	getchar();
	getchar();
	getchar();
	getchar();
		for(int f=0;f<8;f++,printf("\n"))	
		for(int g=0;g<8;g++)	
		{
			printf("%d ",tah[f][g]);
		}
	oyna(enx,eny,1);
	//fclose (dosya);
//	dosya=fopen ("reversetahta.txt","w");
	/*for(int f=0;f<8;f++,fprintf(dosya,"\n"))	
		for(int g=0;g<8;g++)	
		{
			fprintf(dosya,"%d ",tah[f][g]);
		}*/
		

	main();
	
}
