SRC = server.c client.c

B_SRC = server_bonus.c client_bonus.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

all: server client

.c.o: $(SRC) $(B_SRC)
		cc -c $< -o $(<:.c=.o)

server: server.o
	cc -Wall -Wextra -Werror server.o -o server

client: client.o
	cc -Wall -Wextra -Werror client.o -o client

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f server client server_bonus client_bonus

bonus: $(B_OBJ)
	cc -Wall -Wextra -Werror server_bonus.o -o server_bonus
	cc -Wall -Wextra -Werror client_bonus.o -o client_bonus

re: fclean all

.PHONY: all clean fclean re bonus
