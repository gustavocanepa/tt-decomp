/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

/* The root class (its constructor is func_00109658); the vptr sits after its 0x64 bytes. */
struct func_00109658 {
    char pad0[0x64];
    virtual ~func_00109658();
};

/* The base class, named after its constructor so that __13func_00101030 resolves. */
struct func_00100928 : func_00109658 {
    s32 m68;
    func_00100928();
    virtual ~func_00100928();
};

/* No known name: named after its vtable (0x00659E80) so that _vt$10D_00659E80 resolves. */
struct D_005A4CB8 : func_00100928 {
    s32 *m6C;
    D_005A4CB8(s32 *args);
    virtual ~D_005A4CB8();
    void func_00108278(s32 a, f32 t);
};

extern "C" D_005A4CB8 *D_00579740;

D_005A4CB8::D_005A4CB8(s32 *args) : m6C(args) {
    func_00108278(*args, 3.0f);
    m6C++;
    D_00579740 = this;
}
