struct Entry { char d[0x24]; };
struct Out { int a, b, c, d; };
extern "C" unsigned int getNumber(void *p);
extern "C" int func_0042DC10(Entry *e);
extern Entry D_0076BD00[];

extern "C" void func_0042E7B0(void *p, Out *out)
{
    unsigned int v = getNumber(p);
    out->a = func_0042DC10(&D_0076BD00[v >> 24]);
    out->b = (v >> 16) & 0xFF;
    out->c = (v >> 8) & 0xFF;
    out->d = v & 0xFF;
}
