# iMessage-Client-Mojave
So... Apple took off AppleScript handling, and now you can't receive iMessages through your terminal?

Not to worry.

This iMessage client is a solution to your problem.

# Installation

First, cd into your messages archive folder.

```/Users/(whoami)/Library/Messages/Archive/```

then cd into the directory of the current day. (iMessage will have created the directory if you messaged someone that day already.) i.e. ```cd 2018-12-06```

Copy temp.ichat, messageClient.sh, and a.out in the current day's messages folder. Create a blank temp.ichat file.

to run: (in fish shell)

```
   while true
      bash messageClient.sh;
      sleep 3;
   end
   ```

This is a crude remedy to what Apple seems to want to obfuscate. 

# What I'm doing:

It seems that approx. 15 seconds after Messages receives a text, it writes the transcript to a '.ichat' file in that day's directory. So, I convert the .ichat file to a plist and parse through that resulting document, noting that the last received text is located two strings before a certain "NSArray" declaration. This seems arbitrary. I let my C++ do that string parsing. Perhaps there is an easier way to go about this that involves indexing the plist.
