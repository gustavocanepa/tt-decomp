/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_00579518;
extern "C" int func_004677B0(int,unsigned,unsigned,void*);
extern "C" int func_0046D810(int,void*,void*,int,int,int);
extern "C" void func_0046F0F8(unsigned);
extern "C" void func_00472268(int,int);
extern "C" void func_00472528(int,unsigned,unsigned);
extern "C" float *func_00473980(int);
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
struct Obj { void *tex[2]; };
extern "C" void func_00389168(Obj *self,int mode,float x0,float y0,float x1,float y1,float scale){
 if(D_00579518) scale*=0.75f;
 unsigned w=mode==0?96:64;
 float half=((x1-x0)*0.25f)/((y1-y0)*scale);
 unsigned h=mode==0?64:32;
 float wf=(float)w;
 float pf=(float)extentPower(w);
 float extent=wf/pf;
 float u0=(0.5f-half)*extent, u1=(half+0.5f)*extent;
 if(u0<0.0f){
  float d=u0-u1;
  float a=u1*x0, b=u0*x1;
  float c=extent-u1;
  float inv=1.0f/d;
  float e=extent-u0;
  u0=0.0f;
  x0=(b-a)*inv;
  x1=(c*x0-e*x1)*inv;
  u1=extent;
 }
 func_0046F0F8(2);
 float *pos=func_00473980(3);
 float *uv=func_00473980(2);
 pos[0]=x0; pos[1]=y0; pos[2]=0.0f;
 pos[3]=x1; pos[4]=y0; pos[5]=0.0f;
 pos[6]=x0; pos[7]=y1; pos[8]=0.0f;
 pos[9]=x1; pos[10]=y1; pos[11]=0.0f;
 uv[0]=u0; uv[1]=0.0f; uv[2]=u1; uv[3]=0.0f;
 uv[4]=u0; uv[5]=1.0f; uv[6]=u1; uv[7]=1.0f;
 func_004677B0(2,w,h,self->tex[mode]);
 func_00472268(4,2);func_00472268(5,2);
 func_00472528(0,0,w-1);func_00472528(1,0,h-1);
 func_0046D810(4,pos,uv,0,0,0);
}
