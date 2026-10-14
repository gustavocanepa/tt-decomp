struct Blob { char d[0xD9]; };

extern "C" void func_00413D40(Blob *dst, Blob *src) {
    *dst = *src;
}
