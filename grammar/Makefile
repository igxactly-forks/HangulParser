
GRAMMAR_DIR=$(ROOT_DIR)/grammar

GRAMMAR_SRC+=$(GRAMMAR_DIR)/hangul_lex.c $(GRAMMAR_DIR)/hangul_lex.h
CLEAN_FILE+= $(GRAMMAR_DIR)/*.c $(GRAMMAR_DIR)/*.h $(GRAMMAR_DIR)/*.o

$(GRAMMAR_DIR)/hangul_lex.c $(GRAMMAR_DIR)/hangul_lex.h: $(GRAMMAR_DIR)/hangul.l $(INCLUDE_DIR)/token.h
	$(LEX) --header-file=$(GRAMMAR_DIR)/hangul_lex.h --outfile=$(GRAMMAR_DIR)/hangul_lex.c -Cefr $(GRAMMAR_DIR)/hangul.l

C_SRCS+= $(GRAMMAR_SRC)