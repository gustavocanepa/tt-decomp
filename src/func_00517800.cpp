typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct Node {
    s32 p;
    f32 f;
};

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_00517800(Node *arg0, Node *arg1, s8 arg2) {
    volatile s8 tag;
    Node *s1;
    Node *s2;
    s32 v;

    tag = arg2;
    s1 = arg0;
    s2 = s1 - 1;
    goto test;
    do {
        if (s1 != s2) {
            s32 t = s2->p;
            if (t != 0) {
                func_002C0FE8((RefCounter *)t);
            }
            s32 old = s1->p;
            if (old != 0) {
                func_002C1050((RefCounter *)old);
            }
            s1->p = t;
        }
        s1->f = s2->f;
        s1 = s2;
        s2 = s1 - 1;
    test:
        v = arg1->f < s2->f;
    } while (v != 0);
    if (s1 != arg1) {
        s32 t = arg1->p;
        if (t != 0) {
            func_002C0FE8((RefCounter *)t);
        }
        s32 old = s1->p;
        if (old != 0) {
            func_002C1050((RefCounter *)old);
        }
        s1->p = t;
    }
    s1->f = arg1->f;
    func_00128418(arg1, 2);
}
