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
