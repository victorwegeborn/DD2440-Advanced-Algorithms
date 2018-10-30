SUCCESS=0
while [ $SUCCESS -eq 0 ]
do
    SUCCESS=1
    js random-sample.js 500 > tmp
    ../src/build/main < tmp
    SUCCESS=$?
done
