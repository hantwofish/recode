# rm -rf *.exe 
# upload to github
git add .
git reset HEAD *jpg *.jpeg *.bmp *.exe
git status

#git add *.c *.cpp *.md *.sh
git commit -m "add notes 12_27"
git push origin main