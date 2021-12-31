$(NAME): all

all: server client

server:
	cc -Wall -Wextra -Werror server.c -o server

client:
	cc -Wall -Wextra -Werror client.c -o client

clean:
	rm -rf server client server_bonus client_bonus

fclean: clean

bonus:
	cc -Wall -Wextra -Werror server_bonus.c -o server_bonus
	cc -Wall -Wextra -Werror client_bonus.c -o client_bonus

re: fclean all

.PHONY: all clean fclean re bonus
