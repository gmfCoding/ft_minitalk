# RANDOM=$$
# for i in `seq $1`
# do
# 	word="$word $RANDOM % 26"
# done
word=$(openssl rand -hex $1)
set -x 
pid=$(ps a | grep "\.\/server" | awk '{print $1}')
./client $pid "$word"
