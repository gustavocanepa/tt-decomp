extern "C" int func_00502F00(const char *name);
extern "C" int func_004A9150(int fd, void *buf, int size);

extern "C" int func_004A9190(const char *name, void *buf, int size) {
    int fd = func_00502F00(name);
    if (fd < 0)
        return -1;
    return func_004A9150(fd, buf, size);
}
