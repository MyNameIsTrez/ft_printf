# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/01/10 14:41:03 by trez          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


################################################################################################################################


NAME := libftprintf.a

CC := cc

SRC_DIR := src
OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror

SOURCES := src/ft_printf.c

BONUS_SOURCES := src/ft_printf_bonus.c

HEADERS := src/ft_printf.h


################################################################################################################################


ifdef ADD_BONUS
SOURCES := $(BONUS_SOURCES)
endif

OBJECT_PATHS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

# Sort removes duplicates
INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))


################################################################################################################################


all: $(NAME)

$(NAME): $(OBJECT_PATHS)
	ar rcs $(NAME) $(OBJECT_PATHS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:
	@$(MAKE) ADD_BONUS=1 all

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	rm -f $(FCLEANED_FILES)

re: fclean all


################################################################################################################################


tester: bonus
	$(CC) $(CFLAGS) $(INCLUDES) $@.c $(NAME) -o $@


################################################################################################################################


.PHONY: all debug bonus clean fclean re tester


################################################################################################################################
