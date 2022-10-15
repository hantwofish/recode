del *.exe /s
rem latex 输出文件
del  *.aux *.bbl *.blg *.idx *.ilg *.ind *.lof /s
del  *.log *.lot *.out *.tdo *.toc /s


git add .
git reset HEAD *.exe *.png *jpg *.jpeg *.bmp 
git reset HEAD *.exe *.pdf *.pdf_tex *.gz

rem git status

rem git commit -m "add latex code setting01"
rem git push origin master
git status

pause 