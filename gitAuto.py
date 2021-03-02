from os import system
lst = ['git pull', 'git add -A', 'git commit -m "Modified"', 'git push']
for i in lst:
    system(i) 