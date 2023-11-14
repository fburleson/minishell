NAME			=	minishell
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f

SRCDIR			=	./src/
PARSEDIR		=	$(SRCDIR)parse/
INITDIR			=	$(SRCDIR)init_cmd/
INITREDIRECTDIR	=	$(SRCDIR)init_redirection/
REDIRECTDIR		=	$(SRCDIR)redirect/
UTILDIR			=	$(SRCDIR)util/
EXECDIR			=	$(SRCDIR)exec/
BUILTINSDIR		=	$(SRCDIR)builtins/
BINDIR			=	./bin/
HEADERDIR		=	./include/
LIBDIR			=	./lib/

SRCFILES		=	minishell.c			\
					parse.c				\
					parse_arg.c			\
					expand.c			\
					parse_util.c		\
					init_args.c			\
					init_cmd.c			\
					init_cmds.c			\
					cmd_util.c			\
					init_outfiles.c		\
					init_infile.c		\
					init_iofile.c		\
					init_redirection.c	\
					heredoc.c			\
					setup_redirection.c	\
					redirection_util.c	\
					exec_program.c		\
					exec_builtin.c		\
					exec_cmd.c			\
					exec_util.c			\
					echo.c				\
					env.c				\
					exit.c				\
					pwd.c				\
					cd.c				\
					cd2.c				\
					export.c			\
					export2.c			\
					unset.c				\
					lstrlen.c			\
					copy_strarray.c		\
					strarraylen.c		\
					parraylen.c			\
					free_strarray.c		\
					print_strarray.c	\
					cp_modify.c			\
					envvar.c			\
					cmpstr.c			\
					excludechars.c		\
					free_shell.c		\
					print_err.c			\
					ft_open.c			\

BINFILES		=	$(notdir $(SRCFILES:.c=.o))

SRCPATHS		=	$(addprefix $(SRCDIR), $(SRCFILES))
BINPATHS		=	$(addprefix $(BINDIR), $(BINFILES))

LIBFTNAME		=	libft.a
LIBFTDIR		=	./libft/

$(NAME):		$(LIBDIR)$(LIBFTNAME) $(BINPATHS)
					$(CC) $(CFLAGS) $(BINPATHS) $(LIBDIR)$(LIBFTNAME) -lreadline -o $(NAME)

$(BINDIR)%.o:	$(SRCDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(BINDIR)%.o:	$(UTILDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(BINDIR)%.o:	$(PARSEDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(BINDIR)%.o:	$(INITDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(BINDIR)%.o:	$(INITREDIRECTDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(BINDIR)%.o:	$(REDIRECTDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(BINDIR)%.o:	$(EXECDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(BINDIR)%.o:	$(BUILTINSDIR)%.c
					@mkdir -p $(BINDIR)
					$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

$(LIBDIR)$(LIBFTNAME):
					$(MAKE) -C $(LIBFTDIR)

all:			$(NAME)

clean:
					@$(RM) $(BINPATHS)
					$(MAKE) fclean -C $(LIBFTDIR)

fclean:			clean
					@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
