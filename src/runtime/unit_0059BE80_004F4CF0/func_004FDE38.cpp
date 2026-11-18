/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Round-robin slot allocator: returns the next 64-byte slot of the pool. */
struct SlotPool {
	char pad0[0x14];
	char *slots;
	int slotCount;
	char pad1[0x24 - 0x1C];
	int next;
};

extern "C" char *func_004FDE38(SlotPool *pool)
{
	int index = pool->next % pool->slotCount;
	char *slot;
	slot = pool->slots + index * 64;
	pool->next = index + 1;
	return slot;
}
