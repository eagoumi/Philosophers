#for test only



NAME = philo_bonus
INC = philosophers_bonus.h
FLAGS = -Wall -Wextra -Werror
SRC =	check_death.c \
		initial_sems_bonus.c \
		sleep_currtime_bonus.c \
		routine_bonus.c \
		philosophers_bonus.c \
		philo_utils.c \
		parsing_bonus.c 
OBJ = $(SRC:%.c=%.o)

all: $(NAME)
$(NAME) : $(OBJ) $(INC)
	gcc $(FLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all