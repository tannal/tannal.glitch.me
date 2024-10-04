
# tc39

https://github.com/tc39/agendas/blob/main/2024/10.md

# dev

python tools/lint/lint.py --exceptions lint.exceptions test/built-ins/


./tools/dev/gm.py x64.release test262

npm install -g test262-harness

test262-harness -r node test-v-flag.js
test262-harness -r jsshell test-v-flag.js