cmd_/scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/mtd/.install := perl scripts/headers_install.pl /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/include/mtd /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/mtd m68k inftl-user.h mtd-abi.h mtd-user.h nftl-user.h ubi-user.h; perl scripts/headers_install.pl /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/include/mtd /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/mtd m68k ; for F in ; do echo "\#include <asm-generic/$$F>" > /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/mtd/$$F; done; touch /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/mtd/.install
