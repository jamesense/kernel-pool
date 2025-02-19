#include <ntifs.h>

PVOID AllocPool(SIZE_T allocSize, ULONG Tag) {
	PVOID pool = ExAllocatePoolWithTag(NonPagedPool, allocSize, Tag);
	if (pool) {
		DbgPrint("Pool has been successfully allocated at %p", pool);
	}
	else {
		DbgPrint("Pool allocation failed");
	}
	return pool;
}

void FreePool(PVOID pool, ULONG Tag) {
	if (pool) {
		DbgPrint("Freeing pool at %p", pool);
		ExFreePoolWithTag(pool, Tag);
	}
}

DRIVER_INITIALIZE DriverEntry;

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	PVOID pool0001 = AllocPool(0x1024, '0001');
	if (pool0001)
	{
		DbgPrint("Hello from pool!!!");
		strcpy((char*)pool0001, "Hello dudes!!");

		DbgPrint("%s", (char*)pool0001); //prints out the string that we passed into the pool

		FreePool(pool0001, '0001');
	}

	return STATUS_SUCCESS;
}
