cmd_/scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/linux/hdlc/.install := perl scripts/headers_install.pl /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/include/linux/hdlc /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/linux/hdlc m68k ioctl.h; perl scripts/headers_install.pl /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/include/linux/hdlc /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/linux/hdlc m68k ; for F in ; do echo "\#include <asm-generic/$$F>" > /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/linux/hdlc/$$F; done; touch /scratch/kyeung/coldfire-linux-lite-2011.09/obj/linux-2011.09-22-m68k-linux-gnu-i686-pc-linux-gnu/tmp-install/include/linux/hdlc/.install
