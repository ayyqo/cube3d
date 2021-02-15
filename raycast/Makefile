NAME = CUBE

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lmlx -lXext -lX11 -lm

SRCSLIBFT = libft/*.c

SRC = srcs/raycast/raycasting.c srcs/events/keyhook.c\
	  srcs/events/move_right.c srcs/events/move_left.c \
	  srcs/events/camera_left.c srcs/events/camera_right.c \
	  srcs/events/move_backward.c srcs/events/move_forward.c \
	  main.c 

all: $(NAME)

$(NAME): $(SRCSLIBFT) $(SRCS)
		$(CC) -o $(NAME) $(SRCSLIBFT) $(SRC) $(CFLAGS)

