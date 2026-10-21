#include "types.h"

struct Obj_00397CE0 {
    char pad0[0x30];
    f32 m30;
    f32 m34;
    char pad38[0x28];
    char m60[4];
};

extern "C" void func_0034DD80(Obj_00397CE0 *o);
extern "C" void func_0034E3B0(Obj_00397CE0 *o);
extern "C" void func_0034DC08(void *p, f32 t);
extern "C" void func_0034DCD8(Obj_00397CE0 *o);
extern "C" void func_0034DBB8(Obj_00397CE0 *o);
extern "C" void func_00421CE0(f32 v);
extern "C" void func_00421CD0(f32 v);

extern "C" void func_0034DB48(Obj_00397CE0 *o) {
    func_0034DD80(o);
    func_0034E3B0(o);
    func_0034DC08(o->m60, 1.0f);
    func_0034DCD8(o);
    func_0034DBB8(o);
    func_00421CE0(o->m34);
    func_00421CD0(o->m34 * o->m30);
}
