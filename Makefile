# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/01/28 19:08:07 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := libftprintf.a
LIBFT_PATH := libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

MANDATORY_SOURCES :=

BONUS_SOURCES := bonus/src/ft_printf_bonus.c bonus/src/get_type_strings/get_char.c

FCLEANED_FILES := $(NAME)

# HEADERS := libft/libft.h bonus/src/get_type_strings/get_type_strings.h
HEADERS := bonus/src/get_type_strings/get_type_strings.h

################################################################################

BONUS_DIR := bonus
MANDATORY_DIR := mandatory

ifdef USE_BONUS
DIR := $(BONUS_DIR)
SOURCES := $(BONUS_SOURCES)
else
DIR := $(MANDATORY_DIR)
SOURCES := $(MANDATORY_SOURCES)
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

HEADERS += $(SOURCES:.c=.h)

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
	$(MAKE) -C $(dir $(LIBFT_PATH))

################################################################################

bonus:
	@$(MAKE) USE_BONUS=1 all

clean:
	rm -rf $(MANDATORY_DIR)/obj $(BONUS_DIR)/obj
	@$(MAKE) -C $(dir $(LIBFT_PATH)) clean

fclean: clean
	rm -f $(FCLEANED_FILES)
	@$(MAKE) -C $(dir $(LIBFT_PATH)) fclean

re: fclean all

################################################################################

.PHONY: all bonus clean fclean re

################################################################################
