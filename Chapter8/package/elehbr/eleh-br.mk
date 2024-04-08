################################################################################
#
# eleh-br package
#
################################################################################

ELEHBR_VERSION = 1.0
ELEHBR_SITE = package/elehbr/src
ELEHBR_SITE_METHOD = local

define ELEHBR_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define ELEHBR_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/eleh-br  $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))
