extern "C" char *func_004A45F8(int size);
extern "C" void func_004E5D18(void *self, char *begin, char *end, int own);

extern "C" int func_004E61F8(void *self) {
    char *buf = func_004A45F8(0x400);
    if (buf == 0) {
        return -1;
    }
    func_004E5D18(self, buf, buf + 0x400, 1);
    return 1;
}
