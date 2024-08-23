FILE ?= calculator
EXTENSION = .c
ROUTE = ./examples_of_testings

all: clear
	@./build.out global_files
	cd ${ROUTE} && gcc ${FILE}${EXTENSION}
	@echo ""
	@${ROUTE}/a.out

clear:
	@clear
	@echo
	@ls -a1h --color=always
	@echo
