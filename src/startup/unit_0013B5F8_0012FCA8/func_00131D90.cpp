#include "types.h"
struct Text5 { char bytes[5]; };
struct CarRef { char pad[0x14]; s32 id; };
struct Manager;
extern void *D_00586EF8;
extern "C" const Text5 D_005E0FD8;
extern char D_005865D0[];
extern "C" void *func_00408B58(s32);
extern "C" char *func_0040DB60(void *);
extern "C" const char *func_004392A0(Manager *);
extern "C" char *func_00439300(Manager *);
extern "C" void func_0045F468(void *, void *, s32, s32, const char *, const char *, char *);
extern "C" void func_00131D90(CarRef *self, s32 size, char *buffer, s32 value) {
    char *text = func_0040DB60(func_00408B58(self->id));
    if (*text == '-') {
        *(Text5 *)buffer = D_005E0FD8;
        return;
    }
    const char *format = func_004392A0((Manager *)D_005865D0);
    func_0045F468(D_00586EF8, buffer, size, value, format, text,
                  func_00439300((Manager *)D_005865D0));
}
