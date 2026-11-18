/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reads the next batch of directory records from src (16 at a time, or one named entry in mode 8), wraps each one as an Entry (func_00199CA8) and keeps up to 400 accepted ones; counts the calls that found nothing. */
typedef int s32;

template <class _Tp1> struct auto_ptr_ref {
    _Tp1 *_M_ptr;
    auto_ptr_ref(_Tp1 *__p) : _M_ptr(__p) {}
};

template <class _Tp> class auto_ptr {
private:
    _Tp *_M_ptr;
public:
    typedef _Tp element_type;
    explicit auto_ptr(_Tp *__p = 0) : _M_ptr(__p) {}
    auto_ptr(auto_ptr &__a) : _M_ptr(__a.release()) {}
    auto_ptr &operator=(auto_ptr &__a) {
        if (&__a != this) {
            delete _M_ptr;
            _M_ptr = __a.release();
        }
        return *this;
    }
    ~auto_ptr() { delete _M_ptr; }
    _Tp &operator*() const { return *_M_ptr; }
    _Tp *operator->() const { return _M_ptr; }
    _Tp *get() const { return _M_ptr; }
    _Tp *release() {
        _Tp *__tmp = _M_ptr;
        _M_ptr = 0;
        return __tmp;
    }
    auto_ptr(auto_ptr_ref<_Tp> __ref) : _M_ptr(__ref._M_ptr) {}
    template <class _Tp1> operator auto_ptr_ref<_Tp1>() { return auto_ptr_ref<_Tp>(this->release()); }
};

struct Rec { char b[64]; };

struct Entry {
    char data[0x4C];
    virtual ~Entry();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual s32 accepts(void *filter);
};

struct Source {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual s32 failed();
    virtual void v5();
    virtual s32 acceptAll();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual s32 list(char *path, Rec *out, s32 start, s32 count);
};

struct Self {
    char pad0[0x30];
    Source *src;
    auto_ptr<Entry> entries[400];
    s32 count;
    void *table;
    char pad67C[0x69C - 0x67C];
    s32 misses;
    s32 mode;
    char dir[0x24];
    s32 pos;
    char pad6CC[4];
    char filter[4];
};

extern "C" void func_00198598(void *, s32);
extern "C" void *func_00198600(void *, s32, void *);
extern "C" auto_ptr<Entry> func_00199CA8(Self *, char *);

extern "C" void func_001991D8(Self *self) {
    Rec recs[16];
    char path[0x30];
    char *p;
    if (self->mode != 0) {
        s32 n = 0;
        if (self->table != 0 && self->mode == 8) {
            path[0] = '/';
            p = path + 1;
            if (func_00198600(self->table, self->pos, p) != 0) {
                n = self->src->list(path, recs, 0, 1);
                if (n == 0) {
                    func_00198598(self->table, self->pos);
                    return;
                }
            }
        } else {
            n = self->src->list(self->dir, recs, self->pos, 0x10);
        }
        if (self->src->failed() != 0) return;
        self->pos += n;
        for (s32 i = 0; i < n; i++) {
            p = recs[i].b;
            auto_ptr<Entry> e(func_00199CA8(self, p));
            if (self->count < 400 && e.get() != 0) {
                if (self->src->acceptAll() != 0 || e->accepts(self->filter) != 0) {
                    self->entries[self->count] = e;
                    self->count++;
                }
            }
        }
        if (n != 0) return;
    }
    self->misses++;
}
