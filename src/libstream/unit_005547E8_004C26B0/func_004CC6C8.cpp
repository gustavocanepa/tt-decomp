/* One work buffer of the movie decoder: requested size and the address it was given. */
struct WorkBuffer {
    int size;
    int addr;
};
extern WorkBuffer D_00779F80[7];

extern "C" void func_004BD8E8(int xbits, int ybits);
extern "C" int func_004BDC00(void);
extern "C" int func_004BDC18(void);
extern "C" int func_004CBB88(int size);

/* Size the decoder's seven work buffers for a width x height picture and allocate them.
 * A macroblock (16x16 pixels) takes 384 bytes: six 8x8 blocks of coefficients. */
extern "C" void func_004CC6C8(int width, int height) {
    int i;
    int macroblockBytes;

    func_004BD8E8(6, 14);
    macroblockBytes = ((width + 15) / 16) * ((height + 15) / 16) * 384;
    D_00779F80[0].size = 0xA000;
    D_00779F80[1].size = func_004BDC00();
    D_00779F80[2].size = func_004BDC18();
    D_00779F80[3].size = macroblockBytes;
    D_00779F80[4].size = macroblockBytes;
    D_00779F80[5].size = macroblockBytes;
    D_00779F80[6].size = width * height * 8;
    for (i = 0; i < 7; i++)
        D_00779F80[i].addr = func_004CBB88(D_00779F80[i].size);
}
