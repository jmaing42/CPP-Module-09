NAME = btc
OBJS = main.o Database.o

CXXFLAGS = -Wall -Wextra -Werror


all: $(NAME)
.PHONY: all


.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all


.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $<

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
