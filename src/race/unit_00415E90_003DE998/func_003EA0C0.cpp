/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x,y; };
struct Mat3 {
    float m[9];
    void set(float a,float b,float c,float d,float e,float f,float g,float h,float i) {
        m[0]=a; m[3]=d; m[6]=g; m[1]=b; m[4]=e; m[7]=h; m[2]=c; m[5]=f; m[8]=i;
    }
};
extern "C" void func_004A6328(float,float *,float *);
extern "C" int func_003EA0C0(Mat3 *out,Vec2 *p,float *angle) {
    float sc[2];
    float a[4];
    a[0]=*angle;
    func_004A6328(a[0],&sc[0],&sc[1]);
    float c=sc[1],s=sc[0];
    out->set(c,s,0.0f,-s,c,0.0f,p->x,p->y,1.0f);
}
