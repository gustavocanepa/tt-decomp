typedef int s32;

struct Blob { long long d[258]; };

extern "C" void func_002CFED8(void *, float);
extern "C" void func_0042B7C0(void *);

extern "C" void func_002CFA08(char *arg0) {
    *(Blob *)(arg0 + 0x9D8) = *(Blob *)(arg0 + 0x1C8);
    *(s32 *)(arg0 + 0x34) = 0;
    func_0042B7C0(arg0 + 0x18);
    func_002CFED8(arg0, 1.0f);
}
