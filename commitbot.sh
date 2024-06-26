#!/bin/bash

current_date=$(date '+%d.%m.%Y %H:%M:%S')
git pull

if [ "$(git status | grep 'git add')" ]; then
    echo 'Будем коммитить!'
    git add -A
    git commit -m "Sharlabr: автоматический коммит от $current_date" > /dev/null
    git push
else
    echo 'Not to commit!'
fi
