/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" void func_00444B70(u32 *out,const u32 *a,const u32 *b,float t) {
 if(t<=0.0f) {*out=*a;return;}
 if(t>=1.0f) {*out=*b;return;}
 u32 x=*a,y=*b;
 int f=(int)(t*256.0f);
 int g=256-f;
 *out=((((x&0xff00ff00)>>8)*g+((y&0xff00ff00)>>8)*f)&0xff00ff00)|((((x&0xff00ff)*g+(y&0xff00ff)*f)>>8)&0xff00ff);
}
