#!/bin/bash

current_date=$(date '+%d.%m.%Y %H:%M:%S')
echo
echo "Текущее время: $current_date"
cd $1
echo "git pull"
git pull 

if [ "$(git status | grep 'git add')" ]; then
    commit_message="Sharlabr: автоматический коммит от $current_date"
    echo "Коммитим"
    git add -A
    git commit -m "$commit_message"
    git push
else
    echo 'Коммитить нечего'
fi
