set -xe
for DIR in ./src ./include ./test
do
find $DIR -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' -exec clang-format -style=file -i {} \;
done 