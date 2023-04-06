all: test
.PHONY: all


.PHONY: test
test:
	@sh run_test.sh

.PHONY: clean
clean:
	@sh run_clean.sh
	@sh run_make.sh clean

.PHONY: fclean
fclean:
	@sh run_clean.sh
	@sh run_make.sh fclean

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.PHONY: compile_commands.json
compile_commands.json: pre_dev
	@(echo "[" && find . -name "*.part.json" | xargs cat && echo "]") > $@

.PHONY: pre_dev
pre_dev:
	@sh run_pre_dev.sh

.PHONY: dev
dev: compile_commands.json
