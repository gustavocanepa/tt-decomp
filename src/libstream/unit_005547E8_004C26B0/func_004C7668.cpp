#include "types.h"

struct Obj;

extern "C" void func_004A4930(Obj *arg0);
extern "C" void func_004A4970(Obj *arg0);

extern char D_005A0B88[];

struct Blk24 {
    char b[20];
    s32 w;
};

struct Elem {
    s32 a;
    s32 flag;
    Blk24 body;
    s32 tail;
};

extern "C" void func_004C7668(Elem *arg0, s32 arg1, Blk24 *arg2) {
    s32 i;

    func_004A4930((Obj *)D_005A0B88);
    if (arg1 != 2) {
        Elem *e = arg0 + arg1;
        e->body = *arg2;
        e->flag = 1;
    } else {
        Elem *e = arg0;
        for (i = 0; i < 2; i++) {
            e->body = *arg2;
            e->flag = 1;
            e++;
        }
    }
    func_004A4970((Obj *)D_005A0B88);
}
