#!/bin/sh
 # Can be used by your scripts to send iMessages from the shell
 # Usage:
 # ./SendMessage.sh 1234567890 'hi there!'
 recipient="${1}"
 message="${*:2}"
 cat<<EOF | osascript - "${recipient}" "${message}"
 on run {targetBuddyPhone, targetMessage}
    tell application "Messages"
        set targetService to 1st service whose service type = iMessage
        set targetBuddy to buddy targetBuddyPhone of targetService
        send targetMessage to targetBuddy
    end tell
end run
EOF
