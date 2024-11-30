#!/bin/bash

# 进入你的git仓库目录
cd /home/tannal/tannalwork/projects/tannal.glitch.me

# 获取当前时间作为commit信息
timestamp=$(date '+%Y-%m-%d %H:%M:%S')

# 执行git命令
git add .
git commit -m "Auto commit at $timestamp"
git pull --rebase -X theirs
git push origin main

# 可选：添加日志
echo "Committed and pushed at $timestamp" >> auto-commit.log

bun ./scripts/date.js
