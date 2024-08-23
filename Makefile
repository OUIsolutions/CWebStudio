FILE ?= calculator
EXTENSION = .c
ROUTE = ./examples_of_testings

all:
	@./build.out global_files
	cd ${ROUTE} && gcc ${FILE}${EXTENSION}
	@echo ""
	@${ROUTE}/a.out
