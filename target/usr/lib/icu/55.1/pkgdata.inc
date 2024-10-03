GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.55.1
COMPILE=arm-openwrt-linux-muslgnueabi-gcc -I/home/lxy/Desktop/tina-sdk/out/t113-100ask/staging_dir/target/usr/include -I/home/lxy/Desktop/tina-sdk/out/t113-100ask/staging_dir/target/include -I/home/lxy/Desktop/tina-sdk/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/usr/include -I/home/lxy/Desktop/tina-sdk/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/include -I/home/lxy/Desktop/tina-sdk/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/include/fortify  -D_REENTRANT  -DU_HAVE_ELF_H=1 -DU_HAVE_ATOMIC=1 -DU_HAVE_TIMEZONE=0  -DU_ATTRIBUTE_DEPRECATED= -O3 -Os -pipe -march=armv7-a -mtune=cortex-a7 -mfpu=neon -fno-caller-saves -Wno-unused-result -mfloat-abi=hard  -Wformat -Werror=format-security -fPIC -fstack-protector -D_FORTIFY_SOURCE=2 -Wl,-z,now -Wl,-z,relro  -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -c
LIBFLAGS=-I/usr/include -DPIC -fPIC
GENLIB=arm-openwrt-linux-muslgnueabi-gcc -O3 -Os -pipe -march=armv7-a -mtune=cortex-a7 -mfpu=neon -fno-caller-saves -Wno-unused-result -mfloat-abi=hard  -Wformat -Werror=format-security -fPIC -fstack-protector -D_FORTIFY_SOURCE=2 -Wl,-z,now -Wl,-z,relro  -std=c99 -Wall -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings   -L/home/lxy/Desktop/tina-sdk/out/t113-100ask/staging_dir/target/usr/lib -L/home/lxy/Desktop/tina-sdk/out/t113-100ask/staging_dir/target/lib -L/home/lxy/Desktop/tina-sdk/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/usr/lib -L/home/lxy/Desktop/tina-sdk/prebuilt/gcc/linux-x86/arm/toolchain-sunxi-musl/toolchain/lib -specs=/home/lxy/Desktop/tina-sdk/build/hardened-ld-pie.specs -znow -zrelro   -shared -Wl,-Bsymbolic
LDICUDTFLAGS=
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=arm-openwrt-linux-muslgnueabi-ar
ARFLAGS=r
RANLIB=arm-openwrt-linux-muslgnueabi-ranlib
INSTALL_CMD=/usr/bin/install -c
