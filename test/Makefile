TESTS=$(shell ls -d * | grep -v 'common')

COMMON_SRCS=$(shell find common -name '*.c' -type f)
COMMON_OBJS=$(patsubst %.c,%.o,$(COMMON_SRCS))

INC=-I../includes -I. -I./common
PREFIX=test_
SUFFIX=
CFLAGS=-Wall -Werror -Wextra $(INC) -ggdb
LDFLAGS=-L../ -lft_d -lm
CC=gcc

define strip_build_prefix =
echo $@ | sed 's/build_//g'
endef

define strip_link_prefix =
echo $@ | sed 's/link_//g'
endef

define build_test =
@T=$$($(strip_build_prefix)) > /dev/null; \
printf "module: $$T "; \
units=`find $$T -maxdepth 2 -name '*.c' -type f`; \
nunits=$$(echo $$units | wc -w); \
for unit in $$units; do \
obj=$$(echo $$unit | sed 's/\.c/\.o/'); \
printf "."; \
$(CC) -c -o $$obj $$unit $(CFLAGS) -I$$T -I$(INC); \
done; \
printf "done\n";
endef

define link_test =
@T=$$($(strip_link_prefix)) > /dev/null; \
OBJS=$$(ls $(COMMON_OBJS) $$T/*.o); \
printf "linking: $$T ... "; \
$(CC) -o $(PREFIX)$$T$(SUFFIX) $$OBJS $(LDFLAGS); \
printf "\033[2K"; \
printf "\rlinked: $$T\n";
endef


BUILD_RULES=$(patsubst %,build_%,$(TESTS))
LINK_RULES=$(patsubst %,link_%,$(TESTS))

all: $(COMMON_OBJS) build link

build: $(BUILD_RULES)

link: build $(LINK_RULES)

clean: clean_common
	@objs=`find . -maxdepth 2 -name '*.o' -type f`; \
	nobjs=$$(echo $$objs | wc -w); \
	rm -f $$objs; \
	test $$nobjs -gt 0 && printf "Removed %d object(s).\n" "$$nobjs" || echo "No object removed.";

fclean: clean
	@files=`find . -maxdepth 1 -name '$(PREFIX)*' -type f`; \
	nfiles=$$(echo $$files | wc -w); \
	rm -f $$files; \
	test $$nfiles -gt 0 && printf "Removed %d executable(s).\n" "$$nfiles" || echo "No executable removed.";

re: clean all

run: build
	units=`find . -maxdepth 2 -name 'test_*' -type f -printf "%P\n"`; \
	nunits=$$(echo $$units | wc -w); \
	cnt=0; \
	for unit in $$units; do \
		printf "[run %d/%d] %s\n" $$cnt $$nunits $$unit; \
		./$$unit; \
		cnt=$$(echo $$cnt + 1 | bc); \
	done

common/%.o: common/%.c
	@printf "building $@ ... "; \
	$(CC) -c -o $@ $< $(CFLAGS) -I$(INC); \
	printf "done\n"


build_%: $(COMMON_OBJS)
	$(build_test)

link_%:
	$(link_test)

clean_common:
	rm -f $(COMMON_OBJS)

.PHONY: all re build run link clean clean_common

#$(BUILD_RULES) $(LINK_RULES)
