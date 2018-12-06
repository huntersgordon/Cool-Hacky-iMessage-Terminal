# iMessage-Client-Mojave
So... Apple took off AppleScript handling, and now you can't receive iMessages through your terminal?

Not to worry.

This iMessage client is a solution to your problem.

# Installation

First, get the fish shell.

```brew install fish```

Then, cd into your messages archive folder.

```/Users/(whoami)/Library/Messages/Archive/```

then cd into the directory of the current day. (iMessage will have created the directory if you messaged someone that day already.) i.e. ```cd 2018-12-06```

Lastly, place temp.ichat, getResponse.fish, and a.out in that messages folder.

to run:

```fish getResponse.fish```

This is a crude remedy to what Apple seems to want to obfuscate. Why??? Let me automate please.

# What I'm doing:

It seems that approx. 15 seconds after Messages receives a text, it writes the transcript to a '.ichat' file in that day's directory. So, I convert the .ichat file to a plist and parse through that resulting document, noting that the last received text is located two strings before a certain "NSArray" declaration. This seems arbitrary. I let my C++ do that string parsing. Perhaps there is an easier way to go about this.
