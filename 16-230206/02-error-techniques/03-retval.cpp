#include <sqlite3.h>
#include <iostream>

// https://www.sqlite.org/c3ref/open.html
// int sqlite3_open(
//   const char *filename,   /* Database filename (UTF-8) */
//   sqlite3 **ppDb          /* OUT: SQLite db handle */
// );

int main() {
    sqlite3 *db;
    if (int err = sqlite3_open("does-not-exist/some-db.sqlite3", &db); err != SQLITE_OK) {  // Still easy to forget to check, but syntax is ugly.
        std::cout << "err = " << err << " " << sqlite3_errstr(err) << "\n";
        if (err == SQLITE_CANTOPEN) {
            std::cout << "Unable to open DB file\n";
        }
        return 1;
    }
    sqlite3_close(db);
    return 0;
}
