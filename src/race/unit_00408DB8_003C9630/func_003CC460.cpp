extern "C" void func_003CC560(void *self, int arg, int count);

extern "C" void func_003CC460(void *self, int arg) {
    for (int i = 0; i < 20; i++)
        func_003CC560(self, arg, i);
}
