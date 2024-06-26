#!/bin/bash

current_date=$(date '+%d.%m.%Y %H:%M:%S')
echo
echo "Текущее время: $current_date"
echo "git pull"
git pull 

if [ "$(git status | grep 'git add')" ]; then
    commit_message="Sharlabr: автоматический коммит от $current_date"
    echo "Коммитим\ngit add -A"
    git add -A
    echo "git commit -m $commit_message"
    git commit -m "$commit_message"
    echo "git push"
    git push
else
    echo 'Коммитить нечего'
fi
