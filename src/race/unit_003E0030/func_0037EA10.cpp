struct Strings { char pad[0x138]; const char *one; const char *many; };
extern Strings *D_00584418;
extern const char D_005F7418[];
struct Label { int m0; char text[0xB0]; int dirty; };
extern "C" int func_004A6500(char *, const char *, ...);
extern "C" char *func_004F7A30(char *, const char *);

extern "C" void func_0037EA10(Label *l, int n, int plus)
{
    func_004A6500(l->text, D_005F7418, plus ? '+' : ' ', n);
    func_004F7A30(l->text, n < 2 ? D_00584418->one : D_00584418->many);
    l->dirty = 1;
}
