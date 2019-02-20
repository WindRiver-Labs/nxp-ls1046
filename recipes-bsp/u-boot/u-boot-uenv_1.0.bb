SUMMARY = "U-Boot boot.scr SD boot environment generation for nxp-ls1046a rdb targets"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

INHIBIT_DEFAULT_DEPS = "1"
PACKAGE_ARCH = "${MACHINE_ARCH}"

DEPENDS = "u-boot-mkimage-native"

inherit deploy

do_compile(){

    cat <<EOF > ${WORKDIR}/uEnv.txt
setenv machine_name nxp-ls1046a
if test -e \${devtype} \${devnum}:\${distro_bootpart} \$prefix\${kernelfile}; then echo Found kernel @ \$prefix\${kernelfile}; else setenv kernelfile Image; fi
setenv loadkernel load \${devtype} \${devnum}:\${distro_bootpart} \${kernel_addr_r} \$prefix\${kernelfile}
if test -e \${devtype} \${devnum}:\${distro_bootpart} \$prefix\${fdtfile}; then echo Found dtb @ \$prefix\${fdtfile}; else setenv fdtfile devicetree-Image-fsl-ls1046a-rdb-sdk.dtb; fi
setenv loaddtb load \${devtype} \${devnum}:\${distro_bootpart} \${fdt_addr_r} \$prefix\${fdtfile}
setenv bootargs console=\${console},\${baudrate} \${smp} root=/dev/mmcblk0p1 rw rootwait ip=dhcp \${othbootargs}
run loaddtb
run loadkernel
booti \${kernel_addr_r} - \${fdt_addr_r}
EOF
    mkimage -A arm -T script -O linux -d ${WORKDIR}/uEnv.txt ${WORKDIR}/ls1046ardb_boot.scr
}

FILES_${PN} += "/boot/ls1046ardb_boot.scr"

do_install() {
        install -d  ${D}/boot
	install -Dm 0644 ${WORKDIR}/ls1046ardb_boot.scr ${D}/boot/
}
