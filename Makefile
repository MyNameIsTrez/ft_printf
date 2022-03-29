# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/03/29 17:26:43 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := libftprintf.a
LIBFT_PATH := libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

SOURCES :=										\
	src/ft_printf.c								\
	src/get_type_strings/pft_get_char.c			\
	src/get_type_strings/pft_get_decimal.c		\
	src/get_type_strings/pft_get_hex_lower.c	\
	src/get_type_strings/pft_get_hex_upper.c	\
	src/get_type_strings/pft_get_percent.c		\
	src/get_type_strings/pft_get_pointer.c		\
	src/get_type_strings/pft_get_string.c		\
	src/get_type_strings/pft_get_unsigned.c		\
	src/pft_fill_parts.c						\
	src/pft_fix_priorities.c					\
	src/pft_initialize_options.c				\
	src/pft_parse_argument.c					\
	src/pft_parse_format.c						\
	src/pft_utils.c

HEADERS :=										\
	libft/libft.h								\
	src/get_type_strings/pft_get_type_strings.h	\
	src/ft_printf.h

CLEANED_FILES := obj
FCLEANED_FILES := $(NAME)

SRC_DIR := src
OBJ_DIR := obj

LIBFT_DIR := libft

################################################################################

ifdef DEBUG
CFLAGS += -g3 -Wconversion
# CFLAGS += -fsanitize=address # Not compatible with "leaks" program.
FCLEANED_FILES += tester
endif

################################################################################

OBJECT_PATHS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))

################################################################################

all: $(NAME)

$(NAME): $(OBJECT_PATHS) $(LIBFT_PATH)
	cp $(LIBFT_PATH) $(NAME)
	ar rs $(NAME) $(OBJECT_PATHS)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_PATH):
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: all

################################################################################

bonus: all

clean:
	rm -rf $(CLEANED_FILES)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(FCLEANED_FILES)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: bonus clean fclean re

################################################################################
