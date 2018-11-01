//
//  main.cpp
//  testMakeSQL
//
//  Created by Clifford Campo on 10/26/18.
//  Copyright © 2018 CliffordCampo. All rights reserved.
//
//   /Users/cjc/c++/MakeSQL_Library/MakeSQL/MakeSQL
#include <iostream>
//The next 2 include statements refer to headers (classes) used by dynamic library found at: \
/Users/cjc/Library/Developer/Xcode/DerivedData/Build/Products/Debug/libMakeSQL.dylib
#include "/Users/cjc/c++/playingWithContainers-r2/playingWithContainers-r2/playingWithContainers-rev2/makesql.hpp"
//#include "/Users/cjc/c++/MakeSQL_Library/MakeSQL/MakeSQL/MakeSQL.hpp"
//#include "/Users/cjc/c++/MakeSQL_Library/MakeSQL/MakeSQL/MakeSQLPriv.hpp"
#ifdef DLOPEN
#include <dlfcn.h>
#endif
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
#ifdef DLOPEN
    struct dl_info dli;
    dl_info *info;
    info = &dli;
#endif
    int rc = 0;
//    void *h;
//    bool b = false;
//    Dl_info* Info;
    std::cout << "Hello, " << *(argv + 0) << "!\n";
    const char *outputFile = "/tmp/result.sql";
    const char *prototypeFile = "/Users/cjc/sql/computeEnergyUsage.sql";
    char debugCharacter = '\0';
    const char *vectorSize = "5";
#ifdef DLOPEN
//    const char *file =  "/Users/cjc/Library/Developer/Xcode/DerivedData/Build/Products/Debug/libMakeSQL.dylib";
    const char *file = "/Users/cjc/Library/Developer/Xcode/DerivedData/Build/Products/Debug/libmakesql.dylib";
    b = dlopen_preflight(file);
    if (b) {
        cout << "dlopen_prefilight(\"" << file << "\"); indicates good-to-go" << endl;
    } else {
        cout << "dlopen_prefilight(\"/Users/cjc/Library/Developer/Xcode/DerivedData/Build/Products/Debug/libMakeSQL.dylib\"); indicates error of: "<< dlerror() << endl;
    }
    if (b) {
        //    h = dlopen("/Users/cjc/Library/Developer/Xcode/DerivedData/Build/Products/Debug/libMakeSQL.dylib", RTLD_LAZY|RTLD_NODELETE);
        makeSQL *msql = (makeSQL *)dlopen(file, RTLD_LAZY);
        rc = dladdr(msql, info);

            cout << "pathname of the shared object containing the address: " << info->dli_fname;
            cout << "\nbase address (mach_header) at which the image is mapped into the address space of the calling process: " << info->dli_fbase;
            cout << "\nname of the nearest run-time symbol with a value less than or equal to addr: " << info->dli_sname;
            cout << "\nvalue of the symbol returned in dli_sname: " << info->dli_saddr << endl;
        //    msql->HelloWorld(*(argv + 0) );
        rc = dlclose(msql);
    }
    if(rc != 0) {
        cout << "dlclose(h) reported the following error: " << dlerror () << endl;
    }

/*
makeSQL ("/Users/cjc/c++/playingWithContainers-r2/playingWithContainers-r2/playingWithContainers-r2/prototype.sql","/tmp/outfile");
*/
#endif
    if (argc == 1) {
        ;
// no default overrides
    } else if (argc == 2) {
// prototype file supplied
        prototypeFile = *(argv + 1);
    } else if (argc == 3) {
// prototype file and output file supplied
        prototypeFile = *(argv + 1);
        outputFile = *(argv + 2);
    } else if (argc == 4) {
// prototyp file, output file, and debug flag supplied
        prototypeFile = *(argv + 1);
        outputFile = *(argv + 2);
        debugCharacter = 'x';
    } else {
// prototype file, outputfile, debug flag, and vector supplied supplied;
        prototypeFile = *(argv + 1);
        outputFile = *(argv + 2);
        debugCharacter = 'x';
        vectorSize = *(argv + 4);
    }
    makesql msql(prototypeFile, outputFile, debugCharacter, atoi(vectorSize) );
//    makesql msql_("/Users/cjc/sql/computeEnergyUsage.sql", "/tmp/sql.sql", '\0');
//    makesql msql("/Users/cjc/c++/playingWithContainers-r2/playingWithContainers-r2/playingWithContainers-r2/prototype.sql", "/tmp/out.log", '\0');
    const char *theSQL = msql.getsql();
    cout << "The SQL created by dylib, /Users/cjc/Library/Developer/Xcode/DerivedData/Build/Products/Debug/libmakesql.dylib looks like:\n" << theSQL << endl;
    return rc;
}
