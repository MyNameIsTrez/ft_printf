# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/02/09 18:35:05 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := libftprintf.a
LIBFT_PATH := libft/libft.a

CC := cc

# CFLAGS := -Wall -Wextra -Werror -g3 # Is it allowed to keep -g3 turned on?
CFLAGS := -Wall -Wextra -Werror

SOURCES_WITH_HEADERS := src/ft_printf_bonus.c
SOURCES_WITHOUT_HEADERS :=			\
	src/get_type_strings/get_char.c			\
	src/get_type_strings/get_decimal.c		\
	src/get_type_strings/get_hex_lower.c	\
	src/get_type_strings/get_hex_upper.c	\
	src/get_type_strings/get_percent.c		\
	src/get_type_strings/get_pointer.c		\
	src/get_type_strings/get_string.c		\
	src/get_type_strings/get_unsigned.c

HEADERS := src/get_type_strings/get_type_strings.h

CLEANED_FILES := obj
FCLEANED_FILES := $(NAME)

SRC_DIR := src
OBJ_DIR := obj

LIBFT_DIR := libft

################################################################################

HEADERS += $(SOURCES_WITH_HEADERS:.c=.h)
SOURCES := $(SOURCES_WITH_HEADERS) $(SOURCES_WITHOUT_HEADERS)

ifdef DEBUG
CFLAGS += -g3 -Wconversion #-fsanitize=address
FCLEANED_FILES += tester
endif

################################################################################

OBJECT_PATHS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

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
