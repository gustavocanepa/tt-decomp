/* compiler: ee-gcc2.96-no-strict-aliasing */
#define NULL 0

typedef int s32;
typedef short s16;
typedef float f32;

#define FLD(p, t, o) (*(t)((char *)(p) + (o)))

void func_00278E18(void *arg0, void *arg1);                                   /* extern */
void *GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, s32, void *);                      /* extern */

extern char func_00545AB8[];
extern char func_0054D6E8[];

void func_0027B268(void *arg0, void *arg1) {
    void *temp_v0;
    void *var_v1;

    func_00278E18(arg0, arg1);
    var_v1 = NULL;
    if (arg1 != NULL) {
        temp_v0 = FLD(arg1, void **, 4);
        var_v1 = GT4MC__FileGT4GameData__loadInstance(FLD(temp_v0, s32 *, 4), (s32)func_00545AB8, 0,
                               (char *)arg1 + FLD(temp_v0, s16 *, 0), (s32)func_0054D6E8, arg1);
    }
    if (var_v1 != NULL) {
        FLD(arg0, f32 *, 0x108) = FLD(var_v1, f32 *, 0x108);
        FLD(arg0, f32 *, 0x10C) = FLD(var_v1, f32 *, 0x10C);
        FLD(arg0, f32 *, 0xF8) = FLD(var_v1, f32 *, 0xF8);
        FLD(arg0, s32 *, 0xFC) = FLD(var_v1, s32 *, 0xFC);
        FLD(arg0, s32 *, 0x100) = FLD(var_v1, s32 *, 0x100);
    }
}
