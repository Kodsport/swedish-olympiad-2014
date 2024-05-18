#include <stdio.h>
 
int DIR[4][2]={{0,1},{1,0},{0,-1},{-1,0}};   //   > v < ^ 
 
int D(char c) { return c=='>'?0:c=='v'?1:c=='<'?2:c=='^'?3:-1; }
 
int SMIN(int p, int q) {return (p<q || q==-1)?p:q;}
 
int N,M;
char map[2005][2005];
int q[16000005],sd[16000005];
int now, last;
 
 
 
 
int encode(int r, int c, int d) {
  return (r*M+c)*4+d;
}
void decode(int v, int *r, int *c, int *d) {
  *d=v%4;
  v/=4;
  *r=v/M;
  *c=v%M;
}
 
void MLX(int pos) {
  int r,c,d,nr,nc,nd,np;
  decode(pos,&r,&c,&d);
  //printf("pos=%d   %d %d %d: %d\n", pos, r,c,d,sd[pos]);
  nd=D(map[r][c])==-1 ? d : D(map[r][c]);
  nr=r+DIR[nd][0];
  nc=c+DIR[nd][1];
  if(nr>=0 && nr<N && nc>=0 && nc<M) {
    np=encode(nr,nc,nd);
    if(sd[np]==-1) {
      sd[np]=sd[pos];
      MLX(np);
    }
  }
  if(d!=nd) {
    nr=r+DIR[d][0];
    nc=c+DIR[d][1];
    if(nr>=0 && nr<N && nc>=0 && nc<M) {
      np=encode(nr,nc,d);
      if(sd[np]==-1) {
    sd[np]=sd[pos]+1;
        q[last++]=np;
      }
    }
  }
}
    
 
 
 
int main() {
  int R,C,now,m,d,i;
  scanf("%d %d %d %d", &N,&M,&R,&C);  R--; C--;
  for(i=0;i<N;i++) scanf("%s",map[i]);
  for(i=0;i<4*N*M;i++) sd[i]=-1;
  now=0;
  last=1;
  q[0]=0;
  sd[0]=0;
  while(now<last) MLX(q[now++]);
  m=4*N*M;
  for(d=0;d<4;d++) m=SMIN(m,sd[encode(R,C,d)]);
  printf("%d\n", m);
  return 0;
}
