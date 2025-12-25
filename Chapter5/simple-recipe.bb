SUMMARY = "Simple Bitbake recipe"
LICENSE = "CLOSED"

SRC_URI = "\
    file://test_script.sh \
“

do_install() {
    install -d ${D}{bindir}
    install -m 0755 ${WORKDIR}/test_script.sh ${D}{bindir}/test_script.sh
}

FILES_${PN} = “ ${bindir}/test_script.sh