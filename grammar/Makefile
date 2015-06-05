
GRAMMAR_DIR=$(ROOT_DIR)/grammar

GRAMMAR_SRC+=$(GRAMMAR_DIR)/hangul_lex.cpp $(GRAMMAR_DIR)/hangul_lex.hpp
CLEAN_FILE+= $(GRAMMAR_DIR)/*.cpp $(GRAMMAR_DIR)/*.hpp $(GRAMMAR_DIR)/*.o

$(GRAMMAR_DIR)/hangul_lex.cpp $(GRAMMAR_DIR)/hangul_lex.hpp: $(GRAMMAR_DIR)/hangul.l $(INCLUDE_DIR)/token.h
	$(LEX) --c++ --header-file=$(GRAMMAR_DIR)/hangul_lex.hpp --outfile=$(GRAMMAR_DIR)/hangul_lex.cpp $(GRAMMAR_DIR)/hangul.l

SRCS+= $(GRAMMAR_DIR)/hangul_lex.cpp