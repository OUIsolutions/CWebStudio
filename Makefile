
PORT = 3000
EXTENSION = .c
ROUTE = ./examples_of_testings
FILE_STORE = .file_store

ifneq ("$(wildcard $(FILE_STORE))","")
    include $(FILE_STORE)
endif

all: clear check_file setPort
	@./build.out global_files
	cd $(ROUTE) && gcc $(FILE)$(EXTENSION)
	@echo ""
	@$(ROUTE)/a.out

setfile:
	@echo "FILE=$(FILE)" > $(FILE_STORE)
	@echo "FILE set to: $(FILE)"

setPort:
	@echo '#define PORT_SERVER_GLOBAL_IN_MAKE ${PORT}' > ./examples_of_testings/port.h
	@echo "PORT is defined in ${PORT}"
	@echo ""
	@cat ./examples_of_testings/port.h

clear:
	@clear
	@echo
	@ls -a1h --color=always
	@echo

check_file:
ifndef FILE
	$(error FILE is not set. Use 'make FILE=<filename> setfile' to set it.)
endif


