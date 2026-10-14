/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;
struct O { char pad[0x24]; s32 u24; };
extern "C" void func_00402448(s32) throw();
extern "C" void func_00402478(struct O *a, s32 b) {
    if (a->u24 != b) {
        a->u24 = b;
        func_00402448((s32)a);
    }
}
