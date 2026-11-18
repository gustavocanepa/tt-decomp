/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Table { int count; void *items[1]; };
struct Self { char pad[0x14]; Table *table; };
extern "C" void func_0034D9E0(void *, void *);
extern "C" void func_0034D928(Self *self, void *ctx, int index) {
    Table *table=self->table;
    if (table) {
        if (index<0) {
            for (int i=0; i<self->table->count; i++) {
                void *p=self->table->items[i];
                if (p) func_0034D9E0(p,ctx);
            }
        } else if(index<table->count) {
            void *p=table->items[index];
            if (p) func_0034D9E0(p,ctx);
        }
    }
}
