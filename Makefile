MAIN = main.tex
OUT_DIR ?= pdf
PDF_NAME ?= teamnote

LATEXMK = latexmk
LATEXMK_FLAGS = -pdf -shell-escape

PDF = $(OUT_DIR)/$(PDF_NAME).pdf

.PHONY: all clean distclean

all: $(PDF)

$(PDF): $(MAIN)
	mkdir -p $(OUT_DIR)
	$(LATEXMK) $(LATEXMK_FLAGS) -outdir=$(OUT_DIR) -jobname=$(PDF_NAME) $(MAIN)

clean:
	$(LATEXMK) -c -outdir=$(OUT_DIR) -jobname=$(PDF_NAME) $(MAIN)

distclean:
	$(LATEXMK) -C -outdir=$(OUT_DIR) -jobname=$(PDF_NAME) $(MAIN)