/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x,y; };
struct Vec3 { float x,y,z; };
struct Obj { char pad[0x3D0]; float z; char pad2[0xc8]; float limit; };
extern "C" float func_004263F0() throw() __attribute__((const));
extern "C" void func_00428BE8(Obj *self, Vec2 *a, Vec2 *b, Vec3 *out) {
    float ax=a->x;
    float ay=a->y;
    float len=ax*ax+ay*ay;
    float t;
    if (len!=0.0f) t=(b->x*ax+b->y*ay)/len;
    else t=0.0f;
    Vec3 tmp;
    tmp.x=t*ax-b->x;
    tmp.y=t*ay-b->y;
    tmp.z=-self->z;
    float n=tmp.x*tmp.x+tmp.y*tmp.y+tmp.z*tmp.z;
    if (n==0.0f) {
        out->x=0.0f;
        out->y=0.0f;
        out->z=0.0f;
        return;
    }
    float alen;
    __asm__("sqrt.s %0,%1" : "=f"(alen) : "f"(len) : "memory");
    float inv;
    float one=1.0f;
    __asm__("rsqrt.s %0,%1,%2" : "=f"(inv) : "f"(one),"f"(n));
    float s=func_004263F0()*alen*inv;
    if (self->limit<s) s=self->limit;
    out->x=s*tmp.x;
    out->y=s*tmp.y;
    out->z=s*tmp.z;
}
