NAME_SERVER = server

NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus

SERVER_FILE = server.c

CLIENT_FILE = client.c

SERVER_FILE_BONUS = server_bonus.c

CLIENT_FILE_BONUS = client_bonus.c

OBJECT_SERVER = $(SERVER_FILE:.c=.o)

OBJECT_CLIENT = $(CLIENT_FILE:.c=.o)

OBJECTS_SERVER_BONUS = $(SERVER_FILE_BONUS:.c=.o)

OBJECTS_CLIENT_BONUS = $(CLIENT_FILE_BONUS:.c=.o)

FLAGS = -Werror -Wall -Wextra

LIBFT = ./libft/libft.a


$(NAME_SERVER):		$(SERVER_FILE) $(LIBFT) 
						@gcc $(FLAGS) $(LIBFT) $(SERVER_FILE) -o $(NAME_SERVER)

$(NAME_CLIENT):		$(CLIENT_FILE) $(LIBFT) 
						@gcc $(FLAGS) $(LIBFT) $(CLIENT_FILE) -o $(NAME_CLIENT)
		
$(NAME_SERVER_BONUS):		$(SERVER_FILE_BONUS) $(LIBFT) 
						@gcc $(FLAGS) $(LIBFT) $(SERVER_FILE_BONUS) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS):		$(CLIENT_FILE_BONUS) $(LIBFT) 
						@gcc $(FLAGS) $(LIBFT) $(CLIENT_FILE_BONUS) -o $(NAME_CLIENT_BONUS)

$(LIBFT):
						@make -s -C ./libft

all: 				$(NAME_SERVER) $(NAME_CLIENT)

bonus:				$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean:
						@rm -f $(OBJECT_SERVER) $(OBJECT_CLIENT) $(OBJECT_SERVER_BONUS) $(OBJECT_CLIENT_BONUS)
						@make clean -s -C ./libft

fclean:
						@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS) $(OBJECT_SERVER) $(OBJECTS_CLIENT) $(OBJECT_SERVER_BONUS) $(OBJECT_CLIENT_BONUS) $(LIBFT)
						@make fclean -s -C ./libft

re: fclean all

.PHONY: all re clean fclean bonus
