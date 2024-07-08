/*
==========================================================================================
iBour-3R GCCD-IUT-Grenoble - Main file
==========================================================================================

TO-DO:
    §§§§

Changelog:
-- Version 0.0.0 Chonamalus
    -- $(FUTURE VERSION NAME HERE)

Description:
    §§§§
*/

#include "config.h"

#ifdef TESTER
#include <iostream>

#include "test.h"
#endif

#include "Register32_Interface.h"
#include "Register32_Meta.h"
#include "Register32_MetaBuilder.h"

int main() {
#ifdef TESTER
    testRegisterReadWrite();
    testSubRegisterReadWrite();
#ifdef USE_REGISTERS_META
    testMetadataHandling();
#endif
#endif

    return 0;
}
