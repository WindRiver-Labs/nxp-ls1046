#@TYPE: Machine inc.
#@NAME: nxp-ls1046 layer

DEFAULTTUNE = "aarch64"
require conf/machine/include/arm/arch-armv8.inc

MACHINE_FEATURES += "usbhost jffs2 ext2 alsa vfat"

KERNEL_IMAGETYPE = "uImage Image"

SERIAL_CONSOLE = "115200 ttyS0"

IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"
WKS_FILE = "sdimage.wks"
IMAGE_INSTALL_append = " kernel-devicetree kernel-image-uimage"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

EXTRA_IMAGEDEPENDS = "u-boot-qoriq"
UBOOT_CONFIG ??= "emmc sdcard qspi-secure-boot qspi"
UBOOT_CONFIG[emmc] = "ls1046ardb_emmc_defconfig,,u-boot-with-spl-pbl.bin"
UBOOT_CONFIG[sdcard] = "ls1046ardb_sdcard_config,,u-boot-with-spl-pbl.bin"
UBOOT_CONFIG[qspi] = "ls1046ardb_qspi_config,,u-boot-dtb.bin"
UBOOT_CONFIG[qspi-secure-boot] = "ls1046ardb_qspi_SECURE_BOOT_config,,u-boot-dtb.bin"

