#!/usr/bin/env python3

# Usage: ./clipsave.py save <keyword> - Saves coped text to specific word../
#        ./clipsave.py <keyword> - Loads stored text onto clipboard.
#        ./clipsave.py list - Loads all stored text with keywords for reference.


import sys, shelve, pyperclip


clipShelf = shelve.open('clp')
# Save clipboard content

if len(sys.argv) == 3 and sys.argv[1].lower() == 'save':
    clipShelf[sys.argv[2]] = pyperclip.paste()
elif len(sys.argv) == 2:   
# List keywords and load content
    if sys.argv[1].lower() == 'list':
        print((str(list(clipShelf.keys()))))

    elif sys.argv[1] in clipShelf:
        pyperclip.copy(clipShelf[sys.argv[1]])

clipShelf.close()