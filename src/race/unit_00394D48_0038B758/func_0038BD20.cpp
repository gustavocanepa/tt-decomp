/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { float f0,f4,f8,fc,f10,f14,f18,f1c,f20; int i24,i28; char tex[0x3c]; };
struct View { int x,y,w,h; };
extern "C" {
void *func_00104960(void*,void*);
void func_00104C88(void*);
void func_00104CF0(void*);
void func_00105230(void*,void*,int,int,float,float,float,float);
void func_0038C288(void*,void*);
void func_0038C678(void*,void*,int,float,float,float,float);
void func_0046F0F8(int);
int func_004701C0(int);
void func_004702D8(int,float);
void func_00470478(int);
void func_00474BC8(float);
void func_00478C98(int);
float func_004A5EE8(float);
float func_004A6008(float);
}
extern "C" void func_0038BD20(Obj *o,void *tex,View *view,void *state,void *copy,int interlace,float alpha,float r,float g,float b) {
 func_00104960(o->tex,copy);
 func_0038C288(o,view);
 func_00104C88(tex);
 func_00104CF0(state);
 func_0046F0F8(5);
 func_004701C0(3);
 func_00470478(0);
 func_00478C98(8);
 float last=0.0f;
 func_0046F0F8(6);
 func_004702D8(0x44,1.0f);
 float ratio=o->f4/(float)view->h;
 float square=o->fc*o->fc;
 float delta=o->f10-o->fc;
 int i=o->i28*(int)(func_004A6008(o->f20+1.0f)/0x1.62e42ep-1f);
 for(;i>=0;i--) {
  float e=func_004A5EE8((float)i*0x1.62e42ep-1f/(float)o->i28);
  int n=o->i28;
  float fraction=(float)(n-i%n)/(float)n;
  float depth=(square*o->f10)/(square+delta*e*ratio*o->f8);
  if(depth<o->f18) continue;
  func_00474BC8(last);
  last=depth;
  func_0038C678(o,tex,i/o->i28,fraction,r,g,b);
 }
 func_00478C98(6);
 func_00474BC8(last);
 func_00105230(tex,view,interlace,0,alpha,r,g,b);
 func_00104C88(tex);
 func_00104CF0(state);
 func_00470478(0);
 func_0046F0F8(5);
 func_0046F0F8(6);
 func_004702D8(0x44,1.0f);
 for(i=0;;i++) {
  float e=func_004A5EE8((float)i*0x1.62e42ep-1f/(float)o->i24);
  if(o->f1c<e) break;
  int n=o->i24;
  int rem=(i+1)%n;
  float fraction=1.0f;
  if(rem) fraction=(float)rem/(float)n;
  float depth=(square*o->f10)/(square-delta*e*ratio*o->f8);
  if(o->f14<depth || depth<0.0f) break;
  func_00474BC8(depth);
  func_0038C678(o,tex,i/o->i24,fraction,r,g,b);
 }
 func_00470478(1);
 func_0046F0F8(5);
 func_00478C98(6);
}
