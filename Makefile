# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/02/01 15:12:41 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := libftprintf.a
LIBFT_PATH := libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

MANDATORY_SOURCES_WITH_HEADERS :=
MANDATORY_SOURCES_WITHOUT_HEADERS :=

BONUS_SOURCES_WITH_HEADERS := bonus/src/ft_printf_bonus.c
BONUS_SOURCES_WITHOUT_HEADERS :=				\
	bonus/src/get_type_strings/get_char.c		\
	bonus/src/get_type_strings/get_decimal.c	\
	bonus/src/get_type_strings/get_hex_lower.c	\
	bonus/src/get_type_strings/get_hex_upper.c	\
	bonus/src/get_type_strings/get_percent.c	\
	bonus/src/get_type_strings/get_pointer.c	\
	bonus/src/get_type_strings/get_string.c		\
	bonus/src/get_type_strings/get_unsigned.c

FCLEANED_FILES := $(NAME)

LIBFT_DIR := libft

HEADERS := bonus/src/get_type_strings/get_type_strings.h

################################################################################

BONUS_DIR := bonus
MANDATORY_DIR := mandatory

CLEANED_FILES := $(MANDATORY_DIR)/obj

ifdef USE_BONUS
DIR := $(BONUS_DIR)
HEADERS += $(BONUS_SOURCES_WITH_HEADERS:.c=.h)
SOURCES := $(BONUS_SOURCES_WITH_HEADERS) $(BONUS_SOURCES_WITHOUT_HEADERS)
CLEANED_FILES += $(BONUS_DIR)/obj
else
DIR := $(MANDATORY_DIR)
HEADERS += $(MANDATORY_SOURCES_WITH_HEADERS:.c=.h)
SOURCES := $(MANDATORY_SOURCES_WITH_HEADERS) $(MANDATORY_SOURCES_WITHOUT_HEADERS)
endif

SRC_DIR := $(DIR)/src
OBJ_DIR := $(DIR)/obj

ifdef DEBUG
LIBS +=
# HEADERS += tests.h
HEADERS +=
CFLAGS += -g3 -Wconversion
# CFLAGS += -fsanitize=address
FCLEANED_FILES += tester
endif

################################################################################

OBJECT_PATHS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

# Sort removes duplicates
INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))

################################################################################

all: $(NAME)

$(NAME): $(OBJECT_PATHS) $(LIBFT_PATH)
	cp $(LIBFT_PATH) $(NAME)
	ar rs $(NAME) $(OBJECT_PATHS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_PATH):
	$(MAKE) -C $(LIBFT_DIR)

################################################################################

bonus:
	@$(MAKE) USE_BONUS=1 all

clean:
	rm -rf $(CLEANED_FILES)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(FCLEANED_FILES)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

################################################################################

.PHONY: all bonus clean fclean re

################################################################################
