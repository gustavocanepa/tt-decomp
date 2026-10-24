/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned char u8;
struct B {char pad[0x23968];int count;};
struct S {B *base;char pad[0x48];u8 t[6][6];};
extern "C" int func_0030E370(B *,int,int,float *);
extern "C" int func_003D7D08(S *s,int a,unsigned short flags) {
 float f;
 int j=0;
 int n=s->base->count;
 int ret=0;
 if(n>0) {
  int two=flags&2;
  int one=(unsigned short)(flags&1);
  do {
   if(j!=a) {
    u8 x=s->t[a][j];
    u8 y=s->t[j][a];
    if(x || y) {
     if(two || func_0030E370(s->base,a,j,&f)==0) {
      if(!one) {if(x==1)x=0;if(y==1)y=0;}
      if(x || y)ret|=1<<j;
     }
    }
   }
   j++;
  } while(j<n);
 }
 return ret;
}
