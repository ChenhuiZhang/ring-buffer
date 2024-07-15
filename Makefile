
.PHONY: test memtest coverage

test:
	@meson setup build
	@meson test -q -C build

memtest:
	@meson setup build
	@meson test -q --wrapper valgrind -C build

coverage:
	@meson setup build --buildtype=debug -Db_coverage=true
	@meson test -q -C build
	gcovr -r . --html-details -o $(shell mktemp -d)/report.html
