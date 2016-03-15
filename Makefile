#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwelsch <mwelsch@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:02:18 by mwelsch           #+#    #+#              #
#    Updated: 2016/03/15 10:44:16 by mwelsch          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
NAME_D = libft_d.a

NORM_FILE = .last-norm

INC_DIR = includes
SRC_DIR = srcs

DIST_DIR = dist

COUNT=0

DIST_FUNCS_LIST=$(shell find scripts/parts -name 'part_*.list' -exec cat {} \;)
DIST_INC_PRIO=bool types platform config math memory
DIST_INC_PREFIX=$(patsubst %,libft_%.h,$(DIST_INC_PRIO))

SRCS = $(shell ls $(SRC_DIR) | grep \.c)
INCS_ = $(DIST_INC_PREFIX) $(shell ls $(INC_DIR) | grep \.h | grep -v libft\.h)
INCS = $(shell echo $(INCS_) | tr ' ' '\n' | cat -n - | sort -uk2 | sort -nk1 | cut -f2-)

OBJ_DIR = objs
OBJ_DEBUG_DIR = $(OBJ_DIR)/debug
OBJ_RELEASE_DIR = $(OBJ_DIR)/release
OBJS = $(patsubst %.c,$(OBJ_RELEASE_DIR)/%.o,$(SRCS))
OBJS_D = $(patsubst %.c,$(OBJ_DEBUG_DIR)/%.o,$(SRCS))
NOBJS = $(shell echo $(OBJS) | wc -w)

VERSION_FILE=.version
VERSION_CHANGES = .changelog

VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_BUILD = $(shell cat $(VERSION_FILE))
REV=$(shell date +'%l%M')
VERSION_REV = $(shell echo $(REV) | tr -d ' ')

VERSION_TIME = $(shell date +'%H:%M:%S')
VERSION_DATE = $(shell date +'%Y/%m/%d')

VERSION_FLAGS = -D__VERSION_DATE=$(VERSION_DATE)
VERSION_FLAGS += -D__VERSION_BUILD=$(VERSION_BUILD)
VERSION_FLAGS += -D__VERSION_MAJOR=$(VERSION_MINOR)
VERSION_FLAGS += -D__VERSION_MINOR=$(VERSION_MAJOR)
VERSION_FLAGS += -D__VERSION_REV=$(VERSION_REV)

FLAGS = -Wall -Wextra -Werror -std=c89 $(VERSION_FLAGS)
CFLAGS = $(FLAGS)
CFLAGS_D = $(FLAGS) -g -ggdb -D_DEBUG
CC = gcc
LD = ar rcs
RM = /bin/rm -f

default: release
all: release debug

debug: $(NAME_D)
release: $(NAME)

norme:
	@norminette $(SRC_DIR) $(INC_DIR) Makefile > $(NORM_FILE)
	@echo "$$(grep Error $(NORM_FILE) | wc -l) error(s) detected."
	@echo "$$(grep Warning $(NORM_FILE) | wc -l) warning(s) detected."
	@read -p "View $(NORM_FILE)? [Yn]" ANS; [[ $$ANS == "y" || $$ANS == "Y" || $$ANS == "" ]] && less $(NORM_FILE)

$(NAME): $(OBJS) $(VERSION_FILE)
	@PRCT=$$(echo "scale=1; $(COUNT) / $(NOBJS) * 100" | bc); \
	printf "\r\033[K[$(CC)|%s%%]Linking $@\n" "$$PRCT"; \
	$(LD) $@ $^; \
	printf "\r\033[K[$(CC)|%s%%]Linked $@\n" "$$PRCT"


$(NAME_D): $(OBJS_D) $(VERSION_FILE)
	@PRCT=$$(echo "scale=1; $(COUNT) / $(NOBJS) * 100" | bc); \
	printf "\r\033[K[$(CC)|%s%%]Linking $@\n" "$$PRCT"; \
	$(LD) $@ $^; \
	printf "\r\033[K[$(CC)|%s%%]Linked $@\n" "$$PRCT"

