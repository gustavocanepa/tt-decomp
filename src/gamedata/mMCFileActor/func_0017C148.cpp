#include "types.h"
struct Part { char pad[4]; s32 unk4; };
struct mMCFileActor_00173728 { char pad0[0x40]; Part sub40; };
struct D_00579534_00173728 { char pad0[0x78]; s32 unk78; };
extern D_00579534_00173728 D_00579534;
struct CopyObj { s32 data[15]; };
extern "C" void pglPushAttrib(s32);
extern "C" CopyObj *func_00104960(CopyObj *, const CopyObj *);
extern "C" s32 func_00104B10(void *);
extern "C" void func_001050C0(void *, void *, s32, s32);
extern "C" void func_00104C88(void *);
extern "C" void func_00473050();
extern "C" void func_0017C148(mMCFileActor_00173728 *self) {
    pglPushAttrib(1);
    CopyObj *obj = (CopyObj *)((char *)self + 0x7C);
    CopyObj *record = (CopyObj *)((char *)&D_00579534 + D_00579534.unk78 * 0x3C);
    func_00104960(obj, record);
    ((Part *)obj)->unk4 = 1;
    func_00104B10(obj);
    func_001050C0(obj, record, 0, 0);
    func_00104C88(obj);
    func_00473050();
}
