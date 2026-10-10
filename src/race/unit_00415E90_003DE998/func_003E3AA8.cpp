extern "C" void *func_003E4710(void *self, int i);
extern "C" void func_003E1528(void *item, void *data);

extern "C" void func_003E3AA8(void *self, char *data) {
    for (int i = 0; i < 20; i++) {
        func_003E1528(func_003E4710(self, i), data);
        data += 0x40;
    }
}
