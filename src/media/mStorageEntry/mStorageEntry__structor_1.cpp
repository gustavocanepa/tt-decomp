struct Base0 {
    int m0;
};
/* hObject: its constructor is func_002A7618 */
struct func_002A7618 : Base0 {
    func_002A7618();
    virtual ~func_002A7618();
};
struct Data {
    long w[0xA8 / 8];
};
struct mStorageEntry : func_002A7618 {
    int m8;
    int mC;
    Data data;
    mStorageEntry(const Data &d);
    virtual ~mStorageEntry();
};

mStorageEntry::mStorageEntry(const Data &d) : data(d) {}
