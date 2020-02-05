/*
 * does random move to empty place
 * 
 * */

#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;

class check{
public:

    int n;
    int id,x,y;
    vector<vector<int>> matrix;
    check() {
        
        scanf("%d",&n);
        matrix=vector<vector<int>>(n+2,vector<int>(n+2,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                scanf("%d",&matrix[i][j]);
            }
        }
       
        scanf("%d",&id); // id of the player
        srand(time(NULL));
        while(1)
        {
            int x = rand()%n + 1;
            int y = rand()%n + 1;
            if(matrix[x][y]==0)
            {
                printf("%d %d\n",x-1,y-1);
                return ;
            }
        }

    }

};

int main() {

    check();
}
