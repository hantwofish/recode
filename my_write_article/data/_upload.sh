# rm -rf *.exe 
# upload to gitee
rm *.exe
git add *.tex
git reset HEAD *.exe *.pdf *.pdf_tex *.gz
git status
git commit -m "add latex code setting"
git push origin master
git status 