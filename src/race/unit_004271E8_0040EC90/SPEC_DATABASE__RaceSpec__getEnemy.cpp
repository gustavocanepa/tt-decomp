typedef long long s64;
struct RaceSpec;
extern "C" int func_0040EFA8(RaceSpec *, int);
extern "C" int func_0040C0E0(void *, int);
extern "C" s64 func_0040F000(RaceSpec *, int);
extern "C" void func_0040D3D8(void *, int);

extern "C" int SPEC_DATABASE__RaceSpec__getEnemy(RaceSpec *s, int idx, void *out)
{
    int r = func_0040C0E0(out, func_0040EFA8(s, idx));
    s64 id = func_0040F000(s, idx);
    if (id != -1) func_0040D3D8(out, id - 1);
    else func_0040D3D8(out, -1);
    return r;
}
