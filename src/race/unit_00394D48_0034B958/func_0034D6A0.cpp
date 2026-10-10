struct Str;
struct Obj;

extern "C" Str *func_004F7B74(Str *s, const char *t);
extern "C" Str *func_004F7A30(Str *s, const char *t);
extern "C" const char *func_0034D680(Obj *o);

extern const char *D_00584070[];
extern int D_00584084;
extern const char D_005F4160[];

extern "C" Str *func_0034D6A0(Obj *o, Str *s) {
    func_004F7B74(s, D_00584070[D_00584084]);
    func_004F7A30(s, D_005F4160);
    func_004F7A30(s, func_0034D680(o));
    return s;
}
