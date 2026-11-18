/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int a,b,w,h,x,y,dx,dy; char pad20[8]; int tex; char pad[0x10]; };
struct Globals { Buf views[2]; int cur; char pad[0x7c]; Buf other; };
extern Globals D_00579534,D_005795B0;
extern "C" {
void func_00104868(void *,int); int func_001048C8(void *,int,int,int);
void func_001054A0(void *,int);
void func_00104838(void *); void *func_00104960(void *,void *); int GSBuffer__getBufferWidth(void *); void func_00104C58(void *); void func_00104C88(void *);
void func_00104CF0(void *); void func_00104D10(void *); int func_00104F00(void *);
void func_0039E4D8(void *); int func_0039E5D8(void *); void func_00380300(void *,float);
void func_00468C10(float,float,float,float); void func_0046F0F8(int); void func_004701C0(int);
void func_00470450(int); void func_00470478(int); void func_004704E0(int); void func_004A2B10(float,float);
void func_004A2C58(int,int,float); void func_00470B58(float); void func_004716B0(int,float);
void func_00472268(int,int); void func_00473178(int); void func_00473050(); void func_004730A8();
void func_00474520(float,float,float,float,float,float,float,float); int func_00474BC8(float);
void func_004751FC(); void func_004755EC(float,float,float); void func_00475730(float); void func_00475758(float);
void func_00475780(float); void func_00477DC0(int); void func_00477E30(float,float,float,float); void func_00478C98(int);
}
static inline float fixAspect(float aspect, int wide) { if(wide) return aspect * 0x1.555554p+0f; return aspect; }
#define F(off) (*(float *)(self+(off)))
extern "C" void func_0039E140(char *self,Buf *arg) {
 Buf a,b;
 Globals *g=&D_00579534;
 int width=GSBuffer__getBufferWidth(&g->views[g->cur]);
 int height=((Buf *)g)[g->cur].h;
 func_001048C8(&a,0,width,height); func_00104C88(&a);
 Buf *pb=&b;
 func_00104838(pb); func_00104960(pb,&g->other); b.b=0x3a; func_00104CF0(pb);
 func_00470478(1); func_00470450(-1); func_00470B58(1.0f); func_00478C98(4); func_00478C98(3);
 func_00473178(1); func_00473050(); func_004751FC();
 float aspect=(float)width/(float)height;
 aspect = fixAspect(aspect, *(int *)((char *)g-0x1c));
 float zero=0.0f;
 func_00468C10(50.0f,aspect,0.1f,100.0f);
 func_00473178(0); func_0039E4D8(self); func_00473050(); func_00380300(self,F(0x88C)); func_004751FC();
 func_004755EC(F(0x890),F(0x8A0),F(0x8B0)); func_00475758(F(0x8D0)); func_00475730(F(0x8C0)); func_00475780(F(0x8E0));
 func_00104C88(&a); func_00104D10(arg); func_00478C98(6); func_0046F0F8(5); func_004701C0(1);
 func_00474BC8(100.0f); func_00472268(3,0); func_00472268(2,0); float white=1.0f; func_00477E30(white,white,white,white);
 float w=(float)a.dx;
 float h=(float)func_00104F00(&a);
 int x=arg->x; int dx=arg->dx; int dy=arg->dy; int y=arg->y;
 func_00474520(zero,zero,w,h,(float)x,(float)y,(float)(x+dx),(float)(y+dy));
 func_004701C0(3); func_004704E0(D_005795B0.views[D_005795B0.cur].tex); func_0039E5D8(self); func_004730A8();
 func_00473178(1); func_004730A8(); func_00473178(0); func_00478C98(5); func_0046F0F8(6);
 func_00470450(0xffffff); func_00470478(0); func_00472268(2,1); func_00472268(3,1); func_00477DC0(0x80ffffff);
 func_00104C88(arg); func_00104C58(&a); func_004704E0(0);
 if(arg->b==2 || arg->b==10) func_0046F0F8(7);
 func_004716B0(5,F(0x920)); func_00478C98(7); func_00104868(pb,2); func_00104868(&a,2);
}
