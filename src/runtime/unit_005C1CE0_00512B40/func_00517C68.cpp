typedef int s32;
typedef unsigned char u8;

struct Elem {
    void *p;
    s32 f4;
};

extern "C" void func_002C0FE8(void *arg0), func_002C1050(void *arg0);
extern "C" void func_00128418(void *arg0, s32 arg1);
extern "C" s32 func_004A8268(s32 arg0, s32 arg1);

extern "C" void func_00517C68(Elem *arg0, Elem *arg1, u8 arg2) {
    volatile u8 flag = arg2;
    Elem *cur = arg0;
    Elem *prev = cur - 1;
    while (func_004A8268(arg1->f4, prev->f4) < 0) {
        if (cur != prev) {
            void *a = prev->p;
            if (a != 0) {
                func_002C0FE8(a);
            }
            void *b = cur->p;
            if (b != 0) {
                func_002C1050(b);
            }
            cur->p = a;
        }
        cur->f4 = prev->f4;
        cur = prev;
        prev = cur - 1;
    }
    if (cur != arg1) {
        void *a = arg1->p;
        if (a != 0) {
            func_002C0FE8(a);
        }
        void *b = cur->p;
        if (b != 0) {
            func_002C1050(b);
        }
        cur->p = a;
    }
    cur->f4 = arg1->f4;
    func_00128418(arg1, 2);
}
