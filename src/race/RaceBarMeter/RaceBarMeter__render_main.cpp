/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32; typedef unsigned long u64;
struct Reg { char pad[0x20]; u64 value; };
struct Texture { char pad[0x18]; Reg *reg; };
struct E { short delta,index; float (*fn)(void*); };
struct Self { unsigned char a,xmode,ymode,b; short x,y,w,h;float alpha;Texture *tex;E *vt; };
extern "C" void func_0038E838(Texture*,int,int,float,float,float,float);
extern "C" void func_0038EE10(float,float,float,float,float,float,float,float);
extern "C" int func_0038F4A8(int,int,int);
extern "C" int func_0038F5F8(u32,float);
extern "C" int func_00467728(Texture*);
extern "C" void func_0046AC48(Reg*);
extern "C" void func_004702D8(int,float);
extern "C" void func_00472268(int,int);
extern "C" void func_00477DC0(int);
static inline u32 pow2(u32 n) { int r; n--; __asm__("plzcw %0, %1":"=r"(r):"r"(n));return 1U<<((r&31)^31); }
static inline float ratio(u32 n) { float f=(float)n;return f/(float)pow2(n); }
extern "C" void RaceBarMeter__render_main(Self *s) {
 if(s->tex) {
 func_004702D8(0x44,0.0f);
 func_00477DC0(func_0038F5F8(0x80000000,s->alpha*0.5f));
 func_0038E838(s->tex,s->xmode,s->ymode,(float)s->x,(float)s->y,(float)s->w,(float)s->h);
 func_00477DC0(func_0038F5F8(0x80ffffff,s->alpha));
 func_00467728(s->tex);func_0046AC48(s->tex->reg);
 func_00472268(2,0);func_00472268(3,0);
 u64 r=s->tex->reg->value;
 u32 w=((r>>14)&0x3ff)+1;
 u32 h=((r>>34)&0x3ff)+1;
 float u=ratio(w);float v=ratio(h);
 float x=(float)func_0038F4A8(s->x,s->w,s->xmode);
 float y=(float)func_0038F4A8(s->y,s->h,s->ymode);
 E *e=s->vt+11;float scale=e->fn((char*)s+e->delta);
 func_0038EE10(x,y,x+(float)s->w*scale,y+(float)s->h,0.0f,0.0f,u*scale,v);
 }
}
