/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct V4 { f32 x; f32 y; f32 z; f32 w; };
extern V4 D_00623DC8;
extern V4 D_00623DD8;
extern V4 D_00623DE8;
extern char D_00623DF8[], D_00623E60[], D_00623EC0[], D_00623F08[], D_00623F58[], D_00623FD8[];
extern char D_00579430[];

extern "C" void func_00103988(void *, void *);
extern "C" void func_001039E8(void *, s32);
extern "C" void func_00103B00(void *);
extern "C" void func_00103B30(void *, s32);
extern "C" void func_00103BF8(void *, void *, s32);
extern "C" void func_00103CA8(void *, s32) throw();
extern "C" void func_00103F68(void *);
extern "C" void func_00103FC0(void *, s32);
extern "C" void func_001042F0(void *);
extern "C" void func_00104328(void *, s32);

static inline void vec(V4 *const p, float a, float b, float c, float d) {
 p->x=a; p->y=b; p->z=c; p->w=d;
}
extern "C" void func_00104548(s32 init, s32 prio) {
 if(prio==65535 && init==1) vec(&D_00623DC8,0,0,0,1);
 if(prio==65535 && init==1) vec(&D_00623DD8,0.8f,0.8f,0.8f,1);
 if(prio==65535 && init==1) vec(&D_00623DE8,1,1,1,1);
 if(prio==65535 && init==1) func_00103BF8(D_00579430,&D_00623DC8,1);
 if(prio==65535 && init==1) func_00103F68(D_00623DF8);
 if(prio==65535 && init==1) func_00103988(D_00623E60,&D_00623DC8);
 if(prio==65535 && init==1) func_001042F0(D_00623EC0);
 if(prio==65535 && init==1) func_00103B00(D_00623F08);
 if(prio==65535 && init==1) func_00103BF8(D_00623F58,&D_00623DD8,0);
 if(prio==65535 && init==1) func_00103988(D_00623FD8,&D_00623DD8);
 if(prio==65535 && init==0) func_001039E8(D_00623FD8,2);
 if(prio==65535 && init==0) func_00103CA8(D_00623F58,2);
 if(prio==65535 && init==0) func_00103B30(D_00623F08,2);
 if(prio==65535 && init==0) func_00104328(D_00623EC0,2);
 if(prio==65535 && init==0) func_001039E8(D_00623E60,2);
 if(prio==65535 && init==0) func_00103FC0(D_00623DF8,2);
 if(prio==65535 && init==0) func_00103CA8(D_00579430,2);
}
