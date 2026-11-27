/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { float f0,f4,f8,fc,f10,f14,f18,f1c,f20; int i24,i28; char tex[0x3c]; };
struct View { int x,y,w,h; };
extern "C" {
void *func_00104960(void*,void*);
void func_00104C88(void*);
void func_00104CF0(void*);
void func_0038C1F8(void*,void*);
void func_0038C288(void*,void*);
void func_0038C678(void*,void*,int,float,float,float,float);
void func_0046F0F8(int);
int func_004701C0(int);
void func_004702D8(int,float);
void func_00470478(int);
void func_00474BC8(float);
void func_00474CB8(int,int);
void func_00478C98(int);
float func_004A5EE8(float);
}
extern "C" void func_0038B8D8(Obj *o,void *tex,View *view,void *state,void *copy,float r,float g,float b) {
 int i=0;
 func_00104960(o->tex,copy);
 func_00470478(0);
 func_0038C288(o,view);
 func_00104C88(tex);
 func_00104CF0(state);
 func_0046F0F8(5);
 func_004701C0(3);
 func_00478C98(8);
 func_0046F0F8(6);
 func_004702D8(0x44,1.0f);
 float near=o->f14, far=o->f18;
 float range=near-far;
 float ratio=o->f4/(float)view->h;
 float delta=o->f10-o->fc;
 float scale=(near+far)/range;
 float bias=near*far*-2.0f/range;
 float square=o->fc*o->fc;
 for(;;i++) {
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
 func_0038C1F8(o,state);
 func_00104C88(tex);
 func_00104CF0(state);
 func_0046F0F8(5);
 func_0046F0F8(6);
 func_004702D8(0x44,1.0f);
 for(i=0;;i++) {
  float e=func_004A5EE8((float)i*0x1.62e42ep-1f/(float)o->i28);
  if(o->f20<e) break;
  int n=o->i28;
  int rem=(i+1)%n;
  float fraction=1.0f;
  if(rem) fraction=(float)rem/(float)n;
  float depth=(square*o->f10)/(square+delta*e*ratio*o->f8);
  if(depth<o->f18) break;
  func_00474CB8(0xffffff-(int)((1.0f-(scale*depth+bias)/depth)*8388608.0f),255);
  func_0038C678(o,tex,i/o->i28,fraction,r,g,b);
 }
 func_0038C1F8(o,state);
 func_00470478(1);
 func_0046F0F8(5);
 func_00478C98(6);
}
