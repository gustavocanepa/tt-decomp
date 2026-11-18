#include "types.h"

extern "C" void RaceEventDisplay__clear(void *arg0, float arg1);
extern "C" void func_0035BA50(char *arg0);

struct Obj0039CD70 {
    char pad[0x17BC];
};

extern "C" void func_00351C78(struct Obj0039CD70 *arg0) {
    RaceEventDisplay__clear((char *)arg0 + 0x177C, 0.0f);
    func_0035BA50((char *)arg0 + 0x2E24);
}
