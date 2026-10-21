/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pt { float x,y,z,a,b,c; };
struct Shape { signed char count; char pad[3]; Pt pts[24]; };
extern float D_005FFE94;
extern "C" void func_00475850(float *,float *);
extern "C" float func_0041A2B8(Shape *s) {
 float out[4], in[4];
 int i=0;
 float max=D_005FFE94;
 if (s->count>0) {
 float *v=in;
 Pt *p=s->pts;
 do {
   in[0]=p->x;
   in[1]=p->y;
   in[2]=p->z;
   in[3]=1.0f;
   func_00475850(out,v);
   if (max<out[2]) max=out[2];
   i++; p++;
 } while (i<s->count);
 }
 return -max;
}
