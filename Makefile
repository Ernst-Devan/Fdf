# =======================================
# Main Variables - Variables / Values
# =======================================

CC		= cc
CCFLAGS ?= -Wall -Werror -Wextra -Ofast
DEBUG	= -g
NAME 	= fdf
MOD		= 0

# =======================================
# Main Directories - Paths
# =======================================

GLOBAL_FILES	?=	fdf.c				\
		  			error.c				\
		  			utils.c				\
		  			parsing.c			\
		  			vector.c			\
		  			join.c

MANDATORY_FILES =	bresenham.c			\
					draw.c				\
					init.c				\
					keys.c				\
					window.c			\

BONUS_FILES		=	bresenham_bonus.c	\
					draw_bonus.c		\
					init_bonus.c		\
					keys_bonus.c		\
					rotation_bonus.c	\
					window_bonus.c


SRC_DIR			= srcs/basic/
SRC_DIR_BONUS	= srcs/bonus/

OBJ_D		= objs/
INC_D		= -Iincludes 		\
			-ILibft/includes 	\
			-Iminilibx-linux	\

# =======================================
# Decoration Text - Colors
# =======================================

red    	= 	/bin/echo -e "\x1b[31m$1\x1b[0m"
green  	= 	/bin/echo -e "\x1b[32m$1\x1b[0m"
yellow 	= 	/bin/echo -e "\x1b[33m$1\x1b[0m"
blue   	= 	/bin/echo -e "\x1b[34m$1\x1b[0m"
magenta = 	/bin/echo -e "\x1b[35m$1\x1b[0m"
cyan   	= 	/bin/echo -e "\x1b[36m$1\x1b[0m"

# =======================================
# Switch Between Mandatory And Bonus - Colors
# =======================================

ifeq ($(MOD),0)
	GLOBAL_FILES+= $(MANDATORY_FILES)
else
	GLOBAL_FILES+= $(BONUS_FILES)
endif

# =======================================
#  Adding Path
# =======================================

OBJS 			= $(GLOBAL_FILES:.c=.o)
DEPS			= $(OBJS:.o=.d)
DEPS			:= $(addprefix $(OBJ_D), $(DEPS))
OBJS			:= $(addprefix $(OBJ_D), $(OBJS))
BONUS_FILES		:= $(addprefix $(SRC_DIR_BONUS), $(BONUS_FILES))
GLOBAL_FILES	:= $(addprefix $(SRC_DIRS), $(GLOBAL_FILES))
MANDATORY_FILES	:= $(addprefix $(SRC_DIRS), $(MANDATORY_FILES))

# =======================================
#  Mandatory Command
# =======================================

.PHONY:all
all :
	$(MAKE) -C Libft/
	$(MAKE) -C minilibx-linux
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) Libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_D)%.o: $(SRC_DIR)%.c | $(OBJ_D)
	@$(CC) $(CCFLAGS) $(INC_D) -g3 -c $< -o $@

$(OBJ_D)%.o: $(SRC_DIR_BONUS)%.c | $(OBJ_D)
	@$(CC) $(CCFLAGS) $(INC_D) -g3 -c $< -o $@

.PHONY: bonus
bonus:
	$(MAKE) MOD=1

.PHONY: clean
clean:
	$(MAKE) clean -C minilibx-linux
	$(MAKE) clean -C Libft/
	rm -rf $(OBJ_D)

.PHONY: fclean
fclean:	clean
	$(MAKE) fclean -C Libft/ 
	rm -f $(NAME)

.PHONY: re
re: fclean all
	$(MAKE) re -C minilibx-linux
	$(MAKE) fclean -C Libft/


$(OBJ_D):
	mkdir -p $(OBJ_D)

# =======================================
#  Custom Command
# =======================================

.PHONY: debug
debug:
	$(MAKE) CCFLAGS=$(DEBUG)

.PHONY: norminette
norminette:
	watch norminette $(SRC_DIRS) $(INC_D)