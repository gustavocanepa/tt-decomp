/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Display {
 unsigned char pad0, flagsx, flagsy, pad3;
 short x,y,w,h;
 float opacity;
 char pad10[0x10];
 unsigned int color;
 int shadow;
 float width,scale;
 char pad30[4];
 float alpha34;
 char pad38[0x1c];
 float alpha54;
 char pad58[0x18];
 char font[0x20];
 char text[0xc0];
 int back;
 unsigned int backcolor;
};
struct Font { int m0,m4; char pad8[16]; float m18; };
extern "C" Font D_00585CC8;
extern "C" void func_004702D8(int,float);
extern "C" unsigned int func_0038F5F8(unsigned int,float);
extern "C" void func_00477DC0(unsigned int);
extern "C" void func_0038E838(int,int,int,float,float,float,float);
extern "C" void func_00415510(Font *,void *);
extern "C" float func_00415C78(Font *,void *);
extern "C" void func_004157B0(Font *,float,float);
extern "C" void func_00415C30(Font *,float);
extern "C" void func_00415B10(Font *,unsigned int);
extern "C" int func_0038F4A8(int,int,int);
extern "C" float func_0038F448(float,float,int);
extern "C" void func_00415A10(Font *,float,float,float);
extern "C" void GT3OLDFONT__GT3OldFontManagerClass__putstring(Font *,void *);
extern "C" void func_00415578(Font *);
static inline float minf(float a,float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
extern "C" void RaceReplayModeDisplay__render_main(Display *self) {
 float alpha = self->alpha54;
 float a = self->opacity * alpha * self->alpha34;
 if (!(a <= 0.0f)) {
   if (self->back) {
     func_004702D8(0x44,1.0f);
     func_00477DC0(func_0038F5F8(self->backcolor,a));
     func_0038E838(self->back,self->flagsx,self->flagsy,(float)self->x,(float)self->y,(float)self->w,(float)self->h);
   }
   func_00415510(&D_00585CC8,self->font);
   void *text;
   if (self->width == 0.0f) {
     text = self->text;
     float width = func_00415C78(&D_00585CC8,text) / D_00585CC8.m18;
     self->scale = 1.0f;
     self->width = width;
     if (self->w > 0) {
       float scale = minf(1.0f,(self->w * 0x1.ccccccp-1f)/width);
       self->scale = scale;
       self->width = width * scale;
     }
   }
   else { text = self->text; }
   Font *font = &D_00585CC8;
   func_004157B0(font,self->scale,1.0f);
   float shadow = self->shadow == 1 ? 0x1.333332p+0f : 0.0f;
   func_00415C30(font,shadow);
   unsigned int color = func_0038F5F8(self->color,a);
   a = 0.0f;
   func_00415B10(&D_00585CC8,color);
   D_00585CC8.m4 = 0;
   int x = func_0038F4A8(self->x,self->w,self->flagsx) + (self->w >> 1);
   int y = func_0038F4A8(self->y,self->h,self->flagsy);
   func_00415A10(&D_00585CC8,func_0038F448((float)x,self->width,2),(float)y + 13.0f,a);
   GT3OLDFONT__GT3OldFontManagerClass__putstring(&D_00585CC8,text);
   func_004157B0(&D_00585CC8,1.0f,1.0f);
   func_00415C30(&D_00585CC8,a);
   func_00415578(&D_00585CC8);
 }
}
