#include "types.h"

struct Obj00594120 {
    char pad[0x50];
    void *unk50;
};

extern char D_005DB528[];
extern "C" s32 func_004E6248(Obj00594120 *arg0);

extern "C" s32 streambuf__structor_0(Obj00594120 *arg0) {
    arg0->unk50 = D_005DB528;
    return func_004E6248(arg0);
}
