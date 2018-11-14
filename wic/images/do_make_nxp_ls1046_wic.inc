MAKE_NXP_LS1046_WIC = "no"
MAKE_NXP_LS1046_WIC_nxp-ls1046 = "yes"

do_make_nxp_ls1046_wic() {
	if [ ${MAKE_NXP_LS1046_WIC} = "yes" ]; then
		cd ${DEPLOY_DIR_IMAGE}
		for i in {1..10}
		do
			if [ ! -f ${IMAGE_LINK_NAME}.wic ]; then
				sleep 1
			else
				cp ${IMAGE_LINK_NAME}.wic  ${IMAGE_LINK_NAME}-emmc.wic
				dd if=u-boot.bin-emmc of=${IMAGE_LINK_NAME}-emmc.wic bs=512 seek=8 conv=fsync,notrunc
			fi
		done
	fi
}

addtask do_make_nxp_ls1046_wic after do_image_complete before do_build
