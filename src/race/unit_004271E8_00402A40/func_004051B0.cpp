struct Rec {
    int word;
    unsigned int pad1 : 24;
    int kind : 8;
    int pad[2];
};

extern "C" void *func_00408B58(void);
extern "C" int func_0040D640(void *self, Rec *rec);
extern "C" float func_00405110(int id);

extern "C" float func_004051B0(void) {
    Rec rec;
    if (!func_0040D640(func_00408B58(), &rec))
        return 0.0f;
    int hidden = (rec.word >> 26) & 1;
    int on = rec.kind & 1;
    float v = func_00405110(rec.word & 0xFFFFFF);
    return v + ((!hidden && on) ? 1.0f : 0.0f);
}
