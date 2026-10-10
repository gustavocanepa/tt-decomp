/* Real C++ constructor: the compiler stores the vtable (_vt$10D_00689AE0, the vptr follows the
   data at 0x64) before constructing the member at 0, then the body clears the fields. */
class func_004C5128 {
public:
    func_004C5128();
    int v[10];
};

class D_005DB2A0 {
public:
    D_005DB2A0();
    virtual void f0();

    func_004C5128 base;
    unsigned long time;
    int slots[11];
    int current;
    int count;
};

D_005DB2A0::D_005DB2A0()
{
    time = 0;
    current = -1;
    slots[0] = 0;
    slots[1] = 0;
    slots[2] = 0;
    slots[3] = 0;
    slots[4] = 0;
    slots[5] = 0;
    slots[6] = 0;
    slots[7] = 0;
    slots[8] = 0;
    slots[9] = 0;
    slots[10] = 0;
    count = 0;
}
