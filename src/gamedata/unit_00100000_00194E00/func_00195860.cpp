typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern "C" void func_0011C890(void *arg0, s32 *arg1);
extern "C" void func_0011C918(void *arg0, s32 *arg1);
extern "C" void func_0011C8C0(void *arg0, int arg1);
extern "C" void func_00119108(char *arg0, s32 arg1, void *arg2);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_00195860(char *arg0, s32 *arg1) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    s32 temp;

    dst = (s32 *)(arg0 + 0xB8);
    if (*arg1 == 0) {
        zero = 0;
        func_0011C890(buf, &zero);
    } else {
        func_0011C918(buf, arg1);
    }
    if (dst != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *dst = newVal;
    }
    func_0011C8C0(buf, 2);
    temp = *dst;
    if (temp != 0) {
        func_00119108((char *)temp, *(s32 *)(arg0 + 0xB4), arg0);
    }
}
