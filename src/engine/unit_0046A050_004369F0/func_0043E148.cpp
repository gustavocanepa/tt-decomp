struct func_0043E148_Rep {
    int len;
    int cap;
    int ref;
    int sel;
};

struct func_0043E148_Str {
    char *p;
    func_0043E148_Rep *rep() const { return (func_0043E148_Rep *)(p - 0x10); }
    unsigned int length() const { return rep()->len; }
    const char *c_str() const {
        if (length() == 0) return "";
        p[length()] = 0;
        return p;
    }
};

struct func_0043E148_Value {
    int type;
    union {
        float f;
        int i;
        void *p;
        char *s;
    };
};

struct func_0043E148_Node {
    int type;
    union {
        char *s;
        int *map;
        void *p;
    };
};

extern "C" unsigned int func_004A8368(const char *s);
extern "C" int func_005507D8(const func_0043E148_Str *self, const char *s, unsigned int pos, unsigned int n);
extern "C" func_0043E148_Value *func_00447FB0(void *map, const func_0043E148_Str *name);
extern "C" void func_0043D3B8(func_0043E148_Value *self, const func_0043E148_Value *other);
extern "C" func_0043E148_Value *func_004415A8(void *p);
extern "C" void func_004424D8(func_0043E148_Value *ret, void *p, const func_0043E148_Str *name);
extern "C" void func_00443750(func_0043E148_Value *ret, void *p, const func_0043E148_Str *name);
extern "C" void func_00443008(func_0043E148_Value *ret, const func_0043E148_Str *name);
extern "C" void func_004433B8(func_0043E148_Value *ret, const func_0043E148_Str *name);
extern "C" int func_004A6448(const char *fmt, ...);

static inline int compare(const func_0043E148_Str *s, const char *t) {
    return func_005507D8(s, t, 0, func_004A8368(t));
}

extern "C" func_0043E148_Value *func_0043E148(func_0043E148_Value *ret, func_0043E148_Node *node, const func_0043E148_Str *name) {
    switch (node->type) {
    case 7: {
        func_0043E148_Value *v = func_00447FB0(node->map + 1, name);
        if (v != 0) {
            func_0043D3B8(ret, v);
        } else {
            ret->type = 1;
        }
        break;
    }
    case 13:
        if (compare(name, "PROTOTYPE") == 0) {
            func_0043D3B8(ret, func_004415A8(node->p));
            break;
        }
        func_004A6448("\xcc\xa4\xc4\xea\xb5\xc1\xa4\xce\xa5\xe1\xa5\xf3\xa5\xd0 %s \xa4\xac\xbb\xb2\xbe\xc8\xa4\xb5\xa4\xec\xa4\xde\xa4\xb7\xa4\xbf.\n", name->c_str());
        ret->type = 1;
        break;
    case 10:
        func_004424D8(ret, &node->p, name);
        break;
    case 11:
        func_00443750(ret, &node->p, name);
        break;
    case 8:
        func_00443008(ret, name);
        break;
    case 3:
        if (compare(name, "LENGTH") == 0) {
            ret->f = (float)func_004A8368(node->s + 2);
            ret->type = 6;
            break;
        }
    case 4:
        if (compare(name, "LENGTH") == 0) {
            ret->f = (float)func_004A8368(node->s);
            ret->type = 6;
            break;
        }
    case 9:
        func_004433B8(ret, name);
        break;
    default:
        func_004A6448("\xcc\xa4\xc4\xea\xb5\xc1\xa4\xce\xa5\xe1\xa5\xf3\xa5\xd0 %s \xa4\xac\xbb\xb2\xbe\xc8\xa4\xb5\xa4\xec\xa4\xde\xa4\xb7\xa4\xbf.\n", name->c_str());
        ret->type = 1;
        break;
    }
    return ret;
}
