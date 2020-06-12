#@TYPE: Machine inc.
#@NAME: nxp-ls1046 layer

DEFAULTTUNE = "cortexa72"
require conf/machine/include/tune-cortexa72.inc

MACHINE_FEATURES += "usbhost jffs2 ext2 alsa vfat"

KERNEL_IMAGETYPE = "Image"

SERIAL_CONSOLE = "115200 ttyS0"

IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"
WKS_FILE = "nxp-ls1046-sdimage.wks"
IMAGE_INSTALL_append = " kernel-devicetree kernel-image-image"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

EXTRA_IMAGEDEPENDS = "u-boot-qoriq u-boot-uenv"
UBOOT_CONFIG ??= "sdcard qspi"
UBOOT_CONFIG[sdcard] = "ls1046ardb_sdcard_config,,u-boot-with-spl-pbl.bin"
UBOOT_CONFIG[qspi] = "ls1046ardb_qspi_config,,u-boot-dtb.bin"

# it's used by many recipes in meta-freescale
MACHINE_SOCARCH = "${TUNE_PKGARCH}"

# pull in the meta-freescale layer.
BSP_NXP_DERIVED_append_nxp-ls1046  = " nxp-ls1046"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"

