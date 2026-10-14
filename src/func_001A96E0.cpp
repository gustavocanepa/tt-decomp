/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { int a,b,w,h,x,y,dx,dy; char pad[0x20]; };
extern "C" {
void func_00104868(void *,int); int func_001048C8(void *,int,int,int); void func_00104920(void *,void *,int);
void func_00104C88(void *);void func_00104D10(void *);int func_00104E00(void *);int GSBuffer__getBufferWidth(void *);
void *func_001050C0(void *,void *,int,int);
void func_0046F0F8(int);void func_004702D8(int,float);void func_00470450(int);void func_00470478(int);void func_00472268(int,int);void func_00472528(int,int,int);
void func_00474288(int,int,int,int,int,int,int,int);void func_00477E30(float,float,float,float);void func_00478C98(int);
float func_004A5EE8(float);
}
extern "C" void func_001A96E0(Buf *arg,float alpha,float count,float sigma) {
 Buf a,b; float weights[32];
 int i=0;
 func_001048C8(&a,0,GSBuffer__getBufferWidth(arg)/2,arg->h/2);
 Buf *pb=&b;
 func_00104920(pb,&a,0);
 func_001050C0(&a,arg,1,1);
 int w=a.w; int h=func_00104E00(&a);
 for(;i<count;i++) weights[i]=func_004A5EE8((float)(-i*i)/(2.0f*sigma*sigma));
 float sum=0.0f;
 func_0046F0F8(6);func_00478C98(5);func_00470478(0);func_00470450(0xffffff);
 func_00477E30(1.0f,1.0f,1.0f,1.0f);
 func_00104D10(&a);func_00104C88(pb);
 for(i=0;i<count;i++) { float v=weights[i];sum+=v;func_004702D8(100,v/sum);func_00474288(i,0,w,h,0,0,w-i,h); }
 for(i=1;i<count;i++) { float v=weights[i];sum+=v;func_004702D8(100,v/sum);func_00474288(0,0,w-i,h,i,0,w,h); }
 sum=0.0f;
 func_00104D10(pb);func_00104C88(&a);
 for(i=0;i<count;i++) { float v=weights[i];sum+=v;func_004702D8(100,v/sum);func_00474288(0,i,w,h,0,0,w,h-i); }
 for(i=1;i<count;i++) { float v=weights[i];sum+=v;func_004702D8(100,v/sum);func_00474288(0,0,w,h-i,0,i,w,h); }
 func_00104D10(&a);func_00104C88(arg);
 func_00472528(0,0,a.x+a.dx-2);func_00472528(1,0,a.y+a.dy-2);
 func_00472268(3,1);func_00472268(2,1);func_00472268(4,2);func_00472268(5,2);
 func_004702D8(100,alpha);
 int width=arg->w;func_00474288(0,0,width,func_00104E00(arg),0,0,w,h);
 func_00104868(pb,2);func_00104868(&a,2);
}
