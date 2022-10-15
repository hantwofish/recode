rm *.aux *.bbl *.blg *.idx *.ilg *.ind *.lof
rm *.log *.lot *.out *.tdo *.toc


xelatex main.tex
bibtex main
makeindex main
xelatex main.tex
xelatex main.tex

