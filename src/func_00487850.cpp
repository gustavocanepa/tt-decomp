/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf;
struct Node { int color; Node *parent,*left,*right; unsigned key; Buf *value; };
struct Value;
struct It {
    Node *n;
    It():n(0) {}
    It(Node *p):n(p) {}
    It(const It &o):n(o.n) {}
    Value &operator*() const;
};
struct Value { unsigned key; Buf *value; Value(unsigned k, Buf *v):key(k),value(v) {} };
inline Value &It::operator*() const { return *(Value *)&n->key; }
struct Tree { int alloc; Node *header; unsigned count; It insert(It,const Value &); };
extern "C" int func_004877A8(void *) throw();
extern "C" Buf *func_004876F0(void *,unsigned) throw();
extern "C" int func_00487640(void *,Buf *,int) throw();
extern "C" void func_00487968(void *,Buf *);
extern "C" It func_0056F5B8(Tree *,const unsigned &);
extern "C" It func_0056F600(Tree *,It,const Value &);
inline It Tree::insert(It pos,const Value &v) { return func_0056F600(this,pos,v); }
static inline bool equal(const It &a,const It &b) { return a.n == b.n; }
static inline unsigned keyOf(const It &i) { return i.n->key; }
static inline Buf *&access(Tree *t, unsigned &key) {
    It i = func_0056F5B8(t,key);
    It end(t->header);
    int flag = 0;
    if (equal(i,end) || key < keyOf(i)) flag = 1;
    if (flag) i = t->insert(i,Value(key,0));
    return (*i).value;
}
extern "C" Buf *func_00487850(char *self,unsigned key) {
    int status = func_004877A8(self);
    if (status == 0) {
        Buf *r = func_004876F0(self,key);
        if (func_00487640(self,r,1) == 0) {
            func_00487968(self,r);
            return 0;
        }
        access((Tree *)(self+12),key) = r;
        return r;
    }
    return (Buf *)status;
}
