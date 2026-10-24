/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Texture;
struct Obj {
 char b0; unsigned char fx,fy; char b3;
 short x,y,w,h;
 float alpha; int p10; char *vt;
 Texture *tex; float level; float blend; unsigned char visible;
};
extern char D_005F56E0[];
extern "C" Texture *func_00357310(const char *);
extern "C" void func_0038E838(Texture *,unsigned,unsigned,float,float,float,float);
extern "C" void func_0038F2A8(int,int,int,int);
extern "C" int func_0038F4A8(int,int,int);
extern "C" void func_0046F0F8(int);
extern "C" void func_004702D8(int,float);
extern "C" void func_00477DC0(unsigned int);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void RaceCapacityMonitor__render_main(Obj *o) {
 if(o->visible) {
  if(o->tex==0) o->tex=func_00357310(D_005F56E0);
  int sw=o->w-4;
  int sh=sw*20/28;
  float one=1.0f;
  int x=func_0038F4A8(o->x,o->w,o->fx);
  int ix=x+2;
  int y=func_0038F4A8(o->y,o->h,o->fy);
  int bottom=y+o->h-sh;
  int top=bottom-4;
  int len=(int)((float)(top-y-2)*o->level);
  func_00477DC0(0x40000000);
  func_0046F0F8(6);
  func_004702D8(0x44,one);
  func_0038F2A8(x,y,o->w,o->h);
  func_00477DC0(0x80202020);
  func_0038F2A8(ix,y+2,o->w-4,o->h-4);
  func_00477DC0(0x80cc4600);
  func_0038E838(o->tex,0,0,(float)ix,(float)(bottom-2),(float)sw,(float)sh);
  float t=o->blend;
  float s=one-t;
  float r1=t*0.0f,g1=t*0x1.191918p-2f,b1=t*0x1.999998p-1f;
  float r0=s*0x1.199998p-1f,g0=s*0x1.999998p-4f,b0=s*0.25f;
  func_00477E30(r1+r0,g1+g0,b1+b0,one);
  func_0038F2A8(ix,top-len,o->w-4,len);
 }
}
