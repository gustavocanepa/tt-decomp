/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { char pad0[8]; int count; char padC[12]; int w,h; char pad20[20]; float f34; };
extern "C" void func_00465020(float,float,float,float) throw();
extern "C" void func_00465298(S *,int,int,int,int) throw();
extern "C" void func_004656D0(S *,int,int) throw();
extern "C" void func_00465778(S *,float,int,int) throw();
extern "C" void func_0046F0F8(int);
extern "C" void func_00470400(int,int,int,int);
extern "C" void func_00470478(int);
extern "C" void pglPushAttrib(int);
extern "C" void func_00473498();
extern "C" void func_00473F50(int,int,int,int);
extern "C" void func_00477DC0(int);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void func_00478C98(int);
extern "C" int func_00465C48(S *s, unsigned char flag, float x,float y,float size,float strength) {
 int n=(int)size;
 y+=0.5f; x+=0.5f;
 float nf=(float)n;
 float half=nf*0.5f;
 float yy=(float)(int)y;
 float xx=(float)(int)x;
 int top=(int)(yy-half);
 int left=(int)(xx-half);
 int right=left+n;
 int bottom=(int)((float)top+nf);
 if(right>=0) {
  if(s->w<left || bottom<0) return 0;
  if(s->h>=top) goto draw;
 }
 return 0;
draw:
   if(right-left<3)right=left+2;
   if(bottom-top<3)bottom=top+2;
   func_00470400(0,0,0,1);func_00470478(0);func_00477DC0(0);
   func_00478C98(5);func_00478C98(6);
   func_00473F50(left,top,right+2,bottom+2);
   func_0046F0F8(5);func_00477E30(1.0f,1.0f,1.0f,2.0f);
   if(flag) {func_00465020(xx,yy,half,s->f34);strength*=1.2732406f;}
   else func_00473F50(left,top,right,bottom);
   if(s->w-1<right)right=s->w-1;
   if(s->h-1<bottom)bottom=s->h-1;
   if(left<0)left=0;
   if(top<0)top=0;
   pglPushAttrib(0x887);func_00470400(0,0,0,1);
   func_00465298(s,left,top,right+1,bottom+1);
   int width=right-left;int height=bottom-top;
   func_004656D0(s,width,height);
   func_00470400(1,1,1,1);
   func_00465778(s,strength,width,height);
   func_00473498();func_00470478(1);
   s->count++;
   return 1;
}
