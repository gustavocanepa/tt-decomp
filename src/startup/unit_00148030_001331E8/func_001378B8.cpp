#include "types.h"

class hObject {
public:
    s32 ref;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual s32 getInt();
};

extern "C" void func_00128470(void *);
extern "C" s32 func_001324D8(s32);
extern "C" void func_00128418(void *, s32);
extern "C" void func_00406070(s32, s32);
extern "C" void func_00406098(s32, s32);

extern "C" void func_001378B8(s32 *arg0, void *arg1, s32 arg2, hObject **arg3) {
    s32 buf[4];
    s32 garage;
    s32 value;
    s32 kind;

    func_00128470(buf);
    garage = func_001324D8(buf[0]);
    func_00128418(buf, 2);
    value = arg3[1]->getInt();
    kind = arg3[0]->getInt();
    switch (kind) {
    case 0:
        func_00406070(garage, value);
        break;
    case 1:
        func_00406098(garage, value);
        break;
    }
}
