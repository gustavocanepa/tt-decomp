#include "types.h"

/* The base class, named after its constructor (func_004F44B8) so that __13func_00578048
   resolves. The vptr sits after its 0x38 bytes of data. */
struct func_004F44B8 {
    char pad[0x2C];
    char *buf;
    s32 size;
    s32 m34;
    func_004F44B8();
    virtual ~func_004F44B8();
};

/* No known name: named after its vtable (0x006897D8) so that _vt$10D_006897D8 resolves. */
struct D_005DB080 : func_004F44B8 {
    s32 m3C;
    char data[0x40];
    D_005DB080();
    virtual ~D_005DB080();
};

D_005DB080::D_005DB080() {
    buf = data;
    size = 0x40;
}
