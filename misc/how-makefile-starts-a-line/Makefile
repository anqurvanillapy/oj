# - Does Makefile spawn a new shell for each command it starts?
# - Yes... (Maybe that's why it's slow.)

test: subtest
	export foo=42 && echo $$foo
	echo $$foo # undefined
	@echo "[pid] test0:" $$$$
	@echo "[pid] test1:" $$$$

subtest:
	@echo "[pid] subtest0:" $$$$
	@echo "[pid] subtest1:" $$$$
