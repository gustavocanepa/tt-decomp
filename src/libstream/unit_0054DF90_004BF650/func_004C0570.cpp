#include "types.h"

/* The base class; its constructor is func_004CEDD0. Its vptr sits at 0x68. */
struct func_004CEDD0 {
    char pad[0x18];
    s32 m18;
    char pad2[0x4C];
    func_004CEDD0();
    virtual ~func_004CEDD0();
};

struct D_005DB188;
extern D_005DB188 *D_007A6424;

/* Named after its vtable (no known class name) so the compiler-made vptr store
   _vt$10D_006898D8 resolves; a singleton constructor that registers itself in D_007A6424. */
struct D_005DB188 : func_004CEDD0 {
    D_005DB188();
    virtual ~D_005DB188();
};

D_005DB188::D_005DB188() {
    m18 = 1;
    D_007A6424 = this;
}
