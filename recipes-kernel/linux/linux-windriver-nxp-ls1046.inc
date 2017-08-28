#
# Copyright (C) 2016 Wind River Systems, Inc.
#

TARGET_SUPPORTED_KTYPES_nxp-ls1046 = "standard preempt-rt cgl"
KERNEL_DEVICETREE_nxp-ls1046 = "freescale/fsl-ls1046a-rdb.dtb freescale/fsl-ls1046a-rdb-usdpaa.dtb"

KBRANCH_DEFAULT_standard_nxp-ls1046 ?= "standard/nxp/sdk-2-0/sdk-2-0-1703/${KMACHINE}"
KBRANCH_DEFAULT_preempt-rt_nxp-ls1046 ?= "standard/preempt-rt/nxp/sdk-2-0/sdk-2-0-1703/${KMACHINE}"
KBRANCH_DEFAULT_cgl_nxp-ls1046 ?= "standard/cgl/nxp/sdk-2-0/sdk-2-0-1703/${KMACHINE}"

KERNEL_EXTRA_ARGS_append_nxp-ls1046 = " LOADADDR=0x80080000"
