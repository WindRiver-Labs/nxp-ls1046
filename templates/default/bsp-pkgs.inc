IMAGE_INSTALL += "u-boot-uenv"

PNWHITELIST_freescale-layer += 'u-boot-qoriq'
PNWHITELIST_freescale-layer += 'change-file-endianess'
PNWHITELIST_freescale-layer += 'rcw'
PNWHITELIST_freescale-layer += 'ppa'

PNWHITELIST += 'u-boot-uenv'
