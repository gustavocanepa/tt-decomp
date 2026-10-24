/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Font { int f0; int mode; };
struct Self {
    unsigned char p0, fx, fy, p3;
    short x, y;
    char pad8[4];
    float alpha;
    char pad10[8];
    char *title;
    char *artist;
    char pad20[8];
    float fade;
};

extern Font D_00585CC8;
extern char D_005F5A18[];
extern char D_005F5A20[];
extern char D_005F5A28[];
extern char D_005F5A30[];

extern "C" {
float RaceDisplayUtil__wideOffset(int);
unsigned int func_0038F5F8(unsigned int, float);
void func_00415510(Font *, const char *);
void func_00415578(Font *);
void func_004157B0(Font *, float, float);
void func_00415A10(Font *, float, float, float);
void func_00415B10(Font *, unsigned int);
void func_00415C30(Font *, float);
void GT3OLDFONT__GT3OldFontManagerClass__putstring(Font *, const char *);
}

extern "C" void RaceMusicDisplay__render_main(Self *self) {
    float a = self->fade * self->alpha;
    if (a <= 0.0f)
        return;
    func_00415B10(&D_00585CC8, func_0038F5F8(0x80C8C8C8, a));
    D_00585CC8.mode = 0;
    func_00415C30(&D_00585CC8, 2.0f);
    float x = (float)self->x + RaceDisplayUtil__wideOffset(4);
    if (self->title) {
        func_00415510(&D_00585CC8, D_005F5A18);
        func_004157B0(&D_00585CC8, 1.0f, 1.0f);
        func_00415A10(&D_00585CC8, x - 16.0f, (float)self->y, 0.0f);
        GT3OLDFONT__GT3OldFontManagerClass__putstring(&D_00585CC8, D_005F5A20);
        func_00415510(&D_00585CC8, D_005F5A28);
        func_004157B0(&D_00585CC8, 0x1.ccccccp-1f, 0x1.ccccccp-1f);
        func_00415A10(&D_00585CC8, x, (float)self->y, 0.0f);
        GT3OLDFONT__GT3OldFontManagerClass__putstring(&D_00585CC8, self->title);
        if (self->artist) {
            func_00415510(&D_00585CC8, D_005F5A30);
            func_004157B0(&D_00585CC8, 0x1.666666p-1f, 0x1.666666p-1f);
            func_00415A10(&D_00585CC8, x, (float)(self->y + 18), 0.0f);
            GT3OLDFONT__GT3OldFontManagerClass__putstring(&D_00585CC8, self->artist);
        }
    }
    func_004157B0(&D_00585CC8, 1.0f, 1.0f);
    func_00415C30(&D_00585CC8, 0.0f);
    func_00415578(&D_00585CC8);
}
