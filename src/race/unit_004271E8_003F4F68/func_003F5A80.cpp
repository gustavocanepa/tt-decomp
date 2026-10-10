struct Rect { char pad[0x1C]; float x, y, w, h; };
extern "C" void func_00477DC0(unsigned int color);
extern "C" void func_004702D8(int mode, float v);
extern "C" void func_00472268(int a, int b);
extern "C" void func_003F5508(void *ctx, float x, float y, float w, float h);

extern "C" void func_003F5A80(Rect *r, void *ctx)
{
    func_00477DC0(0x80FFFFFF);
    func_004702D8(0x48, 0.0f);
    func_00472268(2, 1);
    func_00472268(3, 1);
    func_003F5508(ctx, r->x, r->y, r->w, r->h);
}
