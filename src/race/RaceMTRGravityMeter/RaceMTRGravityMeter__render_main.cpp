/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Display { char p0;unsigned char xf,yf,p3;short x,y,w,h;float alpha; };
struct Buffer { int head[2];unsigned w,h;char rest[48]; };
extern "C" void func_00104838(void*);
extern "C" void func_00104868(void*,int);
extern "C" void func_00104C88(void*);
extern "C" void func_00104D10(void*);
extern "C" void func_00361CD0(Display*,void*);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void func_0046F0F8(int);
extern "C" void func_004702D8(int,float);
extern "C" void func_00472268(int,int);
extern "C" int func_0038F4A8(int,int,int);
extern "C" void func_0038EE10(float,float,float,float,float,float,float,float);
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
extern "C" void RaceMTRGravityMeter__render_main(Display*self,void*ctx){
 Buffer b;
 func_00104838(&b);func_00361CD0(self,&b);func_00104C88(ctx);func_00104D10(&b);
 func_00477E30(1,1,1,self->alpha);func_0046F0F8(6);func_004702D8(0x44,0);func_00472268(2,1);func_00472268(3,1);
 float x=func_0038F4A8(self->x,self->w,self->xf);
 float y=func_0038F4A8(self->y,self->h,self->yf);
 float w=self->w,h=self->h;
 float u=(float)b.w/(float)extentPower(b.w),v=(float)b.h/(float)extentPower(b.h);
 func_0038EE10(x,y,x+w,y+h,0,0,u,v);
 func_00104868(&b,2);
}
