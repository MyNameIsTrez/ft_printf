# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/01/10 16:02:56 by trez          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


################################################################################################################################


NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

MANDATORY_SOURCES := 

BONUS_SOURCES := bonus/src/ft_printf_bonus.c


################################################################################################################################


ifdef ADD_BONUS
SRC_DIR := bonus/src
OBJ_DIR := bonus/obj
SOURCES := $(BONUS_SOURCES)
else
SRC_DIR := mandatory/src
OBJ_DIR := mandatory/obj
SOURCES := $(MANDATORY_SOURCES)
endif

HEADERS := $(SOURCES:.c=.h)


################################################################################################################################


OBJECT_PATHS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

# Sort removes duplicates
INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))


################################################################################################################################


all: $(NAME)
	echo $(HEADERS)
	echo $(INCLUDES)

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
	./tester


################################################################################################################################


.PHONY: all bonus clean fclean re tester


################################################################################################################################
