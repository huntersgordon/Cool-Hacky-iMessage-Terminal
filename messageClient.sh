a=$(find . -type f -print0 | xargs -0 stat -f "%m %N" |
sort -rn | head -1 | cut -f2- -d" ");
extension=$(echo -n $a | tail -c 6)
if [ $extension = ".ichat" ]
then
  if [ "$a" != "./temp.ichat" ]
  then
    #echo "the most recent modified file's an ichat file!";
    cp "$a" temp.ichat 2>>/dev/null;
    plutil -convert xml1 temp.ichat;
    message=$(./a.out); #outputs the last message.
    if [[ $message == *";"* ]]; then
      response=$(eval $message); #if user inputs a semicolon the message is executed.
      echo $message;
      ./messageSender.sh 8186215850 $response;
      ./messageSender.sh 8186215850 "end message";
    fi
  #else
    #echo "temp.ichat appears to be the last modified file";
  #  echo "";
  fi
else
  #echo "it's not an ichat file."
  exit;
fi
