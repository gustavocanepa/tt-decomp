#include "types.h"

/* The base class; its constructor is RaceDisplayObjectBase__structor_0. Its vptr sits at 0x14. */
struct RaceDisplayObjectBase__structor_0 {
    char pad[0x14];
    RaceDisplayObjectBase__structor_0();
    virtual ~RaceDisplayObjectBase__structor_0();
};

struct D_005D12F0;
extern "C" void func_00359988(D_005D12F0 *);

/* Named after its vtable so the compiler-made vptr store _vt$10D_0067F8A8 resolves. */
struct D_005D12F0 : RaceDisplayObjectBase__structor_0 {
    char pad18[0x8];
    s32 m20;
    char pad24[0x20];
    float m44;
    D_005D12F0();
    virtual ~D_005D12F0();
};

D_005D12F0::D_005D12F0() {
    func_00359988(this);
    m20 = 3;
    m44 = 0.9f;
}
