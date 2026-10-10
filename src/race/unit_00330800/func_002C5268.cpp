struct S { float f0; char pad[0x10]; float f14; char pad2[0x20]; };

extern void func_004752F8(S *);
extern void func_00475638(float, float, float);

void func_002C5268(float x)
{
    S s;
    func_004752F8(&s);
    float v = s.f14 / s.f0;
    v = v / x;
    func_00475638(v, 1.0f, 1.0f);
}
