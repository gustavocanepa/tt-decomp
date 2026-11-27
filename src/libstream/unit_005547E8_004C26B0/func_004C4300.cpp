/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct Struct_005599F8 {
    char pad0[8];
    u8 *buf;
};

extern "C" int func_004C4300(Struct_005599F8 *arg0, int arg1) {
    u8 *temp_v1 = arg0->buf;
    if (temp_v1 == 0) {
        return arg1;
    }
    return temp_v1[arg1];
}
