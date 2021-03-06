#include <string>
#include <init.h>
#include <config.h>
#include <error.h>
#include <DbStore.h>
#include <Cdobs.h>

/* Inits DbStore object, passes it to cdobs,
 * and return the cdobs object */
int init_cdobs (Cdobs **cdobs, string &err_msg) {
	DbStore *store = new DbStore();
	// Init the DbStore object
	int rc = store->init(SQLITE_DB_FILE);
	if (rc) {
		err_msg = ERR_DB_NOINIT;
		return 1;
	}
	// Init Cdobs
	*cdobs = new Cdobs(store);
	if (!(*cdobs)->good()) {
		err_msg = ERR_CDOBS_NOINIT;
		return 1;
	}
	return 0;
}