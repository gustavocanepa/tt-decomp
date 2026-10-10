struct Obj {
    int m0;
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08();
    virtual void set(int value);
};

/* A handle class named after its destructor (func_00215EC8) so that _$_13func_00273CA0
   resolves; its constructor (func_00216300) is called explicitly. */
struct func_00215EC8 {
    Obj *p;
    ~func_00215EC8();
};

extern "C" void func_00216300(func_00215EC8 *h);

/* The result class, named after its constructor so that __13func_0021D810... resolves. */
struct func_001CFEA8 {
    int m0;
    func_001CFEA8(func_00215EC8 *h);
    func_001CFEA8(const func_001CFEA8 &o);
};

func_001CFEA8 func_001CB078(int value)
{
    func_00215EC8 h;
    func_00216300(&h);
    h.p->set(value);
    return func_001CFEA8(&h);
}
