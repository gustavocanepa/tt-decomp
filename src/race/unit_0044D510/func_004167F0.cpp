/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int w0, w4; char pad[56]; };
struct E { short delta, index; void (*fn)(void *, float); };
struct Obj { E *vt; };
extern char D_005FCE40[];
extern "C" {
void func_00104838(void *);
void func_00104868(void *,int);
void func_001049E0(void *,int);
void func_00104A48(void *,int,int);
int func_00104B10(void *);
void func_00104C88(void *);
void func_00104CF0(void *);
void func_00104D10(void *);
int func_00104E30(void *);
void func_0046AC38(int);
void func_0046AE40(int);
void func_0046AE68(int);
void func_0046B668(void *);
void func_0046F0F8(int);
void func_00470450(int);
void func_00470478(int);
void func_00470B48(int);
void func_00470E60(int);
void func_00472628();
void func_00473178(int);
void func_00473050();
void func_004730A8();
void pglPushAttrib(int);
void func_00473498();
void func_004737C8(float,float,float,float,float,float,float);
void func_004738A0(float,float,float,float,float,float);
void func_00473EF0(float,float,float,float);
void func_00473F10(float,float,float,float);
void func_004751FC();
void func_00475730(float);
void func_00475780(float);
void func_00478C98(int);
}
extern "C" void func_004167F0(void *a0, Obj *a1, void (*cb)(int), int a3, int a4, int a5, int a6) {
 if (cb) {
  pglPushAttrib(0x887);
  func_00104C88(a0);
  func_00470450(-1); func_00470478(1); func_00470B48(0x80000000); func_00470E60(1);
  func_00473F10(0.0f,0.0f,0.0f,0.0f);
  func_00473EF0(1.0f,1.0f,1.0f,1.0f);
  Buf b0,b1;
  func_00104838(&b0); func_00104838(&b1);
  b0.w4=0; func_00104A48(&b0,a4,a5);
  b1.w4=0x31; func_00104A48(&b1,a4,a5);
  if (a6<0) { func_00104B10(&b0); func_00104B10(&b1); }
  else { func_001049E0(&b0,a6); func_001049E0(&b1,a6+func_00104E30(&b0)); }
  int i=0;
  do {
   float f=(float)i;
   func_00473178(1); i++; func_004751FC();
   func_004737C8(-0.5f,0.5f,-0x1.81ef30p-1f,0x1.cf1f14p-1f,0x1.47ae14p-8f,200.0f,0x1.4779a6p-3f);
   func_00473178(0); func_004751FC();
   func_00475730(0x1.3fe668p+6f); func_00475780(f*-120.0f);
   func_00104C88(&b0); func_00104CF0(&b1);
   func_0046F0F8(5); func_00478C98(4); func_00470E60(3); func_00473050();
   E *e=(E *)((char *)a1->vt+0x18); e->fn((char *)a1+e->delta,0.0f);
   cb(a3); func_004730A8(); func_00472628();
   func_00104C88(a0); func_00104D10(&b0);
   func_00473178(1); func_004751FC();
   func_004738A0(-0x1.ccccccp-1f,0x1.ccccccp-1f,-0x1.ccccccp-1f,0x1.ccccccp-1f,-1.0f,1.0f);
   func_00473178(0); func_004751FC();
   func_00475780(240.0f-f*120.0f);
   func_00478C98(5); func_00478C98(4); func_00478C98(3); func_00478C98(15);
   func_00470478(0); func_00470450(0xffffff);
   func_0046AE68(0); func_0046AE40(0); func_0046AC38(0); func_0046B668(D_005FCE40);
   func_0046F0F8(17); func_00470478(1); func_00470450(-1);
  } while(i<3);
  func_00472628(); func_00473498();
  func_00104868(&b1,2); func_00104868(&b0,2);
 }
}
