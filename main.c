#include <ntifs.h>

void AllocPool(SIZE_T allocSize) {
	PVOID pool = ExAllocatePoolWithTag(POOL_RAISE_IF_ALLOCATION_FAILURE, allocSize, 'Drvr');
	if (pool)
	{
		DbgPrint("Pool has been successfully made");

		ExFreePoolWithTag(pool, 'Drvr');
	}
	else
	{
		DbgPrint("Pool has not been created");
	}
}

DRIVER_INITIALIZE DriverEntry;

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	AllocPool(0x1024);

	return STATUS_SUCCESS;
}