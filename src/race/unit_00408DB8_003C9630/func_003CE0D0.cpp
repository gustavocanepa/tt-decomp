/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {
    char p0[8];
    float f8, fC, f10, f14, f18, f1C;
    char p20[0x48 - 0x20];
    float f48;
    int f4C;
};
extern "C" void func_00423BB0(void *, int);
extern "C" void func_00423BD0(void *, int);
extern "C" void GT4Model__BinStreamWriter__writeFloat(void *, float);
inline const int &mn(const int &a, const int &b) { return (b < a) ? b : a; }
inline const int &mx(const int &a, const int &b) { return (a < b) ? b : a; }

extern "C" void func_003CE0D0(Self *self, void *out, int base) {
    func_00423BD0(out, ((self->f4C - base - 0xC) >> 2) * 0x4F72C235);
    func_00423BB0(out, (int)(self->f8 * 128.0f / 0x1.921fb4p+1f));
    func_00423BB0(out, (int)(self->fC * 128.0f / 0x1.921fb4p+1f));
    func_00423BB0(out, (int)(self->f10 * 128.0f / 0x1.921fb4p+1f));
    GT4Model__BinStreamWriter__writeFloat(out, self->f14);
    GT4Model__BinStreamWriter__writeFloat(out, self->f18);
    GT4Model__BinStreamWriter__writeFloat(out, self->f1C);
    int t = (int)(self->f48 * 255.0f);
    func_00423BB0(out, mx(mn(t, 255), 0));
}
