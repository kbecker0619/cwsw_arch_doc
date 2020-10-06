
OBJTREE		:= $(if $(BUILD_DIR),$(BUILD_DIR),$(CURDIR))
SRCTREE		:= $(CURDIR)
TOPDIR		:= $(SRCTREE)
LNDIR		:= $(OBJTREE)
export	TOPDIR SRCTREE OBJTREE

KLB_BACKUP_FILE_NAME_BASE := $(shell basename $(shell pwd))
KLB_BACKUP_FILE_NAME := $(shell date +$(KLB_BACKUP_FILE_NAME_BASE)-%Y-%m-%d-%T.tar.gz)
export KLB_BACKUP_FILE_NAME KLB_BACKUP_FILE_NAME_BASE

# Targets which don't build the source code
NON_BUILD_TARGETS = backup clean clobber distclean mkproper tidy unconfig

backup:
	@#pushd $(TOPDIR)
	@# methinks the following line is redundant, given normal usage, but nevertheless ...
	@cd $(TOPDIR)
	@tar --force-local -zcvf ~/$(KLB_BACKUP_FILE_NAME) --exclude-vcs --exclude-vcs-ignores ./
	@#popd
	@echo ""
	@echo ""
	@echo "Project Backup Made:"
	@ls -l ~/$(KLB_BACKUP_FILE_NAME)
	@echo ""
	@echo "All Local Backups of Project:"
	@ls ~/$(KLB_BACKUP_FILE_NAME_BASE)*
	@echo ""
	@echo ""
