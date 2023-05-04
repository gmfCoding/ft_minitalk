RANDOM=$$
for i in `seq $1`
do
	word="$word $RANDOM"
done
set -x 
./server &
pid=$!
echo "./client $pid \"\"" | xargs echo -n | pbcopy
