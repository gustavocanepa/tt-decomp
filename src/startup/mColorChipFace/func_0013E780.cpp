typedef int s32;
struct RefCounter;
struct Owner { char pad0[0xBC]; s32 *slots[2]; };
extern "C" void func_0020B408(Owner *self);
extern "C" void func_001C1380(void *, s32 *);
extern "C" void func_001C13B0(void *, s32);
extern "C" void func_002C0FE8(RefCounter *);
extern "C" void func_002C1050(RefCounter *);
extern "C" void func_0013E780(Owner *self) {
    s32 buf[4];
    s32 zero;
    s32 *dst;
    s32 newVal;
    s32 oldVal;
    s32 count;
    func_0020B408(self);
    dst = (s32 *)&self->slots[0];
    count = 1;
    do {
        zero = 0;
        func_001C1380(buf, &zero);
        if (dst != buf) {
            newVal = buf[0];
            if (newVal != 0) func_002C0FE8((RefCounter *)newVal);
            oldVal = *dst;
            if (oldVal != 0) func_002C1050((RefCounter *)oldVal);
            *dst = newVal;
        }
        func_001C13B0(buf, 2);
        dst += 1;
        count -= 1;
    } while (count >= 0);
}
