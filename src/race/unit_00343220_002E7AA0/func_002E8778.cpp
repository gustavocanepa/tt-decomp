#include "types.h"

/* A member class, named after its constructor (func_002E7AA0). */
struct func_002E7AA0 {
    char data[0x58];
    func_002E7AA0();
};

/* No known name: named after its vtable (0x00679958); a real C++ constructor (vptr at 0x6C,
   after the data members). */
struct D_005C9270 {
    s32 m0;
    s32 m4;
    func_002E7AA0 sub;
    s32 m60;
    s32 m64;
    s32 m68;
    D_005C9270();
    virtual ~D_005C9270();
};

D_005C9270::D_005C9270() {
    m0 = 0;
    m4 = 0;
    m60 = 0;
    m64 = 0;
    m68 = 0;
}
