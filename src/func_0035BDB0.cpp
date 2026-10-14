struct Obj {
 char b0; unsigned char b1,b2; char b3;
 short h4,h6,h8,hA;
 float fC; int p10; char *vt;
 float f18; char pad1c[0x38-0x1c];
 unsigned int color; float prev; unsigned char mode;
};
extern "C" int RaceDisplayUtil__getScaledColor(unsigned int, float, float);
extern "C" void func_00477DC0(int);
extern "C" void func_0038E838(int,unsigned char,unsigned char,float,float,float,float);
static inline float maxf(float a,float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" int RaceIndicator__render_main(Obj *o) {
 float x;
 if(o->mode==3) x=o->f18;
 else x=(float)o->mode*0.5f;
 func_00477DC0(RaceDisplayUtil__getScaledColor(o->color,maxf(x,o->prev),o->fC));
 func_0038E838(o->p10,o->b1,o->b2,(float)o->h4,(float)o->h6,(float)o->h8,(float)o->hA);
 o->prev=x;
}
