typedef unsigned int u32;
typedef unsigned short u16;

extern "C" void func_0029F9D0(void *stream, u16 v);

extern "C" void func_0029FA10(void *stream, u32 v) {
    func_0029F9D0(stream, v);
    func_0029F9D0(stream, v >> 16);
}
