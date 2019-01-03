# iMessage-Client-Mojave
So... Apple took off AppleScript handling, and now you can't receive iMessages through your terminal?

Not to worry.

This iMessage client is a solution to your problem.

# Installation

```open -a messages.app```

```cd /Users/(whoami)/Library/Messages/Archive/```

then cd into the directory of the current day.  i.e. ```cd 2018-12-06```

Copy messageClient.sh into to the current day's messages folder. 

to run: 

```
   while true; do bash messageClient.sh; sleep 3; done
   ```
   
If you want to execute a command just message your command to anyone (or anyone can message you) followed by a semicolon and it will be executed!

This is a crude remedy to what Apple seems to want to obfuscate. 

# Notes

It seems that approx. 15 seconds after Messages receives a text, it writes the chat to a '.ichat' "binary1"-formatted file in the current day's directory. So, I convert the .ichat file to xml1 and parse through that resulting document, noting that the last received text is located two strings before an "NSArray", "NSMutableArray", or "InstantMessage" string declaration, AND directly before a hyphenated string declaration. C++ Does the string parsing. 

![alt text](http://www.calhat.com/juulpics/example.png)
