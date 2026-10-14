/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_005865D0[];
extern char D_005F7428[];
extern "C" float func_00439488(int *);
extern "C" char *func_004391C8(int *);
extern "C" double func_004B4C18(float);
extern "C" int func_004A6500(char *, const char *, ...);
struct Obj { int first; char text[0xB0]; int flag; };
extern "C" void func_0037EB58(Obj *self) {
 int *p=D_005865D0;
 char *buf=self->text;
 float x=func_00439488(p);
 char *s=func_004391C8(p);
 const char *fmt=D_005F7428;
 func_004A6500(buf,fmt,func_004B4C18(x+0x1.47ae14p-8f),s);
 self->flag=1;
}
