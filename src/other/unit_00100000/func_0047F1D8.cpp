struct Mgr {
    char pad[0xA4];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18();
    virtual int v19(int a, int b, int c);
};
extern "C" Mgr *func_0047F398(void);

extern "C" int func_0047F1D8(int a, int b)
{
    return func_0047F398()->v19(a, b, 1);
}
