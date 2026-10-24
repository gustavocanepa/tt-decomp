/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;

extern "C" void func_004CF3C0(s32 arg0, s32 arg1, s32 arg2);

extern char D_004C8950[];
extern char D_0059D4A8[];

extern "C" void func_004C7DE0(void) {
    s32 third = (s32)D_0059D4A8;
    s32 second = (s32)D_004C8950;
    func_004CF3C0(3, second, third);
}
