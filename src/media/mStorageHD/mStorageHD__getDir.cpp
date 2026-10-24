/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long u64;

/* sceIoDirent of the HDD file system */
struct Dirent {
    s32 mode;
    u32 attr;
    u32 size;
    u8 ctime[8];
    u8 atime[8];
    u8 mtime[8];
    u32 hisize;
    u32 priv[6];
    char name[256];
    void *pdata;
};

struct Date {
    s16 year;
    u8 month;
    u8 day;
    u8 hour;
    u8 minute;
    u8 second;
};

struct Entry {
    u64 other : 3;
    u64 group : 3;
    u64 user : 3;
    u64 dir : 1;
    u64 reg : 1;
    u64 link : 1;
    Date ctime;
    Date atime;
    Date mtime;
    u64 size;
    char name[128];
};

struct Item {
    void *p;
    Item(const Item &);
    ~Item() __asm__("func_00283D10");
};

struct Result {
    void *p;
    Result(const Result &);
    ~Result() __asm__("func_002A75A8");
};

struct Array {
    Result push(const Item &) __asm__("func_002944D0");
};

struct List {
    Array *p;
    List() __asm__("func_00295180");
    List(const List &) __asm__("func_002A7590");
    ~List() __asm__("func_002931C8");
    Array *operator->() { return p; }
};

extern char D_005EA700[], D_005EA708[], D_005EA710[], D_005EA718[];
extern "C" s32 func_004A8368(const char *) throw();
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" void func_001F07E0(Date *, u8 *) throw();
extern "C" void func_004A6500(char *, const char *, ...);
extern "C" s32 func_005011D0(const char *);
extern "C" s32 func_00501400(s32, Dirent *);
extern "C" s32 func_00501298(s32);
extern "C" char *func_004F7B74(char *, const char *) throw();
Item func_00284798(Entry *) __asm__("func_00284798");

extern "C" List mStorageHD__getDir(void *self, const char *path, const char *suffix) {
    if (suffix == 0)
        suffix = D_005EA710;
    s32 len = func_004A8368(suffix);
    List list;
    char fullpath[128];

    func_004A6500(fullpath, D_005EA700, D_005EA708, path);
    s32 fd = func_005011D0(fullpath);
    if (fd >= 0) {
        Dirent dir;
        Dirent *pd = &dir;
        s32 n;

        /* Entered at the func_005AE2E8: loop.c ignores this loop (multiple entry points), so nothing in
           the body is hoisted, as in the original; while/for/do forms all hoist. */
        goto next;
        for (;;) {
            {
                s32 isdir = (pd->mode >> 12) & 1;

                if (n == 1 && dir.name[0] == '.')
                    goto next;
                if (n == 2 && func_004A8268(dir.name, D_005EA718) == 0)
                    goto next;
                if (!isdir) {
                    if (n < len)
                        goto next;
                    if (func_004A8268(suffix, pd->name + n - len) != 0)
                        goto next;
                }
                Entry e;
                Entry *pe = &e;

                func_004F7B74(e.name, dir.name);
                e.other = pd->mode & 7;
                e.group = ((u32)pd->mode >> 3) & 7;
                e.user = ((u32)pd->mode >> 6) & 7;
                e.dir = isdir;
                e.reg = (pd->mode >> 13) & 1;
                e.link = (pd->mode >> 14) & 1;
                e.size = (u64)dir.size + ((u64)dir.hisize << 32);
                func_001F07E0(&e.ctime, dir.ctime);
                func_001F07E0(&e.atime, dir.atime);
                func_001F07E0(&e.mtime, dir.mtime);
                list->push(func_00284798(pe));
            }
        next:
            n = func_00501400(fd, pd);
            if (n <= 0)
                break;
        }
        func_00501298(fd);
    }
    return list;
}
