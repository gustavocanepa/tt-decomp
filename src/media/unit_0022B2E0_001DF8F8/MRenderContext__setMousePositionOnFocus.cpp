extern "C" void func_001DF1F8(void *, int) throw();
extern "C" void func_001DF250(void *, void *) throw();
extern "C" void func_001E4438(void *, void *);
extern "C" void func_001E6428(void *, int);
extern "C" void func_001E6480(void *, void *);
extern "C" void MRenderContext__setMousePositionOnFocus(void *unused, void *source, int n, void *name) {
    void *buf[4];
    void *v = 0;
    if (n > 0) {
        func_001E6480(buf, name);
        v = buf[0];
        func_001E6428(buf, 2);
    }
    func_001DF250(buf, source);
    func_001E4438(buf[0], v);
    func_001DF1F8(buf, 2);
}
