EXTENSION = .c
ROUTE = ./examples_of_testings
FILE_STORE = .file_store

ifneq ("$(wildcard $(FILE_STORE))","")
    include $(FILE_STORE)
endif

all: clear check_file
	@./build.out global_files
	cd $(ROUTE) && gcc $(FILE)$(EXTENSION)
	@echo ""
	@$(ROUTE)/a.out

setfile:
	@echo "FILE=$(FILE)" > $(FILE_STORE)
	@echo "FILE set to: $(FILE)"

clear:
	@clear
	@echo
	@ls -a1h --color=always
	@echo

check_file:
ifndef FILE
	$(error FILE is not set. Use 'make FILE=<filename> setfile' to set it.)
endif

