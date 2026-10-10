extern "C" void func_003C8888(void *self, int index, int value);

extern "C" void func_003C9758(void *self, int value) {
    func_003C8888(self, 0, value);
    func_003C8888(self, 1, value);
    func_003C8888(self, 2, value);
}
