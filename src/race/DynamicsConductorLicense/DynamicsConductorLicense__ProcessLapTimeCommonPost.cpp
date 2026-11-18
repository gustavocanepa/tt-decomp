/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0x23968]; int count; };
extern "C" void *func_002F04D8(Self *, int);
extern "C" void func_003A5358(Self *, void *);
extern "C" int func_002FBCD8(Self *);
extern "C" int DynamicsConductorLicense__ProcessLapTimeCommonPost(Self *self) {
    for (int i = 0; i < self->count; i++) {
        func_003A5358(self, func_002F04D8(self, i));
    }
    return func_002FBCD8(self);
}
