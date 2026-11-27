#include "types.h"

extern "C" void func_0044E618(void *arg0);
extern "C" void func_00453FB0(void *arg0, void *arg1);

extern "C" void func_0044E6A0(void *arg0) {
    char buf[0x10];
    func_0044E618(buf);
    func_00453FB0(arg0, buf);
}
