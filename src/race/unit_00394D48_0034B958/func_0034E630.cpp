/* compiler: ee-gcc2.96-nogcse */
static inline void factor(float *out, const float *in, float a, float b, float c, float d, float e) {
    a=(1.0f-a)*b;
    float t=1.0f-a;
    float r=1.0f-d;
    d=t*d*c;
    t=d+r;
    t*=e;
    for(int i=0;i<3;i++) out[i]=in[i]*t;
    out[3]=in[3];
}
extern "C" void func_0034E630(float *out, const float *in, float a, float b, float c, float d, float e) {
    factor(out,in,a,b,c,d,e);
}
