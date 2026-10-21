#include "types.h"

extern "C" void func_0044EBF8(void *arg0);
extern "C" void func_00453FB0(void *arg0, void *arg1);

extern "C" void func_0044ECD0(void *arg0) {
    char buf[0x10];
    func_0044EBF8(buf);
    func_00453FB0(arg0, buf);
}
