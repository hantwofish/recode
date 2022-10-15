# rm -rf *.exe 
git add .
git reset HEAD *jpg *.jpeg *.bmp *.bat
git reset HEAD *.exe
git status

git add *.c *.cpp *.md *.sh
git commit -m "add markdown notes"
git push origin master