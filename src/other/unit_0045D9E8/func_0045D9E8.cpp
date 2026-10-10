typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
extern "C" {
void func_0045D620(s32 *, s32 *) throw();
void func_0045D750(s32 *, s32 *) throw();
void func_0045DA70(void *);
}
struct Pair { s32 *a; s32 *b; };
extern "C" void func_0045D9E8(Pair *self, s32 *data) {
    func_0045DA70(self);
    if (data != NULL) {
        if (*data == 0x31627067) {
            func_0045D620(data, data);
            self->a = data;
            self->b = NULL;
        }
        if (*data == 0x32627067) {
            func_0045D750(data, data);
            self->a = NULL;
            self->b = data;
        }
    }
}
