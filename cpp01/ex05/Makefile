
define BANNER
                                                                                                 
HHHHHHHHH     HHHHHHHHH               AAA               RRRRRRRRRRRRRRRRR   LLLLLLLLLLL             
H:::::::H     H:::::::H              A:::A              R::::::::::::::::R  L:::::::::L             
H:::::::H     H:::::::H             A:::::A             R::::::RRRRRR:::::R L:::::::::L             
HH::::::H     H::::::HH            A:::::::A            RR:::::R     R:::::RLL:::::::LL             
  H:::::H     H:::::H             A:::::::::A             R::::R     R:::::R  L:::::L               
  H:::::H     H:::::H            A:::::A:::::A            R::::R     R:::::R  L:::::L               
  H::::::HHHHH::::::H           A:::::A A:::::A           R::::RRRRRR:::::R   L:::::L               
  H:::::::::::::::::H          A:::::A   A:::::A          R:::::::::::::RR    L:::::L               
  H:::::::::::::::::H         A:::::A     A:::::A         R::::RRRRRR:::::R   L:::::L               
  H::::::HHHHH::::::H        A:::::AAAAAAAAA:::::A        R::::R     R:::::R  L:::::L               
  H:::::H     H:::::H       A:::::::::::::::::::::A       R::::R     R:::::R  L:::::L               
  H:::::H     H:::::H      A:::::AAAAAAAAAAAAA:::::A      R::::R     R:::::R  L:::::L         LLLLLL
HH::::::H     H::::::HH   A:::::A             A:::::A   RR:::::R     R:::::RLL:::::::LLLLLLLLL:::::L
H:::::::H     H:::::::H  A:::::A               A:::::A  R::::::R     R:::::RL::::::::::::::::::::::L
H:::::::H     H:::::::H A:::::A                 A:::::A R::::::R     R:::::RL::::::::::::::::::::::L
HHHHHHHHH     HHHHHHHHHAAAAAAA                   AAAAAAARRRRRRRR     RRRRRRRLLLLLLLLLLLLLLLLLLLLLLLL
                                                                                                                                                                           
		Made with love by: hbendjab     
endef
export BANNER

NAME		= 	Harl
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR		= .objfiles

FILES		= main Harl 

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)
	@printf "$(GREEN)- Replace ready!$(RESET)\n"
	@echo "$$BANNER"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@printf "$(CURSIVE)- Compiled with $(FLAGS) -$(RESET)\n"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(YELLOW)- Object files cleaned!$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)- Executable cleaned!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re