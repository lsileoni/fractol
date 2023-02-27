CC=gcc
AR=ar rus
CFLAGS=-Wall -Wextra -Werror -Ofast -march=skylake
RM=rm -f

SRCDIR=src
OBJDIR=obj
STRDIR=$(SRCDIR)/string
CONVDIR=$(SRCDIR)/conversion
VALDIR=$(SRCDIR)/validation
MEMDIR=$(SRCDIR)/memory
PRINTDIR=$(SRCDIR)/print
LLDIR=$(SRCDIR)/linkedlist
BDIR=build

CFILES=\
	   $(CONVDIR)/ft_atoi.c \
	   $(CONVDIR)/ft_itoa.c \
	   $(CONVDIR)/ft_tolower.c \
	   $(CONVDIR)/ft_toupper.c \
	   $(CONVDIR)/ft_to_lowercase.c \
	   $(CONVDIR)/ft_to_uppercase.c \
	   $(CONVDIR)/ft_uitoa_base.c \
	   $(CONVDIR)/ft_ulltoa_base.c \
	   $(LLDIR)/ft_lstadd_back_bonus.c \
	   $(LLDIR)/ft_lstadd_front_bonus.c \
	   $(LLDIR)/ft_lstclear_bonus.c \
	   $(LLDIR)/ft_lstdelone_bonus.c \
	   $(LLDIR)/ft_lstiter_bonus.c \
	   $(LLDIR)/ft_lstlast_bonus.c \
	   $(LLDIR)/ft_lstmap_bonus.c \
	   $(LLDIR)/ft_lstnew_bonus.c \
	   $(LLDIR)/ft_lstsize_bonus.c \
	   $(MEMDIR)/ft_bzero.c \
	   $(MEMDIR)/ft_calloc.c \
	   $(MEMDIR)/ft_memchr.c \
	   $(MEMDIR)/ft_memcmp.c \
	   $(MEMDIR)/ft_memcpy.c \
	   $(MEMDIR)/ft_memmove.c \
	   $(MEMDIR)/ft_memset.c \
	   $(PRINTDIR)/ft_i_putchar_fd.c \
	   $(PRINTDIR)/ft_putchar_fd.c \
	   $(PRINTDIR)/ft_putendl_fd.c \
	   $(PRINTDIR)/ft_putnbr_fd.c \
	   $(PRINTDIR)/ft_putstr_fd.c \
	   $(PRINTDIR)/ft_printf/ft_printf.c \
	   $(PRINTDIR)/ft_printf/ft_printf_ops.c \
	   $(STRDIR)/ft_split.c \
	   $(STRDIR)/ft_strchr.c \
	   $(STRDIR)/ft_strdup.c \
	   $(STRDIR)/ft_striteri.c \
	   $(STRDIR)/ft_strjoin.c \
	   $(STRDIR)/ft_strlcat.c \
	   $(STRDIR)/ft_strlcpy.c \
	   $(STRDIR)/ft_strlen.c \
	   $(STRDIR)/ft_strmapi.c \
	   $(STRDIR)/ft_strncmp.c \
	   $(STRDIR)/ft_strnstr.c \
	   $(STRDIR)/ft_strrchr.c \
	   $(STRDIR)/ft_strtrim.c \
	   $(STRDIR)/ft_substr.c \
	   $(VALDIR)/ft_isalnum.c \
	   $(VALDIR)/ft_isalpha.c \
	   $(VALDIR)/ft_isascii.c \
	   $(VALDIR)/ft_isdigit.c \
	   $(VALDIR)/ft_isprint.c \

OBJS=\
	   $(OBJDIR)/ft_atoi.o \
	   $(OBJDIR)/ft_itoa.o \
	   $(OBJDIR)/ft_tolower.o \
	   $(OBJDIR)/ft_toupper.o \
	   $(OBJDIR)/ft_to_lowercase.o \
	   $(OBJDIR)/ft_to_uppercase.o \
	   $(OBJDIR)/ft_uitoa_base.o \
	   $(OBJDIR)/ft_ulltoa_base.o \
	   $(OBJDIR)/ft_lstadd_back_bonus.o \
	   $(OBJDIR)/ft_lstadd_front_bonus.o \
	   $(OBJDIR)/ft_lstclear_bonus.o \
	   $(OBJDIR)/ft_lstdelone_bonus.o \
	   $(OBJDIR)/ft_lstiter_bonus.o \
	   $(OBJDIR)/ft_lstlast_bonus.o \
	   $(OBJDIR)/ft_lstmap_bonus.o \
	   $(OBJDIR)/ft_lstnew_bonus.o \
	   $(OBJDIR)/ft_lstsize_bonus.o \
	   $(OBJDIR)/ft_bzero.o \
	   $(OBJDIR)/ft_calloc.o \
	   $(OBJDIR)/ft_memchr.o \
	   $(OBJDIR)/ft_memcmp.o \
	   $(OBJDIR)/ft_memcpy.o \
	   $(OBJDIR)/ft_memmove.o \
	   $(OBJDIR)/ft_memset.o \
	   $(OBJDIR)/ft_i_putchar_fd.o \
	   $(OBJDIR)/ft_putchar_fd.o \
	   $(OBJDIR)/ft_putendl_fd.o \
	   $(OBJDIR)/ft_putnbr_fd.o \
	   $(OBJDIR)/ft_putstr_fd.o \
	   $(OBJDIR)/ft_printf.o \
	   $(OBJDIR)/ft_printf_ops.o \
	   $(OBJDIR)/ft_split.o \
	   $(OBJDIR)/ft_strchr.o \
	   $(OBJDIR)/ft_strdup.o \
	   $(OBJDIR)/ft_striteri.o \
	   $(OBJDIR)/ft_strjoin.o \
	   $(OBJDIR)/ft_strlcat.o \
	   $(OBJDIR)/ft_strlcpy.o \
	   $(OBJDIR)/ft_strlen.o \
	   $(OBJDIR)/ft_strmapi.o \
	   $(OBJDIR)/ft_strncmp.o \
	   $(OBJDIR)/ft_strnstr.o \
	   $(OBJDIR)/ft_strrchr.o \
	   $(OBJDIR)/ft_strtrim.o \
	   $(OBJDIR)/ft_substr.o \
	   $(OBJDIR)/ft_isalnum.o \
	   $(OBJDIR)/ft_isalpha.o \
	   $(OBJDIR)/ft_isascii.o \
	   $(OBJDIR)/ft_isdigit.o \
	   $(OBJDIR)/ft_isprint.o \

NAME=$(BDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): $(CFILES)
	make all -C ./src/print
	make all -C ./src/print/ft_printf
	make all -C ./src/memory
	make all -C ./src/string
	make all -C ./src/vector
	make all -C ./src/hashmap
	make all -C ./src/conversion
	make all -C ./src/linkedlist
	make all -C ./src/dlinkedlist
	make all -C ./src/validation

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
