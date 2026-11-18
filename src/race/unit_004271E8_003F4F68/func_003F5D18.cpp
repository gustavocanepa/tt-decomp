#include "types.h"

struct Date_0042E660 {
    s16 year;
    u8 month;
    u8 day;
};

extern "C" void func_004F8588(char *dst, const char *src);
extern "C" s32 func_004A64A8(char *buf, s32 size, const char *fmt, ...);
extern "C" char D_005F9680[];
extern "C" char D_005F9688[];

extern "C" void func_003F5D18(Date_0042E660 *date, char *buf, s32 size) {
    if (date == 0) {
        return func_004F8588(buf, D_005F9680);
    }
    func_004A64A8(buf, size, D_005F9688, date->year, date->month, date->day);
}
