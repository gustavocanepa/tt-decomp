/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_005865D0[];
extern char D_005F7410[];
extern "C" float func_00439770(int *);
extern "C" char *func_004393E0(int *);
extern "C" double func_004B4C18(float);
extern "C" int func_004A6500(char *, const char *, ...);
struct Obj { int first; char text[0xB0]; void update() __asm__("func_0037E990"); };
void Obj::update() {
 int *p=D_005865D0;
 float x=func_00439770(p);
 char *buf=text;
 char *s=func_004393E0(p);
 const char *fmt=D_005F7410;
 func_004A6500(buf,fmt,func_004B4C18(x),s);
}
