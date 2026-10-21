/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Info { char pad[0x23968]; int size; };
struct Grid { Info *info; short cost[6][6]; u8 flag[6][6]; };
extern "C" float func_003A1610(Info *, int, int);
extern "C" u8 func_003A1268(Info *, int, int);
extern "C" void func_003D78A8(Grid *g) {
 int n=g->info->size;
 for(int i=0;i<n;i++) {
  for(int j=0;j<n;j++) {
   if(i!=j) {
    if(func_003A1610(g->info,i,j)>0.0f) {
     if(g->cost[i][j]<300) g->cost[i][j]++;
    } else if(g->cost[i][j]>0) g->cost[i][j]--;
    u8 t=func_003A1268(g->info,i,j)&15;
    switch(g->flag[i][j]) {
    case 0:
     if(g->flag[j][i]==0) {
      if(t==4) g->flag[i][j]=3;
      else if(t==5) g->flag[i][j]=2;
      else if(g->cost[i][j]>60) g->flag[i][j]=1;
     }
     break;
    case 1:
     if(g->flag[j][i]==0) {
      if(t==4) { g->flag[i][j]=3; break; }
      else if(t==5) { g->flag[i][j]=2; break; }
     }
     if(g->cost[i][j]==0) g->flag[i][j]=0;
     break;
    case 2:
     if(t==3 || t==4) g->flag[i][j]=3;
     else if(t==0 || t==6) g->flag[i][j]=1;
     else if(t==1 || t==2) { g->flag[j][i]=2; g->flag[i][j]=0; }
     break;
    case 3:
     if(t==1 || t==2) { g->flag[j][i]=2; g->flag[i][j]=0; }
     else if(t==5 || t==6) g->flag[i][j]=2;
     break;
    }
   }
  }
 }
}
