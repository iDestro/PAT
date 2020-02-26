
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAX=1100;
const int INF=1000000000;
int n, m, k, DS;
bool vis[MAX]={false};
int d[MAX], G[MAX][MAX];
int getid(char c[]){
	int i=0, len=strlen(c), id=0;
	while(i<len){
		if(c[i]!='G')id=id*10+c[i]-'0';
		i++;
	}
	if(c[0]=='G')return id+n;
	else return id;
}
void Dijkstra(int k){
	fill(d,d+MAX,INF);
	memset(vis,false,sizeof(vis));
	d[k]=0;
	for(int i=0;i<n+m;i++){//n+m遍循环
		int u=-1, minn=INF;
		for(int j=1;j<=n+m;j++){//找点
			if(!vis[j]&&d[j]<minn){u=j; minn=d[j];}
		}
		if(u==-1)return ;
		vis[u]=true;
		for(int j=1;j<=n+m;j++){
			if(!vis[j]&&G[u][j]!=INF){
				if(d[j]>d[u]+G[u][j])
					d[j]=d[u]+G[u][j];
			}
		}
	}
}
int main(){
int i, j, dis;
char c1[6], c2[6];
fill(G[0],G[0]+MAX*MAX,INF);
scanf("%d%d%d%d",&n,&m,&k,&DS);
for(i=0;i<k;i++){
	scanf("%s%s%d",c1,c2,&dis);
	int id1=getid(c1);
	int id2=getid(c2);
	G[id1][id2]=G[id2][id1]=dis;
}
int ans=-1;
double mindis=-1, minavg=INF;
double ds, avg;
for(i=n+1;i<=n+m;i++){
	Dijkstra(i);
	ds=INF; avg=0;
	for(j=1;j<=n;j++){
		if(d[j]>DS){ds=-1;break;}
	    if(ds>d[j])ds=d[j];
		avg+=1.0*d[j]/n;
	}
	if(ds==-1)continue;
	if(ds>mindis){mindis=ds;minavg=avg;ans=i;}
	else if(ds==mindis&&avg<minavg){ans=i;minavg=avg;}
}
if(ans==-1)printf("No Solution\n");
else {
	printf("G%d\n%.1f %.1f\n",ans-n,mindis,minavg);
}
return 0;
}