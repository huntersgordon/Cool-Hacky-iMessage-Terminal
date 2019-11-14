# iMessage-Terminal

Control your Mac through sending it text messages!
This tool takes messages your Mac receives via the Messages app and executes them through the bash shell. Output is sent back to the user.

# Installation

OS X 10.14+: [disable rootless mode](https://www.macworld.co.uk/how-to/mac/how-turn-off-mac-os-x-system-integrity-protection-rootless-3638975/)if you want this to work.

```open -a messages.app```

```cd /Users/(whoami)/Library/Messages/Archive/```

then cd into the directory of the current day.  i.e. ```cd 2018-12-06```

Copy messageClient.sh, getResponse.cpp, and messageSender.sh into to the current day's messages folder. 

```g++ getResponse.cpp```

to run: 

```
   while true; do bash messageClient.sh; sleep 3; done
   ```
# Running commands through iMessage (iPhone as a terminal)

Change line 16 and 17 to your phone number, or wherever you'd like to recieve your terminal output.

If you want to execute a command, just message your command to yourself, followed by a semicolon, and it will be executed!

texting your computer ```say hi;``` will make it say hi. ```ls;``` lists current directory, etc. Be creative!


# Notes

It seems that approx. 15 seconds after Messages receives a text, it writes the chat to a '.ichat' "binary1"-formatted file in the current day's directory. So, I convert the .ichat file to xml1 and parse through that resulting document, noting that the last received text is located two strings before an "NSArray", "NSMutableArray", or "InstantMessage" string declaration, AND directly before a hyphenated string declaration. C++ Does the string parsing. 

shown below: the last message, "say 4;" can be found 2 strings before the "InstantMessage" string, and 1 string before the hyphenated string. (Perhaps this is an ID for that specific message...)

![alt text](http://www.calhat.com/juulpics/example.png)
