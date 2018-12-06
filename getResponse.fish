#grab most recent modified file.
echo "waiting for incoming messages... (can take up to 15 seconds)"
set x 1
while true
  set a (find . -type f -print0 | xargs -0 stat -f "%m %N" |sort -rn | head -1 | cut -f2- -d" ")
  #should be, instead, an "if" statement that checks whether $a is a .ichat file.
  if [ $a = "./getResponse.fish" ]
    #echo "no new sauce";
    set x 0
  end
  if [ $a = "./temp.ichat" ]
    #echo "no new sauce";
    set x 0
  end
  if [ $a = "getResponse.cpp" ]
    #echo "no new sauce";
    set x 0
  end
  if [ $x = 1 ]
    cat $a > temp.ichat;
    plutil -convert xml1 temp.ichat
    ./a.out
    echo ""
  end
  set x 1
  sleep 2
end
