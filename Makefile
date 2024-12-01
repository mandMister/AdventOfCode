CFLAGS := -Wall -pedantic -std=gnu++17 -march=native -mtune=native -Og -g -Ilib

DAY_DIRS := $(wildcard day*)
DAYS     := $(notdir $(DAY_DIRS))

OUT_DIR   := out
BINARIES := $(addprefix $(OUT_DIR)/,$(DAYS))

LIB_SRCS := $(wildcard lib/*.cpp)

.PHONY: all clean bear run

all: outdir $(BINARIES)

$(OUT_DIR)/%:
	clang++ $(CFLAGS) $(wildcard $*/*.cpp) $(wildcard lib/*.cpp) -o $@

outdir:
	@mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OUT_DIR)

bear:
	bear -- make

run%: outdir $(OUT_DIR)/day%
	@cd day$* && ../$(OUT_DIR)/day$*
