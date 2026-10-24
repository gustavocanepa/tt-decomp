/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
struct Config { float a,b,c; u8 c0,c1,c2,c3; float d,e,f; u8 c4,c5,c6,c7; u8 pad[16]; u8 en0,en1,en2,en3; };
struct Gains { float a[2],b[2],c[4],d[4],e[4]; };
extern "C" int func_00303AA0(Config *) throw();
extern u8 D_005834C3,D_005834C4,D_005834C5,D_005839A0;
extern float D_00582E10;
extern "C" void func_00303AF0(u8 *self,Config *cfg,Gains *g,int enable) {
 u8 *state=self+0x104;
 u8 *data=*(u8 **)(self+0x10);
 for(int i=0;i<2;i++) g->b[i]*=F(data,0x1078+i*4);
 if(enable) {
  int flags=0;
  int side;
  float speed=F(state,0x490), slip=F(state,0x498);
  if(F(state,0x59C)>0.0f) side=0; else side=1;
  int other=1-side;
  if(F(state,0x4AC)==0.0f) {
   if(cfg->en0) {
    float x=(slip-cfg->b)*cfg->a;
    if(x>0.0f) {
     flags=1;
     if(cfg->c0) g->e[other]+=x;
     if(cfg->c1) g->e[other+2]+=x;
    }
   }
   if(D_005834C4 || F(state,0x4A8)==0.0f) {
    if(cfg->en2) {
     float x=(speed-cfg->e)*cfg->d;
     if(x>0.0f) {
      if(D_005834C3) flags|=2;
      if(cfg->c4) g->e[side]+=x;
      if(cfg->c5) g->e[side+2]+=x;
     }
    }
   }
  } else {
   if(cfg->en1) {
    float x=1.0f-(slip-0x1.999998p-4f)*cfg->c;
    if(x<0.0f) x=0.0f;
    if(x<1.0f) {
     flags=1;
     if(cfg->c2) { g->c[side]*=x; g->d[side]*=x; }
     if(cfg->c3) { g->c[side+2]*=x; g->d[side+2]*=x; }
    }
   }
   if(cfg->en3) {
    float x=1.0f-(speed-0x1.999998p-4f)*cfg->f;
    if(x<0.0f) x=0.0f;
    if(x<1.0f) {
     if(D_005834C3 && !D_005834C5) flags|=2;
     if(cfg->c6) { g->c[other]*=x; g->d[other]*=x; }
     if(cfg->c7) { g->c[other+2]*=x; g->d[other+2]*=x; }
    }
   }
  }
  if((flags&2) && D_005839A0 && (unsigned)(state[0x486]-1)>=2 && !state[0x487]) {
   float x=1.0f-speed*D_00582E10;
   if(x<0.0f) x=0.0f;
   F(state,0x4B4)*=x;
  }
  if(flags) state[0x614]=2;
  else if(func_00303AA0(cfg)) state[0x614]=1;
 }
}
