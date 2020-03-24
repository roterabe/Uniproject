#!/usr/bin/env python3

# Usage: ./formatDate.py - formats all files with an American date format, to files with an European format.

import os, re, shutil

# Regex to match American date formats in files.

dateMatch = re.compile(r"""^(.*?) # all text before date
    ((0|1)?\d)- # month is either 04 or 4
    ((0|1|2|3|4)?\d)- # day is either 09 or 19
    ((19|20)?\d) # looks at the 20th and 21st century
    (.*?)$ # all text after the date
    """, re.VERBOSE)

    # Loop over files in current directory.
for amerFilename in os.listdir('.'):
    match = dateMatch.search(amerFilename)

    # Skip files without a date.
    if match == None:
        continue

    # Get the needed text from the filename.
    beforeDate = match.group(1)
    monthPart = match.group(2)
    dayPart = match.group(4)
    yearPart = match.group(6)
    afterDate = match.group(8)

    # Format to European date.
    euroFilename = beforeDate + dayPart + '-' + monthPart + '-' + yearPart + afterDate


    # Get the full filepath for the file edited.
    absWorkingDir = os.path.abspath('.')
    amerFilename = os.path.join(absWorkingDir, amerFilename)
    euroFilename = os.path.join(absWorkingDir, euroFilename)


    # Rename the files after the format.
    print('Renaming "%s" to "%s"...' % (amerFilename, euroFilename)) # Test print before changing
    shutil.move(amerFilename, euroFilename)
