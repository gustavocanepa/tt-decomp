/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int a,b; unsigned int c; };
struct Stream { unsigned int base,end,pos; };
extern "C" void func_00424318(Block *,Stream *) throw();
extern "C" void func_004243E0(Block *,Stream *) throw();
static inline bool eof(Stream *s) { return s->pos >= s->end; }
extern "C" Block *func_00424450(Block *out,Stream *s,int tag) {
    Block b;
    b.c=0;
    b.b=-1;
    b.a=0;
    while(!eof(s)) {
        func_00424318(&b,s);
        if(b.a==tag) {
            *out=b;
            goto done;
        }
        if(b.c<8) {
            out->b=-1;
            out->c=0;
            goto clear;
        }
        func_004243E0(&b,s);
    }
    out->c=0;
    out->b=-1;
clear:
    out->a=0;
done:
    return out;
}