$(OBJ_DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	@PRCT=$$(echo "scale=1; $(COUNT) / $(NOBJS) * 100" | bc); \
	$$(test -e "$(OBJ_DEBUG_DIR)" || mkdir -p $(OBJ_DEBUG_DIR)); \
	printf "\r\033[K[$(CC)|%s%%]Compiling $< into $@" "$$PRCT"; \
	$(CC) $(CFLAGS_D) -c -I$(INC_DIR) -o $@ $<; \
	$(eval COUNT = $(shell echo "$(COUNT) + 1" | bc) ) \
	printf "\r\033[K[$(CC)|%s%%]Compiled $< into $@" "$$PRCT"

$(OBJ_RELEASE_DIR)/%.o: $(SRC_DIR)/%.c
	@PRCT=$$(echo "scale=1; $(COUNT) / $(NOBJS) * 100" | bc); \
	$$(test -e "$(OBJ_RELEASE_DIR)" || mkdir -p $(OBJ_RELEASE_DIR)); \
	printf "\r\033[K[$(CC)|%s%%]Compiling $< into $@" "$$PRCT"; \
	$(CC) $(CFLAGS) -c -I$(INC_DIR) -o $@ $<; \
	$(eval COUNT = $(shell echo "$(COUNT) + 1" | bc) ) \
	printf "\r\033[K[$(CC)|%s%%]Compiled $< into $@" "$$PRCT"

# build number file
$(VERSION_FILE): $(OBJS)
	@printf "\r\033[KUpdating version ($(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV))\n"
	@if ! test -f $@; then echo 0 > $@; fi
	@echo $$(($$(cat $@) + 1)) > $@
	@if ! test -f $(VERSION_CHANGES); then touch $(VERSION_CHANGES); fi
	@echo "Version $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV): Library build ($(VERSION_DATE) at $(VERSION_TIME))" | cat - $(VERSION_CHANGES) >> $(VERSION_CHANGES).tmp
	@rm -rf $(VERSION_CHANGES)
	@mv $(VERSION_CHANGES).tmp $(VERSION_CHANGES)

version: $(VERSION_FILE)
	@echo Current $(NAME) version: $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV)

test:
	make -C test

clean:
	@N=$$(ls $(OBJ_RELEASE_DIR) | grep '\.o' | wc -w); \
	if [ $$N -gt 0 ]; then \
		echo "Removing $$N object(s)."; \
		$(RM) $(OBJS); \
	fi

fclean : clean
	@if [ -e "$(NAME)" ]; then \
		echo Removing $(NAME); \
		$(RM) $(NAME); \
	fi

clean_debug:
	@N=$$(ls $(OBJ_DEBUG_DIR) | grep '\.o' | wc -w); \
	if [ $$N -gt 0 ]; then \
		echo "Removing $$N object(s)."; \
		$(RM) $(OBJS_D); \
	fi

fclean_debug : clean_debug
	@if [ -e "$(NAME_D)" ]; then \
		echo Removing $(NAME_D); \
		$(RM) $(NAME_D); \
	fi

help:
	@printf "rules:\n"
	@printf "\tall:\t\tsee release.\n"
	@printf "\trelease:\t\tbuilds in release mode.\n"
	@printf "\tdebug:\t\tbuilds in debug mode.\n"
	@printf "\tclean:\t\tremoves all release object(s).\n"
	@printf "\tfclean:\t\tremoves release target\n"
	@printf "\tre:\t\tfclean + release\n"
	@printf "\trelink:\t\trelinks all release object(s) into target.\n"
	@printf "\tdist:\t\tcreates the rendu folder.\n"
	@printf "\tdist_clean:\t\tcleans the rendu folder.\n"
	@printf "\tdist_fclean:\t\tforce cleans the rendu folder.\n"

re: fclean default

