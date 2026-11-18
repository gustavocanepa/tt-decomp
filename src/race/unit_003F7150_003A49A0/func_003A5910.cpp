/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header {unsigned char pad,n;};
extern "C" Header *func_002FD378(void *);
static inline float sqrt_s(float a) {float r; asm("sqrt.s %0,%1":"=f"(r):"f"(a));return r;}
extern "C" int func_003A5910(char *self,float *out) {
 int count=0;
 char *body=self+0x104;
 *out=0.0f;
 int n=func_002FD378(*(void **)(self+0x10))->n;
 int less=count<n;
 if(n) {
 unsigned char *p=(unsigned char *)self+0x857;
 int remain=n;
 do {
 unsigned char f=*p;
 p+=0x34;
 remain--;
 if(f&4)count++;
 }while(remain);
 less=count<n;
 }
 int result=0;
 if(!less) {
 float x=*(float *)(body+0x564),y=*(float *)(body+0x568),z=*(float *)(body+0x56C);
 float v=sqrt_s(x*x+y*y+z*z);
 const float k=0x1.1c71c6p-2f;
 if(!(v>k)) {
 result=1;
 *out=v/k;
 }
 }
 return result;
}
