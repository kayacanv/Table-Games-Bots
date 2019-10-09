#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf 1000000000
#define MP make_pair
#define orta ((a+b)/2)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 8
#define MOD 1000000009
using namespace std;
typedef  pair <int ,int> ii;
typedef  long long int lint;
vector <int> garbage;
vector < vector<int> > v,bos,hamle[3][7];

const int po2=2,po3=7,podd=3,po4=10000000,ag[7]={-2,-1,0,1,0,-1-2};
int mat[N][N],limit,ts;
ii ab[7];//alfabeeta
int yon[4][2]={{1,0},{0,1},{1,1},{1,-1}};
map <vector< vector<int> > ,int> mp;
vector< vector<int> > operator+(vector< vector<int> > qw,vector< vector<int> >er)
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j <(int) er[i].size(); j++)
			qw[i].pb(er[i][j]);	
	return qw;
}
ii points(vector< vector<int> > a)
{
/*	printf("******************\n");
	for (int i = 0; i < 7; i++,printf("\n"))
		for (int j = 0; j < (int)a[i].size(); j++)
			printf("%d ",a[i][j]);
	printf("\n");*/
	ii don=ii(0,0);
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < (int)a[i].size(); j++)
			if(a[i][j])
				for (int y = 0; y < 4; y++)
				{
					int t=1,say=0;
					while(i+yon[y][0]*t<7 && j+yon[y][1]*t>=0 && t<4)
					{
						if(j+yon[y][1]*t<(int)a[i+yon[y][0]*t].size())
						{
							if(a[i][j]!=a[i+yon[y][0]*t][j+yon[y][1]*t])
								break;
						}
						else say++;
						t++;
					}
					if(a[i][j]==2) swap(don.fi,don.sc);
					t=t-say;
					if(t==2 && say==0)
						don.fi+=po2;
					if(t==3)
					{
						if(y==1) don.fi+=podd; 
						else don.fi+=po3;
					}
					if(t==4)
						don.fi+=po4;
					//~ printf("%d %d %d\n",i,j,t);
					if(a[i][j]==2) swap(don.fi,don.sc);
					//~ printf("%d %d\n",don.fi,don.sc);
					if(t==4) return don;
				}
	//~ printf("%d %d\n",don.fi,don.sc);
	return don;
}
int myturn(vector< vector<int> > a,int der);
int yourturn(vector< vector<int> > a,int der)
{
	if(mp.count(a)) return mp[a];
	vector< vector<int> >  tut= v+a;
	//~ printf("ust %d\n",der);
	int mn=inf,say=0;
	lint ort=0;
	
	for (int i = 0; i < 7; i++)
		if(tut[i].size()<6)
		{
			ab[i]=points(tut+hamle[2][i]);//will be updated
			if(ab[i].sc>=po4) return mp[a]=-po4;
			ort+=ab[i].sc;
			say++;
		}
	//~ printf("alt %d\n",der);
	ort=ort/say;
	for (int i = 0; i < 7; i++)
		if(tut[i].size()<6)
		if(ts>15 || ort-3<=ab[i].sc)
		{
			int ed=myturn(a+hamle[2][i],der+1);
			if(mn>=ed)
				mn=ed;
		}
	return mp[a]=mn;
}
int myturn(vector< vector<int> > a,int der)
{
	if(mp.count(a)) return mp[a];
	vector< vector<int> >  tut= v+a;
	int mx=-inf,say=0,best=-inf;
	lint ort=0;
	for (int i = 0; i < 7; i++)
		if(tut[i].size()<6)
		{
			ab[i]=points(tut+hamle[1][i]);//will be updated
			if(ab[i].fi>=po4) return mp[a]=po4;
			ort+=ab[i].fi;
			best=max(best,ab[i].fi-ab[i].sc);
			say++;
		}
	ort=ort/say;
	if(der>=limit) return best;
	for (int i = 0; i < 7; i++)
		if(tut[i].size()<6)
		if(ts>15 || ort-3<=ab[i].fi)
		{
			int ed=yourturn(a+hamle[1][i],der+1);
			if(mx<=ed)
				mx=ed;
		}
	return mp[a]=mx;
}
int main()
{
	clock_t t=clock();
	srand(time(NULL));
	for (int i = 0; i < 7; i++)
		bos.pb(garbage);
	v=bos;
	for (int qq = 1; qq < 3; qq++)
		for (int i = 0; i < 7; i++)
		{
			hamle[qq][i]=bos;
			hamle[qq][i][i].pb(qq);
		}
	freopen("in","r",stdin);
	FILE *f=fopen("yaz.txt","a+");
	for (int i = 5; i >=0 ; i--,fprintf(f,"\n"))
		for (int j = 0; j < 7; j++)
		{
			char c;
			scanf(" %c",&c);
			if(c=='A')
				mat[i][j]=1;
			if(c=='B')
				mat[i][j]=2;
			if(c=='.')
				mat[i][j]=0;
			fprintf(f,"%c",c);
		}
	for (int i = 0; i < 7; i++)
		for(int j=0;j<6 && mat[j][i]!=0;j++)
		{
			ts++;
			v[i].pb(mat[j][i]);
			//~ printf("%d ",mat[j][i]);
		}
	if(ts<=2) return printf("3"),0;
	int oyna=0;
	int eniyi=-inf;
	limit=4;
	while((clock()-t)/CLOCKS_PER_SEC<1)
	{
		limit++;
		fprintf(f,"%d\n",limit);
		mp.clear();
		//~ ii tut=points(v);
		//~ printf("send %d %d\n",tut.fi,tut.sc);
		for (int i = 0; i < 7; i++)
		{
			if(v[i].size()<6)
			{
				int ed=yourturn(bos+hamle[1][i],0)-ag[i];
				printf("%d %d\n",i,ed);
				if(ed>eniyi || (ed==eniyi && rand()%2))
				{
					eniyi=ed;
					oyna=i;
				}
			}
		}
		eniyi-=200;
	}
	printf("%d\n",oyna);
}
