struct Vec3 { float x, y, z; };
struct SparkParticle {
    int m0, m4;
    unsigned short flags;
    short pad;
    Vec3 pos;
    char pad2[0x2C - 0x18];
    float width;
    char pad3[0x4C - 0x30];
    Vec3 last;
    void Render();
};
extern "C" void func_00475850(Vec3 *, Vec3 *);
extern "C" void func_00473050(void);
extern "C" void func_004751FC(void);
extern "C" void func_004730A8(void);
extern "C" int SparkParticle__getColor(SparkParticle *);
extern "C" void ThickLine2(Vec3 *, Vec3 *, int, float);

void SparkParticle::Render()
{
    Vec3 v;
    func_00475850(&v, &pos);
    if (flags & 1) {
        func_00473050();
        func_004751FC();
        ThickLine2(&last, &v, SparkParticle__getColor(this), width);
        func_004730A8();
    } else {
        flags |= 1;
    }
    last.x = v.x;
    last.y = v.y;
    last.z = v.z;
}
