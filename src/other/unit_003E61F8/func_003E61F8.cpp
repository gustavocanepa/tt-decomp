typedef int s32;

struct R { s32 w[9]; };
extern "C" void func_003E6160(R *, void *);
extern "C" void *func_004F64C4(void *, const void *, s32);

extern "C" void func_003E61F8(void *self, void *out) {
    R t;
    func_003E6160(&t, self);
    func_004F64C4(out, &t, 0x24);
}
