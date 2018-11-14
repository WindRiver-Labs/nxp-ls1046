COMPATIBLE_MACHINE_nxp-ls1046 = "nxp-ls1046"
DEPENDS_append_nxp-ls1046 = " change-file-endianess-native dtc-native tcl-native"

SRC_URI += " \
	file://0001-ls1046ardb-enable-distro-feature-for-eMMC-configurat.patch\
"

FILESEXTRAPATHS_prepend := "${THISDIR}:${THISDIR}/files:"
