rem git add *.md *.bat *.cpp
del  *.aux *.bbl *.blg *.idx *.ilg *.ind *.lof /s
del  *.log *.lot *.out *.tdo *.toc /s

git add .
git reset HEAD *.exe *.pdf *.pdf_tex *.gz
git status
git commit -m "add latex code setting"
git push origin master
git status