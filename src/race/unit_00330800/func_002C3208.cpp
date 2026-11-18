/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { int x; char *data; int p8, pc; int w,h,stride,p1c,bpp; };
extern "C" int func_004677B0(int,int,int,void*);
extern "C" void func_00472268(int,int);
extern "C" void func_00472528(int,unsigned int,unsigned int);
extern "C" void func_00478C98(unsigned int);
extern "C" void func_00470478(int);
extern "C" void func_0046F0F8(unsigned int);
extern "C" void func_004702D8(signed char,float);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void func_00474288(int,int,int,int,int,int,int,int);
extern "C" void func_002C3208(Image *p,int x,int y,float alpha) {
 int w=p->w; int h=p->h;
 int size=w*p->bpp;
 size *= h;
 int index=y*p->stride+x;
 func_004677B0(1,w,h,p->data+size*index);
 func_00472268(4,2); func_00472268(5,2);
 func_00472528(0,0,w-1); func_00472528(1,0,h-1);
 func_00472268(3,0); func_00472268(2,0);
 func_00478C98(5); func_00478C98(4);
 func_00470478(0); func_0046F0F8(6);
 func_004702D8(100,alpha);
 func_00477E30(1.0f,1.0f,1.0f,1.0f);
 func_00474288(0,0,w,h,0,0,w,h);
}
