struct func_0043DEF8_Any {
    unsigned int type;
    union {
        int i;
        float f;
        char *s;
    };
};

extern "C" void func_0043D738(func_0043DEF8_Any *self, const char *s);
extern "C" void func_0043D6E8(func_0043DEF8_Any *self, const char *s);
extern "C" int func_004A6500(char *buf, const char *fmt, ...);
extern "C" double func_004B4C18(float f);

extern "C" char *strobe__Any__toString(func_0043DEF8_Any *self) {
    switch (self->type) {
    case 0:
        func_0043D738(self, "Null");
        break;
    case 1:
        func_0043D738(self, "");
        break;
    case 3:
    case 4:
        break;
    case 5:
        func_0043D738(self, self->i ? "true" : "false");
        break;
    case 6: {
        char buf[16];
        float f = self->f;
        int i = (int)f;
        if (f == (float)i) {
            func_004A6500(buf, "%d", i);
        } else {
            const char *fmt = "%f";
            double d = func_004B4C18(f);
            func_004A6500(buf, fmt, d);
        }
        func_0043D6E8(self, buf);
        break;
    }
    case 13:
        func_0043D738(self, "[type Function]");
        break;
    case 7:
        func_0043D738(self, "[object Object]");
        break;
    default:
        func_0043D738(self, "[internal object]");
        break;
    }
    if (self->type == 3) return self->s + 2;
    return self->s;
}
