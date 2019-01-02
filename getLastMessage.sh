a=$(find . -type f -print0 | xargs -0 stat -f "%m %N" |
sort -rn | head -1 | cut -f2- -d" ");
a=$(basename $a);
extension=$(echo -n $a | tail -c 6)
if [ $extension = ".ichat" ]
then
  #echo "the most recent modified file's an ichat file!";
  cp $a temp.ichat 2>>/dev/null;
  plutil -convert xml1 temp.ichat;
  ./a.out; #outputs the last message.
else
  #echo "it's not an ichat file."
  exit;
fi
