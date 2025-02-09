# =======================================
# Main Variables - Variables / Values
# =======================================

CC		= cc
CFLAGS 	= -Wall -Werror -Wextra -g3
NAME 	= fdf

# =======================================
# Main Directories - Paths
# =======================================

SRCS 	= fdf.c 	\
		  parsing.c	\
		  draw.c	\
		  window.c	\
		  error.c	\
		  init.c	\
		  utils.c	\
		  vector.c	\
		  bresenham.c \
		  moving.c	\

OBJS 	= $(SRCS:.c=.o)

SRC_D	= srcs/
OBJ_D	= objs/
INC_D	= -Iincludes 		\
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
# Objets Files
# =======================================

.PHONY:all
.SILENT:
all :
	@$(call yellow," ENTER LIBFT DIRECTORY")
	$(MAKE) --no-print-directory -C Libft/
	@$(call yellow," ENTER MINILIBX DIRECTORY")
	$(MAKE) -s --no-print-directory -C minilibx-linux
	@$(call yellow," ENTER FDF DIRECTORY")
	$(MAKE) -s --no-print-directory $(NAME)

OBJS	:= $(addprefix $(OBJ_D), $(OBJS))
SRCS	:= $(addprefix $(SRC_D), $(SRCS))

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC_D) $(OBJS) Libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_D)%.o: $(SRC_D)%.c $(OBJ_D)
	@$(call green," [v] $<")
	@$(CC) $(INC_D) -g3 -c $< -o $@

.PHONY: clean
.SILENT:
clean:
	$(MAKE) -s --no-print-directory  clean -C minilibx-linux
	$(MAKE) -s --no-print-directory  clean -C Libft/
	rm -rf $(OBJ_D)

.PHONY: fclean
.SILENT:
fclean:	clean
	$(MAKE) -s --no-print-directory  fclean -C Libft/ 
	rm -f $(NAME)

.PHONY: re
.SILENT:
re: fclean all
	$(MAKE) -s --no-print-directory  re -C minilibx-linux
	$(MAKE) -s --no-print-directory  fclean -C Libft/

.PHONY: debug
.SILENT:
debug: $(OBJS)
	@$(CC) $(INC_D) $(OBJS) Libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -o $(NAME)
	$(MAKE) -s --no-print-directory  -C Libft/
	$(MAKE) -s --no-print-directory  -C minilibx-linux

.SILENT:
$(OBJ_D):
	mkdir -p $(OBJ_D)