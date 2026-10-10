#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"


struct func_002BCE20_arg1 {
    char pad0[0xC];
    void *unkC;
    void *unk10;
};
struct func_002BCE20_temp_v1 {
    char pad0[0x10];
    void *unk10;
};
struct func_002BCE20_arg0 {
    void *unk0;
    void *unk4;
};

void func_002BCE20(struct func_002BCE20_arg0 *arg0, struct func_002BCE20_arg1 *arg1) {
    struct func_002BCE20_temp_v1 *temp_v1;

    temp_v1 = arg1->unkC;
    if (temp_v1 != NULL) {
        temp_v1->unk10 = (void *) arg1->unk10;
    }
    if (arg1->unk10 != NULL) {
        M2C_FIELD(arg1->unk10, void **, 12) = arg1->unkC;
    }
    if (arg1->unkC == NULL) {
        arg0->unk0 = arg1->unk10;
    }
    if (arg1->unk10 == NULL) {
        arg0->unk4 = (void *) arg1->unkC;
    }
    arg1->unkC = NULL;
    arg1->unk10 = NULL;
}