dist: release #norme
	@[ -d $(DIST_DIR) ] || mkdir -p $(DIST_DIR)
	@cp scripts/make/dist.mak $(DIST_DIR)/Makefile
	@for SRC in $(DIST_FUNCS_LIST); do \
		FNAME=ft_$$(echo $$SRC | sed 's/ft_//' | sed 's/\.c//').c; \
		head -n 12 $(SRC_DIR)/$$FNAME | tee $(DIST_DIR)/$${FNAME}.header > /dev/null; \
		tail -n +13 $(SRC_DIR)/$$FNAME | grep -vi '#include' | tee $(DIST_DIR)/$${FNAME}.body > /dev/null; \
		tail -n +13 $(SRC_DIR)/$$FNAME | grep -i '#include' | sort | uniq | tee $(DIST_DIR)/$${FNAME}.includes > /dev/null; \
		sed -i 's/#include[ | ]\+[<|"]libft_[a-z]\+.h[>|"]/#include "libft.h"/g' $(DIST_DIR)/$${FNAME}.includes; \
		cat $(DIST_DIR)/$${FNAME}.header | tee $(DIST_DIR)/$$FNAME > /dev/null; \
		cat $(DIST_DIR)/$${FNAME}.includes | tee -a $(DIST_DIR)/$$FNAME > /dev/null; \
		cat $(DIST_DIR)/$${FNAME}.body | tee -a $(DIST_DIR)/$$FNAME > /dev/null; \
		$(RM) $(DIST_DIR)/$${FNAME}.{header,body,includes}; \
		echo $$SRC: $$(test -e $(DIST_DIR)/$$FNAME && echo "OK" || echo "ERROR"); \
	done
	@echo "Catting all header files into $(DIST_DIR)/libft.h"
	@[ -e $(DIST_DIR)/libft.h ] && $(RM) -f $(DIST_DIR)/libft.h || echo 0
	@cat header | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo -e "\n#ifndef LIBFT_H" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo "# define LIBFT_H" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo "# define VERSION_MAJOR $(VERSION_MAJOR)" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo "# define VERSION_MINOR $(VERSION_MINOR)" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo "# define VERSION_BUILD $(VERSION_BUILD)" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo "# define VERSION_REV $(VERSION_REV)" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@echo "# define VERSION_STRING \"$(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_BUILD).$(VERSION_REV)\"" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@for HEADER in $(INCS); do \
		echo $$HEADER: $$(tail -n +15 $(INC_DIR)/$$HEADER | head -n -1 | tee -a $(DIST_DIR)/libft.h > /dev/null && echo "OK" || echo "ERROR"); \
	done
	@echo "#endif" | tee -a $(DIST_DIR)/libft.h > /dev/null
	@grep -Pzo "#ifndef LIBFT_[a-zA-Z_]*_H[\n]+# define LIBFT_[a-zA-Z_]*_H" $(DIST_DIR)/libft.h | tee $(DIST_DIR)/hguards.list > /dev/null
	@echo "Found $$(cat $(DIST_DIR)/hguards.list | grep ifndef | wc -l) useless header guards, removing."
	@cat $(DIST_DIR)/hguards.list | xargs -I{} sed -i "s/{}//g" $(DIST_DIR)/libft.h
	@echo "Final header is $$(du -h $(DIST_DIR)/libft.h)"
	@$(RM) $(DIST_DIR)/hguards.list
	@grep -i '# include' $(DIST_DIR)/libft.h | grep -v 'libft_' | uniq | sort | tee -a $(DIST_DIR)/includes.list >/dev/null
	@grep -vi '# include' $(DIST_DIR)/libft.h | tee $(DIST_DIR)/libft.h.new  > /dev/null
	@head -n 14 $(DIST_DIR)/libft.h.new | tee $(DIST_DIR)/libft.h > /dev/null
	@cat $(DIST_DIR)/includes.list | tee -a $(DIST_DIR)/libft.h > /dev/null
	@tail -n +15 $(DIST_DIR)/libft.h.new | tee -a $(DIST_DIR)/libft.h > /dev/null
	@$(RM) $(DIST_DIR)/libft.h.new
	@$(RM) $(DIST_DIR)/includes.list
	@make --no-print-directory -C $(DIST_DIR)
	@UNDEFINED=$$(nm -A -u $(DIST_DIR)/$(NAME) | xargs -I{} echo -e "\t{}"); \
	NUNDEFINED=$$(echo -e "$$UNDEFINED" | cat - | wc -l); \
	if [ $$NUNDEFINED -gt 0 ]; then \
		echo "$$NUNDEFINED undefined symbol(s):"; \
		echo -e "$$UNDEFINED" | cat -; \
	else \
		echo "No undefined symbols!"; \
	fi;

relink: $(OBJS)
	@$(RM) $(NAME) && echo "Removed $(NAME)"
	@$(LD) $(LDFLAGS) $(NAME) $^ && echo "Linked $@"

dist_clean:
	@OK=$$(test -e $(DIST_DIR)); \
	make clean --no-print-directory -C $(DIST_DIR);

dist_fclean: dist_clean
	@OK=$$(test -e $(DIST_DIR)); \
	make fclean --no-print-directory -C $(DIST_DIR); \
	$(RM) -r $(DIST_DIR);

.PHONY: clean fclean all re relink debug release test version dist dist_clean dist_clean help default