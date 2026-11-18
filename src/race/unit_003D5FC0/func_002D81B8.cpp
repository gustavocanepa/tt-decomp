/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Color { u32 r:8; u32 g:8; u32 b:8; u32 a:8; };
struct Obj { char pad0[4]; void *p4; char pad8[0x30]; int f38; char pad3c[0x38]; int f74; char pad78[0x28]; const char *pA0; u32 cA4,cA8; char padAc[0x2ac]; u32 c358; };
struct Global { char pad[0x17C]; const char *p178; };
extern Global *D_00584418;
extern "C" void func_0043BE20(void *,int);
extern "C" void func_0043C410(void *);
extern "C" void RaceMessageDisplay__setMessage(void *,const char *,float,float);
extern "C" void func_002D81B8(Obj *p) {
 u32 mask=~0xffu;
 int one=1;
 u32 *c=&p->c358;
 p->f38=one;
 p->f74=one;
 func_0043BE20(p->p4,0);
 func_0043C410(p->p4);
 u32 a=p->cA4;
 u32 b=p->cA8;
 a &= mask; a |= 1;
 a &= 0xffff00ffu; a |= 0x100;
 a &= 0xff00ffffu; a |= 0x10000;
 a &= 0x00ffffffu; a |= 0x1000000;
 b &= mask; b |= 1;
 b &= 0xffff00ffu; b |= 0x100;
 p->cA4=a;
 p->cA8=b;
 const char *s=D_00584418->p178;
 p->pA0=s;
 RaceMessageDisplay__setMessage((char *)p+0x394,s,0.0f,0.0f);
 *c=(*c & mask)|one;
}
