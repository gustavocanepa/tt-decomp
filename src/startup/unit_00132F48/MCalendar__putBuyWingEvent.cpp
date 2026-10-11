struct Str {
    char *p;
    int length() const { return ((int *)p)[-4]; }
    const char *c_str() const {
        if (length() == 0)
            return "";
        p[length()] = 0;
        return p;
    }
};

struct Data { char pad[0x10]; int id; };

extern "C" void func_00120608(void *self, void *src);
extern "C" void func_001205B0(void *self, int flags);
extern "C" void func_002ADC48(void *self, void *argv);
extern "C" void func_002ADBF0(void *self, int flags);
extern "C" Str *func_002AFE68(void *rep);
extern "C" void func_003F6C80(int id, const char *name);

extern "C" void MCalendar__putBuyWingEvent(void *ret, void *self, int argc, void *argv) {
    if (argc > 0) {
        int buf[4];
        int id;
        func_00120608(buf, self);
        id = ((Data *)buf[0])->id;
        func_001205B0(buf, 2);
        func_002ADC48(buf, argv);
        func_003F6C80(id, func_002AFE68((void *)buf[0])->c_str());
        func_002ADBF0(buf, 2);
    }
}
