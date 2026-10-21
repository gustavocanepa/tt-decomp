typedef float f32;

extern "C" void AutomaticFader__fadein(char *o, f32 t);

extern "C" void func_00372558(char *self) {
    f32 zero = 0.0f;
    AutomaticFader__fadein(self + 0x1490, zero);
    AutomaticFader__fadein(self + 0x1570, zero);
}
