#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define inf 1000000000
using namespace std;
clock_t t;
double Time_Limit;
char Y,I,Bos;
const int yon[4][2]={{1,0},{0,1},{1,1},{1,-1}};

int Kcrp2=2,Kcrp3=100;
int Klvl[30]={5,5,5,5,5,4,4,4,4,4}; // LIMIT OF THE ROW IS 30 

class board{
public:
	int n,m;
	std::vector<char> v;
	#define plc(x,y) (((x)*(m))+y)
	int isItOver(int x,int y) // x,y ye koyulduktan sonra bitti mi, sadece x y icerenlere bak
	{
		if(!v[plc(x,y)])
				return 0;
		int t=v[plc(x,y)];
		int cnt[4]={0};
		for (int j= 0; j < 4; ++j)
		{
			cnt[j]=1;
			int i=1;
			for (;  ; ++i)
				if( x+i*yon[j][0] >=0 && y+i*yon[j][1]>=0 && x+i*yon[j][0] <n && y+i*yon[j][1]<m  && v[plc( x+i*yon[j][0] , y+i*yon[j][1])]==t)
					cnt[j]++;
				else break;
			i=-1;
			for (;  ; --i)
				if( x+i*yon[j][0] >=0 && y+i*yon[j][1]>=0 && x+i*yon[j][0] <n && y+i*yon[j][1]<m   && v[plc( x+i*yon[j][0] , y+i*yon[j][1])]==t)
				{
					cnt[j]++;
				}
				else break;
			if(cnt[j]>=4) return t;
		}
		return false;
	}
	int wherePut(int k) //returns -1 if cannot put
	{
		for (int i = n-1; i >= 0; --i)
			if(v[plc(i,k)]==0)
				return i;
		return -1;
	}
	int Put(int k,int p) //returns -1 if cannot put
	{
		int t=wherePut(k);
		if(t==-1) return -1;
		v[plc(t,k)]=p;
		return t;
	}
	bool delPut(int k) //returns 0 if cannot del , del top one
	{
		for (int i = n-1; i >= 0; --i)
			if(v[plc(i,k)]==0)
			{
				if(i==n-1) return 0;
				v[plc(i+1,k)]=0;
				return 1;
			}
		v[plc(0,k)]=0;
		return 1;
	}
	int whereToWin(int p) // checks if there is a possibility to win // ret -1 if not
	{
		for (int i = 0; i < m; ++i)
		{
			int t=Put(i,p);
			if(t==-1) continue;
			if(isItOver(t,i))
			{
				delPut(i);
				return i;
			}
			delPut(i);				
		}
		return -1;
	}
	void printBoard()
	{
		for (int i = 0; i < n*m; ++i)
		{
			cout << v[i] << " ";
			if((i+1)%m==0) cout<< endl;
		} 
	}
	int getScore(int p) //score of the board
	{
		int sc[3]={0};
		for (int j = 0; j < m; ++j)
			for (int i = n-1; i >= 0; --i)
			{
				int x=i,y=j;
				int t=v[plc(x,y)];
				if(t==0) break;
				int cnt[4]={0};
				for (int j= 0; j < 4; ++j)
				{
					cnt[j]=1;
					int bos=0;
					int i=1;
					for (;  ; ++i)
						if( x+i*yon[j][0] >=0 && y+i*yon[j][1]>=0 && x+i*yon[j][0] <n && y+i*yon[j][1]<m  ){
							if(v[plc( x+i*yon[j][0] , y+i*yon[j][1])]==t)
							{
								cnt[j]++;
							}
							else if(v[plc( x+i*yon[j][0] , y+i*yon[j][1])]==0){
								bos+=Klvl[x+i*yon[j][0]];
								break;
							}
							else break;
						}
						else break;
					i=-1;
					for (;  ; --i)
						if( x+i*yon[j][0] >=0 && y+i*yon[j][1]>=0 && x+i*yon[j][0] <n && y+i*yon[j][1]<m  ){
							if(v[plc( x+i*yon[j][0] , y+i*yon[j][1])]==t)
							{
								cnt[j]++;
							}
							else if(v[plc( x+i*yon[j][0] , y+i*yon[j][1])]==0){
								bos+=Klvl[x+i*yon[j][0]];
								break;
							}
							else break;
						}
						else break;
					if(bos==0) continue;
					int crp=1;
					if(cnt[j]==2)
						crp=Kcrp2;
					if(cnt[j]==3)
						crp=Kcrp3;
					sc[t]+=crp*bos;
				}
			}
		
		if(p==1)
			return (sc[1]-sc[2]+inf/2);
		else
			return (sc[2]-sc[1]+inf/2);
	}
	board(){
		n=0;m=0;
	}
	board(int n,int m)
	{
		this->n=n;
		this->m=m;
		char o;
		for (int i = 0; i < n*m; ++i)
		{
			scanf(" %c",&o);

			if(o==I)
			{
				this->v.push_back(1);
			}
			else if(o==Y)
			{
				this->v.push_back(2);
			}
			else
			{
				this->v.push_back(0);
			}
		}
	}
	board(std::vector<int> v){
		for (int i = 0; i < v.size(); ++i)
			this->v.push_back(v[i]);
	}

};
int sayac=0;
int bay=0;
int fon(board a,int p,int lvl,int mxlvl,int First=0)
{
	sayac++;
	if(bay || (sayac%100==0 && ((double)(clock()-t)/CLOCKS_PER_SEC)>Time_Limit-0.1))
	{
		bay=1;
		return -1;
	}
	if(lvl==mxlvl)
	{
		return a.getScore(p);
	}
	if(a.whereToWin(p)!=-1)
	{
		return inf;
	}
	int mx=0,plc=0,ret;
	long long int totval=0;
	for (int i = 0; i < a.m; ++i)
		if(a.Put(i,p)!=-1)
		{
			int tut=inf-fon(a,3-p,lvl+1,mxlvl);
			totval+=tut;
			if(mx==tut && rand()%3)
			{
				mx=tut;	
				plc=i;
			}
			if(mx<tut)
			{
				mx=tut;	
				plc=i;
			}
			a.delPut(i);
		}
	if(First==1)
	{
		return plc;
	}
	return mx + totval/a.m/1000+2;
}
int main()
{
	clock();
	srand(time(NULL));
//	return 0;
	freopen("test.in","r",stdin);
	int n,m;
	cin >> n >>  m;
	scanf(" %c %c %c",&I,&Y,&Bos);
	cin >>  Time_Limit;
	Time_Limit-=0.3;
	board start(n,m);
	if(start.whereToWin(1)!=-1)
	{
		cout << start.whereToWin(1) << endl;
		return 0;
	}

	int lastans=0;
	for (int i = 3; i < n*m; i+=2)
	{
		int t=fon(start,1,0,i,1);
		if(((double)(clock()-t)/CLOCKS_PER_SEC)>Time_Limit-0.1)
		{
			break;
		}
		if(t>=0 && t<=m)
			lastans=t;	
	}
	cout << lastans <<endl;
}

/*

2 tarafi koyulabilir x varsa bitir, kazan.

3 satirda kapistirma kodu yazilcak









*/