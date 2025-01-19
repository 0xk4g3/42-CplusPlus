
define BANNER



                                                                                                                              
                                                                                                                              
RRRRRRRRRRRRRRRRR                                           lllllll                                                           
R::::::::::::::::R                                          l:::::l                                                           
R::::::RRRRRR:::::R                                         l:::::l                                                           
RR:::::R     R:::::R                                        l:::::l                                                           
  R::::R     R:::::R    eeeeeeeeeeee    ppppp   ppppppppp    l::::l   aaaaaaaaaaaaa       cccccccccccccccc    eeeeeeeeeeee    
  R::::R     R:::::R  ee::::::::::::ee  p::::ppp:::::::::p   l::::l   a::::::::::::a    cc:::::::::::::::c  ee::::::::::::ee  
  R::::RRRRRR:::::R  e::::::eeeee:::::eep:::::::::::::::::p  l::::l   aaaaaaaaa:::::a  c:::::::::::::::::c e::::::eeeee:::::ee
  R:::::::::::::RR  e::::::e     e:::::epp::::::ppppp::::::p l::::l            a::::a c:::::::cccccc:::::ce::::::e     e:::::e
  R::::RRRRRR:::::R e:::::::eeeee::::::e p:::::p     p:::::p l::::l     aaaaaaa:::::a c::::::c     ccccccce:::::::eeeee::::::e
  R::::R     R:::::Re:::::::::::::::::e  p:::::p     p:::::p l::::l   aa::::::::::::a c:::::c             e:::::::::::::::::e 
  R::::R     R:::::Re::::::eeeeeeeeeee   p:::::p     p:::::p l::::l  a::::aaaa::::::a c:::::c             e::::::eeeeeeeeeee  
  R::::R     R:::::Re:::::::e            p:::::p    p::::::p l::::l a::::a    a:::::a c::::::c     ccccccce:::::::e           
RR:::::R     R:::::Re::::::::e           p:::::ppppp:::::::pl::::::la::::a    a:::::a c:::::::cccccc:::::ce::::::::e          
R::::::R     R:::::R e::::::::eeeeeeee   p::::::::::::::::p l::::::la:::::aaaa::::::a  c:::::::::::::::::c e::::::::eeeeeeee  
R::::::R     R:::::R  ee:::::::::::::e   p::::::::::::::pp  l::::::l a::::::::::aa:::a  cc:::::::::::::::c  ee:::::::::::::e  
RRRRRRRR     RRRRRRR    eeeeeeeeeeeeee   p::::::pppppppp    llllllll  aaaaaaaaaa  aaaa    cccccccccccccccc    eeeeeeeeeeeeee  
                                         p:::::p                                                                              
                                         p:::::p                                                                              
                                        p:::::::p                                                                             
                                        p:::::::p                                                                             
                                        p:::::::p                                                                             
                                        ppppppppp                                                                             
                                                                                                                              


		Made with love by: hbendjab     
endef
export BANNER

NAME		= Replace
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR		= .objfiles

FILES		= main 

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