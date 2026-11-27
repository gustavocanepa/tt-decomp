/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char p0[0x10]; int flags; char p1[0x38-0x14]; float scale; char p2[0xAB4-0x3c]; float ab4,ab8,abc,ac0,ac4,ac8,acc; };
extern "C" void func_0034E630(void *,void *,float,float,float,float,float) throw();
extern "C" void func_0046F0F8(int);
extern "C" void func_00473A08(int,int,void *);
extern "C" void func_00478C98(int);
extern "C" void func_0034DE60(Obj *p,float a,float b) {
 float inv, c23,c24,c25,c26,c28,c27;
 int reg=0x65; int i=0; char *cur;
 int buf[4];
 inv=1.0f/p->scale;
 c28=1.0f-p->ab4; c27=1.0f-p->ac8; c26=1.0f-p->ac0;
 c25=1.0f-p->abc; c24=1.0f-p->acc; c23=1.0f-p->ac4;
 cur=(char*)p;
 do {
  int mask=1<<(i+11); i++;
  if(p->flags & mask) {
   func_0046F0F8(reg);
   func_0034E630(buf,cur+0xae0,a,c27,b,c24,inv); func_00473A08(reg,0,buf);
   func_0034E630(buf,cur+0xaf0,a,c28,b,c25,inv); func_00473A08(reg,1,buf);
   func_0034E630(buf,cur+0xb00,a,c26,b,c23,inv); func_00473A08(reg,4,buf);
  } else func_00478C98(reg);
  cur+=0x50; reg++;
 } while(i<=0);
}
