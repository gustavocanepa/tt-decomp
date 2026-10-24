#include "types.h"

/* The base class, named after its constructor (func_004CEDD0) so that __13func_005659D8
   resolves. The vptr sits after its 0x68 bytes of data. */
struct func_004CEDD0 {
    char pad[0x18];
    s32 type;
    char pad2[0x4C];
    func_004CEDD0();
    virtual ~func_004CEDD0();
};

/* The class has no known name: it is named after its vtable (0x006898F8) so that
   _vt$10D_006898F8 resolves. A real C++ constructor: the compiler's own vptr store gives the
   original's scheduling; the same stores written by hand in C do not. */
struct D_005DB1A8 : func_004CEDD0 {
    D_005DB1A8();
    virtual ~D_005DB1A8();
};

extern D_005DB1A8 *D_007A6414;

D_005DB1A8::D_005DB1A8() {
    type = 2;
    D_007A6414 = this;
}
