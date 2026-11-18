/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 D_007A5F60[];
u16 func_004C0A40(u32 arg0, u32 arg1) {
    u16 *p = (u16 *)((char *)D_007A5F60 + ((arg1 & 0xFFFF) << 2));
    return arg0 & 0x22 ? p[1] : p[0];
}
