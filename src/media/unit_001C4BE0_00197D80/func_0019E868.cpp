struct Self { char pad[0x24]; char name[1]; };
extern char D_005E6BD8[];
extern "C" int func_004A6500(char *, const char *, ...);

extern "C" char *func_0019E868(Self *self, char *buf) {
    func_004A6500(buf, D_005E6BD8, self->name);
    return buf;
}
