NAME = minitalk

NAME_SERVER = server

NAME_CLIENT = client

BONUS_SERVER = server_bonus

BONUS_CLIENT = client_bonus

CFLAGS = -Wall -Wextra -Werror

SRC_S = server.c utils.c

SRC_C = client.c utils.c

SRC_S_BONUS = server_bonus.c utils.c

SRC_C_BONUS = client_bonus.c utils.c

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)

OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o: %.c minitalk.h
	cc $(CFLAGS) -o $@ -c $<

$(NAME_SERVER) : $(OBJ_S)
	cc -o $(NAME_SERVER) $(OBJ_S)

$(NAME_CLIENT) : $(OBJ_C)
	cc -o $(NAME_CLIENT) $(OBJ_C)

$(BONUS_SERVER) : $(OBJ_S_BONUS)
	cc -o $(BONUS_SERVER) $(OBJ_S_BONUS)

$(BONUS_CLIENT) : $(OBJ_C_BONUS)
	cc -o $(BONUS_CLIENT) $(OBJ_C_BONUS)

bonus : $(BONUS_SERVER) $(BONUS_CLIENT)

clean:
	rm -rf $(OBJ_S) $(OBJ_C) $(OBJ_S_BONUS) $(OBJ_C_BONUS)

fclean: clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: clean re all fclean bonus
