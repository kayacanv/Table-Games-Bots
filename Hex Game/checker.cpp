/*
 * Checker for python. 
 * Back-end
 * */

#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;

class check{
public:

    int n;
    int winner;
    int id,x,y;
    vector<vector<int>> matrix,vis;
    int go[6][2]={-1,0,-1,1,0,1,1,0,1,-1,0,-1};

    void illegal() {

        winner=3-id;

    }
    
    int dfs(int x,int y) {

        int res=0;
        if(x<0 || y<0) return 0;
        if(matrix[x][y]!=id) return 0;
        if(vis[x][y]) return 0;
        vis[x][y]=1;
        if(x>n || y>n) return 1;
        for(int i=0;i<6;i++) {
            res|=dfs(x+go[i][0],y+go[i][1]);
        }
        return res;

    }

    check() {
        
        winner=0;
        scanf("%d",&n);
        vis=matrix=vector<vector<int>>(n+2,vector<int>(n+2,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                scanf("%d",&matrix[i][j]);
            }
        }
        for(int j=1;j<=n;j++) {
            matrix[0][j]=matrix[n+1][j]=1;
        }
        for(int i=1;i<=n;i++) {
            matrix[i][0]=matrix[i][n+1]=2;
        }
        scanf("%d",&id); // id of the player
        scanf("%d %d",&x,&y); // position of play
        x++;y++;
        assert(id>=1 && id<=2);
        if(x<1 || y<1 || x>n || y>n) illegal();
        else if(matrix[x][y]!=0) illegal();
        else {
            matrix[x][y]=id;
            if(dfs(1,0) || dfs(0,1)) winner=id;
        }
        /*for(int i=0;i<=n+1;i++) {
            for(int j=0;j<=n+1;j++) {
                printf("%d ",vis[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",winner);

    }

} ;

int main() {

    check();

}
