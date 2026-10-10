extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA710(...) throw();
s32 func_004FA740(...) throw();
s32 func_004FA840(...) throw();
s32 func_004FA860(...) throw();

struct func_004BCC08_arg0 {
    char pad0[0x3FC];
    s32 unk3FC;
    s32 unk400;
};

void func_004BCC08(char *arg0) {
    func_004FA860(((struct func_004BCC08_arg0 *)arg0)->unk400);
    ((struct func_004BCC08_arg0 *)arg0)->unk3FC = func_004FA710();
    func_004FA840(((struct func_004BCC08_arg0 *)arg0)->unk400);
    func_004FA740();
}

}
