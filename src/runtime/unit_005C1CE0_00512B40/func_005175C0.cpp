typedef int s32;
typedef unsigned char u8;

struct Elem {
    s32 f0;
    float f4;
};

struct Tmp {
    s32 f0;
    float f4;
};

extern "C" void func_00128400(void *arg0, void *arg1);
extern "C" void func_00517668(void *arg0, s32 arg1, s32 arg2, void *arg3, u8 arg4);

extern "C" void func_005175C0(Elem *first, Elem *last, u8 arg2, int unused0, int unused1) {
    volatile u8 flag = arg2;
    Tmp tmp;
    s32 length = last - first;
    if (length >= 2) {
        s32 parent = (length - 2) / 2;
        while (true) {
            float v;
            func_00128400(&tmp, &first[parent]);
            v = first[parent].f4;
            tmp.f4 = v;
            func_00517668(first, parent, length, &tmp, flag);
            if (parent == 0) {
                return;
            }
            parent -= 1;
        }
    }
}
