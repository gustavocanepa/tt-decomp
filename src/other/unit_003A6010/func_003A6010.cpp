typedef int s32;

struct S003FAD18 {
    s32 unk0;
};

extern "C" void func_003A5E98(S003FAD18 *arg0, s32 arg1, s32 arg2);

extern "C" void func_003A6010(S003FAD18 *arg0) {
    func_003A5E98(arg0, arg0->unk0, 0);
}
