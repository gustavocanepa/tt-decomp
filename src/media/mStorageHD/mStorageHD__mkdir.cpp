#include "types.h"

extern char D_005EA700[];
extern char D_005EA708[];

extern "C" s32 func_004A6500(char *buf, const char *fmt, ...);
extern "C" s32 func_00500C28(const char *path, s32 mode);

extern "C" bool mStorageHD__mkdir(void *self, const char *name) {
    char buf[0x80];
    func_004A6500(buf, D_005EA700, D_005EA708, name);
    return func_00500C28(buf, 0x1FD) == 0;
}
