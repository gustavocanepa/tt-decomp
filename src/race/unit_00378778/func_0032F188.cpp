extern "C" int func_002FED98(void *car);
extern "C" void func_003BC7D8(void *self, float x, float y, float z);
extern "C" void func_003C17A0(void *self, float x, float y, float z);

extern "C" void func_0032F188(void *self, void *car, float x, float y, float z) {
    switch (func_002FED98(car)) {
    case 0:
        break;
    case 1:
        return func_003BC7D8(self, x, y, z);
    }
    return func_003C17A0(self, x, y, z);
}
