struct A { char p[0x1DC]; float f1a0; float f1a4; };
struct B { char p[8]; int f8; };
extern "C" int func_00104E00(void *);
extern "C" void func_0046F0F8(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00470450(int);
extern "C" void func_00470478(int);
extern "C" void func_00473F50(int, int, int, int);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(int);

extern "C" void func_001AA558(A *a, B *b) {
    float thr = 0.0078125f;
    func_0046F0F8(6);
    func_00478C98(5);
    func_00470478(0);
    func_00470450(0xFFFFFF);
    if (a->f1a0 > thr) {
        func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
        func_004702D8(0x62, a->f1a0);
        int s = b->f8;
        func_00473F50(0, 0, s, func_00104E00(b));
    }
    float f2 = a->f1a4;
    if (f2 > thr) {
        float r = 1.0f / (f2 - a->f1a0);
        if (r <= 0.9921875f || r >= 1.0078125f) {
            func_004702D8(0x89, 1.0f);
            func_00477E30(1.0f, 1.0f, 1.0f, r);
            int s = b->f8;
            func_00473F50(0, 0, s, func_00104E00(b));
        }
    }
}
