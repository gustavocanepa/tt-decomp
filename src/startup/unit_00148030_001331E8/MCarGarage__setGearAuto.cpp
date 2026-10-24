/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
extern "C" void func_00128418(void *, int) throw();
extern "C" void func_00128470(void *) throw();
extern "C" s32 func_001324D8(void *);
extern "C" void func_002F8C40(void *, s32, void *, s32);
extern "C" void func_004057B0(void *, s32, s16);
extern "C" void func_00405830(void *, s32);
extern "C" u16 func_00406158(void *);
extern "C" u8 func_00406180(void *);
extern "C" void *func_00408B58(void *);
extern "C" void func_00408D48(void *, char *);
extern "C" s32 func_0040D2D8(void *);

extern "C" void MCarGarage__setGearAuto(void) {
    s16 arr[16];
    char buf[0x600];
    s32 holderbuf[4];
    s32 *holder=holderbuf;
    s32 s3;
    void *obj;
    s32 n;
    s16 *p;
    func_00128470(holder);
    obj = (void *)func_001324D8((void *)holder[0]);
    func_00128418(holder, 2);
    func_00408D48(func_00408B58(obj), buf);
    func_00405830(obj, func_00406158(obj));
    buf[0x156] = 1;
    func_002F8C40(buf, func_00406180(obj) * 10, arr, 0);
    s3 = 1;
    n = func_0040D2D8(func_00408B58(obj));
    if (n > 0) {
        p = &arr[1];
        do {
            s16 a = *p;
            p++;
            func_004057B0(obj, s3, a);
            s3++;
        } while (n >= s3);
    }
}
