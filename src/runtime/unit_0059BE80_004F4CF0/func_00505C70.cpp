/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern "C" void func_004FAC50(s32 arg0, void *arg1);

extern "C" void func_00505C70(s32 arg0) {
    s32 buf = arg0;
    func_004FAC50(4, &buf);
}
