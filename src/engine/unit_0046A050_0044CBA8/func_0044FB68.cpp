/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0044FB68(float *out,const float *m,const float *v) {
 int k=4;
 float *o1=(float*)((char*)out+k);
 const float *v1=(const float*)((const char*)v+k);
 float vx=v[0];
 float p1=m[0]*vx;
 float vy=v1[0];
 float p2=m[3]*vy;
 out[0]=p1+p2+m[6];
 o1[0]=m[1]*v[0]+m[4]*v1[0]+m[7];
}
